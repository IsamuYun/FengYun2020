// wuyoucha.c

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(YEL"��������" NOR, ({ "wuyou" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIG"���Ƿ��Ʋ����͸���ҵ�����\n" NOR);
                set("unit", "��");
                set("max_liquid", 50);
        }


        set("liquid", ([
                "name": YEL"���ǲ�" NOR,
                "remaining": 50,
        ]) );
}
