// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
������λ̩ɽ���У��ش�����룬��Ϫ�������Ѷ��£��Ը�������
Ȫ���ö���Ȫ��ӭ�ӷ�����ɽ�����ˡ�һ���޴����¥�������ŵ�ʤ��
��������᾵�ɽʯ��ʯ����¥����ô�ľ��ɣ����ֻ�Ȼ��ɣ���������
���ܹ��ɽ�����棬�������Ѿ���Ϊ��һ����Զ����������ʷʫ������
�ϱ��ǳ�����ʤ��---�Ʋ��š�
LONG
  );
  set("exits",([
	"down" : __DIR__"butian",
	"up" : __DIR__"buyun",
               ]));
        set("objects", ([
        "/d/fy/npc/beggar" : 3,
                        ]) );

        set("outdoors", "fengyun");
	set("coor/x",-490);
	set("coor/y",-320);
	set("coor/z",60);
	setup();
  	replace_program(ROOM);
}
