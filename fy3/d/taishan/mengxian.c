// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
�س����򶫱�ȥ���㵽�����裬һ·����Ʈ����ɽ�����󣬼е���
ľ���ǰ����ɰأ������Բԣ�Զ��������ɽ�������������������磬��
������ƮƮ���ɣ��ഫ�������ƻ���ɽ����С�����μ���ϼԪ�������ڣ�
ɽ��������ССһ���裬ʮ�־��£�����Ҳ���������ܹ��ɽ�֮����Զ
����ľԽ��Խ�ܣ���������������կ�ˡ�
LONG
  );
  set("exits",([
	"east" : "/d/oldpine/npath1",
	"westdown" : __DIR__"chaoyang",
               ]));


        set("outdoors", "fengyun");
	set("coor/x",-470);
	set("coor/y",-310);
	set("coor/z",100);
	setup();
  	replace_program(ROOM);
}