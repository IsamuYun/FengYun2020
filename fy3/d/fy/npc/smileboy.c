
inherit NPC;

void create()
{
	set_name("��ͯ", ({ "jintong" }) );
	set("gender", "����" );
	set("age", 14);
	set("long",
		"һ��������а��δ�����µ�С��ͯ\n");
          set("combat_exp", 1000000);
	set("attitude", "friendly");
		  set_temp("kf_tufei",54);
        set("pursuer", 1);
set("per",30);
	set_skill("unarmed",5);
	set_skill("dodge",5);
	setup();
	carry_object(__DIR__"obj/yellow_cloth")->wear();

}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
message_vision("$N����$nһ�ۣ�Ȼ����ס�쿪ʼ���Գԣ���Ц��\n",this_object(),ob);
			break;
		case 1:
message_vision("$N����$n����һ�ۣ�Ȼ���ߵ�ת������ʼ���Գԣ���Ц��\n",this_object(),ob);
			break;
		case 2:
			command("snicker");
	}
}
