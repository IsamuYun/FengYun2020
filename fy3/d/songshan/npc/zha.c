// TIE@FY3
inherit NPC;
int give_letter();
void create()
{
	set_name("��ľ��", ({ "muhe", "zha" }) );
	set("title", "��Ӱ��");
	set("gender", "����" );
set("reward_npc", 1);
    set("difficulty", 30); 
	set("age", 52);
	set("agi",35);
	set("str",35);
	set("long",
		"���������ĵ�һ�쵶\n"
		);
       set("chat_chance", 2);
        set("chat_msg", ({
                "��ľ�ϵ��������ò�������ѽ���ɺ�ѽ����\n",
                (: random_move :),
                (: random_move :),
        }) );
	set("max_force",random(100)+20);
	set("force", random(100)+20);
	set("attitude", "peaceful");
	set_skill("blade", 60);
	set_skill("shenji-blade", 80);
	set_skill("shenji-steps",90);
	set_skill("dodge",90);
	map_skill("dodge","shenji-steps");
	map_skill("blade","shenji-blade");
	set("combat_exp", 9000000);
	setup();
        carry_object(__DIR__"obj/dafeng")->wield();
}
int is_ghost() { return 1; }

