inherit ROOM;
#include <ansi.h>
void create()
{
    set("short",HIY"���ش��"NOR);
  set("long",@LONG
����һ�������������ֱ�����������������͵�������Ͽ�����
Լ�������Ƴǵĳ��ţ����ǼúӶɿڣ�������һƬ���֣�������һ��
ɽ��������ɽ���ؽ硣
LONG
  );
  set("exits",([
         "west" :"/d/laowu/road1",
         //  "north" :"/p/residence/room2",
         "east" :__DIR__"shanjiao",
        
               ]));

        set("outdoors", "qianfo");
  set("coor/x",10);
	set("coor/y",2000);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}

