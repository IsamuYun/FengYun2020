// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����¥");
        set("long", @LONG
��Ⱥ�ߴ�Ľ�������Ϊ���������壬�����ֳ�����¥���ڴ˿���
��������������������ɫ�������춼����ɽ��ֱ��ɽ�ţ�������ֱ��
����������ǡ�ơ�ͻأ����񷡱��ʢ��ܽ�ء�������ش�����������
�ģ�����ɽ�澰��ɣ����ĺ�����������ɽ�ӣ������桱�������ֲ�
��ֳơ���ɽ��ʤ������
LONG
        );
        set("exits", ([ 
  "northeast"  : __DIR__"yingke",
  "west" : __DIR__"lianhua",
  "southeast" : __DIR__"lianrui",
]));
        set("objects", ([
        __DIR__"npc/wang" : 1,
                        ]) );

        set("outdoors", "huangshan");
	set("coor/x",-580);
	set("coor/y",-520);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
