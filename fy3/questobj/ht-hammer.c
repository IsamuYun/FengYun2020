#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
        set_name(HIB"���촸"NOR, ({ "ht-hammer" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "iron");
                set("long", "����һ�����촸���õ���������һ����ʮ���ء�\n");
                set("wield_msg", "$N�þ����̵ľ���$n���ڼ��ϡ�\n");
                set("unwield_msg", "$N������$n�۵�����������\n");
        }
                init_hammer(100);
        setup();
}
