
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "Œ‰µ±π€");
	set("long", @LONG
∫Ï…´µƒŒß«Ω£¨ª∆…´µƒ¥Û√≈°£√≈…œπ“÷¯“ªøÈΩÿ“£¨…œ È°∞Œ‰µ±π€°±
»˝∏ˆ¡˙∑…∑ÔŒËµƒ¥Û◊÷°£¥Û√≈◊Û”“∏˜Œ‘÷¯“ª÷ª–€Œ∞µƒ Ø ®°£“ª√˚Õ∑¥˜ª∆
…´µ¿π⁄£¨…Ì¥©«‡…´µ¿≈€µƒ÷™øÕµ¿»À£¨øø√≈∂¯¡¢°£

                  [35;41m©≥©•©•©•©•©•©•©•©•©•©∑[0m
                  [35;41m©ß[37m    Œ‰  µ±  π€ [35;41m   ©ß[0m
                  [35;41m©ª©•©•©•©•©•©•©•©•©•©ø[0m

LONG
	);
	set("exits", ([ 
		"northdown" : __DIR__"road3",
		"enter" : __DIR__"wudang1",
	]));
	set("objects", ([ 
		__DIR__"npc/wtaoist" : 1,
	]));
	set("outdoors", "wudang");
	set("coor/x",100);
	set("coor/y",-110);
	set("coor/z",40);
	set("coor/x",100);
	set("coor/y",-110);
	set("coor/z",40);
	set("coor/x",100);
	set("coor/y",-110);
	set("coor/z",40);
	set("coor/x",100);
	set("coor/y",-110);
	set("coor/z",40);
	set("coor/x",100);
	set("coor/y",-110);
	set("coor/z",40);
	setup();
}

int valid_leave(object me, string dir)
{
        object *enemy, ob;
        int i;

        if( userp(me) && (ob=present("waiter taoist", this_object()))) {
		enemy = ob->query_enemy();
		i = sizeof(enemy);
		while(i--) {
                	if( enemy[i] == me )
                                return notify_fail(HIY + ob->name()+"∂‘" + me->name() 
				+ "∫»µ¿£∫œÎ≈‹£ø√ªƒ«√¥»›“◊£°\n" + HIR + ob->name() + 
				"∞—" + me->name() + "µ≤¡Àªÿ¿¥£°\n" + NOR);
                }
        }
        return 1;
}

