
inherit NPC;

void create()
{
        set_name("������", ({ "guard", "yellow guard"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ��Ǯ���ܶ�Ļ�������\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("sword", 90+random(100));
	set_skill("dodge", 100);
        	  set_temp("kf_tufei",28);
        set("pursuer", 1);
set("iron-cloth", 200);
        set("chat_chance", 1);
        set("chat_msg", ({
                "����������ȵ��������\n",
                "����������ȵ���վס����������ƣ�\n",
        }) );
	
	setup();
	add_money("silver", 5);
        carry_object(__DIR__"obj/tangfu")->wear();
	carry_object("/obj/longsword")->wield();
}

