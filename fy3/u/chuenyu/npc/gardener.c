inherit NPC;

void create()
{
        set_name("԰��", ({ "gardener" }) );
        set("nickname", "����һ��");
        set("gender", "����");
        set("age", 32);
        set("long",
"����һ���Ƿ�԰��ʮ��������԰����һ�Ѵ��ʹ�ĳ����绯��");
        set("combat_exp", 2000);
        set("score", 200);
        set("str", 20);
        set("int", 30);
        set("cor", 20);
        set("cps", 30);
        set("spi", 30);
        set("max_gin", 500);
        set("eff_gin", 500);
        set("gin", 500);
        set("max_kee", 2000);
        set("eff_kee", 2000);
        set("kee", 2000);
        set("max_sen", 500);
        set("eff_sen", 500);
        set("sen", 500);

        set("force", 150);
        set("max_force", 150);
        set("force_factor", 5);

        set("atman", 1500);
        set("max_atman", 1500);

        set("mana", 3000);
        set("max_mana", 3000);
        set("mana_factor", 50);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "invocation" :)
        }) );


        set_skill("literate", 10);
        set_skill("magic", 50);
        set_skill("force", 50);
        set_skill("spells", 50);
        set_skill("scratching", 30);
        set_skill("unarmed", 30);
        set_skill("sword", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        set_skill("gouyee", 30);

        set_skill("taoism", 30);
        set_skill("necromancy", 30);

        map_skill("spells", "necromancy");

        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);

        setup();

        carry_object(__DIR__"obj/lscissors")->wield();
        carry_object("/obj/cloth")->wear();
        add_money("gold", 3);

}

