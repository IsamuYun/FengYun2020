// quit.c
// 由jjgod为模拟华附修改

#include <command.h>
#include <ansi.h>
inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
	seteuid(getuid());
	set("channel_id", "值日精灵");
}

int main(object me, string arg)
{
	int i;
	object *inv, link_ob;
	int stage;

	if( !me->query_temp("netdead") )
	{
	        stage = me->query_temp("suicide_countdown");

		if ( !wizardp(me) && (stage<1) && me->is_busy()  )
		{
			return notify_fail("你上一个动作还没有完成,不能退出。\n");
		}
        	if ( me->is_busy() )
	        {
        	        return notify_fail("你上一个动作还没有完成，不能退出。\n");
	        }
		if( me->query_temp("no_quit"))
			return notify_fail("你现在暂时不可以退出！\n");
	}
	if( !wizardp(me) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(me, inv[i]);
	}

	link_ob = me->query_temp("link_ob");
		// We might be called on a link_dead player, so check this.
	if( link_ob ) {

	// 是否possess进别人身体里了
		if( link_ob->is_character() ) {
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
		destruct(link_ob);
	}
	write(YEL"欢迎您下次再来！\n"NOR);
	message("system", me->name() + "回家了。\n", environment(me), me);
	i=me->query("combat_exp")-me->query_temp("temp_exp");
	if (i < 0 ) i=0;
	CHANNEL_D->do_channel(this_object(), "sys",
		me->name() + "(" + me->query("id") + ")离开游戏了。本次连线经验增长"+i+
			"。\n");	
	CHANNEL_D->do_channel(this_object(), "hf",me->name() + "(" + me->query("id") + ")回家了，请大家夹道欢送！\n");	
// 有些游戏当ppl在0气血退出时给回它满气血，有些则不是，在这里，只给回他1点气血
	if(!(int)me->query("kee") ) me->set("kee",1);
	me->save();
/*拜托，写这么多log干什么？浪费硬盘呀！
	log_file( "USAGE", sprintf("%s 在 %s 退出，经验: %d, 潜能: %d, 金钱: %d\n",
       	me->query("id"), ctime(time()), me->query("combat_exp"),me->query("potential"),
       	me->query("deposit")));
	log_file("STAT", sprintf("退出： %s %s %d %d %d %d %d %d %s\n",
	me->query("id"),me->query("name"),me->query("combat_exp"),
	me->query("deposit"),me->query("potential"),me->query("TASK"),
	me->query("mud_age"), me->query("QUEST"), ctime(time()) ) );
	me->set("time_aged",me->query("time_aged")+time()-me->query_temp("temp_time"));
*/
	destruct(me);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : quit

当你(玩家)想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}
