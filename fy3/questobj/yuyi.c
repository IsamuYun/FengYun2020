#include <armor.h>
inherit CLOTH;
#include <ansi.h>
void create()
{
        set_name(HIY"������������"NOR, ({ "yuxi-cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�Ű�������ʵ۵������Ľ�ɫ������\n");
                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/intelligence",2);
        }
        setup();
}
