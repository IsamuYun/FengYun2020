// worker.c

inherit NPC;

void create()
{
        set_name("�ɻ��", ({ "little girl", "girl" }) );
        set("gender", "Ů��" );
        set("age", 9);
        set("long", "�����СŮ��������ˣ�� \n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_skill("unarmed", 40);
        set_skill("parry", 45);
	set_skill("dodge", 100);
	set_skill("throwing", 50);

        set("inquiry", ([
		"С��" : "��Ҫ������ɽȥ�ʡ�", 
        ]) );

	setup();
	add_money("coin", 15);
        carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/flower")->wield();
}

