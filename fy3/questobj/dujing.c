#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"����"NOR, ({ "dujing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "�Ȿ�ƾɵ������ܼ�һ������Ѫ�������˴����ƶ����ö��ķ�����\n");
            set("value", 200);
            set("material", "paper");
		set("skill", ([
			"name": 		"toxin",	
			"exp_required":	0,				
			"sen_cost":		20,				
			"difficulty":	20,		
			"max_skill":	50		
		]) );
          }

    setup();
}
