#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"����"NOR, ({ "biaoqi" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "��ʨ�ھֵ����졣\n");
          }

    setup();
}
