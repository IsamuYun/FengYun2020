inherit ROOM;
void create()
{
        set("short", "���Կռ�");
        set("long", @LONG
��������ʦ����������Ʒ�ķ��䣬��Χ�����Ž����Ĺ�������û�еƣ�����ȴ������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "east" :"/d/fy/yitea",
        "north" : "/d/dali/chazhuang",
        "up" : __DIR__"workroom",
]));
        set("coor/x",10);
set("coor/y",-30);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
