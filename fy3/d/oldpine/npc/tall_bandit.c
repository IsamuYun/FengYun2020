// tall_bandit.c

inherit NPC;

void create()
{
        set_name("����", ({ "bandit" }) );
        set("gender", "����");
        set("age", 27);
        set("long",     "��һﳤ�ø߸����ݣ���ɫ�԰ף�һ���޾���ɵ����ӡ�\n");
        set("combat_exp", 900);
        set("score", 100);
        set("attitude", "aggressive");
        set_skill("sword", 15);
        set_skill("parry", 15);
        set_skill("dodge", 10);
        setup();
        carry_object(__DIR__"obj/long_sword")->wield();
        add_money("silver", 6);
}
