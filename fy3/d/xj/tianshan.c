#include <globals.h>
inherit ROOM;
void create()
{
	object con,item;
        set("short", "��ɽɽ��");
        set("long", @LONG
������ɽ������߷岩���壬Ϊ��ɽ�ڶ��߷壬ɽ�������ѩ��
�嶥�����ݺᣬ����������ڲ������ɽ����һ������������С����
��ˮ��Σ����˾ͽ��˸е�ϲ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"gela",
  "northwest" : __DIR__"tianchi",
]));
        set("objects", ([
	__DIR__"obj/snow" : 1,
	__DIR__"obj/lotus" : 1,
       	]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1140);
	set("coor/y",990);
	set("coor/z",0);
	setup();
        con = present("��ѩ",this_object());
        item= present("��ɽѩ��", this_object());
        item->move(con);
}
