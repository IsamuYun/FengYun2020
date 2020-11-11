//gift's hongbao by tiandi 20071229
#include <ansi.h>;
inherit ITEM;
string *gifts = ({
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/swordbook4",
"/obj/weapons/swordbook5",
"/obj/weapons/swordbook6",
"/obj/weapons/bladebook6",
"/obj/weapons/bladebook5",
"/obj/weapons/bladebook4",
"/obj/weapons/staffbook4",
"/obj/weapons/staffbook5",
"/obj/weapons/staffbook6",
"/obj/weapons/ringbook4",
"/obj/weapons/ringbook5",
"/obj/weapons/ringbook6",
"/obj/weapons/hammerbook4",
"/obj/weapons/hammerbook5",
"/obj/weapons/hammerbook6",
"/obj/armors/headbook4",
"/obj/armors/headbook5",
"/obj/armors/headbook6",
"/obj/armors/clothbook4",
"/obj/armors/clothbook5",
"/obj/armors/clothbook6",
"/obj/armors/neckbook4",
"/obj/armors/neckbook5",
"/obj/armors/neckbook6",
"/obj/armors/bootsbook4",
"/obj/armors/bootsbook5",
"/obj/armors/bootsbook6",
"/obj/armors/waistbook4",
"/obj/armors/waistbook5",
"/obj/armors/waistbook6",
"/obj/armors/wristsbook4",
"/obj/armors/wristsbook5",
"/obj/armors/wristsbook6",
"/obj/armors/fingerbook4",
"/obj/armors/fingerbook5",
"/obj/armors/fingerbook6",
"/obj/armors/shieldbook4",
"/obj/armors/shieldbook5",
"/obj/armors/shieldbook6",
"/obj/food/cj4",
"/obj/food/cj5",
"/obj/food/cj6",
"/obj/food/dan4",
"/obj/food/dan5",
"/obj/food/dan6",
"/obj/food/double",
"/obj/food/tongjiauto",
"/obj/food/heiyiauto",
"/obj/food/linjobauto",
"/obj/food/mengzhuauto",
"/obj/food/mmeng",
"/obj/food/mlinjob",
"/obj/food/mhyr",
"/obj/food/mtj",
});
void create()
{
set_name( HIR"奇怪的小盒子"NOR, ({ "little box" }));;
set_weight(10);
set("value", 0);
set("unit", "个");
set("long", "这是在东瀛人身上搜到的盒子。你可以打开(open)看看。\n");
setup();
}
void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        object me,gift_give;
        int i;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="little box" || arg =="box" )
			{
                   
                   gift_give = new(gifts[random(sizeof(gifts))]);
                   gift_give->move(me);
                   tell_object(me,HIW"\n你打开奇怪的小盒子，恭喜您额外获得"+gift_give->query("name")+HIW"。\n"NOR);
  				   message("channel:rumor",HIM"【谣言惑众】某人："+"听说"+me->query("name")+"从东瀛人的身上搜得了"+gift_give->query("name")+HIM"。\n"NOR,users());
                   destruct(this_object());
                   return 1;
                   }
        return 1;
}