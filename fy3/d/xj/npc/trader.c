
inherit NPC;

void create()
{
        set_name("��³������", ({ "tulufa trader"}) );
        set("gender", "����" );
        set("age", 42);
        set("long", "����һλ��˿��֮·���̵����ˡ�\n");
        set("combat_exp", 3000);
        set("attitude", "friendly");
	set("env/wimpy", 50);
        set_skill("unarmed", 40);
	set_skill("shuaijiao", 30);
	map_skill("unarmed", "shuaijiao");
        set("chat_chance", 30);
        set("chat_msg", ({
                "�����૵���Ϊ��׬Ǯ������Ҫ���Դ�ϵ�ڿ������Ϲ���˿��֮·��\n",
		(: random_move :)
        }) );
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "����˻�е������޷Ǿ���ҪǮô��Ϊʲôһ��Ҫɱ�ң�\n",
		(: random_move :)
        }) );

	
	setup();
	add_money("silver", 50);
        carry_object("/obj/cloth")->wear();
}