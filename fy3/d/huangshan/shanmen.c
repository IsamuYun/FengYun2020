// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����һ��ʯ���ŷ�������ɽ�ź󣬱��ǻ�ɽ������������꣬��
����Ϊǭɽ����ɽɫ��ڣ�Զ������������������������š��Ƶ���
�˷����������Ը�Ϊ��ɽ��������Ⱥ�������������������ˡ���
ɽ�ź󣬱�����Ȫ��
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"wenquan", 
  "east" : "/d/chenxiang/cxs1",
]));
        set("objects", ([
        __DIR__"npc/3cheng" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-510);
	set("coor/y",-510);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
