#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name("������" + HIR "��" +  HIG"��" + HIC"����" NOR, ({ "goodpin"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���������ε�����,���Ź�ʶ�Ŀ�ı�ʯ��Ƕ�����档\n");
                set("unit", "��");
                set("value", 200000);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");


        }
        setup();
}