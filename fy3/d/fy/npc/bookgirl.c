// worker.c

inherit NPC;

void create()
{
        set_name("�ŷ�", ({ "yafang", "shu" }) );
        set("gender", "Ů��" );
        set("age", 9);
	set("title","С��ͯ");
        set("long", "�����С��ͯ���������䡣 \n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        	  set_temp("kf_tufei",4);
        set("pursuer", 1);
set_skill("unarmed", 10);
        set_skill("parry", 25);
	set_skill("dodge", 100);
	set_skill("throwing", 50);
	set("max_kee",400);
	set("eff_kee",400);
	set("kee",400);

	setup();
        carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/flower")->wield();
}

