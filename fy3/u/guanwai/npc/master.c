
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "master gelun", "master","gelun" }) );
	set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 150); 
	set("class","dazhao");

	set("age", 99);
    set("apprentice_available", 20);
    create_family("������", 20, "����");
	set("long",
		"���׸�ɮ���ڴ��������ֶ��ꡣ��Ů���ӱ鲼���⡣\n"
		);
	set("inquiry", ([
		"������": "��....������.....���������\n",
		"����": "�����ڴ����µ�ľ���",
	]) );
    set("combat_exp", 100000000);
    set("score", 90000);
    set_skill("unarmed", 550);
    set_skill("staff", 1000);
    set_skill("force", 300);
    set_skill("parry", 1000);
    set_skill("literate", 300);
	set_skill("iron-cloth", 1000);

	set_skill("bloodystrike", 1000);
	set_skill("cloudstaff", 1000);
	set_skill("bolomiduo", 1000);
	set_skill("buddhism", 500);
    set_skill("jin-gang", 1000);


	map_skill("unarmed", "bloodystrike");
    map_skill("force", "bolomiduo");
    map_skill("literate", "buddhism");
    map_skill("iron-cloth", "jin-gang");
    map_skill("staff", "cloudstaff");
    map_skill("parry", "cloudstaff");

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
        }) );
	setup();
	carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/9staff")->wield();
}
void attempt_apprentice(object me)
{
	if( me->query("class")&&me->query("class") != "dazhao")
	{
	command("stare");
	command("say ���Ѿ����Լ��������ˣ�\n");
	}
	else if( me->query("national") == "����" )
	{
	command("smile");
	command("say �ܺã�����Ժ���������������ˣ�\n");
            command("recruit " + me->query("id") );
	}
	else
	command("say ������ֻ�ղ���֮�ˣ�\n");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dazhao");
}
 
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("level");
        if( exp <= 10 ) {
                student->set("title","�����µ���");
                return ;
        } else if ( exp <= 20 ) {
                student->set("title","�������޺�");
                return ;
        } else if ( exp <= 30 ) {
                student->set("title","�����¸�ɮ");
                return ;
        } else if ( exp <= 40 ) {
                student->set("title","������ʥɮ");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","�����·���");
                return ;
        } else if ( exp <= 60 ) {
                student->set("title","�����»��");
                return ;
        } else if ( exp <= 70 ) {
                student->set("title","�����¸�����");
                return ;
        } else
                student->set("title","����������");
                return ;

}
