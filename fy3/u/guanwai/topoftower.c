
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����쳣խС��ʹ���޷��ƶ����������￴��ȥ����Щ������ɽͷ�ϵ�¥
����������Ժ���Ǹ�������ʯ�ϵľ��˳Ǳ�����������Ȼ����ô��������ô
���͡�
LONG
        );
        set("exits", ([ 
  "down"   : __DIR__"citygate",
]));
        set("objects", ([
                __DIR__"npc/towerguard1" : 1,
		__DIR__"npc/towerguard2" : 1,
        ]) );
        set("coor/x",-1190);
	set("coor/y",-10);
	set("coor/z",10);
	set("coor/x",-1190);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
}

