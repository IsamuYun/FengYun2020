#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
    set_name(HIY"�޳���"NOR, ({ "wcsword" }) );
        set_weight(8000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "һ�ѱ�����\n");
          }
        init_sword(90);
    setup();
}
