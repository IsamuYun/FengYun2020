#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( BLK"��ڵĵ�"NOR, ({ "black blade", "blade"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value",10000);
                set("unit", "��");
                set("long", "����һ����ڵĵ�����˵����û�б���˼���������״��");
		set("rigidity", 2000);
                set("material", "steel");
        }
        init_blade(100);
        setup();
}
