
inherit ROOM;

void create()
{
	set("short", "�ؽ�");
	set("long", @LONG
�ؽ��ﺮ�����ʪ��������ǽ���Ϲ���һյ�͵ơ��谵�ĵƹ��£�
������Ե���ɭ�ɲ����ؽ�����һ�����ӣ������϶˶�����������һ
���ˡ�
LONG
	);
	set("exits", ([
                "down" : __DIR__"dijiao2",
	]));
	set("objects", ([
                __DIR__"npc/biaoge" : 1,
	]));
	set("coor/x",-1120);
	set("coor/y",-120);
	set("coor/z",-20);
	setup();
	replace_program(ROOM);
}
