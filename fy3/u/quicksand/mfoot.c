
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
ɳĮ���������ƺ��Ѿ������ߵ�ɽ�Ե�ס�ˡ����ۿ����ô������ĮҲ
��������չһ����������ȻҲ�ǹ�ͺͺ�ģ������Ѿ����������˵Ŀ��ȡ���
�걻������Ĺ����Ѿ����������¸�������������ɽ���������˾�ס�ĵط���
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"desert10",
  "west" : __DIR__"mroad",
]));
        set("outdoors", "quicksand");

        set("coor/x",-1110);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-1110);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

