// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����£���������������ɽ��֮�У���Ȼ����˶࣬�������
�ɻ���ʵ�������������š����̵�̶ˮ�������طۺ�ĺɻ�������
������Ȼ�����޽�ڻԻ�֮�ޡ�
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"erzu",
  "southdown" : __DIR__"qingliang",
]));
	set("coor/x",-220);
	set("coor/y",390);
	set("coor/z",60);
	setup();
        replace_program(ROOM);
}
