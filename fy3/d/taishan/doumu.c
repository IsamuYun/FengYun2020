// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��ĸ��");
  set("long",@LONG
����ƾ����Ϫ������Ϫ֮ˮ����ɽ�������£���������������ɽ��
�����͵�С̶��ˮ���䲻�ͼ���������ɫ��ѣ����С���̶���١�֮��
���Ź����Ķ�ĸ����������Ȼ�Ĺ�ͬ������Ϊһ�塣��ĸ���߻������ţ�
���������Ϫ���Ŷ���ˮ���˳ơ������š����롰עˮ���š�������
����ī�������ڴˣ�����ǧ�ž�����
LONG
  );
  set("exits",([
         "up":__DIR__"hutian",
         "down" :__DIR__"wanxian",
	"west" : __DIR__"linghan",
	"eastup" : __DIR__"jingshi",
               ]));
        set("objects", ([
        __DIR__"npc/yaren" : 2,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",-490);
	set("coor/y",-320);
	set("coor/z",30);
	setup();
  	replace_program(ROOM);
}
