#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
void create()
{
        set_name(HIM "����ͷ" NOR, ({ "egt" }) );
        set_weight(10);
        if( clonep() )
             set_default_object(__FILE__);
        else {
set("long", "һ������ͷ��\n");
                set("unit", "ƿ");
                set("value", 0);
                set("max_liquid", 20);
        }
        set("liquid", ([
                "type": "alcohol",
                "name": "����ͷ",
                "remaining": 20,
                "drunk_apply": 5,
        ]) );
}
