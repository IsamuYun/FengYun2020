
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
  "east" : __DIR__"huangyie0",
  "west" : __DIR__"huangyie1",
]));
        set("outdoors", "quicksand");
        set("coor/x",-1005);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-1005);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
