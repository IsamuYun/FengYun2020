// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
����̩ɽ�����壬Ҳ����߷壬���Ͻ�����ʹ�һ�����չ�ͤ����
��ͤ���ŵǷ�̨���ܻ��ƣ��������������������������ڴˡ�����
������������ϼϦ�ա������ƺӽ���������ƺ����̡��Ĵ��澰������
�ס�
LONG
  );
  set("exits",([
	"southdown" : __DIR__"bixia",
               ]));
        set("outdoors", "fengyun");
        set("objects", ([
                "/d/fy/npc/half_god" : 1,
       ]) );
	set("coor/x",-470);
	set("coor/y",-300);
	set("coor/z",130);
	setup();
  	replace_program(ROOM);
}
