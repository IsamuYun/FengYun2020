//3290,0,10
inherit ROOM;
void create()
{
        set("short", "�յ� ");
        set("long", @LONG
    ����һƬ�յ�,���ܶ�����ʯ,�Ӳݴ�����������һ��ɽ����
    ̫�����߹�������������С�
LONG
        );
        set("exits", ([ 
		  "northup" : __DIR__"ren",
		  "east" : __DIR__"anbian",
		]));         
		set("objects",([
        	__DIR__"npc/dizi" : 1,
       	]) );
    set("outdoors", "bat");
    set("coor/x",3290);
	set("coor/y",0);
	set("coor/z",10);
	set("no_magic",1);set("no_dazuo",1);

	setup();
    replace_program(ROOM);

}
