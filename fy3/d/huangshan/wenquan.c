// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Ȫ");
        set("long", @LONG
��ɽ��Ȫ�ų���Ȫ�������ơ����Ʒ��²�̫������ʩ¯���Գ�������
������ҽҩ�����������¡���Ϊ�����ӿ����ɫȪˮ����Ϊ��
ɰ�������ֳ���ɰȪ������ɽ���ڴ˽�®�ᣬ�����ף�������
ԡ���޲�����ٱ�����Ȫ���ϱ��Ǵȹ�󣬱���ԶԶ�ɼ���
��ͤ��
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"ciguang", 
  "northup" : __DIR__"guanpu",
  "eastdown" : __DIR__"shanmen", 
]));
        set("objects", ([
        __DIR__"obj/tangquan" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-520);
	set("coor/y",-510);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
