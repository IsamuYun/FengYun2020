inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY "������" NOR, ({ "sppearl"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "һֻ���ɫ�������顣\n");
                set("value", 1);
        }
}