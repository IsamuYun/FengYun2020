
inherit ROOM;

void create()
{
        set("short", "��Ұ");
        set("long",
"����һ���ޱߵ�ɳ���أ�ɽ�Ƶ�������ͻȻ������Ӱ���١���\n"
"����������綼��ů�ġ����ϵ�ʯ������һ�ְ������ɫ����\n"
"���Ǳ���ѪȾ���һ����һ���������۵Ĺٵ��������Ͷ�����չ��\n"
);
        set("exits", ([ 
  "east" : "/d/songshan/dengfeng",
  "west" : __DIR__"huangyie4",
  "northwest" : __DIR__"huangyie2",
  "southwest" : __DIR__"huangyie3",
]));
        set("outdoors", "quicksand");

        set("coor/x",-1000);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-1000);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}
