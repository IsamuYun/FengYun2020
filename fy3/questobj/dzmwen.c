#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(MAG "��������" NOR, ({ "dzmwen" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ�������µ����ģ�
���������Ӳ�����ʧ����ȻΪ����������ƶɮҲӦ����
��������������

				����\n");
          }

    setup();
}
