
inherit NPC;
inherit  F_MASTER;
void create()
{
        set_name("л�ƹ�", ({ "xie zhang gui"}) );
        set("gender", "����" );
set("reward_npc", 1);
    set("difficulty", 40); 

        set("age", 42);
        set("long", "�������Ϊ�徲¥л�ƹ񣬴��һ�����л������
��˵�书�ѳ����뻯��\n");
        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set("max_force",10000);
        set("force",10000);
        set("force_factor",25);
        set_skill("blade", 90);
        set_skill("move",100);
        set_skill("parry",80);
        set_skill("force",80);
        set_skill("cloudforce",60);
	set_skill("dodge", 100);
        set_skill("shenji-blade",150);
        set_skill("shenji-steps",150);
        map_skill("force","cloudforce");
        map_skill("blade","shenji-blade");
        map_skill("parry","shenji-blade");
        map_skill("dodge","shenji-steps");
        map_skill("move","shenji-steps");
        create_family("��Ϊ�徲¥", 1, "�ƹ�");
        set("chat_chance", 10);
        set("chat_msg", ({
               name()+"����û�뵽����С��������ү��ǰ��Ȼ��ô����һ����\n",
               name()+"������Ҫȥ����¥�ǵ�ɱ���Ҳ��С�\n",
        }) );
	setup();
	add_money("silver", 50);
        carry_object(__DIR__"obj/qingcloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();
}
/*
void attempt_apprentice(object me)
{
        command("say ��ֻ�Ἰ������è�Ĺ��򡣡���\n");
	me->add_temp("tried",1);
	if(me->query_temp("tried") < random(10)+10)
        return;
	else
        command("smile");
        command("recruit " + me->query("id") );
                return;
}
*/
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "blademan");
}
void re_rank(object student)
{
                student->set("title","��Ϊ�徲¥С��");
                return ;

}

