// inn.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "ӭ÷��ջ");
	set("long", @LONG
���ǲ�������������һ�ҿ�ջ����˵��ҵ�����һ������������ˡ���
�����￪��ջ����ϣ������������ԭʧɢ�������ܹ�֪�����������������
��ᡣ���ǵ꿪���꣬��ԭ����������������û�����������˵�һ����Ϣ��
һ�����(sign)�������ڡ�
LONG
	);

	// This enables players to save this room as their startroom.
	set("valid_startroom", 1);

		set("item_desc", ([
                "sign": @TEXT

�����·��ʿ��С���Ƴ���վ���񣬶���ʮ�����ϵ��ˣ���Ȼ��Ҫ��ȡһ�������ѿ���
ȥ���Ƴ�(gofengyun)   ��ʮ������      
ȥ����(gochenxiang)   ʮ������

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
			return notify_fail("ȥ������Ҫ֧��ʮ������!\n");
		if (gold->query_amount() < 10)
			return notify_fail("ȥ������Ҫ֧��ʮ������!\n");
		message_vision("$N�����˵�С��ʮ�����������������С�\nֻ����С�����ų���˵��:���㡣���������ͷ����$N�󺰣��͹������ˣ�\n����ʼ����������ˡ�\n......\n......\n......\n......\n���պ������ڵ��˳����ˡ����򺰵����͹٣������³��ˣ�\n",me);
		gold->add_amount(-1);
	}
	else 
	{
		message_vision("$N���������С�\nֻ����С�����ų���˵��:���㡣���������ͷ����$N�󺰣��͹������ˣ�\n����ʼ����������ˡ�\n......\n......\n......\n......\n���պ������ڵ��˳����ˡ����򺰵����͹٣������³��ˣ�\n",me);
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
			return notify_fail("ȥ������Ҫ֧����ʮ������!\n");
		if (gold->query_amount() < 20)
			return notify_fail("ȥ������Ҫ֧����ʮ������!\n");
		message_vision("$N�����˵�С����ʮ�����������������С�\nֻ����С�����ų���˵��:���Ƴǡ����������ͷ����$N�󺰣��͹������ˣ�\n����ʼ�����Ƴǳ����ˡ�\n......\n......\n......\n......\n���պ������ڵ��˷��Ƴ��ˡ����򺰵����͹٣������³��ˣ�\n",me);
		gold->add_amount(-2);
	}
	else 
	{
		message_vision("$N���������С�\nֻ����С�����ų���˵��:���Ƴǡ����������ͷ����$N�󺰣��͹������ˣ�\n����ʼ�����Ƴǳ����ˡ�\n......\n......\n......\n......\n���պ������ڵ��˷��Ƴ��ˡ����򺰵����͹٣������³��ˣ�\n",me);
	}
	me ->move("/d/fy/fqkhotel");
	return 1;
}