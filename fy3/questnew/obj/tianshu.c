#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"ˮ������"NOR, ({ "tianshus" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "����һ����˵û���ܿ��������飬���������ܺ����Ѿ����˷����ˡ�
��ˮ�����ĺۼ�����Լ�ܱ��ϳ�һЩ���֡���ģ���������Ϸ�����
����һ�����ذ�ʶ��ͨ�������湦����鼮��\n");
            set("value", 20000);
            set("material", "paper");
                set("skill", ([
                        "name":                 "essencemagic", 
                        "exp_required": 0,                              
                        "sen_cost":             100,                            
                        "difficulty":   40,             
                        "max_skill":    40              
                ]) );
          }

    setup();
}