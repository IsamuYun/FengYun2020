// sleepbag.c

inherit ITEM;

void create()
{
    	set_name("˯��", ({ "sleepbag" }) );
	set_weight( 1500 );
	set_max_encumbrance( 8000 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
          	set("unit", "ֻ");
          	set("long", "����һֻ��ͨ����֯˯����������ʿ��������Ұ��¶�ޡ�\n");
          	set("value", 1000);
	}
}
