inherit ROOM;
void create()
{
        set("short", "���� ");
                set("long", @LONG
����һ����խ�����������������ݡ�
LONG
        );
       set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
		  "down" : __DIR__"secret",
		  "up" : __DIR__"tt2",
		]));         
		set("objects",([
			__DIR__"npc/bianfu2" : 1,
       	]) );
    set("coor/x",3300);
	set("coor/y",20);
	set("coor/z",-10);
	set("no_magic",1);set("no_dazuo",1);

	setup();
   
}
