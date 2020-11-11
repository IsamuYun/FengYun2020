
inherit ROOM;
#include <room.h>

void create()
{
        set("short", "蝴蝶泉");
        set("long", @LONG
这里景色宜人,树木苍翠,繁花点点,最奇特的景观是漫天飞舞的蝴蝶,成双成对,在人们
面前盘旋,有时还出奇不意的给你送上一个鸳鸯双吻,似乎在悲怜你的孤独.正对面就是
传说中梁祝化蝶的蝴蝶温泉了,热气扑面，白白的水气笼罩了整个湖面,使你没法看清湖
有多大,传说此泉水能去腐生新,是疗伤的最佳良药,不知是真是假,但在里面泡(pao)一
下,能快速恢复疲劳却是不争的事实.
LONG
        );
        set("exits", ([
                "north" : __DIR__"shanmen",
        ]));
        set("objects", ([
                __DIR__"npc/hudei": 4,
        ]) );
	set("no_magic", 1);
        set("outdoors", "huangshan");
	set("coor/x",-510);
	set("coor/y",-550);
	set("coor/z",0);
	setup();

}

void init()
{
	add_action("do_pao", "pao");

}

int do_pao()
{
	object me;
	int wait;
	me = this_player();
	wait = random( 20 - (int)(me->query("con"))) * 2;
	if ( wait <= 20) wait = 21;
	wait = 5;
	message_vision("$N和衣跃入温泉中．\n",me);
	tell_object(me,"你感到无穷的精力在你体内增长..．\n");
	call_out("curehimup", wait, me);
return 1;
}

void curehimup(object me)
{
        int gin,kee,sen;
	if(!me) return;
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
if( me && environment(me) == this_object())
	{
	message_vision("$N的精气神全恢复了！！\n", me);
	me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
	me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
	}
return;
}

