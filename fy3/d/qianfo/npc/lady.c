// lady.c

inherit NPC;

void create()
{
        set_name("ǧ��С��", ({ "lady" }) );
        set("long", "һ�����λ����ĸ��������������ϵ�Ĥ������\n");
        set("age", 32);
        set("gender", "Ů��");
        set("attitude", "peaceful");
        set("combat_exp", 10);
        set("chat_chance", 50);
        set("chat_msg", ({
                "ǧ��С��������ȣ�����ѽ�����컯����ǿ����Ů����\n",
        }) );
        setup();
        carry_object(__DIR__"obj/lady_dress")->wear();
        carry_object(__DIR__"obj/silver_clasp")->wear();
        add_money("silver", 10);
}
