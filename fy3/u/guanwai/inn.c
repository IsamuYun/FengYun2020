// inn.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "迎梅客栈");
	set("long", @LONG
这是布达拉宫中最大的一家客栈。据说这家店主是一个痴情的年青人。他
在这里开客栈就是希望他当年在中原失散的情人能够知道他在这里，而来与他
相会。可是店开多年，中原客人来人往，还是没有他昔年情人的一点消息。
一块大匾(sign)悬于堂内。
LONG
	);

	// This enables players to save this room as their startroom.
	set("valid_startroom", 1);

		set("item_desc", ([
                "sign": @TEXT

方便各路人士，小店推出驿站服务，对于十级以上的人，当然需要收取一点手续费咯。
去风云城(gofengyun)   二十两白银      
去沉香(gochenxiang)   十两白银

TEXT
        ]) );
	
	set("exits", ([
		"west"   : __DIR__"octo1",]) );


	set("objects", ([
		__DIR__"npc/waiter" : 1, 
		"/obj/shusheng" :3,
		"/obj/npc/trashcan":1,
		]) );

	set("coor/x",-1190);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-1190);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        // To "load" the board, don't ever "clone" a bulletin board.

}

void init()
{	
	add_action("go_chenxiang","gochenxiang");
	add_action("go_fy","gofengyun");
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
		gold->add_amount(-1);
	}
	else 
	{
		message_vision("$N坐进了马车中。\n只听店小二对着车夫说道:沉香。车夫得令后回头冲着$N大喊：客官坐稳了！\n马车开始朝沉香出发了。\n......\n......\n......\n......\n数日后，马车终于到了沉香了。车夫喊道：客官，可以下车了！\n",me);
	}
	me ->move("/d/chenxiang/inn");
	return 1;
}
int go_fy()
{
	object me,gold;
	int lv;
	me = this_player();
	gold = present("silver_money", me);
	lv = me->query("level");
	if (lv>9 )
	{
		if (!gold)
			return notify_fail("去沉香需要支付二十两白银!\n");
		if (gold->query_amount() < 20)
			return notify_fail("去沉香需要支付二十两白银!\n");
		message_vision("$N交给了店小二二十两白银，坐进了马车中。\n只听店小二对着车夫说道:风云城。车夫得令后回头冲着$N大喊：客官坐稳了！\n马车开始朝风云城出发了。\n......\n......\n......\n......\n数日后，马车终于到了风云城了。车夫喊道：客官，可以下车了！\n",me);
		gold->add_amount(-2);
	}
	else 
	{
		message_vision("$N坐进了马车中。\n只听店小二对着车夫说道:风云城。车夫得令后回头冲着$N大喊：客官坐稳了！\n马车开始朝风云城出发了。\n......\n......\n......\n......\n数日后，马车终于到了风云城了。车夫喊道：客官，可以下车了！\n",me);
	}
	me ->move("/d/fy/fqkhotel");
	return 1;
}