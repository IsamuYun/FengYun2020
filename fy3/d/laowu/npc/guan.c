
inherit NPC;

void create()
{
        set_name("������", ({ "laowuren"}) );
        set("gender", "����" );
        set("age", 32+ random(10));
        set("long", "����һλ�þ������յı����ˡ�\n");
        set("combat_exp", 5000);
        set("attitude", "aggrensive");
        set_skill("unarmed", 30 + random(100));
        set("chat_chance", 10);
        set("chat_msg", ({
                "�������������˴걻�����˫��\n",
        }) );
	setup();
	add_money("silver", 5);
        carry_object(__DIR__"obj/bigcloth")->wear();
}

