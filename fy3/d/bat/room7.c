inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����һ�䴢���ң����߰���Ķ����ѳ���ɽ���������ӹ�������������
LONG
        );
        set("exits", ([ 
		  "east" : __DIR__"dating",
		  "west" : __DIR__"room6",
		]));         

//(3260,30,-30)
    set("coor/x",3260);
	set("coor/y",30);
	set("coor/z",-30);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
