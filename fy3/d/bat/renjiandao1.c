inherit ROOM;
void create()
{
        set("short", "�˼��");
        set("long", @LONG
����һ����խ��ɽ��,���ű���һ��ɽ����ȥ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"renjiandao2",
  "southdown" : __DIR__"kongdi",
]));
        set("outdoors", "bat");
        set("coor/x",3290);
	set("coor/y",10);
	set("coor/z",20);
	set("no_magic",1);
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/wu-shi3" :1,
                        ]) );
	this_object()->set("blocks", ([
		"northup" : "wu shi",
	]));
	setup();
        
}
