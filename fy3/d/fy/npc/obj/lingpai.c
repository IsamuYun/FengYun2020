
#include <ansi.h>
inherit ITEM;

void create()
{
		set_name("����", ({"ling pai","ling" }));
       set_max_encumbrance(10);
       set("unit", "��");
       set("long", "����һ����������,���ִ��죬����֤���ٸ���ʿ����ݡ�\n��������Ϳ�����Ѱ�ﷸ(souxun)��\n");
       set("value", 0);
       set("no_drop", "�������������뿪�㡣\n");
       set("no_burn",1);
       set("no_get", "���ǳ�͢�Ķ�����ƽ�������˻����鷳�ġ�\n");
       set_weight(200);
       set("place","on");
       setup();
}

void init()
{
      add_action("do_watch","souxun");
}

int do_watch(string arg)
{
	object me = this_player();

	if(me->query_temp("kf_name") && me->query("kf_working") && !me->query_temp("kf_finish"))
	{
		tell_object(me,HIC"����ϸ��Ѱ��"+me->query_temp("kf_name")+"......\n"NOR);
	}
	else
	{
		tell_object(me,"ʲô��\n");
	}
	
   return 1;
}

