#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIB"�ϵ��ĺ��ǵ���"NOR, ({ "duanqiao" }) );
        set_weight(8000);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ������ɽ��ǧ�꺮�����ɵĵ��ʡ���ϧ�Ѿ���Բ���䵶������.\n");
        }
}

