// gold-belt.c �ƽ�����

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
        set_name( HIY "��������޵���" NOR, ({ "gold belt", "belt" }) );

        set("no_get", 1);
        set("no_put", 1);
        set("no_drop", 1);

        set_weight( 1000 );

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @TEXT
����һ�����������鱦��$HIY$�ƽ�����$NOR$��
�������һ�н��֣���$HIY$��������޵���$NOR$����
���ļ�ֵ�������������󣬶�����Ϊ����������������
TEXT
                );

                set("unit", "��");
                set("value", 0);

                set("material", "gold");
                set("armor_type", TYPE_WAIST);

                set("armor_prop/armor", 5 );
                set("armor_prop/defense", 5 );
                set("armor_prop/dodge", 5 );
        }
        
        setup();
}
