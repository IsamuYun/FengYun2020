inherit ROOM;
void create()
{
        set("short", "�����ʾ�");
        set("long", @LONG
�����Ƿ�����վ���ã����е��ż㶼�������һ���ʲ���æ�ţ�
�ַ����ţ����˿·���Ƶ������������࣬�����������Բ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"mailst",
]));
        set("objects", ([
        __DIR__"npc/youchai" : 1,
                        ]) );

        set("coor/x",-20);
        set("coor/y",20);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}

