
inherit NPC;
inherit F_MASTER;

void create()
{
		object armor;
        set_name("�պ�", ({ "master queen", "master","queen" }) );
        set("gender", "Ů��" );
    set("reward_npc", 1);
    set("difficulty", 50); 

        set("age", 46);
	set("agi",35);
        set("int", 30);
        set("per", 30);
        create_family("������", 1, "����");
	set("long",
		"�պ�����Ѫ�����ŵ��ߴ�����������֮�ޣ��򿴲�����Ѫ�������˶���\n"
		"���ӵ����飬����������һ�ɣ�������������������Ů�ӡ�\n"
		);
        set("force_factor", 10);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_force", 3000);
        set("force", 3000);
        set("attitude", "peaceful");
        set("combat_exp", 30000000);
        set("score", 90000);
        set_skill("dormancy",150);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
		set_skill("dodge", 100);
		set_skill("ill-quan", 100);
		set_skill("fy-sword", 150);
		set_skill("jiayiforce", 120);
		set_skill("tie-steps", 150);
    	
		map_skill("unarmed", "ill-quan");
        map_skill("sword", "fy-sword");
        map_skill("force", "jiayiforce");
        map_skill("parry", "fy-sword");
        map_skill("dodge", "tie-steps");

		setup();
	    armor=new(__DIR__"obj/corclot");
		armor->set_name("����˿��",({"cloth"}) );
		armor->move(this_object());
		armor->wear();

}
