
inherit ROOM;

void create()
{
	set("short", "��ɽ·");
	set("long", @LONG
��������������·��ȴ��ƽ̹���������߶���ïʢ�����֣����
����ʱ�������������������ķҷ�����һ����ʹ�����ؿ��ʣ�����
һ�з��ա�����������ֵķ�϶��ɼ����䵱�۵ĺ�ɫΧǽ��
LONG
	);
	set("exits", ([ 
		"northdown" : __DIR__"rock",
		"southup" : __DIR__"wudang",
	]));
        set("objects", ([
        "/d/wiz/llx/newjob/npc/farmer3" : 1,
                        ]) );
	set("outdoors", "wudang");
	set("coor/x",100);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",100);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",100);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",100);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",100);
	set("coor/y",-100);
	set("coor/z",30);
	setup();
	replace_program(ROOM);
}
