inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
ֻ��һ���ֿ���������������Ǿ��ǣ��󣢣���������������ǧ�ˣ�
���Ҳ����Ե�ӵ�������ֱ���һ������¥��ͨ���¥��������Χ����
���˶�ߵĴ��š�
LONG
        );
        set("exits", ([ 
		  "east" : __DIR__"zoulang2",
		  "west" : __DIR__"room7",
		  "up" : __DIR__"qinshi",
		  "north" : __DIR__"d1",
		]));         
		set("objects",([
			__DIR__"npc/zhao" : 1,
       	]) );

//(3270,30,-30)
    set("coor/x",3270);
	set("coor/y",30);
	set("coor/z",-30);
	set("no_magic",1); set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
