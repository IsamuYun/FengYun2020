inherit NPC;

void create()
{
        set_name("��", ({ "man" }) );
        set("gender", "����");
        set("age", 32);
        set("long",
		"һλ���ʹ󺺴���������������ŷ�����ȥ����ȸ��\n"
	);
	set_skill("sword", 50);
	set_skill("three-sword", 50);
	set_skill("dodge", 50);
	set_skill("move", 50);
	set_skill("five-steps", 50);

	map_skill("sword", "three-sword");
	map_skill("dodge", "five-steps");
	map_skill("move", "five-steps");

        setup();
        add_money("silver", 1);
	carry_object(__DIR__"obj/shuzhi")->wield();
}

int accept_object(object who, object ob)
{
	object		shu;
	if( ob->name() == "����") {
		say("�󺺿�����һ�ۣ�˵����лл��\n");
		if( shu = present("shu zhi", this_object()) ) {
			say("�󺺽ӹ�������˳�ְ���֦���ڵ��ϡ�\n");
			shu->move(environment(this_object()));
		}
		return 1;
	}
	return 0;
} 

