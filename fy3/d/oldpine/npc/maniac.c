// maniac.c

inherit NPC;

void create()
{
        object ob;

        set_name("��ң��", ({ "xiaoyao", "xiaoyao hou", "hou" }) );
    set("reward_npc", 1);
    set("difficulty", 50); 

        set("gender", "����");
        set("age", 67);
        set("long",
                "�����ͷ�����������������죬���������ƺ����ˡ�\n");

        set("str", 30);
        set("cor", 30);
        set("combat_exp", 4000000);
        set("score", 8000);
        set("bellicosity", 10000);

        set("force", 600);
        set("max_force", 600);
        set("force_factor", 2);

        set("mana", 800);
        set("max_mana", 800);

        set_skill("unarmed", 50);
        set_skill("dodge", 70);
        set_skill("force", 100);
        set_skill("spells", 50);
        set_skill("necromancy", 70);
        map_skill("spells", "necromancy");

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "drainerbolt" :)
        }) );

        // These temp apply are intended for beast race. If you want apply
        // to a human, need some good reason. For this example, this oldman
        // is a maniac, go can apply some extra attack bonus and damage.
        set_temp("apply/attack", 150);
        set_temp("apply/damage", 100);
        setup();
}
