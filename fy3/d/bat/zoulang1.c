inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ���������ֲ�����ָ�����ȣ�͸��ɭɭ�ĺ����ɱ����
���м��ߵƹ�����Ե������������������͸�����˵ĺ���
�����۷�֬��ζ����
LONG
        );
        set("exits", ([ 
		  "east" : __DIR__"room1",
		  "west" : __DIR__"zoulang2",
		  "north" : __DIR__"room2",
		  "south" :__DIR__"room3",
		]));         
		set("objects",([
        	__DIR__"npc/xunluo" : 1,
			__DIR__"npc/dizi" : 1,
       	]) );
//3290,30,-30
    set("coor/x",3290);
	set("coor/y",30);
	set("coor/z",-30);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
