inherit NPC;
void create()
{
        set_name("����ѩ", ({ "hongxue", "fu hongxue", "fu hong xue"}) );
        set("gender", "����");
    set("reward_npc", 1);
    set("difficulty", 250); 

        set("age", 24);
        set("long","����ѩ���������ŵ���һ����״�����صĵ���������ڣ�������ڡ�
����������ʲô��ʱ��û�зŹ��������\n"); 
	set("attitude", "friendly");
        set("combat_exp", 10000000);
        set("eff_gin", 100000);
        set("eff_kee", 100000);
        set("eff_sen", 100000);
        set("max_gin", 100000);
        set("max_kee", 100000);
        set("max_sen", 100000);
        set("gin", 100000);
        set("kee", 100000);
        set("sen", 100000);
	set("str", 60);
	set("cor", 30);
	set("courage", 1000);
	set("int", 30);
	set("cps", 30);
	set("max_force" , 15000);
	set("force" , 15000);
	set("force_factor" , 3);
	set("score" , 200000);
        set("chat_chance", 3);
        set("chat_msg", ({
                "����ѩ���ڳԷ�����һ�ڷ�����һ�ڲˣ��Եú�����\n",
		"����ѩ��ڵĵ�����ڵ��·�����ڵ����ӣ��ڵ÷�����\n"
        }) );
        set_skill("blade", 300);
        set_skill("dodge", 200);
        set_skill("parry", 200);
	set_skill("move", 200);
        setup();

	carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();
}
