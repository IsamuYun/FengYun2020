// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","�¹۷�");
  set("long",@LONG
����һС��¥����¥��С�����������ɽ֮�ϣ�Ҳ�ǲ��ף��չ�
��ĺ��գ��¹۷�Ľ��¶��Ǽ��ÿ��ľ��£�ÿ�����֮Ҳ���¸���
���ϣ�����ʤ�գ���ǡ�������ˬ֮ʱ���������£��˷���裬��֮
���£�ʵ���޿ɱ��⡣
LONG
  );
  set("exits",([
	"east" : __DIR__"nantian",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",-490);
	set("coor/y",-310);
	set("coor/z",120);
	setup();
  	replace_program(ROOM);
}
