// worker.c

inherit NPC;

void create()
{
        set_name("���ͽ", ({ "chantu", "tu" }) );
        set("gender", "Ů��" );
        set("age", 19);
	set("title","��������");
        set("long", "һ��������������ͽ\n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        	  set_temp("kf_tufei",10);
        set("pursuer", 1);
set_skill("parry", 25);
	set_skill("dodge", 100);
	set_skill("throwing", 50);
	set("max_kee",400);
	set("eff_kee",400);
	set("kee",400);

	setup();
        carry_object("/obj/cloth")->wear();
}

