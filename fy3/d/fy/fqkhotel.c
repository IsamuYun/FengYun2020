inherit ROOM;

void create()
{
        set("short", "凤求凰客栈");
        set("long", @LONG
前厅挂着一幅龙凤双飞的巨画。当门挂着对鸳鸯球。球上系着几个小小的黄铜风铃。
微风掠过，风铃发出清脆悦耳的叮咚声。大门两侧挂着斗大的大红灯笼，上各书凤凰两
字。朱门上横批一个“求”字。最近和各大驿站联手推出驿站服务，详情请看牌。（ｓｉｇｎ）
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"swind1",
]));
        set("objects", ([
        __DIR__"npc/waiter" : 1,
		 __DIR__"npc/gmss" : 1,
                        ]) );
		set("item_desc", ([
                "sign": @TEXT

方便各路人士，小店推出驿站服务，当然需要收取一点手续费咯。
去关外(goguanwai)   二十两白银      
去沉香(gochenxiang)   十两白银

TEXT
        ]) );

        set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
     
}
void init()
{	
	add_action("go_guanwai","goguanwai");
	add_action("go_chenxiang","gochenxiang");
}
int go_guanwai()
{
	object me,gold;
	int lv;
	me = this_player();
	gold = present("silver_money", me);
	lv = me->query("level");
	if (lv>9 )
	{
		if (!gold)
			return notify_fail("去关外需要支付二十两白银!\n");
		if (gold->query_amount() < 20)
			return notify_fail("去关外需要支付二十两白银!\n");
		message_vision("$N交给了店小二二十两白银，坐进了马车中。\n只听店小二对着车夫说道:关外。车夫得令后回头冲着$N大喊：客官坐稳了！\n马车开始朝关外出发了。\n......\n......\n......\n......\n数日后，马车终于到了关外了。车夫喊道：客官，可以下车了！\n",me);
		gold->add_amount(-20);
	}
	else 
	{
		message_vision("$N坐进了马车中。\n只听店小二对着车夫说道:关外。车夫得令后回头冲着$N大喊：客官坐稳了！\n马车开始朝关外出发了。\n......\n......\n......\n......\n数日后，马车终于到了关外了。车夫喊道：客官，可以下车了！\n",me);
	}
	me ->move("/u/guanwai/inn");
	return 1;
}
int go_chenxiang()
{
	object me,gold;
	int lv;
	me = this_player();
	gold = present("silver_money", me);
	lv = me->query("level");
	if (lv>9 )
	{
		if (!gold)
			return notify_fail("去沉香需要支付十两白银!\n");
		if (gold->query_amount() < 10)
			return notify_fail("去沉香需要支付十两白银!\n");
		message_vision("$N交给了店小二十两白银，坐进了马车中。\n只听店小二对着车夫说道:沉香。车夫得令后回头冲着$N大喊：客官坐稳了！\n马车开始朝沉香出发了。\n......\n......\n......\n......\n数日后，马车终于到了沉香了。车夫喊道：客官，可以下车了！\n",me);
		gold->add_amount(-10);
	}
	else 
	{
		message_vision("$N坐进了马车中。\n只听店小二对着车夫说道:沉香。车夫得令后回头冲着$N大喊：客官坐稳了！\n马车开始朝沉香出发了。\n......\n......\n......\n......\n数日后，马车终于到了沉香了。车夫喊道：客官，可以下车了！\n",me);
	}
	me ->move("/d/chenxiang/inn");
	return 1;
}