// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�춼��");
        set("long", @LONG
�춼��������������Ϊ�վ���һ�����ųơ�Ⱥ������������Ϊ��
�϶��ᡣ����·��������ɽ��͵�ʯ��������Χ���ĵ�ɽ����������
Ȼ�����С����������족֮�С�;����һʯ���磬���С�����������
���֣��ɴ˴�Զ�������ƹַ壬ɽȪ�ɺ��������۵ס�
LONG
        );
        set("exits", ([ 
  "southdown"  : __DIR__"jiyu",
  "westdown" : __DIR__"yixian",
]));
        set("objects", ([
        __DIR__"npc/hong" : 1,
	__DIR__"npc/lu" :1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-560);
	set("coor/y",-490);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
