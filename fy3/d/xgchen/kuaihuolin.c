#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����־Ƽ�");
	set("long",@LONG
������Ƿ��Ƴ��������Ŀ���־Ƽ��ˣ����ھƵ�����ϰ����ھ�Ӫ�ܶ�
֪����ʿ�������￪���ϯ����ףһЩ���顣�Ƶ�������������˵������
Ҳ��������������ء�
LONG  
	);
	set("exits",([
		"westdown":"/d/fy/fysquare",
		"enter":"/d/fy/khl_hall",
		]));
	set("objects",([
		"/d/fy/npc/yuyoucai" : 1,
		]));
	set("no_fight",1);
	set("no_huanlong",1);
	set("no_burn",1);
	set("no_magic",1);
	set("no_spells",1);
	set("coor/x",5);
	set("coor/y",0);
	set("coor/z",5);
    setup();
}
int valid_leave(object me,string dir)
{
	if (userp(me))
	if ( dir=="westdown" && me->query_temp("gold_given"))
		return notify_fail("�붨���ϯ��ϲ�������\n");
	if ( dir=="enter" && me->query_temp("gold_given"))
	{
		return notify_fail("���ȶ����ϯ�����ƺ�ϲ���������\n");
	}
	else{
		if ( dir=="enter" && !(me->query_temp("host")) && !(me->query_temp("guest")))
			return notify_fail("�㻹���ܽ�ȥ��\n");
		else {
			return 1;
		}
	}
}
