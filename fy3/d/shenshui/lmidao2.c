// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ���ص�");
        set("long", @LONG
�ص�������ͻȻ������γ���һ���޴��ʯ�ң����ڳ����˸���ǧ��
�ٹֵ�����ʯ���ڹ��ߵ���ҫ����˸�����˵�ɫ�ʣ����û�й�������Ѵ���
���Ƴ�ȥ��ʯ��һ����һ���޴�İ�ʯ����һ����Ȼ��������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"lmidao1",
  "north" : __DIR__"lmidao3",
  "northeast" : __DIR__"lmidao4",
]));

   set("objects", ([
      __DIR__"obj/stone": 1,
   ]) );
        set("coor/x",100);
        set("coor/y",12070);
        set("coor/z",0);
        setup();
	setup();
        replace_program(ROOM);
}
