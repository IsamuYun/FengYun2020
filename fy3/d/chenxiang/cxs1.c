// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�������Ͻ�");
        set("long", @LONG
������Ĵ󲿷־����Ը���ˮ��Ϊ���������������ס�ĵط���ÿ��
����ũ�������ų��صĲ�������������ĺ�ˮ�����л������ص�����һ��
��ð��ŨŨ�Ĵ��̣�ɢ�������˵ĵ��������ļҡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxcenter",
"east":__DIR__"farmershop",
//"south":"/d/dali/qxroad1",
  "west" : "/d/huangshan/shanmen",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-500);
	set("coor/y",-510);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
