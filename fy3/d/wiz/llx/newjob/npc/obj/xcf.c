inherit ITEM;
#include <ansi.h>
void create()
{
        string *order=({HIY"����ë��" NOR, YEL"����̨" NOR,
HIW"������" NOR,HIG"��������" NOR,GRN"������" NOR,GRN"���ݴ�" NOR});
        set_name((order[random(6)]), ({"xincha"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");set("unit", "��");
                set("material", "wood");
                set("long", "һ��������Ʋ販ʿ���²衣\n");
        }
        setup();
}
