inherit ROOM;
void create()
{
        set("short", "�˼��");
        set("long", @LONG
����һ����խ��ɽ�������ű���һ��ɽ����ȥ���˷���һ��������ֱ�̲�񷡣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"renjiandao3",
  "southdown" : __DIR__"renjiandao1",
]));
        set("outdoors", "bat");
        set("coor/x",3290);
	set("coor/y",20);
	set("coor/z",30);
	set("no_magic",1);
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/wu-shi2" :1,
                        ]) );
	this_object()->set("blocks", ([
		"northup" : "wu shi",
	]));
	setup();
        
}
