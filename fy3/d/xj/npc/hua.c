
inherit NPC;
void create()
{
        set_name("�·��ܻ��������κ������������", ({ "middle aged man", "man" }) );
        set("gender", "����");
    set("reward_npc", 1);
    set("difficulty", 80); 

        set("age", 44);
        set("long","����������һ�����������һ���������Ź��ƣ��������˿�������������¡�\n"); 
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
	set("per", 30);
	set("cps", 30);
	set("max_force" , 15000);
	set("force" , 15000);
	set("force_factor" , 3);
	set("score" , 200000);
        set_skill("unarmed", 300);
        set_skill("dodge", 200);
        set_skill("parry", 200);
	set_skill("move", 200);
        setup();
	carry_object("/obj/cloth")->wear();
}
