// teacher.c

inherit NPC;

void create()
{
        int i,amun;
        string *order = ({"��", "��", "��", "��", "��", "��", "֣", "��", "��",
"��", "��", "��", "��", "��", "��", "κ", "��", "��", "��", "��"});
	string *orderr = ({"����", "���", "�ô�", "����", "����",
"ŷ��", "����", "����"});
        set_name( order[random(20)] + orderr[random(8)], ({ "shuseng", "seng" }) );
	set("title", "�������");
	set("gender", "����" );
	set("age", random(20)+20);
	set("int", 26);
	set("long",
		"���Խ���Ϊҵ.\n");
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );

	set("attitude", "peaceful");
	set_skill("literate", 40);
	set("combat_exp", random(50));
	set_skill("dodge", random(5));
	setup();
}
