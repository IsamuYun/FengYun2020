// tea_waiter.c

inherit NPC;
void create()
{
        set_name("�ο�", ({ "you ke" }) );
        set("gender", (random(2)? "Ů��":"����") );
        set("age", random(40)+10);
        set("long",
                "һ����ɽ��������\n");
	set("combat_exp", 5+random(5000));
        set("chat_chance", 70);
        set("chat_msg", ({
                (: random_move :),
                "�ο�ָ����Χ�ľ�ɫ̾��������ѽ����\n",
		"�ο͵�������Ϊһ����ɽ����������������ѽ��\n",
                "�οͶ���˵������Ҳ������ɽ�ģ�\n",
                "�οͶ���˵�����㿴�������ѽ��\n",
                "�οͶ���˵��������ı���������ˣ�\n",
        }) );

        set("attitude", "friendly");
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{
        add_action("do_vendor_list", "list");
}

