// Tie@fengyun
inherit ROOM;
void create()
{
        set("short", "����ʯ��");
        set("long", @LONG
ʯ��ɢ����һ����ֵ�ù��ζ�����ּ�����һ˿Ѫ�ȣ��͸ɾ�����
���ƴ�·����룮һ�������ֳ���С�ӹ�˳����໺�����ʣ����滹Ư
��Ⱦ���ź�Ѫ�ı�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : "/d/fy/ecloud1",
  "north" : __DIR__"stone2",
]));
        set("objects", ([
        __DIR__"npc/scavenger" : 1,
			]) );

        set("outdoors", "fengyun");
        set("coor/x",10);
	set("coor/y",15);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
