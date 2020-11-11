// tao_2.c

inherit NPC;

void create()
{
        set_name("������", ({ "fighter", "taoist fighter" }) );
        set("nickname", "��ָС����");
        set("gender", "����");
        set("age", 20);
        set("long",
"�����������ָС���ˣ����ּ���ϲ����ͽ�ܡ��������ּ��洫��\n"
);
        set("combat_exp", 100000);
        set("score", 500);

        set("class", "taoist");

        set("int", 30);
        set("cps", 30);
        set("spi", 30);

        set("force", 1000);
        set("max_force", 500);
        set("force_factor", 20);

        set("atman", 1000);
        set("max_atman", 1000);

        set("mana", 3000);
        set("max_mana", 3000);
        set("mana_factor", 5);

        set("inquiry", ([
                "�����ķ�": 
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
        ]) );
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );

        create_family("���幬", 6, "����");

        set_skill("literate", 90);
        set_skill("magic", 50);
        set_skill("move", 50);
        set_skill("force", 50);
        set_skill("spells", 90);
        set_skill("unarmed", 50);
        set_skill("sword", 80);
        set_skill("parry", 60);
        set_skill("dodge", 80);
        set_skill("gouyee", 90);

        map_skill("force", "gouyee");

        set_skill("taoism", 80);
        set_skill("necromancy", 80);    

        map_skill("spells", "necromancy");

        set_temp("apply/dodge", 20);
        set_temp("apply/armor", 20);

        setup();

        add_money("gold", 3);
        carry_object("/u/taoguan/obj/sword1")->wield();

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="���幬" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say ���幬���ͱ��ɵ��˹��С�");
        return 0;
}
 
