// CYNGIRL.C
inherit NPC;
void create()
{       
        object armor;
        set_name("������Ů", ({ "girl" }) );
        set("long", "һ�������������������µ���Ů��\n");
        set("age", 16);
        set("per",20);
        set("gender", "Ů��");
        set("attitude", "friendly");
        set("combat_exp", random(50000));  
		set("kee", 300);
        set("eff_kee", 300);
        set("max_kee", 300);
        set_skill("ill-quan",30);
        set_skill("unarmed",30);
        set_skill("force",50);
        set_skill("cloudsforce",50);
        set_skill("dodge",50);
        set_skill("parry",30);
        set_skill("tie-steps",50);
        set("force_factor",10);
        set("max_force",100);
        set("force",200);
        map_skill("force","cloudsforce");
        map_skill("dodge","tie-steps");
        map_skill("unarmed","ill-quan");                         
        
       
        create_family("������", 2, "����");
        setup();
        armor=new(__DIR__"obj/corclot");
	armor->set_name("����",({"cloth"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corgirt");
	armor->set_name("���",({"belt"}) );
	armor->move(this_object());
	armor->wear();
}