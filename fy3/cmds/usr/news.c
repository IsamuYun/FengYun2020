#include <ansi.h>;
inherit BULLETIN_BOARD;
int do_post(string arg);

void create()
{
    set_name("新闻牌", ({ "news_board"}) );
        set("board_id", "news_b");    
    set("long","想清楚了写，写了就会生效而且不能删，原 code 来自xgchen编写\n\n");         
        setup();
        set("capacity", 1000);
}

int check_news(object me)
{
        int num,i,last_time_read;
        mapping *notes, last_read_time;
        string myid,msg="";
        
        notes = query("notes");
        last_read_time = me->query("board_last_read");
        myid = query("board_id");
        
        if( !pointerp(notes) || !sizeof(notes) ) return 1;

        if(userp(me))
        {
                i=sizeof(notes)-me->query("LastReadNews");
                
                if(i < 6 && i > 0) // 小于6条新闻才显示标题，不然会FLOOD
                {
                        msg = "\n\n    ━━━━━━━━━━━━ "HIW"快乐风云2最新消息"NOR" ━━━━━━━━━━━━    \n";
                        
                        if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
                                num = 1;
                                
                        else
                                for(num = 1; num<=sizeof(notes); num++)
                                        if( notes[num-1]["time"] > last_read_time[myid] ) break;
                                        
                        if (mapp(last_read_time)) last_time_read = last_read_time[myid];
                        for(i=sizeof(notes)-1 ; i>num-2 ; i--)
                        {
                                msg += sprintf("<%3d>"NOR,i+1);
                                msg += sprintf("     %-=36s %18s (%s)\n",
                                        notes[i]["title"], notes[i]["author"],
                                        CHINESE_D->chinese_time(5, ctime(notes[i]["time"])));
                        }
                        
                        msg += "    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    \n\n";
                        
                        me->start_more(msg);
                }
                
                i=sizeof(notes)-me->query("LastReadNews");
      if (i<0) i=0;
                write("\n从您上次阅读到现在"+((i==0)? "没有任何":"共有"+HIY+chinese_number(i)+NOR"条")+"新闻。\n\n");
                if(i>10) 
  //             me->start_call_out(bind((: call_other, __FILE__, "auto_notice", me :), me), 10 + random(10));
write("\n你可以 Help news 来查看快乐风云2新闻系统的使用方法。\n"); // 提醒不知道有NEWS系统的玩家使用news
        }
}
int main(object me, string arg)
{
        int num,i,last_time_read;
        mapping *notes, last_read_time;
        string myid,msg;

        last_read_time = me->query("board_last_read");
        myid = query("board_i");
        notes = query("notes");
        i=sizeof(notes)-me->query("LastReadNews");
        if( !pointerp(notes) || !sizeof(notes) )
                return notify_fail("「快乐风云2」目前没有任何新闻。\n");
                
        if( !arg ) 
      {
      if (i<0) i=0;
                if(i>10) write("你可以 Help news 来查看快乐风云2新闻系统的使用方法。\n"); 
                        return notify_fail(
                                "「快乐风云2」目前共有"+HIW+chinese_number(sizeof(notes))+NOR"条新闻"+((i==0)? "。":"，您有"+HIY+chinese_number(i)+NOR"条新闻尚未阅读。")+"\n"); }
                                
if(arg=="jia")
{
return do_post("快乐风云2");
}
                if( arg=="all") // 显示所有新闻
                {
                        msg = "\n\n    ━━━━━━━━━━━━ "HIW"快乐风云2新闻一览"NOR" ━━━━━━━━━━━━    \n";
                        notes = query("notes");
                        
                        if (mapp(last_read_time)) last_time_read = last_read_time[myid];
                        for(i=sizeof(notes)-1 ; i>-1 ; i--)
                        {
                                msg += sprintf("%s<%3d>" NOR,
                                notes[i]["time"] > last_time_read ? HIY: "", i+1);
                                msg += sprintf("     %-=36s %18s (%s)\n",
                                        notes[i]["title"], notes[i]["author"],
                                        CHINESE_D->chinese_time(5, ctime(notes[num]["time"])));
                        }
                        msg += "\n";
                        me->start_more(msg);
                        return 1;
                        
                }
                else
                if ( arg=="new" )  // 显示最新新闻
                {
                        if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
                                num = 1;
                        else
                                for(num = 1; num<=sizeof(notes); num++)
                                        if( notes[num-1]["time"] > last_read_time[myid] ) break;
                                        
                } else if( !sscanf(arg, "%d", num) )
                
        return notify_fail("你到底要看第几条新闻呀？\n");
        
        if( num < 1 || num > sizeof(notes) )
                return notify_fail("看清楚点，好像没有这条新闻耶。\n");
                
        num--;
     me->start_more( sprintf("\n\n%s\n
[47;34m  作者 [44;37m %-70s
[47;34m  标题 [44;37m %-70s
[47;34m  时间 [44;37m %-70s[m  [36m\n------------------------------------------------------------------------------[m\n\n\n",
               BBLU HIY"快乐"HIR"风云"HIG"第"+chinese_number(num + 1)+"条新闻"NOR, 
notes[num]["author"],notes[num]["title"],ctime(notes[num]["time"]))
+ notes[num]["msg"]+
        HIY"\n\n\t\t\t快乐风云2"NOR"\n-------------------------------------------------------------------------------\n\n", );

        if( !mapp(last_read_time) )
                me->set("board_last_read", ([ myid: notes[num]["time"] ]) );
        else 
                if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
                        last_read_time[myid] = notes[num]["time"];

        if(me->query("LastReadNews") < num + 1)
                me->set("LastReadNews",num+1);

        return 1;
}

void init()
{
        object me=this_player();
// 只给apprentice级别以上的巫师修改新闻
       if (wizardp(me) &&  wiz_level(me) > wiz_level("(apprentice)") )
        {
                add_action("do_post", "jia");
             //   add_action("do_discard", "qu");
      } 
}

int do_post(string arg)
{
        mapping note;

        if(!arg) return notify_fail("新闻要个加题目。\n");

        note = allocate_mapping(4);
        note["title"] = arg;
      note["author"] = this_player()->query("name")+"("+this_player()->query("id")+")";
        note["id"] = this_player()->query("id"); 
        note["qianminglong"] = this_player()->query("qianminglong"); 
        this_player()->edit( (: done_post, this_player(), note :) );
        return 1;
}

void done_post(object me, mapping note, string text)
{
        mapping *notes;

        note["time"] = time();
        note["msg"] = text;
        notes = query("notes");
        if( !pointerp(notes) || !sizeof(notes) )
                notes = ({ note });
        else
                notes += ({ note });

        if( sizeof(notes) > query("capacity"))
                notes = notes[query("capacity")/2 .. query("capacity")];

        set("notes", notes);
        save();
        restore();
// 使用channel显示提示有了最新新闻
        CHANNEL_D->do_channel(me, "fy", BLINK HIR"\n\n「快乐风云2」有了最新新闻，请用(news new)查看。\n" NOR);

        tell_object(me, "新闻发表完毕。\n");

        return;
}
/*
void auto_notice(object me)
{
        int num;
        mapping *notes;
        string msg;
        int last_read_time;

        if (! objectp(me))
                return;

        last_read_time = me->query("last_read_news");
        notes = query("notes");

        if (! pointerp(notes) || ! sizeof(notes))
                return;

        num = sizeof(notes) - 1;
        if (notes[num]["time"] <= last_read_time)
                return;

        // some news need read, start next call out
        me->start_call_out(bind((: call_other, __FILE__, "auto_notice", me :), me), 30 + random(30));

        if (! living(me) || me->query_temp("block_msg/all"))
                return;

        while (num-- > 0)
        {
                if (notes[num]["time"] <= last_read_time)
                {
                        num++;
                        break;
                }

                // contine to find next
        }

        if (num < 0) num = 0;

        switch (random(5))
        {
        case 0:
                msg = HIM "一阵烟雾过后，新闻精灵出现在你的面前，手里"
                      "捏着一张破破烂烂的纸头，对你宣读起来。\n" NOR;
                break;
        case 1:
                msg = HIM "地上突然开了一个裂缝，冒出一个鬼鬼祟祟的新"
                      "闻精灵，对着你就喋喋不休的罗嗦起来。\n" NOR;
                break;
        case 2:
                msg = HIM "你忽然听见有人喊你，你回头一看，原来是新闻"
                      "精灵满头大汗的跑了过来，\n" NOR;
                break;
        case 3:
                msg = HIM "你刚打了一个哈欠，忽然前面冒出一股烟雾，散"
                      "去以后只见一个新闻精灵懒洋洋的看着你，口中念念有词。\n" NOR;
                break;
        default:
                msg = HIM "“啪啦”一声，新闻精灵狼狈不堪的摔在地上，"
                      "你连忙将他扶起。\n" NOR;
                break;
        }

        msg += HIG "新闻精灵告诉你来自神界的最新消息：\n" NOR;
        tell_object(me, msg);
     me->start_more( sprintf("\n\n%s\n
[47;34m  作者 [44;37m %-70s
[47;34m  标题 [44;37m %-70s
[47;34m  时间 [44;37m %-70s[m  [36m\n------------------------------------------------------------------------------[m\n\n\n",
               BBLU HIY"一世"HIR"风云"HIG"第"+chinese_number(num + 1)+"条新闻"NOR, 
notes[num]["author"],notes[num]["title"],ctime(notes[num]["time"]))
+ notes[num]["msg"]+
        HIY"\n\n\t\t\t快乐风云2"NOR"\n-------------------------------------------------------------------------------\n\n", );

        // Keep track which post we were reading last time.
        if (notes[num]["time"] > (int)last_read_time)
                me->set("last_read_news", notes[num]["time"]);
        tell_object(me, HIM "新闻精灵说完后，消失在一阵烟雾之中。\n" NOR);
}

*/
int help(object me)
{
    write(@HELP
「快乐风云2」新闻系统指令 

指令格式 :
news                    查看共有的和最新发布的新闻。
news all                快乐风云2新闻一览。 
news new                阅读最新的新闻。 
news <新闻编号>         查看此编号新闻的详细内容。 
HELP
    );
    return 1;
}
