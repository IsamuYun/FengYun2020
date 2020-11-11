
inherit ROOM;

void create()
{
	object silver;
	set("short", "地下密室");
	set("long", @LONG
这里是一间窄小的密室，你的面前只有一个破旧的小床跟一
些乾草。
LONG
	);

	set("objects", ([
		"/obj/money/silver": 1
	]) );

	set("coor/x",20);
	set("coor/y",50);
        set("coor/z",-20);
	setup();
	silver = present("silver",this_object());
	silver->set_amount(random(1000)+1000);	
	silver->set("name", "镖银");
}
