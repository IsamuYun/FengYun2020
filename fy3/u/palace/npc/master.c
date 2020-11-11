
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("������", ({ "master xiao", "xiao","master" }) );
	set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 150); 

        set("title",HIY "���¿�" NOR);
	set("age", 45);
	set("int", 30);
	set("per", 30);
        set("apprentice_available", 50);
        create_family("������", 1, "����");
	set("long",
		"�����������û���κ���֪��������\n"
		);
        set("force_factor", 80);
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
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("whip", 150);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);
	set_skill("move",100);
        set_skill("cursism",200);
        set_skill("celecurse",70);
	set_skill("flying-dragon", 100);
	set_skill("thunderwhip", 130);
	set_skill("iceheart", 50);
	set_skill("zuixian-steps", 100);

	map_skill("unarmed", "flying-dragon");
        map_skill("whip", "thunderwhip");
        map_skill("force", "iceheart");
        map_skill("parry", "thunderwhip");
        map_skill("dodge", "zuixian-steps");
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "whip.tianleiyiji" :),
        }) );
	setup();
	carry_object(__DIR__"obj/shenxue")->wear();
        carry_object(__DIR__"obj/baojia")->wear();
        carry_object(__DIR__"obj/zhiai")->wear();
        carry_object(__DIR__"obj/sidai")->wield();
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
                command("say �����������Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
}
*/
void do_recruit(object ob)
{
        if((int) ob->query_temp("wait_time") < 360)
        {
        command("think");
        command("say ���Ĳ��ϣ�����\n");
        ob->set_temp("xiao_failed",1);
	return;
        }
        else {

                command("smile");
                command("say ���պ���д�ɣ�");
                command("smile");
                command("recruit " + ob->query("id") );
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yinshi");
        add("apprentice_availavble", -1);
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","�����ȵ���");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","���������");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","������С�ܼ�");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","�����ȹܼ�");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","�����ȴ�ܼ�");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","�������ܹ�");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","�����ȴ��ܹ�");
                return ;
        } else
                student->set("title","�����ȸ�����");
                return ;
}

