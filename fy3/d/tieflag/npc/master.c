inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({ "master tie", "master","tie" }) );
        set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 150); 

        set("age", 26);
        create_family("��Ѫ������", 8, "����");
	set("long",
		"����������Ѫ�����ŵĴ��ˡ�\n"
		);
        set("force_factor", 30);
        set("max_gin", 30000);
        set("max_kee", 30000);
        set("max_sen", 30000);
        set("eff_gin", 30000);
        set("eff_kee", 30000);
        set("eff_sen", 30000);
        set("gin", 30000);
        set("kee", 30000);
        set("sen", 30000);
        set("max_force", 5000);
        set("force", 5000);
        set("attitude", "peaceful");
        set("combat_exp", 99999999);
        set("score", 90000);
        set_skill("dormancy",1000);
        set_skill("unarmed", 100);
        set_skill("sword", 200);
        set_skill("force", 500);
        set_skill("parry", 500);
        set_skill("literate", 500);
		set_skill("dodge", 1000);
		set_skill("ill-quan", 1000);
		set_skill("fy-sword", 1000);
		set_skill("jiayiforce", 500);
		set_skill("tie-steps", 1000);
		map_skill("unarmed", "ill-quan");
        map_skill("sword", "fy-sword");
        map_skill("force", "jiayiforce");
        map_skill("parry", "fy-sword");
        map_skill("dodge", "tie-steps");
	set("class","tieflag");

		setup();
        	carry_object(__DIR__"obj/tieflag");
              carry_object(__DIR__"obj/tiesword");
		carry_object("obj/cloth")->wear();
}
void attempt_apprentice(object me)
{
	if( me->query("class"))
	{
	command("stare");
	command("say ���Ѿ����Լ��������ˣ�\n");
	}
	else if( me->query("national") == "����" )
	{
	command("smile");
	command("say �ܺã������������һ�����ҫ���պ�����д�ɣ�\n");
            command("recruit " + me->query("id") );
	}
	else
	command("say ��Ѫ������ֻ�ղ���֮�ˣ�\n");
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tieflag");
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("level");
        if( exp <= 10 ) {
                student->set("title","��Ѫ�����ŵ���");
                return ;
        } else if ( exp <= 20 ) {
                student->set("title","��Ѫ������С��");
                return ;
        } else if ( exp <= 30 ) {
                student->set("title","��Ѫ����������");
                return ;
        } else if ( exp <= 40 ) {
                student->set("title","��Ѫ�����Ŵ���");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","��Ѫ����������");
                return ;
        } else if ( exp <= 60 ) {
                student->set("title","��Ѫ������Ԫ��");
                return ;
        } else if ( exp <= 70 ) {
                student->set("title","��Ѫ������Ԫ��");
                return ;
        } else
                student->set("title","��Ѫ�����Ÿ�����");
                return ;
}
