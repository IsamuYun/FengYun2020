//TIE@FY3`
inherit NPC;
void create()
{
        set_name("��ԯ��ȱ", ({ "san que" }) );
    set("reward_npc", 1);
    set("difficulty", 50); 

        set("gender", "����" );
        set("age", 53);
	set("title","���۵���");
        set("long", "��ԯ���ɵ��ֵܣ��书�߾���Ϊ���ĺ�������\n");
        set("combat_exp", 5000000);
        set("str", 27);
        set("force", 200);
	set("attitude", "aggressive");
        set("max_force", 200);
        set("force_factor", 20);
        set("chat_chance", 10);
        set("chat_msg", ({
"��ԯ��ȱ��Ц���������ҵġ����ذ�����ɱ���󡱣�\n",
"��ԯ����Ц������ʮһ���������������ǰѸ�¹�����������ҵ���ɱ����\n",
                (: random_move :),
                (: random_move :),
                (: random_move :),
        }) );
        set("inquiry", ([
                "��ʮһ��" : "�Ҹոմ��������ϸ���һ���⣬�����ˡ�\n",
		"xiao 11" : "�Ҹոմ��������ϸ���һ���⣬�����ˡ�\n",
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/qin")->wield();
}
