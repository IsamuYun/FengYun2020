//XXDER
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("��ˮ����", ({ "master shenshui", "master", "shenshui" }) );
        set("nickname", "ˮĸ����");
set("reward_npc", 1);
    set("difficulty", 150); 

        set("gender", "Ů��");
        set("age", 33);
        set("long",
"һλ���ϴ�����ɳ����Ů�����ڵ����ϣ�����Ȼ�������������ݣ�ȴ���Ըо�����
�Ǿ��ѵ����ʺ;���Ͷ���ĳ�����ϡ�\n"
                );
        set("attitude", "peaceful");
        set("class", "shenshui");
        set("apprentice_available", 2);
        create_family("��ˮ��", 11, "����");
        set("int", 28);
        set("spi", 26);
	set("max_kee",700);
	set("max_gin",700);
	set("max_sen",700);
        set("per", 30);
        set("cps", 30);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        set("force", 1200);
        set("max_force", 1200);
        set("force_factor", 18);

        set("combat_exp", 15000000);
        set("score", 90000);

        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("throwing", 100);
        set_skill("force", 90);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100);
        set_skill("perception", 100);

        set_skill("nine-moon-steps", 150);
        set_skill("nine-moon-claw", 150);
        set_skill("nine-moon-force", 100);
        set_skill("nine-moon-sword", 100);

        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("force", "nine-moon-force");
        map_skill("sword", "nine-moon-sword");

        set_temp("apply/defense", 100);

        setup();
        carry_object(__DIR__"obj/ghostyboots")->wear();
        carry_object(__DIR__"obj/ghostycloth")->wear();
        carry_object(__DIR__"obj/ghostygirth")->wear();
        carry_object(__DIR__"obj/ghostyribbon")->wear();




}

void reset()
{
        delete_temp("learned");
        set("apprentice_available", 5);
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
                command("say �����Ž����Ѿ�����������ӣ���������ͽ�ˡ�");
        }
}
*/
void do_recruit(object ob)
{
        object girl;

        if( (string)ob->query("gender") != "Ů��" )
          {      command("say �󵨣������ģ�");
                 girl = new(__DIR__"fightgirl");
                 girl->move("/d/shenshui/gong");                 
          }
        else {
        if( ((int)ob->query("cor") < 10) || ((int)ob->query("cps") < 10)
|| ((int)ob->query("int") < 10)
        ||      ((int)ob->query("con") < 10)) {
                command("say ����ˮ����Ҫ��Ե�ݣ����ҿ�" +
RANK_D->query_respect(ob) + "�;���������Ե��");
                return;
        }
                command("smile");
                command("say �ܺã��ܺã��ܺá�");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shenshui");
        add("apprentice_availavble", -1);
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","��ˮ������");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","��ˮ��С��Ů");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","��ˮ����Ů");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","��ˮ������Ů");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","��ˮ����");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","��ˮ��ʥ��");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","��ˮ���ɼ�");
                return ;
        } else
                student->set("title","��ˮ��������");
                return ;
}
