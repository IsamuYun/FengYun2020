inherit ROOM;
void create()
{
        set("short", "�˼��");
        set("long", @LONG
ɽ��Խ��Խ����,��ӥ����ͷ���ɹ������������ĺ�Х����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"jueding",
  "southdown" : __DIR__"renjiandao2",
]));
        set("outdoors", "bat");
        set("coor/x",3290);
	set("coor/y",30);
	set("coor/z",40);
	set("no_magic",1);
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/wu-shi1" :1,
                        ]) );
	this_object()->set("blocks", ([
		"northup" : "wu shi",
	]));
	setup();
        
}
