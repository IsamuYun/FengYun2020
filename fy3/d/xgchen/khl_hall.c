#include <ansi.h>
inherit ROOM;

void greeting(object me);
int give_him(object who,object host);
void create()
{
	set("short","������");
	set("long",@LONG
�����ǿ���ֵ�������������ܴ󣬰ڷ��˺ܶ�������Σ�����
�ڷŵ������ϻ滭�������Ϻ�ͼ���Է���ĵ������ɡ������ڲ�������
�ڵĵط��и�СϷ̨��һ����ϯ�����˶���������ܴ�ҵĺ�ϲ��
�����������˺�ϲ��(hexi)
LONG
	);
	set("exits",([
		"out" : "/d/fy/kuaihuolin",
		]));
	set("no_burn",1);
	set("no_quit",1);
	set("no_fight",1);
	set("no_magic",1);
	set("no_spells",1);
	set("no_huanlong",1);
	set("no_dazuo",1);
	set("coor/x",5);
	set("coor/y",5);
	set("coor/z",5);
	setup();
}
void init()
{
	object me;
	me=this_player();
	add_action("do_hexi","hexi");
	greeting(me);
	return;
}

int valid_leave(object me,string dir)
{
	if (userp(me))
	if ( dir=="out" && me->query_temp("host"))
	{
		return notify_fail("���Ǿ�ϯ���˰�����ϯû�н�����ô���뿪�أ�\n");
	}
	else {
		if (dir=="out" && me->query_temp("guest"))
		{
			me->delete_temp("guest");
			me->delete_temp("hongbao_given");
			return 1;
		}
		else{
			return 1;
		}
	}
}
void greeting(object me)
{
	message_vision(HIG"ֻ��$N�������ӣ����̻���һ����\n"NOR,me);
	me->set("food",200);
	me->set("water",200);
	return;
}
int do_hexi()
{
	object who,host,*ob;
	int key=0,i;
	who=this_player();
	ob=all_inventory(environment(who));
	if (who->query_temp("host"))
		return notify_fail("�������Լ���ϲ����\n");
	for (i=0;i<sizeof(ob);i++)
	{
		if ((ob[i]->query_temp("host")))
		{
			host=ob[i];
			key=1;
			break;
		}
		else {
			continue;
		}
	}
	if (!key) {return notify_fail("���˲��������˭��ϲ����\n");}
	if (!(who->query_temp("hongbao_given")))
	{
		give_him(who,host);	
		return 1;
	}
	else {
		message_vision(HIC"$N��$n˵������ϲ����ϲ��\n"NOR,who,host);
		message_vision(HIY"$N������Ц��$n˵����ͬϲ��ͬϲ��\n"NOR,host,who);
		return 1;
	}
}
int give_him(object guest,object master)
{
	object hongbao;
	int deposit;
	hongbao=new("/d/fy/npc/obj/hongbao");
	hongbao->set_temp("account",master->query_temp("gold"));
	deposit=master->query("deposit");
	message_vision(HIC"$N��$n˵������ϲ����ϲ��\n"NOR,guest,master);
	message_vision(HIY"$N������Ц,��$n����ͬϲ��ͬϲ��\n"NOR,master,guest);
	if (deposit < (master->query_temp("gold")*10000))
	{
		message_vision(HIM"$N��һ�죬ԭ��$P�Ĵ���������ˡ�\n"NOR,master);
		return 1;
	}
	else{
		message_vision(HIR"ֻ��$N�ӻ����ͳ�һ������ݸ�$n��\n"NOR,master,guest);
		guest->set_temp("hongbao_given",1);
		hongbao->move(guest);
		master->add("deposit",-(master->query_temp("gold")*10000));
		return 1;
	}
}