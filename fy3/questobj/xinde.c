// TIE@FY3
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"�����ĵ�"NOR,({ "xinde" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("long", "����һ�����ظ��׶����������ֵ��ĵá�\n");
        }
}
