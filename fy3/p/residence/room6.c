#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",YEL"̩���㳡"NOR);
  set("long",@LONG
�������������ܵ��������е��徻����ɫʯ���̳ɵĴ�����ķ����ӡ��㳡
�����Σ�����������ڴ�Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ����㳡���и���
ˮ�أ�������Ϻ��浹Ҳ���˲��٣������ļ��紺�������£��ɻ�˯���ޱ���次�
LONG
  );
  set("exits",([
          "southwest" :__DIR__"room7",
	  "northwest" :__DIR__"room5",	
               ]));
	set("owner","public");
        set("outdoors", "qianfo");
  	set("coor/x",20);
	set("coor/y",2040);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",2040);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}