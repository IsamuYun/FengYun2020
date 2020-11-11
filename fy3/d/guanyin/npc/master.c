inherit NPC;
inherit F_MASTER;
int kill_him();
void create()
{
	set_name("ʯ����", ({ "master guanyin", "master","guanyin" }) );
	set("gender", "Ů��" );
	set("age", 25);
	set("int", 30);
	set("str",60);
	set("per", 30);
	set("agi",100);
        set("apprentice_available", 50);
        create_family("�����", 2, "����");
	set("long",
"ʯ�����������������ǽ��˲�������ģ���Ϊ����������ȫ��ռ����
���ǵ����������кܶ��˶����á�������������Ů�ӵ����������ǹ�����
������˫�۾������������ᡣ�кܶ��˶����á���ɽ����������Ů��ü��
�������������ʵĴ�ɽҲ��������ü����Լ��
"
		);
        set("force_factor", 400);
        set("chat_chance", 2);
        set("chat_msg", ({
                "ʯ������������......�㲻�����ϣ���\n",
                "ʯ����Ц��Ц���ֵ��������֪��������ʲô�ط�����\n",
		"ʯ�����۹�ͻȻ���ʣ��������������֪����Ϊ�λ�����������\n",
        }) );

        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yaozhan" :),
        }) );
        set("combat_exp", 99999999);
        set("inquiry", ([
                "�޻�" : (: kill_him :),
                "�����" : (: kill_him :),
                "����" : (: kill_him :),
                "���ʮ����" : (: kill_him :),
                "�Ϲ���" : (: kill_him :),

        ]));
        set_skill("unarmed", 100);
        set_skill("blade", 150);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("kongshoudao", 100);
	set_skill("wind-blade", 130);
	set_skill("ghosty-force", 300);
	set_skill("ghosty-steps", 100);

	map_skill("unarmed", "kongshoudao");
        map_skill("blade", "wind-blade");
        map_skill("force", "ghosty-force");
        map_skill("parry", "wind-blade");
        map_skill("dodge", "ghosty-steps");

	setup();
	carry_object("/questobj/jpm");
	carry_object(__DIR__"obj/whitecloth")->wear();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
/*
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �����Ž����Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
}
void do_recruit(object ob)
{
                command("smile");
                command("say ���պ��Ҫ���Ŭ����");
                command("smile");
                command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "bandit");
        add("apprentice_availavble", -1);
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","����ɵ���");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","�����Сħ");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","�������ħ");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","����ɴ�ħ");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","�������ħ");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","����ɳ���");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","�����Ԫ��");
                return ;
        } else
                student->set("title","����ɸ�����");
                return ;
}
*/
int kill_him()
{
        object me;
        me = this_player();
        command("say �������Ѿ�֪���ҵ������ˣ��� \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
}

