#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(HIW"С��ɵ�"NOR, ({ "feidao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "iron");
                set("long", "����һ����Ѱ�����õķɵ��������ĵ�����ҫ�۵Ĺ�â��\n");
                set("wield_msg", "ֻ���׹�һ����$N���ж��һ�ѱ����ķɵ���\n");
                set("unwield_msg", "$N��ϸ�İѷɵ����ɾ�����������\n");
        }
        init_blade(100);
        setup();
}
