inherit NPC;

void create()
{
        set_name("������", ({ "bingyan" }) );
        set("gender", "����" );
        set("age", 42);
	set("str",40);
        set("long",
                "����������������з�ȵļ�����\n");
	set("combat_exp", 7000000);
        set("chat_chance", 2);
        set("chat_msg", ({
                "������������������ô˵�ģ���\n",
		"�����������������Ҳ����\n",
        }) );

        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/bcloth2")->wear();

}
