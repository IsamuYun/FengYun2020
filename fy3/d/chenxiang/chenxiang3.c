// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;
void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
�������ƺ������ŵ����꽭�ϵ�ζ������Զ���ĳ�����ͺͽ��ϵ�
�󲿷ֶ���һ����С�����¿ɰ���������ǰ������ǻ�ɫ�ģ��Ʋ�Ҳ
�ǻ�ɫ�ģ�����������С��ȫ����������һƬ���롣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"road",
  "southwest" : __DIR__"cx1",
//"west":"/d/wiz/hdq",
   ]) );
        set("outdoors", "chenxiang");
        set("coor/x",-500);
	set("coor/y",-450);
	set("coor/z",0);
	set("coor/x",-500);
	set("coor/y",-450);
	set("coor/z",0);
	set("coor/x",-500);
	set("coor/y",-450);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
