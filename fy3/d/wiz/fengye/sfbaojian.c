#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
    set_name("�з�����", ({ "sfbaojian" }) );
        set_weight(8000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "�������͵�һ�ѱ�����\n");
set("wield_msg", "$N���һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n������ڡ�\n");
           set("weapon_prop/personality",2);
          }
        init_sword(90);
    setup();
}
