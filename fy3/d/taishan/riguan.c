// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","�չ۷�");
  set("long",@LONG
�˴��ǹ����ճ�������ѵط����������£�������ȣ�����ϰϰ��
����Ʈ��������Ⱥɽ�������۲����Ļ��ÿ���峿��һ�ֺ����Զ���
��ɣ���Ϻ�ճ������˸��Ƶͣ����ڽ��£�����һ���ֿ�������֮�ƣ�
����Ӣ�۵��ˣ��޲�Ϊ֮����ӿ����
LONG
  );
  set("exits",([
	"south" : __DIR__"zhanlu",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",-460);
	set("coor/y",-300);
	set("coor/z",120);
	setup();
  	replace_program(ROOM);
}
