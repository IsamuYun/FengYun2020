// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�ѽӽ�ɽ�ţ�����һ�磬��ǧ���ز������ܵİ�����Χ�ڵ�
�У�����������֮�У����������ޱȣ��ʴ�����������ÿ��������
��ӯ���������˱ǡ��˼����ɲ���Ϊ�����ˣ������˲�Զǧ����Ʒ
�����г��ϵ��Ƶ��ɲ衣ÿ�괺�����������������أ�����Ҫ��
������ɨ��������������ࡣ
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"lianhua",
]));
	set("coor/x",-220);
	set("coor/y",380);
	set("coor/z",50);
	setup();
        replace_program(ROOM);
}
