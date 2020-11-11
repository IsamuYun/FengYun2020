// wuyoucha.c

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(HIY"茶坊精制雪茄" NOR, ({ "xuejia" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIR"这是风云茶王送给大家的礼物\n" NOR);
                set("unit", "支");
             }
}

void init()
{
        add_action("do_xi", "xi");
}

int do_xi()
{
        object me;
        int wait,gin,kee,sen;
        me = this_player();
        if (me->query_temp("xiyan")) {
                tell_object(me,WHT"你感到头有些晕，恩，停一下再吸吧\n" NOR);
                return 1;
        }
        wait = random( 40 - (int)(me->query("con"))) ;
        if ( wait <= 10) {wait = 11;
        message_vision(HIR"$N抽出一支猛吸了一口。\n"NOR,me);
        tell_object(me,RED"烟从你的鼻孔和嘴里吐出来，让你感到全身无比的舒泰．．\n"NOR);
        me->set_temp("xiyan",1);
        gin=(int)me->query("eff_gin") / 20;
        kee=(int)me->query("eff_kee") / 20;
        sen=(int)me->query("eff_sen") / 20;
        if( me && environment(me) == this_object())
        {
        message_vision(HIG"$N"WHT"你感到一阵快意，$N"YEL"真想再来一口！！\n"NOR, me);
        me->set("eff_gin",-gin);
        me->set("eff_kee",-kee);
        me->set("eff_sen",-sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
        }
        me->delete_temp("xiyan");
        }
        return 1;
}
