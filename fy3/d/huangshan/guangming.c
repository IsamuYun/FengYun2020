// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������ǵڶ��߷壬��Ϊ��γ��ַ�⣬���Ա���Ϊ����������
���������ƽ���������󣬹���������������������������������
��ˮ���ӣ�����һɫ���������ǿ��ճ������ƺ�����ѳ����������
Ե�ɺϣ������Կ����ѵ�һ���ķ�⡣
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"feilai",
  "eastup" : __DIR__"lianhua",
]));
        set("objects", ([
        __DIR__"npc/monk" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-600);
	set("coor/y",-520);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
