// searoad.c
inherit ROOM;
void create()
{
        set("short", "���ں��ߵĴ�");
        set("long", @LONG
�󺣣�һ���޼ʵĴ󺣡����߲���һ�Ҵ������ɵ���Φ������׵ķ���
�����Ĵ�����ʵ�������ľ�ʣ�����һ�ְ�����Ѹ�١����һ����ĸо���
������ã���ˮտ������Ÿ���ɵ��Դ�Φ�们�����������ഺ�Ļ��֡�
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"lin2",
		]));         
		set("objects",([
        	__DIR__"npc/lihong" : 1,			
			__DIR__"npc/chu" : 1,			
//			__DIR__"obj/mupai" :1,
       	]) );
    set("outdoors", "bat");
	set("coor/x",1120);
	set("coor/y",-290);
	set("coor/z",-10);
	set("no_dazuo",1);set("no_magic",1);
	setup();
    replace_program(ROOM);

}
