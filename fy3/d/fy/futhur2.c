inherit ROOM;
void create()
{
        set("short", "���ݶ�¥");
        set("long", @LONG
¥�����˸о���ɭ�ֲ����޴��޵ƣ��������ɼ������ë���Ȼ��
����·�ͨ������һ�����磬��ڤ��硣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	"down" : __DIR__"futhur",
]));
        set("objects", ([
        __DIR__"npc/laowushi" : 1,
                        ]) );

        set("coor/x",-30);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
