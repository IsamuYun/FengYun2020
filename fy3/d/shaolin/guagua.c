// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�Ӵ��");
        set("long", @LONG
����ΪͬԴ����������׼����ס����������������ͥ������������
�ذ�ɽ�����߲����������صرٳ��˵أ����η�����ʹ�ã����ڳ����
����һ��ͨ�̼�����ÿ������һ��С������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"neiyuan",
  "east" : __DIR__"yibo",
]));
        set("objects", ([
                __DIR__"npc/other_monk" : 5,
       ]) );
	set("coor/x",-200);
	set("coor/y",300);
	set("coor/z",60);
	setup();
        replace_program(ROOM);
}
