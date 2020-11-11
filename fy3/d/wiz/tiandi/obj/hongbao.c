//gift's hongbao by tiandi 20071229
#include <ansi.h>;
inherit ITEM;
string *gifts = ({
"/obj/food/double",
"/obj/food/heiyiauto",
"/d/wiz/fyup/obj/baotu",
});
void create()
{
set_name( HIR"节日红包"NOR, ({ "gift-hongbao" }));;
set_weight(10);
set("value", 0);
set("unit", "个");
set("long", "这里快乐风云的节日礼物，巫师组与大家共享节日的喜悦，同时也\n希望大家越来越支持本站。你可以打开(open)看看。\n");
set("no_get",1);
set("no_drop",1);
setup();
}
void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        object me,gift_give;
        int exp,pot,i;
        me = this_player();
        exp = me->query("level")*500;
        pot = exp/4;
        if( !arg || arg=="" ) return 0;
        if( arg=="gift-hongbao" || arg =="红包" ) {
                   if (!me->query_skill("idle-force"))
                               return notify_fail("你这个角色是刚建立的吧，先在游戏里发会呆再说。\n");

	   if(this_object()->query_temp("giftowner")!=this_player()->query("name"))
			return notify_fail("这个红包是"+this_object()->query_temp("giftowner")+"的不是你的。\n");

/*
                   if (me->query("yuandangift") > 20087 )
                               {message_vision("$N已经拿过礼物了，还想拿？红包化成一缕青烟飞上了天空。\n只留下$N坐在地上发呆，喃喃道:想多拿一次礼物都不行。。。\n",me);
                               return 1;
                               }
*/
                   me->add("combat_exp",exp);
                   me->add("potential",pot);
                   tell_object(me,HIY"你被奖励了：\n" +
                   chinese_number(exp) + "点实战经验\n"+chinese_number(pot) + "点潜能\n"+NOR);
                    i = random(100);
                   if (i<50) {
                     tell_object(me,HIY"感谢您为快乐风云做出的贡献。\n"+NOR);
                }else  {
                   gift_give = new(gifts[random(sizeof(gifts))]);
                   gift_give->move(me);
                   tell_object(me,HIW"\n恭喜您额外获得"+gift_give->query("name")+"。\n"NOR);
				    message("channel:rumor",HIM"【谣言惑众】某人："+"听说"+me->query("name")+"从礼物礼物中获得了"+gift_give->query("name")+HIM"。\n"NOR,users());
                   }
                   tell_object(me,HIW"\n祝您节日快乐!\n"NOR);
                   destruct(this_object());
                   return 1;
                   }
        return 1;
        }
