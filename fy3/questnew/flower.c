#include <armor.h>

inherit ITEM;
#include <ansi.h>
void create()
{
        string *order=({HIY"��Ʒ�軨" NOR, YEL"һƷ�軨" NOR,
HIW"��Ʒ�軨" NOR,HIG"��Ʒ�軨" NOR,GRN"һ��軨" NOR});
        set_name((order[random(5)]), ({ "tea flower","flower"}) );
        set_weight(500000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
        setup();
}
