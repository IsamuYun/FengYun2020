// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
������������������һ������������ʷ��֤���������Ĺ��ţ�Ʈ��
���ף�ÿ��ĺ�ĳ��ӣ��䲻�󣬵���ׯ�ϲ����������ɰ�ӳ�գ�������
������֮�⣬����һ�ꡰһƷ����ɡ����������¸��Ӿ�Զ����������
�����ŷ��ߣ���̩ɽ������ص������½�������������������֮ʢ��
Ҳ��һʱ������

LONG
  );
  set("exits",([
	"eastdown" : __DIR__"hongmen",
               ]));
        set("objects", ([
        __DIR__"obj/tree" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",-500);
	set("coor/y",-320);
	set("coor/z",20);
	setup();
  	replace_program(ROOM);
}
