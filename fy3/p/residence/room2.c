inherit ROOM;
#include <ansi.h>
void create()
{
    set("short",YEL"֮����С·"NOR);
  set("long",@LONG
��ɽ��С·Խ���꣬����ׯ������Ұ��Լ�����������������ˮ���ĺ�����
��ǰ������һƬ�µص�ǰ�ˣ����ֵ�Ѿ�������䣬�Ǿ޴�ĺ����������Ǵ�����
���ﴫ���ġ������ϵ�֮����С·���ٷ�ʯ���Ѷ��£�Լ����ɣ�����ף�һƬ
����׳�۵��ٲ���������������ǰ��
LONG
  );
set("exits",([
         "south" :"/d/qianfo/road1",
         "west" : __DIR__"ttab982930900",
         "east" : __DIR__"baiyun982545370.c",
         "north" :__DIR__"room3",
               ]));
	set("owner","public");
        set("outdoors", "qianfo");
  	set("coor/x",10);
	set("coor/y",2010);
	set("coor/z",0);
	set("coor/x",10);
	set("coor/y",2010);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}