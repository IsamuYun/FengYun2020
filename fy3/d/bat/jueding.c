inherit ROOM;
void create()
{
        set("short", "�·����");
        set("long", @LONG
���羢�������¾����۵ף�������˼�ľ�����
ֻ�о�����ƥ�ĸ��ֲ��ܵ���������Ǹߴ���ʤ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"renjiandao3",
]));
        set("outdoors", "bat");
        set("coor/x",3290);
	set("coor/y",40);
	set("coor/z",50);
	set("no_magic",1);
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/baiyiren" :1,
                        ]) );
	setup();
        
}
