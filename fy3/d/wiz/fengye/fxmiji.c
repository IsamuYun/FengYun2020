#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"�����ؼ�" NOR, ({ "fxmiji" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "����һ��Ҷ�³����ϵ�С���֣�������������д�������ֺ�ͼ�Ρ���ϧ����ôҲ��������\n");
          }
    setup();
}
