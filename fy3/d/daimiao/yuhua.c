//mac's yuhua.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","�껨��Ժ");
  set("long",@LONG
����Ϊ��ʿ��Ϣ����ʳ�������Ĵ����������徻���м���ʯ����
���ӣ��ڷ���һЩ�򵥵�ʳƷ�����ϡ�
LONG
  );
  set("exits",([
         "east":__DIR__"peitian.c",
               ]));
        set("objects", ([
                __DIR__"npc/daoshi" : 1,
       ]) );
  set("coor/x",-500);
	set("coor/y",-400);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
