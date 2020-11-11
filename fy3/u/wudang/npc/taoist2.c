inherit NPC;

void create()
{
        set_name("����", ({ "peng" }) );
        set("gender", "����");
        set("age", 34);
        set("long",
		"�������䵱�𹤵��ˣ����Ż�ɫ����\n"
	);
        set("combat_exp", random(5000));
        set("class", "taoist");
        set("force", random(100));
        set("max_force", random(100));

        create_family("�䵱��", 58, "����");

        set_skill("move", 10+random(40));
        set_skill("force", 10+random(40));
        set_skill("unarmed", 10+random(40));
        set_skill("sword", 10+random(40));
        set_skill("parry", 10+random(40));
        set_skill("dodge", 10+random(40));
        set_skill("taijiforce", 10+random(30));
        set_skill("taiji", 10+random(30));
        set_skill("three-sword", 10+random(30));
        set_skill("five-steps", 10+random(30));

        map_skill("force", "taijiforce");
        map_skill("sword", "three-sword");
        map_skill("parry", "three-sword");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");

        set_skill("changelaw", 10);
        setup();

        add_money("silver", 5);
        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/cloth")->wear();

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="�䵱��" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say �䵱�ɲ��ͱ��ɵ��˹��С�");
        return 0;
}
 
void die()
{
        int i;
        object killer;

        if(objectp(killer = query_temp("last_damage_from")))
            killer->set_temp("marks/����", 1);

        ::die();

}

