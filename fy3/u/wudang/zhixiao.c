
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ĸ����ɸߵĺ����������ذ������ɰ���ʯ�̳ɡ�����ǽ
�Ϲ��������ֻ��������ǽ�ϸ߸ߵع���һ����ң����顰��������
���֡�������һ�Ź�̨��һ��̫���Ͼ����������С���ǰ������ʽˮ
����������̨��
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"wudang1",
	]));
	set("objects", ([ 
		__DIR__"npc/master" : 1,
		__DIR__"npc/taoist" : 1,
	]));
        set("valid_startroom", 1);
	set("coor/x",110);
	set("coor/y",-120);
	set("coor/z",50);
	set("coor/x",110);
	set("coor/y",-120);
	set("coor/z",50);
	set("coor/x",110);
	set("coor/y",-120);
	set("coor/z",50);
	set("coor/x",110);
	set("coor/y",-120);
	set("coor/z",50);
	set("coor/x",110);
	set("coor/y",-120);
	set("coor/z",50);
	setup();
replace_program(ROOM);

}
