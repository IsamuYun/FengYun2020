#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("伏龙隐士", ({ "master fulong", "master", "fulong" }) );
        set("nickname", HIW "幻世伏龙"NOR);
        set("gender", "男性");
        set("reward_npc", 1);
        set("difficulty", 100); 

        set("age", 74);
        set("attitude", "peaceful");
        set("class", "dragon");
        set("apprentice_available", 3);
        set("student_title","居士");
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
        create_family("伏龙隐阁", 1, "居士");
        setup();
        carry_object(__DIR__"obj/dragon-blade")->wield();
        carry_object(__DIR__"obj/dragon-cloth")->wear();

}


void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本居士今天已经收够了弟子，不想再收徒了。");
        }
}

void do_recruit(object ob)
{
       if( ob->query("betrayer") > 1 )
                command("say 我向来不与你这种叛徒为友,你速速离开吧。");
        else if(ob->query("m_success/孽龙")){
                ob->set("class","dragon");
                command("say 看在你不惧生死，勇屠孽火巨龙的份上，我就收你为徒吧！\n");
                command("rumor 又有人成功地成为“伏龙隐阁”的弟子了！！！\n");
                command("recruit " + ob->query("id") );
          }
         else
         command("say 你如果能杀了孽火巨龙,证明你是个勇士,我就收下你了！\n");
        
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
                command("say 师傅我怎么能和你一般见识呢？");
        else
                command("say 本居士向来不愿意与人争斗，你速速离开吧。");

        return 0;
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","伏龙隐阁--入阁弟子");
                return ;
          } else if ( exp <= 128000 ) {
                  student->set("title","伏龙隐阁--阁内门客");
                  return ;
          } else if ( exp <= 512000 ) {
                 student->set("title","伏龙隐阁--唤龙居士");
                  return ;
          } else if ( exp <= 1536000 ) {
                  student->set("title","伏龙隐阁--斗龙居士");
                  return ;
          } else if ( exp <= 3456000 ) {
                 student->set("title","伏龙隐阁--降龙居士");
                 return ;
          } else if ( exp <= 5187000 ) {
                 student->set("title","伏龙隐阁--伏龙居士");
                 return ;
          } else if ( exp <= 26244000 ) {
                 student->set("title","伏龙隐阁--驾龙居士");
                 return ;
          } else
                student->set("title","伏龙隐阁--御龙居士");
                return ;

}


