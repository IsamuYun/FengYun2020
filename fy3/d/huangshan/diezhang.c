// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���ַ�");
        set("long", @LONG
ɽ��ʵ���Ƕ࣬�ഫ��ɽ��ǧ���ٷ壬�ӵ��ַ�������ֻ�����й�
֮������һ��ɽ������Լ��㣬Ⱥ����֣�����һ������������Ⱥ�壬
Ҳ��˵�徿�����ж��٣���ȥ�Ǽ������ߣ�������������ʯ�ף�������
���˱�������ɵ����ɽ���ɹ��֡�
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"qingliang",
  "west" : __DIR__"songgu",
]));
        set("objects", ([
        __DIR__"npc/dizi" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-640);
	set("coor/y",-540);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
