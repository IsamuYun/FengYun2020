#include <armor.h>

inherit ITEM;
#include <ansi.h>
void create()
{
        string *order=({HIY"ǧ���˲�" NOR, YEL"�����ھ�" NOR,
HIW"�����" NOR,HIG"���ͻ�ɽ" NOR,GRN"һ������" NOR,GRN"һ��ҩ��" NOR,GRN"һ���Ӳ�" NOR});
        set_name((order[random(7)]), ({ "yao cai","yao"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
        setup();
}