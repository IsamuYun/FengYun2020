// searoad.c
inherit ROOM;
void create()
{
        set("short", "��ʯ");
        set("long", @LONG
����ɽ�ң����漱�����ȣ�������ӿ��������ǧ�ٿ���ް�Ľ�ʯ��
����ɽ�����ǹ�ʯ�϶룬����ն񡣽�ʯ�������ӿ���ȣ�ѩ�׵��˻���
�ɼ��Ľ���
LONG
        );
        set("exits", ([ 
	  	"north" : __DIR__"island",
  		"east" : __DIR__"rock1",
	]));
        set("outdoors", "tieflag");
        set("coor/x",2000);
	set("coor/y",-210);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
