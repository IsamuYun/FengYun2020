// searoad.c
inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
·���ϵ�ɳʯԽ��Խϸ��������������һ����ζ��Խ��ǰ�ߣ���ζԽ���ԡ�Զ��
�������������İ���������ż���߹�ȥһ��������ˮ�Ƶ������
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"searoad",
"east" : "/d/bat/lin1",  		  
        "south" : __DIR__"seaside",
		]));         
		set("objects",([
                "/d/wiz/llx/newjob/npc/farmer6" : 1,
        	__DIR__"npc/fishman" : 1,
       	]) );
        set("outdoors", "tieflag");
        set("coor/x",1000);
	set("coor/y",-290);
	set("coor/z",-10);
	set("coor/x",1000);
	set("coor/y",-290);
	set("coor/z",-10);
	set("coor/x",1000);
	set("coor/y",-290);
	set("coor/z",-10);
	setup();
}