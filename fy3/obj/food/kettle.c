// kettle.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���", ({ "kettle" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����Ʋ������������װˮ��\n");
		set("unit", "��");
		set("value", 50);
		set("max_liquid", 20);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		"remaining": 20,
		"drunk_apply": 6,
	]) );
}
