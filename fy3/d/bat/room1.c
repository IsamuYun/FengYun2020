inherit ROOM;
void create()
{
        set("short", "销魂窝");
        set("long", @LONG
屋子里的香气更浓，浓得几乎可以令人溶化。 陌生的地方，陌生的女人，黑暗…… 
世上又有哪个男人能抵抗这种可怕的诱惑......
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"zoulang1",
		]));         
		set("objects",([
        	__DIR__"npc/woman" : 1,
       	]) );

//(3300,30,-30
    set("coor/x",3300);
	set("coor/y",30);
	set("coor/z",-30);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
