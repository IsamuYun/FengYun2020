//TIE@FY3`
inherit NPC;
void create()
{
        set_name("��ԯ����", ({ "san cheng" }) );
    set("reward_npc", 1);
    set("difficulty", 50); 

        set("gender", "����" );
        set("age", 53);
        set("long", "һ���ܿ��µ�����书�߾������ٹ��أ����ۺڰ������Ľ��ף�
ֻҪ����֪������Ҫ�����ɣ������˲��ϴ�Ӧ���������죬�ͻ�ʬ���޴档\n");
        set("combat_exp", 4000000);
        set("str", 27);
        set("force", 200);
	set("attitude", "friendly");
        set("max_force", 200);
        set("force_factor", 20);
        set("chat_chance", 10);
        set("chat_msg", ({
"��ԯ����Χ����ת��һȦ�������������н����ˣ�\n",
"��ԯ����Ц���������ʮһ���治��������Ҫ�����߳ɣ�\n",
                (: random_move :),
                (: random_move :),
                (: random_move :),
        }) );
        set("inquiry", ([
                "��ʮһ��" : "Ŷ����Ҳ����������\n",
		"xiao 11" : "Ŷ����Ҳ����������\n",
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();
}

int accept_object(object me, object obj)
{
        command("grin");
        command("say ��λ" + RANK_D->query_respect(me) + 
"����͹�����������");
        return 1;
}
