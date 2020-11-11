
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����ü", ({ "master liu", "master","liu" }) );
    set("reward_npc", 1);
    set("difficulty", 150); 

        set("gender", "Ů��" );
        set("title", "��ɽ�����ŷ���");
        set("age", 26);
        set("int", 30);
        set("per", 30);
        set("apprentice_available", 50);
        create_family("��ɽ��", 3, "����");
	set("long",
		"����ü��ɽ�����ŷ���\n"
		);
        set("force_factor", 200);
        set("chat_chance", 5);
        set("chat_msg", ({
name()+"�ֹ������森���ҵ�������ô�����ˣ�\n",
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
        set("max_force", 3000);
        set("force", 3000);

        set("combat_exp", 9999999);
        set_skill("unarmed", 100);
        set_skill("sword", 150);
        set_skill("force", 100);
        set_skill("move", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);
        set_skill("perception", 100);


        set_skill("yunwu-strike", 100);
        set_skill("siqi-sword", 120);
        set_skill("xianjing", 150);
        set_skill("liuquan-steps", 100);

        map_skill("unarmed", "yunwu-strike");
        map_skill("sword", "siqi-sword");
        map_skill("force", "xianjing");
        map_skill("dodge", "liuquan-steps");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.siqi" :),
        }) );

	setup();
	carry_object(__DIR__"obj/yellowcloth")->wear();
        carry_object(__DIR__"obj/yusword")->wield();
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
                command("say �����˽����Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
          {      command("say ��ֻ��Ů���ӣ��㻹��ȥ���ҵķ���ɣ�");
          }
        else {

                command("smile");
                command("say ���պ��Ҫ����ɽ��Ӵ��");
                command("smile");
                command("recruit " + ob->query("id") );
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huangshan");
        add("apprentice_availavble", -1);
}
int accept_fight(object me)
{
                return 0;
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","��ɽ�ɵ���");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","��ɽ��С��");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","��ɽ������");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","��ɽ�ɴ���");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","��ɽ������");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","��ɽ�ɳ���");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","��ɽ��Ԫ��");
                return ;
        } else
                student->set("title","��ɽ�ɸ�����");
                return ;
}
*/
int accept_object(object who, object ob)
{
	if(ob->query("id") == "old jade")
	{
	command("smile");
	command("thank "+who->query("id"));
	if((int)ob->query("max_cure") < 10)
	call_out("give_pena",3,who);
	else
	call_out("give_reward",3,who);
	return 1;
	}

}
int give_reward(object who)
{
if(environment() != environment(who)) return 1;
if(!who->query("m_success/����ʯ"))
        {
                who->set("m_success/����ʯ",1);
                who->add("score",700);

        }
return 1;
}

int give_pena(object who)
{
if(environment() != environment(who)) return 1;
command("say �㾹Ȼ��͵�ñ����˵���ʯ������\n");
kill_ob(who);
who->kill_ob(this_object());
return 1;
}
