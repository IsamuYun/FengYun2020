// bandit_chief.c

inherit NPC;

void create()
{
        set_name("�����ϴ�", ({ "bandit chief", "chief" }) );
        set("gender", "����");
        set("age", 39);
        set("long",
                "��һ������׶�һ˫���������������������Ĳ��ӡ�\n");
        set("combat_exp", 6000);
        set("score", 700);
        set("attitude", "aggressive");
        set("chat_chance", 10);
        set("chat_msg_combat", ({
                "\n�����ϴ���������˵�����ԹԵ����°ɣ�\n",
                "\n�����ϴ󻢺�һ����������ǰ��\n"
        }) );
        set_skill("blade", 60);
        set_skill("parry", 50);
        set_skill("dodge", 50);

        // Because the chief's �书 is not done yet, set apply to replace it.
        set_temp("apply/attack", 50);
        set_temp("apply/dodge", 30);

        setup();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        add_money("silver", 30);
}

