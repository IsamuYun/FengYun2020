#include <ansi.h>
#include <weapon.h>
inherit ITEM;
void create()
{
        set_name( "����������ͷ", ({ "tou" }) );
        set_weight(1400);
                set("unit", "��");
                set("long",
                        "һ���ոտ������ģ�Ѫ���ܵ���ͷ��\n");
                set("value", 0);
        setup();
}
