// wuyoucha.c

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(HIY"�跻����ѩ��" NOR, ({ "xuejia" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIR"���Ƿ��Ʋ����͸���ҵ�����\n" NOR);
                set("unit", "֧");
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
                tell_object(me,WHT"��е�ͷ��Щ�Σ�����ͣһ��������\n" NOR);
                return 1;
        }
        wait = random( 40 - (int)(me->query("con"))) ;
        if ( wait <= 10) {wait = 11;
        message_vision(HIR"$N���һ֧������һ�ڡ�\n"NOR,me);
        tell_object(me,RED"�̴���ıǿ׺������³���������е�ȫ���ޱȵ���̩����\n"NOR);
        me->set_temp("xiyan",1);
        gin=(int)me->query("eff_gin") / 20;
        kee=(int)me->query("eff_kee") / 20;
        sen=(int)me->query("eff_sen") / 20;
        if( me && environment(me) == this_object())
        {
        message_vision(HIG"$N"WHT"��е�һ����⣬$N"YEL"��������һ�ڣ���\n"NOR, me);
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
