//gift's hongbao by tiandi 20071229
#include <ansi.h>;
inherit ITEM;
string *gifts = ({
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