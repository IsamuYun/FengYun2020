// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��ʯ��");
  set("long",@LONG
�������۷�ң���Ӧ����һ����ģ�����Ħ��ʯ�̣����Զ�ݵ���
�룬�����Ȼ�У�����������ʷ�ˣ�������Ȼʯƺ֮�ϣ���������Ŀ���
����հ��������۾����������ִ��綷�������汸���鷨�پ���������Ϊ
�����ֱ��桱��������֮�ڡ���ǧ����꣬���ھ���ֻ��һǧ�����ˣ���
ȴ��Ȼ�޿ɱ��⡣
LONG
  );
  set("exits",([
	"westdown" : __DIR__"doumu",
	"southup" : __DIR__"luohan",
               ]));
        set("objects", ([
        __DIR__"obj/jingwen" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",-480);
	set("coor/y",-320);
	set("coor/z",40);
	setup();
  	replace_program(ROOM);
}
