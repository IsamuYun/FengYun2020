#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������ʿ", ({ "master fulong", "master", "fulong" }) );
        set("nickname", HIW "��������"NOR);
        set("gender", "����");
        set("reward_npc", 1);
        set("difficulty", 100); 

        set("age", 74);
        set("attitude", "peaceful");
        set("class", "dragon");
        set("apprentice_available", 3);
        set("student_title","��ʿ");
        set("str", 50);
        set("int", 30);
        set("spi", 30);
        set("con", 30);
        set("spi", 30);
        set("con", 30);
        set("cps", 30);
        set("cor", 20);
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.huanshijinlong" :),
                (: perform_action, "dodge.huanshijinlong" :),
        }) );
        set("atman", 1000);
        set("max_atman", 1000);
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 100);
        set("mana", 1000);
        set("max_mana", 1000);
        set("combat_exp", 10000000);
        set("score", 10000);
        set_skill("blade", 200);
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 150);
        set_skill("literate", 200);
        set_skill("parry", 150);
        set_skill("magic", 150);
        set_skill("move",150);
        set_skill("dragon-blade", 150);
        set_skill("huanlong",150); 
        set_skill("serpentforce", 150);
        set_skill("dragon-steps",150);
        set_skill("flying-dragon",150);
        map_skill("blade", "dragon-blade");
        map_skill("parry", "dragon-blade");
        map_skill("force", "serpentforce");
        map_skill("dodge","dragon-steps");
        map_skill("unarmed", "flying-dragon");
        map_skill("magic","huanlong");
        create_family("��������", 1, "��ʿ");
        setup();
        carry_object(__DIR__"obj/dragon-blade")->wield();
        carry_object(__DIR__"obj/dragon-cloth")->wear();

}


void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say ����ʿ�����Ѿ��չ��˵��ӣ���������ͽ�ˡ�");
        }
}

void do_recruit(object ob)
{
       if( ob->query("betrayer") > 1 )
                command("say ������������������ͽΪ��,�������뿪�ɡ�");
        else if(ob->query("m_success/����")){
                ob->set("class","dragon");
                command("say �����㲻��������������������ķ��ϣ��Ҿ�����Ϊͽ�ɣ�\n");
                command("rumor �����˳ɹ��س�Ϊ���������󡱵ĵ����ˣ�����\n");
                command("recruit " + ob->query("id") );
          }
         else
         command("say �������ɱ���������,֤�����Ǹ���ʿ,�Ҿ��������ˣ�\n");
        
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                add("apprentice_availavble", -1);
                return 1;
        }
}

int accept_fight(object me)
{
        if( (string)me->query("class")=="dragon" )
                command("say ʦ������ô�ܺ���һ���ʶ�أ�");
        else
                command("say ����ʿ������Ը�������������������뿪�ɡ�");

        return 0;
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","��������--������");
                return ;
          } else if ( exp <= 128000 ) {
                  student->set("title","��������--�����ſ�");
                  return ;
          } else if ( exp <= 512000 ) {
                 student->set("title","��������--������ʿ");
                  return ;
          } else if ( exp <= 1536000 ) {
                  student->set("title","��������--������ʿ");
                  return ;
          } else if ( exp <= 3456000 ) {
                 student->set("title","��������--������ʿ");
                 return ;
          } else if ( exp <= 5187000 ) {
                 student->set("title","��������--������ʿ");
                 return ;
          } else if ( exp <= 26244000 ) {
                 student->set("title","��������--������ʿ");
                 return ;
          } else
                student->set("title","��������--������ʿ");
                return ;

}


