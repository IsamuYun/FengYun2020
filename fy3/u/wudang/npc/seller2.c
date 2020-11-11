// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�ӻ����ϰ�", ({ "seller" }) );
	set("gender", "����" );
	set("age", 34);
	set("long",
		"��λ�ӻ����ϰ������ڹ�̨�������ʣ���ʱ��̧ͷ��һ�����⡣\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("vendor_goods", ([
		"/obj/example/bag":4,
		"/obj/paper_seal":100,
		"/obj/dust":10,
	]) );
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "�ӻ����ϰ�Ц������ʵ�����λ" + RANK_D->query_respect(ob)
				+ "����Ҫ���ʲô��\n");
			break;
		case 1:
			say( "�ӻ����ϰ����ڵ�ͷ���ʣ���ûע�⵽" + ob->name() + "������\n");
			break;
	}
}
