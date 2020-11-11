inherit NPC;

void create()
{
        set_name("��ʿ", ({ "taoist" }) );
        set("gender", "����");
        set("age", 32);
        set("long",
"���幬�ĵ�ʿ����һ���ɫ�ĵ���\n"
);
        set("combat_exp", 10000);
        set("score", 200);

        set("class", "taoist");

        set("int", 30);
        set("cps", 30);
        set("spi", 30);

        set("force", 150);
        set("max_force", 150);
        set("force_factor", 5);

        set("atman", 150);
        set("max_atman", 150);

        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5);

        set("inquiry", ([
                "�����ķ�": 
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
        ]) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );

        create_family("���幬", 7, "����");

        set_skill("literate", 40);
        set_skill("magic", 20);
        set_skill("move", 20);
        set_skill("force", 20);
        set_skill("spells", 50);
        set_skill("unarmed", 40);
        set_skill("sword", 40);
        set_skill("parry", 50);
        set_skill("dodge", 30);
        set_skill("gouyee", 50);

        map_skill("force", "gouyee");

        set_skill("taoism", 60);
        set_skill("necromancy", 50);    

        map_skill("spells", "necromancy");

        set_temp("apply/dodge", 25);
        set_temp("apply/armor", 25);

        setup();

        add_money("silver", 10);
        carry_object("/u/taoguan/obj/sword1")->wield();

}
