#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name( HIW"������"NOR , ({ "lin" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ɭɭ�Ĺ�����\n");
                set("no_get",1);
                set("no_drop",1);
                set("value", 400);
                set("material", "steel");
                set("wield_msg", "$N��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���¡�\n");
        }
        init_dagger(65);
        setup();
}

