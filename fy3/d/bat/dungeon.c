//3270,50,-30
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ����ɭ�ֲ��ĵ�����ƺ��кܶ��ڴ���ȥ��ԩ��Ʈ�����������µ�
�綾��Ѫ���������ȥ������һ��൨���ĵ��������ţ��ϱ�ǽ�Ǵ�һ��������
�Ϸ���һ�ˣ���֪�����ǻ
LONG
        );
        set("exits", ([ 
		  "south" : __DIR__"d5",		  
		]));         
		set("objects",([
        	__DIR__"npc/dizi" : 2,
			__DIR__"npc/xunluo" : 1,
			__DIR__"npc/bianfu1" : 1,
			__DIR__"npc/bianfu2" : 1,
 		    __DIR__"npc/hu" : 1,

       	]) );
    // (3270,50,-30)

    set("coor/x",3270);
	set("coor/y",50);
	set("coor/z",-30);
	set("no_magic",1); set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
