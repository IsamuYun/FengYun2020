// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","հ³̨");
  set("long",@LONG
�˴�����̩ɽ��ּ���������Զ������³��ؾ����۵ͣ�������Ϊհ
³̨��̨��һ����ͤ����������ЪϢ��
LONG
  );
  set("exits",([
	"west" : __DIR__"bixia",
	"north" : __DIR__"riguan",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",-460);
	set("coor/y",-310);
	set("coor/z",120);
	setup();
  	replace_program(ROOM);
}
