inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ����խ����,�����������ݡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"secret",
  "up" : __DIR__"tianti2",
]));
        set("outdoors", "bat");
        set("coor/x",3310);
	set("coor/y",20);
	set("coor/z",-10);
	set("no_magic",1);
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/bianfu2" :1,
                        ]) );
	setup();
}

