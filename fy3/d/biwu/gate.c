// 山猫(adx) by snow 2000-05-15

inherit ROOM;

void create ()
{
	set ("short", "比武场大门");
	set ("long", @LONG
这是小雪初晴比武场的大门，一座高高的木制牌坊，上书『比武场』
三个镏金大字。这里经常举办各种类型的比武大会。所有的人都有机会参
加。
LONG);
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"north"   : __DIR__"zoulang",
		"south"   : "/d/bianliang/guangming",
	]));
	set("objects", ([
		__DIR__"npc/gongping" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob, where;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if ( !wizardp(me) && dir=="north" ) {
		if(me->query("snowzongshi"))
			return ::valid_leave(me, dir);
		if( ob->query("fangshi")!="个人赛" && !ob->query("start/start"))
			return notify_fail("现在没有任何比武，你不能进去。\n");
	}
	return ::valid_leave(me, dir);
}
