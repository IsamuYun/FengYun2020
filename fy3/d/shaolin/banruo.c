// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
Ϊ����Ӵ���Ħ������������������Ϊ��ɮ���������þ����ˣ�
���ĦԺ���޺��ò��У��������ֺ󱲵����书������ʤ����ĦԺ��
�ϣ�������������ס�����в��������������������ţ���Сɳ��ר��
����
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"xueshen",
  "southwest" : __DIR__"yangxing",
  "northwest" : __DIR__"bamboo1",
  "northeast" : __DIR__"bamboo1",
  "north": __DIR__"muren",
  "east": __DIR__"lao",
  "west" : __DIR__"shan",
]));
        set("objects", ([
                __DIR__"npc/monk11" : 2,
       ]) );
	set("coor/x",-210);
	set("coor/y",380);
	set("coor/z",70);
	setup();
        replace_program(ROOM);
}
