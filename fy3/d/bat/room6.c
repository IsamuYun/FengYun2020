inherit ROOM;
void create()
{
        set("short", "���䳡");
        set("long", @LONG
����һ��������䳡��ʮ�˰����������ȫ�����м��������õ�ľ׮��
LONG
        );
        set("exits", ([ 
		  "east" : __DIR__"room7",		  
		]));         

//(3250,30,-30)
    set("coor/x",3250);
	set("coor/y",30);
	set("coor/z",-30);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
