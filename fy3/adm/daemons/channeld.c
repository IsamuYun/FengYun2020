//xgchen@fy
// channeld.c
#define NEW_PERIOD 32400
#include <ansi.h>
#include <net/dns.h>
inherit F_DBASE;
mapping channels = ([
        "sys":  ([      "msg_speak": RED "【系统监测】%s：%s\n" NOR, "wiz_only": 1 ]),
        "qst" : ([      "msg_speak": HIC "【报告任务】%s：%s\n" NOR, "anonymous": " ", "wiz_only": 1 ]),
        "wiz":  ([      "msg_speak": HIY "【巫师交流】%s：%s\n" NOR, "wiz_only": 1 ]),
        "chat": ([      "msg_speak": HIC "【江湖闲聊】%s：%s\n" NOR ]),
        "new":  ([      "msg_speak": HIG "【初入江湖】%s：%s\n" NOR ]),
        "gab":  ([      "msg_speak": MAG "【市井脏言】%s：%s\n" NOR ]),
        "fy":   ([      "msg_speak": HIR "【一世风云】%s：%s\n" NOR,
                        "msg_emote": HIR "【一世风云】%s\n" NOR,
                              "intermud": GCHANNEL, "channel": "fy",
                               "filter": (: $1["MUDLIB"]=="FYMUD" :) ]),
        "rumor":(["msg_speak": HIM "【谣言惑众】%s：%s\n" NOR,"anonymous": "某人"]), 
        ]);

void create()
{
        seteuid(getuid()); // This is required to pass intermud access check.
        set("channel_id", "频道精灵");
}

varargs int do_channel(object me, string verb, string arg, int emote)
{
        object *ob;
        string *tuned_ch, who;
 //       if( verb != "chat"  &&
//                 verb != "fy"  &&
//                 verb != "rumor"  &&
//                 verb != "new") return 0;

        if(!wizardp(me) && userp(me) && (int)me->query("mud_age") < NEW_PERIOD &&  (
        verb == "chat" || 
        verb == "rumor" || 
        verb == "fy" 
        )
        )
        {
        write("你只可以使用【初入江湖】（ｎｅｗ）频道。\n");
        return 1;
        }
        if ((int)me->query("chblk_on") && !wizardp(me) && channels[verb])
             return notify_fail("你的公共频道被关闭了！\n");
        // check if rumor or chat is blocked
        if ((int)query("block_rumor") && (verb == "rumor"||verb == "rumor*") )
                return notify_fail("谣言惑众频道被关闭了！\n");
        if ((int)query("block_chat") && (verb == "chat"||verb == "chat*") )
                return notify_fail("江湖闲聊频道被关闭了！\n");
        if ((int)query("block_new") && (verb == "new"||verb == "new*") )
                return notify_fail("初入江湖频道被关闭了！\n");
        if ((int)query("block_fy") && (verb == "fy"||verb == "fy*") )
                return notify_fail("一世风云频道被关闭了！\n");

        if( !mapp(channels) || undefinedp(channels[verb]) )
                return 0;
        if( userp(me) ) {
                if(channels[verb]["wiz_only"] && !wizardp(me) )
                        return 0;

                if( arg==(string)me->query_temp("last_channel_msg") )
                        return 
notify_fail("用交谈频道说话请不要重复相同的讯息。\n");
//  新加限制 xgchen@zzfy
//    if ( (int)me->query("mud_age") > NEW_PERIOD && verb=="new" && !wizardp(me))
//          return notify_fail("你已经不是新手了,请使用(chat或者fy频道）。\n")
// 反应不好暂时封闭
    if (me->query("level")<30&&verb=="fy"&&!wizardp(me))
          return notify_fail("你的经验不够,请使用(chat频道）。\n");
         // If we speaks something in this channel, then must tune it in.]
                tuned_ch = me->query("channels");
                if( !pointerp(tuned_ch) )
                        me->set("channels", ({ verb }) );
                else if( member_array(verb, tuned_ch)==-1 )
                        me->set("channels", tuned_ch + ({ verb }) );
        }
// log fy channel
 //       if( verb == "fy" ) 
  //   log_file("FY_LOG", ctime(time())+" "+ 
   //             me->query("name")+"("+ me->query("id")+") "+query_ip_name(me)+"("+query_ip_number(me)+"):"+arg+"\n");

//太多log 文件不好 
       if( channels[verb]["anonymous"] ) {
                who = channels[verb]["anonymous"];
                if (userp(me))
                {
                do_channel( this_object(), "sys", sprintf("谣言：%s。", me->name()));
/*
               log_file("RUMOR_LOG", ctime(time())+" "+ 
                me->query("name")+"("+ me->query("id")+") "+query_ip_name(me)+"("+query_ip_number(me)+"):"+arg+"\n");
*/
                }
        }
        else if( userp(me) || !stringp(who = me->query("channel_id")) )
                who = me->query("name") + "(" + capitalize(me->query("id")) + ")";

        // Ok, now send the message to those people listening us.
ob = filter_array(users(),"filter_listener",this_object(),channels[verb]);
           if( !arg ) arg = "...";
        if( emote )
        message( "channel:" + verb,
                sprintf( channels[verb]["msg_emote"],arg ),ob);
        else
        message( "channel:" + verb,
                sprintf( channels[verb]["msg_speak"], who, arg ), ob );

        if( arrayp(channels[verb]["extra_listener"]) ) {
                channels[verb]["extra_listener"] -= ({ 0 });
                if( sizeof(channels[verb]["extra_listener"]) )
           channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
        }
        
        if( !undefinedp(channels[verb]["intermud"])
        &&      base_name(me) != channels[verb]["intermud"] )
                channels[verb]["intermud"]->send_msg(
     channels[verb]["channel"], me->query("id"), me->name(1), arg, emote,
                        channels[verb]["filter"] );
// 增加防止刷频 xgchen@zzfy
             if( userp(me) && !wizardp(me)) {
        me->add_temp("channel_msg_cnt", 1);
       if (me->query_temp("channel_msg_cnt")>2)
            if (time()-me->query_temp("chat_time")<1){
                me->set("chblk_on",time());
                do_channel( this_object(), "rumor", sprintf("长孙无情拿出一张狗皮膏，“啪”地捂住了%s的嘴巴。\n", me->name(1) ));
                return 1;
            }else{
                me->set_temp("chat_time",time());
                me->delete_temp("channel_msg_cnt");
               }
        }
        if( userp(me) ) 
                me->set_temp("last_channel_msg", arg);

        return 1;
}

int filter_listener(object ppl, mapping ch)
{
        // Don't bother those in the login limbo.
        if( !environment(ppl) ) return 0;
        
        if( ch["wiz_only"] ) return wizardp(ppl);
        return 1;
}

void register_relay_channel(string channel)
{
        object ob;

        ob = previous_object();
        if( undefinedp(channels[channel]) || !ob) return;
        if( arrayp(channels[channel]["extra_listener"]) ) {
                if( member_array(ob, channels[channel]["extra_listener"]) >=0 
) return;
                channels[channel]["extra_listener"] += ({ ob });
        } else
                channels[channel]["extra_listener"] = ({ ob });
}
 
int set_block(string channel, int d)
{
        set("block_"+channel,d);
        return 1;
}

