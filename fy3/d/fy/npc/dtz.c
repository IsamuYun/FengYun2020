// dtz.c

inherit NPC;

void create()
{
        set_name("��ͽ��", ({ "dtz" }) );
        set("gender", "����" );
        set("age", 32);
        set("long", "һ��ɫ���Եĵ�ͽ��.\n");

        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 20);
        	  set_temp("kf_tufei",17);
        set("pursuer", 1);
set_skill("parry", 20);
	set_skill("dodge", 20);
        set("chat_chance", 15);
        set("chat_msg", ({
                (:random_move :)
        }) );

	setup();
	add_money("silver", 1);
        carry_object("/obj/cloth")->wear();
        
}
