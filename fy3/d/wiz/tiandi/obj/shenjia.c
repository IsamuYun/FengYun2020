#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIG"��������"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "������װ֮һ�����ּ������ֱر��Ķ�����������Ч�ذ������ֳɳ���\n");
                set("material", "steel");
               set("no_get",1);
				set("limited_lv",1);
				set("abradability",500);
                set("armor_prop/armor", 50);
        }
        setup();
}

int query_autoload() { return 1; }

