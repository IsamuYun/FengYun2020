// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����Ժ");
        set("long", @LONG
���������������������⣬������λ���³��ϣ��书������ߣ��ҷ�
������ĳ���ִ��ɮ�࣬ά�����ְ�ȫ�����������ֲ��ڷ���֮�£���
����������λ����������ǧ�������ɫ����λ������ʮ�������������ӳ�
����ɮ�ࡣ
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"jian",
  "southeast" : __DIR__"laos",
  "northeast": __DIR__"laon",
]));
        set("objects", ([
                __DIR__"npc/master_17_6" : 1,
       ]) );
	set("coor/x",-200);
	set("coor/y",380);
	set("coor/z",70);
	setup();
        replace_program(ROOM);
}
void init()
{
        if(this_player()->query_skill("daode",1) >= 10)
	set("exits/west",__DIR__"banruo");
	else
	delete("exits/west");

}

