
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������СС�Ĵ����ݡ����м������еļҾ߶�������
���ɵġ����е����Ϸ���һ���������ɰ��ߡ���ѩɽׯ����
Ů��������Ʒ�����塣
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"front_yard",
  "north" : __DIR__"back_yard",
]));
       set("objects", ([
                __DIR__"npc/master" : 1,
                __DIR__"npc/master2" : 1,
                __DIR__"npc/girl" : 1,
        ]) );
        set("valid_startroom", 1);
        set("coor/x",-1230);
	set("coor/y",60);
        set("no_curse",1);
	set("coor/z",-10);
	setup();
}

