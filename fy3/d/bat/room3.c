inherit ROOM;
void create()
{
        set("short", "�鷿");
        set("long", @LONG
һ��С�ݣ�ֻ��ǽ�Ϲ���������������ֻ��������Ҳ������ƽʱ�ѵ�
һ���ĸ��ָ������鼮��һ��������ʿ������һ���ֻ�����
LONG
        );
        set("exits", ([ 
		  "north" : __DIR__"zoulang1",		  
		]));         
		set("objects",([
        	__DIR__"npc/wenshi" : 1,			
			__DIR__"obj/book-silk" : 1,			
			__DIR__"obj/book-paper" :1,
       	]) );

//(3290,20,-30)
    set("coor/x",3290);
	set("coor/y",20);
	set("coor/z",-30);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
