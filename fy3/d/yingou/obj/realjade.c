// movebook.c

inherit ITEM;

void create()
{
	set_name("��ɲ��", ({ "luosha" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("for_bandit",1);
		set("long",
			"�������ɲ�������̵�����ʦ����\n");
		set("value", 0);
		set("material", "stone");
		set("skill", ([
			"name": 		"taoism",	
			"exp_required":	20000,				
			"sen_cost":		20,				
			"difficulty":	40,		
			"max_skill":	40		
		]) );
	}
}
