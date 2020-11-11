// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�����", ({ "waiter" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set_skill("iron-cloth", 2000);
	set_skill("unarmed", 100);
	set_skill("bloodystrike", 50);
	map_skill("unarmed", "bloodystrike");
	set("rank_info/respect", "С����");
	set("vendor_goods", ([
		__DIR__"obj/junksword":10,
		__DIR__"obj/junkblade":10,
		__DIR__"obj/junkstaff":10,
		__DIR__"obj/jade3":10,
		__DIR__"obj/wineskin":10,
		__DIR__"obj/sheep_leg":10,
		__DIR__"obj/snake_drug":10,
		__DIR__"obj/movebook":10,

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
	switch( random(3) ) {
		case 0:
			say( "��С�������Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȱ��裬ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "��С��������ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
		case 2:
			say( "��С�������˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȼ���С��ľưɣ��⼸��Ŵӽ����￪���Ӵ��\n");
			break;
	}
}