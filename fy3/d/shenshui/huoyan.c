// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���Ҷ���");
        set("long", @LONG
ԭ��������ˮ���ǽ�����ɽ��֮�У��������̵ľ޴�����֪�����ߵ�����
��ǰ����һ����ͬ�ľ�ɫ����Զ��һ����������ɢ����������������һ��������
���Ĵ��ϱߵ�ʯ����ԶԶ��Ҳ�м��䷿�ݣ�ֻ���쳣�Ļ谵������̫�����
LONG
        );
        set("outdoors","shenshui");
        set("exits", ([ 
   "down" : __DIR__"migong2",
  "northup" : __DIR__"gong",
  "southup" : __DIR__"ruanhong",
]));

   set("objects", ([ 
      __DIR__"npc/jian": 1,
   ]) );
	set("outdoors","shenshui");
	set("coor/x",200);
	set("coor/y",12330);
	set("coor/z",-20);
	setup();
        replace_program(ROOM);
}
