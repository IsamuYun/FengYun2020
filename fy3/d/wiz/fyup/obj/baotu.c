//gift's baotu by tiandi 20071229
#include <ansi.h>;
inherit ITEM;
string *gifts = ({
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/swordbook",
"/obj/weapons/swordbook2",
"/obj/weapons/swordbook3",
"/obj/weapons/swordbook4",
"/obj/weapons/swordbook5",
"/obj/weapons/swordbook6",
"/obj/weapons/swordbook7",
"/obj/weapons/swordbook8",
"/obj/weapons/swordbook9",
"/obj/weapons/swordbook10",
"/obj/weapons/bladebook",
"/obj/weapons/bladebook2",
"/obj/weapons/bladebook3",
"/obj/weapons/bladebook4",
"/obj/weapons/bladebook5",
"/obj/weapons/bladebook6",
"/obj/weapons/bladebook7",
"/obj/weapons/bladebook8",
"/obj/weapons/bladebook9",
"/obj/weapons/bladebook10",
"/obj/weapons/staffbook",
"/obj/weapons/staffbook2",
"/obj/weapons/staffbook3",
"/obj/weapons/staffbook4",
"/obj/weapons/staffbook5",
"/obj/weapons/staffbook6",
"/obj/weapons/staffbook7",
"/obj/weapons/staffbook8",
"/obj/weapons/staffbook9",
"/obj/weapons/staffbook10",
"/obj/weapons/hammerbook",
"/obj/weapons/hammerbook2",
"/obj/weapons/hammerbook3",
"/obj/weapons/hammerbook4",
"/obj/weapons/hammerbook5",
"/obj/weapons/hammerbook6",
"/obj/weapons/hammerbook7",
"/obj/weapons/hammerbook8",
"/obj/weapons/hammerbook9",
"/obj/weapons/hammerbook10",
"/obj/weapons/ringbook",
"/obj/weapons/ringbook2",
"/obj/weapons/ringbook3",
"/obj/weapons/ringbook4",
"/obj/weapons/ringbook5",
"/obj/weapons/ringbook6",
"/obj/weapons/ringbook7",
"/obj/weapons/ringbook8",
"/obj/weapons/ringbook9",
"/obj/weapons/ringbook10",
"/obj/armors/headbook",
"/obj/armors/headbook2",
"/obj/armors/headbook3",
"/obj/armors/headbook4",
"/obj/armors/headbook5",
"/obj/armors/headbook6",
"/obj/armors/headbook7",
"/obj/armors/headbook8",
"/obj/armors/headbook9",
"/obj/armors/headbook10",
"/obj/armors/clothbook",
"/obj/armors/clothbook2",
"/obj/armors/clothbook3",
"/obj/armors/clothbook4",
"/obj/armors/clothbook5",
"/obj/armors/clothbook6",
"/obj/armors/clothbook7",
"/obj/armors/clothbook8",
"/obj/armors/clothbook9",
"/obj/armors/clothbook10",
"/obj/armors/neckbook",
"/obj/armors/neckbook2",
"/obj/armors/neckbook3",
"/obj/armors/neckbook4",
"/obj/armors/neckbook5",
"/obj/armors/neckbook6",
"/obj/armors/neckbook7",
"/obj/armors/neckbook8",
"/obj/armors/neckbook9",
"/obj/armors/neckbook10",
"/obj/armors/bootsbook",
"/obj/armors/bootsbook2",
"/obj/armors/bootsbook3",
"/obj/armors/bootsbook4",
"/obj/armors/bootsbook5",
"/obj/armors/bootsbook6",
"/obj/armors/bootsbook7",
"/obj/armors/bootsbook8",
"/obj/armors/bootsbook9",
"/obj/armors/bootsbook10",
"/obj/armors/waistbook",
"/obj/armors/waistbook",
"/obj/armors/waistbook2",
"/obj/armors/waistbook3",
"/obj/armors/waistbook4",
"/obj/armors/waistbook5",
"/obj/armors/waistbook6",
"/obj/armors/waistbook7",
"/obj/armors/waistbook8",
"/obj/armors/waistbook9",
"/obj/armors/waistbook10",
"/obj/armors/wristsbook",
"/obj/armors/wristsbook2",
"/obj/armors/wristsbook3",
"/obj/armors/wristsbook4",
"/obj/armors/wristsbook5",
"/obj/armors/wristsbook6",
"/obj/armors/wristsbook7",
"/obj/armors/wristsbook8",
"/obj/armors/wristsbook9",
"/obj/armors/wristsbook10",
"/obj/armors/fingerbook",
"/obj/armors/fingerbook2",
"/obj/armors/fingerbook3",
"/obj/armors/fingerbook4",
"/obj/armors/fingerbook5",
"/obj/armors/fingerbook6",
"/obj/armors/fingerbook7",
"/obj/armors/fingerbook8",
"/obj/armors/fingerbook9",
"/obj/armors/fingerbook10",
"/obj/armors/shieldbook",
"/obj/armors/shieldbook2",
"/obj/armors/shieldbook3",
"/obj/armors/shieldbook4",
"/obj/armors/shieldbook5",
"/obj/armors/shieldbook6",
"/obj/armors/shieldbook7",
"/obj/armors/shieldbook8",
"/obj/armors/shieldbook9",
"/obj/armors/shieldbook10",
"/obj/food/cj",
"/obj/food/cj2",
"/obj/food/cj3",
"/obj/food/cj4",
"/obj/food/cj5",
"/obj/food/cj6",
"/obj/food/cj7",
"/obj/food/cj8",
"/obj/food/cj9",
"/obj/food/cj10",
"/obj/food/dan1",
"/obj/food/dan2",
"/obj/food/dan3",
"/obj/food/dan4",
"/obj/food/dan5",
"/obj/food/dan6",
"/obj/food/dan7",
"/obj/food/dan8",
"/obj/food/dan9",
"/obj/food/dan10",
"/d/wiz/fyup/obj/qh1",
"/d/wiz/fyup/obj/qh2",
"/d/wiz/fyup/obj/qh3",
"/d/wiz/fyup/obj/qh4",
"/d/wiz/fyup/obj/qh5",
"/d/wiz/fyup/obj/sheet",
});

string *wheres = ({
"岱庙坊",
 "叠嶂峰",
"天都峰",
"十八盘",
 "放生池",
"启母石",
 "白杨沟",
"黑松山",
"黄山剑庐",
});

void create()
{
set_name( HIW"藏宝图"NOR, ({ "treasure" }));;
set_weight(10);
set("value", 10000);
set("unit", "张");
set("long", "一张藏宝图。你可以查看(checkmap)它描述的位置，然后到指定的地点挖掘(dig)，就可能会发现宝藏。\n");
setup();
}
void init()
{
        add_action("do_dig", "dig");
        add_action("do_check", "checkmap");
}

int do_dig()
{
        object me,gift_give;
        int i,money;
        me = this_player();
        i = random(10);
	if(environment(me)->query("short") != this_object()->query_temp("place"))
	{
		return notify_fail("你再仔细看看图上的位置吧。\n");
	}
	else if(i == 0)
	{
	       tell_object(me,"\n你拿出一把小铁锹，挖了起来。\n"NOR);
	       tell_object(me,"很遗憾，结果你什么都没有发现。\n"NOR);
	}
	else if( i == 1)
	{
                   tell_object(me,"\n你拿出一把小铁锹，挖了起来。\n"NOR);
	       tell_object(me,"结果只听轰的一声，你被不知道什么东西炸飞了。\n"NOR);
	       me->move("/d/fy/church");
		   message("rumor", HIM"【谣言惑众】某人：听说"+me->query("name")+"挖宝的时候误中了机关，被炸飞了！\n" NOR,users());
	       me->unconcious();
	}
	else if( i == 2)
	{
                   tell_object(me,"\n你拿出一把小铁锹，挖了起来。\n"NOR);
	       tell_object(me,"结果发现了一些黄金。\n"NOR);
	       gift_give = new("/obj/money/gold");
		   money = random(100);
		   gift_give->set_amount(money);
	       message("rumor", HIM"【谣言惑众】某人：听说"+me->query("name")+"根据藏宝图上的坐标挖到了"+chinese_number(money)+"两"+HIY+gift_give->query("name")+HIM"！\n" NOR,users());

                   gift_give->move(me);
	}
	else
	{
                   gift_give = new(gifts[random(sizeof(gifts))]);
                   gift_give->move(me);
	       tell_object(me,"\n你拿出一把小铁锹，挖了起来。\n"NOR);
	       tell_object(me,"恭喜您，挖到了"+gift_give->query("name")+"！\n"NOR);
	       message("rumor", HIM"【谣言惑众】某人：听说"+me->query("name")+"根据藏宝图上的坐标挖到了"HIY+gift_give->query("name")+HIM"！\n" NOR,users());

	}
                   destruct(this_object());
                   return 1;
}

int do_check()
{
            string where;
	if (query_temp("place"))
		return notify_fail("这张宝图提示的位置好像在"+query_temp("place")+"附近。\n");
	else
		{
		where = wheres[random(sizeof(wheres))];
		set_temp("place",where);
		set("value",0);
		return notify_fail("这张宝图提示的位置好像在"+query_temp("place")+"附近。\n");
		}
	return 1;
}

