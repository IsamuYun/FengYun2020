// bandit_guard.c

inherit NPC;

void create()
{
        set_name("�������", ({ "bandit" }) );
        set("gender", "����");
        set("age", 33);
        set("long",
                "��һ��������⣬һ�������ɷ��ģ��������������η��\n");
        set("combat_exp", 3600);
        set("pursuer", 1);
        set("score", 260);
        set("bellicosity", 600);
        set("attitude", "aggressive");
        set_skill("sword", 50);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        setup();
        carry_object(__DIR__"obj/short_sword")->wield();
        add_money("silver", 5);
}
