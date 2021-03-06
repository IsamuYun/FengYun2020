// marry_ring.c - 结婚戒指

#include <ansi.h>
#include <mudlib.h>
#include <armor.h>

inherit FINGER;

int do_coupletalk(string arg, int emote);

void create()
{
        set_name( HIY "结婚戒指" NOR, ({"marry ring", "ring"}) );
        set_weight(400);
        set( "no_get", 1);
	set( "no_put", 1 );
        set( "no_drop", "你的结婚戒指不能丢弃,只能去红娘庄解除婚约。\n");
        set( "long", @LONG
这是一枚结婚戒指。你可以使用以下命令：
[36m
coupletalk ( ct )	和伴侣对话。

支持命令：ct, ct#, ct*
[2;37;0m
LONG
	);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("material", "gold");
		set("armor_type", "finger");
                set("armor_prop/armor", 10);
		set("armor_prop/defense", 10);
	        set("wear_msg", "$N将$n拿出来小心地戴在手指上。\n");
	        set("remove_msg", "$N将$n小心地从手指上摘下来放好。\n");
        }
}

string couplename( object ob ) {
	if( ob ) {
		if( (string)ob->query("gender") == "女性" ) return "夫人" + ob->name(1);
		if( (string)ob->query("gender") == "男性" ) return "丈夫" + ob->name(1);
		return "旧伴侣" + ob->name(1);
	}
}

void init()
{
        object me, couple_ob;

	me = this_player();
	if( me->query("marry") ) {
	        couple_ob = find_player( me->query("marry") );
                    if (couple_ob && environment(couple_ob) ){
                 if ( couple_ob->query("marry")!=me->query("id") ){
                    tell_object(me,HIY "你的伴侣已经重新投胎了,如果有缘...\n"+NOR);
                  me->delete("marry");
                  destruct(this_object());
                  return;
                }
        	 	write( HIM "\n你的" + couplename( couple_ob ) + "也在这里，快去找啦....\n" NOR);
                	tell_object(couple_ob , sprintf( HIM "\n你的%s来啦，快去接啦....\n" NOR, couplename( me ) ));
	        }
	        set("name", HIC + me->query("id") + HIY "和" HIC + me->query("marry") 
			+ HIY "的结婚戒指" NOR );
	}

        add_action("do_coupletalk_0", "ct");
        add_action("do_coupletalk_1", "ct*");
        add_action("do_coupletalk_2", "ct#");
}

int do_coupletalk_0(string arg) { return do_coupletalk( arg, 0 ); }

int do_coupletalk_1(string arg) { return do_coupletalk( arg, 1 ); }

int do_coupletalk_2(string arg) { return do_coupletalk( arg, 2 ); }

int do_coupletalk(string arg, int emote)
{
        object me, couple_ob;
        int i;

        me = this_player();

        if ( !stringp(me->query("marry")) )
                return notify_fail("你没有伴侣。\n");

        couple_ob = find_player( me->query("marry") );
        if( !couple_ob )
                return  notify_fail("你的伴侣现在无法听见你，或者已经离开游戏了。\n");

        if ((string)couple_ob->query("gender") == "无性") 
                return  notify_fail("你原来的伴侣已经做了太监，你还是把他忘了吧。\n");

        if ( !arg ) {
                write( MAG "你又深情地想念你的爱侣了。\n" NOR);
                tell_room(environment(me), CYN + (string)me->name() + "又在深情地想念自己的爱侣" 
			+ (string)couple_ob->name() + "。\n" + NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(HIM "%s又在深情地想念你了。\n"NOR, couplename( me ) ) ); 

                return 1;
        }
	
        if (!stringp(arg) || arg == "" || arg == " ") arg = "...";

        // Support of channel emote
        if( emote ) {
                string vb, emote_arg;

                if( sscanf(arg, "%s %s", vb, emote_arg) != 2 ) {
                        vb = arg;
                        emote_arg = "";
                }
                arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, me->name());

		// If out support of channel emote and still send this message
        	if (!arg && emote == 2)
                 	arg = me->name() + vb + "\n";

                // If not Support of channel emote ruturn
        	if (! arg) return 0;

		arg = replace_string( arg, me->name(), couplename( me ) );

        	tell_object( me, MAG + replace_string( arg, couplename( me ), "你" ) + NOR );
        	tell_object( couple_ob, HIM + arg + NOR );
        }
	else {
	        write(sprintf(MAG "你对%s说：%s\n" NOR, couplename( couple_ob ), arg ));
        	tell_object(couple_ob, sprintf(HIM "%s对你说：%s\n" NOR, couplename( me ), arg ));
	}

        return 1;
}

