
inherit NPC;

void create()
{
	set_name("����", ({ "chuchu" }) );
	set("gender", "Ů��" );
	set("age", 18);
	set("long",
		"һ��������а��δ�����µ�СѾ��\n");
          set("combat_exp", 1000000);
	set("attitude", "friendly");
		  set_temp("kf_tufei",55);
        set("pursuer", 1);
set("per",30);
	set_skill("unarmed",5);
	set_skill("tenderzhi",5);
	set_skill("dodge",5);
	set_skill("stormdance",5);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/green_cloth")->wear();
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
message_vision("$N����$nһ�ۣ�Ȼ����סС�����ʼ���Գԣ���Ц��\n",this_object(),ob);
			break;
		case 1:
message_vision("$N����$n����һ�ۣ�Ȼ���ߵ�ת������ʼ���Գԣ���Ц��\n",this_object(),ob);
			break;
		case 2:
			command("snicker");
	}
}
