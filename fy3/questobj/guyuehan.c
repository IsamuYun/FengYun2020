//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIW"��ȱ���º�"NOR, ({ "guyuehan" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������һ��ȱ�ڵ�������");
		set("rigidity", 2000);
                set("material", "steel");
        }
        init_blade(70);
        setup();
}
