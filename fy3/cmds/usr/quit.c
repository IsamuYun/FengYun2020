// quit.c
#include <ansi.h>;
#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
	seteuid(getuid());
	set("name", "����ָ��");
	set("id", "quit");
}

int main(object me, string arg)
{
	int i;
        object *inv, link_ob, env, ob;
	int stage;

	if( !me->query_temp("netdead") )
	{
                stage = me->query_temp("suicide_countdown");

		if ( !wizardp(me) && (stage<1) && me->is_busy()  )
		{
			return notify_fail("����һ��������û�����,�����˳���\n");
		}
/*
                if ( me->is_busy() )
	        {
        	        return notify_fail("����һ��������û�����,�����˳���\n");
}
*/
		if( me->query_temp("no_quit"))
			return notify_fail("�����ڲ������˳����ƣ�\n");
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

	// Are we possessing in others body ?
		if( link_ob->is_character() ) {
			write("��Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
		destruct(link_ob);
	}

	write("��ӭ�´�������\n");
	message("system", me->name() + "�뿪��Ϸ��\n", environment(me), me);
		CHANNEL_D->do_channel(this_object(), "sys",
		me->name()  +" ( " + me->query("id") + " ) "+"�뿪��Ϸ�ˡ�");
// don't why need this, some linux give players full kee if quit with 0 kee
// but some does not!
	if(!(int)me->query("kee") ) me->set("kee",1);
       me->set("quit_time",time());
        me->save();
	log_file( "USAGE", sprintf("%s quits at %s with exp: %d, pot: %d, money: %d\n",
       	me->query("id"), ctime(time()), me->query("combat_exp"),
        me->query("potential"),
       	me->query("deposit")));
	log_file("STAT", sprintf("OFF %s %s %d %d %d %d %d %d %s\n",
me->query("id"),me->query("name"),me->query("combat_exp"),
me->query("deposit"),me->query("potential"),me->query("TASK"),
me->query("mud_age"), me->query("QUEST"), ctime(time()) ) );
	destruct(me);

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : quit

����(���)����ʱ�뿪ʱ, �����ô�һָ�
HELP
    );
    return 1;
}
