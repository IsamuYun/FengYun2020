// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ĦԺ");
        set("long", @LONG
�����Ǵ�Ħ����֮����Ժ�ڳ��輫Ϊ�򵥣�����ǽ�������������
��������������ɮ�뷢�԰ף��������׿�˼������ħ�ʣ�һ����˼����
����������̻ӱ���������֮�ϣ����ӡ֤��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"xiji",
  "west" : __DIR__"jiangwu",
  "north": __DIR__"cj",
  "south": __DIR__"luohan",
]));
        set("objects", ([
                __DIR__"npc/master_18" : 1,
		__DIR__"npc/laomonk" : 2,
       ]) );
	set("coor/x",-210);
	set("coor/y",350);
	set("coor/z",70);
	setup();
}
