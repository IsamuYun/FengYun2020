inherit ROOM;
#include <ansi.h>
void create()
{
  set("short", HIG "��Ϫ̶" NOR );
  set("long",@LONG
��Ϫ̶����������ˮ�������������Ͽ���С�ɽȪ�Ҹ�ӿ��������к����
Ϫ��أ�׳�����裬��������ˮ��ʯ������̽��ӣ����׳����Ϫ��Ϫǰ���²�
԰�������̣������˱ǡ���ͨ�裬����گʱ��������ֲ�����׿���ɽ������ͦ
�㣬����ʮ�����
LONG
  );
  set("exits",([
          "south" :__DIR__"room2",
          "northwest" :__DIR__"hfh981609039",
          "west" : "p/residence/lazylazy985687794",
          "north" :__DIR__"room7",
               ]));
	set("owner","public");
        set("outdoors", "qianfo");
  	set("coor/x",10);
	set("coor/y",2020);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",2020);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
