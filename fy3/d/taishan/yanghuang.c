// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
̩ɽ�౻���ɴ�ظ��ǣ������Բԣ�Ψ��ɽ���ݺᣬɽʯ���һ�֮
ɫ������һ����ζ������ɽʯ���ι�״����֮�Ի�ɫ����Դ���ӳ�գ�
ʵ�ڱ��¡����ܵ�����ۼ�̩ɽ������������֮��ʧ�ִ������ϣ���
ӦΪ���£������ӯ������������̩ɽ������ɫ��
LONG
  );
  set("exits",([
	"northeast" : __DIR__"diaojun",
	"north" : __DIR__"zhongxi",
	"southwest" : __DIR__"hutian",
               ]));
        set("objects", ([
        __DIR__"npc/qing" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",-480);
	set("coor/y",-310);
	set("coor/z",40);
	setup();
  	replace_program(ROOM);
}
