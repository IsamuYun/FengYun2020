inherit ROOM;
void create()
{
        set("short", "书房");
        set("long", @LONG
一进小屋，只见墙上挂满了无数名贵的字画。书架上也堆满了平时难得
一见的各种各样的书籍。一个中年文士正对着一幅字画出神。
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
