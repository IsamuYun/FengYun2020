// Room: /d/oldpine/riverbank2.c

inherit ROOM;

void create()
{
        set("short", "ɽ��֮��");
        set("long", @LONG
��������վ��һ��ɽ���е���ʯ�ϣ�һ��Сʯ�����߸ߵش����ͷ
������ɽ�����ߵ�ʯ�ڣ�һ���ٲ�������ı�����Զ������һ������
�������ϴ���������
LONG
        );
        set("item_desc", ([
                "cliff":
                        "�����ɽ�ڱȱ��߸߶��Ե��˵㣬���ǶԷ��˶�����Ҫ����ȥ��Ȼ\n"
                        "����һ�β�ࡣ\n"
        ]) );
        set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/oldpine/waterfall",
  "south" : "/d/oldpine/riverbank1",
]));
        set("outdoors", "oldpine");
        set("resource/water", 1);

        set("coor/x",-260);
	set("coor/y",-350);
	set("coor/z",70);
	setup();
        replace_program(ROOM);
}
