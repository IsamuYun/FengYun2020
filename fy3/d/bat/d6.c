inherit ROOM;
void create()
{
        set("short", "�ڰ�ɽ��");
        set("long", @LONG
����һ����ɭ�ɲ����������޹��ɽ����һ�߽������㵹����һ������������
һ����ѣ����ʲôҲ�벻�����ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"d6",
  "north" : __DIR__"d6",
  "east" : __DIR__"d7",
  "west" : __DIR__"d6",
]));
        set("outdoors", "bat");
        set("coor/x",3260);
	set("coor/y",40);
	set("coor/z",-30);
	set("no_magic",1);
        set("no_clean_up", 0);
	setup();
}

