#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
inherit F_MASTER;
void create()
{
        set_name("����ϼ", ({ "sqx" }) );
set("long","���������İ��ɣ�Ȩ�����������\n");
set("nickname", HIR"����"NOR);
    set("reward_npc", 1);
    set("difficulty", 150); 

        create_family("Ȩ����",2,"����");
        set("gender", "Ů��");
set("age", 20);
        set("str", 20);
        set("cor", 20);
        	  set_temp("kf_tufei",58);
        set("pursuer", 1);
set("cps", 20);
        set("agi",20);
        set("int",20);
        set("attitude","friendly");
        set("max_force", 10000);
        set("force", 10000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({(: perform_action, "sword.yueyinghanshan" :),
                  (: perform_action, "dodge.changmengwuchen" :),      }) );
                 set("inquiry", ([
"����": "����������ȴ�Ӯ����˵�� \n",
        ]) );
        set("combat_exp", 1000000);
        set_temp("apply/damage",500);
        set_skill("unarmed", 150);
        set_skill("force",80);
        set_skill("parry",70);
        set_skill("dodge",120);
        set_skill("move",100);
        set_skill("literate",70);
        set_skill("wuchenforce",70);
        set_skill("sword",180);
        set_skill("hanshan-sword",150);
        set_skill("wuchen-steps",70);
        map_skill("force","wuchenforce");
        map_skill("sword","hanshan-sword");
        map_skill("dodge","wuchen-steps");
            set("chat_chance", 2);
          set("chat_msg", ({
                "����ϼ˵����������أ�ʮ����ħ��\n",
                "����ϼ˵�������������û����Ҳ��֪���������١�\n",
        }) );

    setup();

             carry_object("/obj/glass");
carry_object("/obj/weapon/sword")->wield();
}

void attempt_apprentice(object me)
{
        command("recruit " + me->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "quanli");
}
void init()
{
        add_action("give_quest", "quest");
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 4000 ) {
                student->set("title","Ȩ�������");
                return ;
        } else if ( exp <= 10000 ) {
                student->set("title","Ȩ����С��ħ");
                return ;
        } else if ( exp <= 18000 ) {
                student->set("title","Ȩ�����ħ");
                return ;
        } else if ( exp <= 30000) {
                student->set("title","Ȩ����С��ħ");
                return ;
        } else if ( exp <= 60000 ) {
                student->set("title","Ȩ������ħ");
                return ;
        } else if ( exp <= 120000 ) {
                student->set("title","Ȩ����С����");
                return ;
        } else if ( exp <= 300000 ) {
                student->set("title","Ȩ��������");
                return ;
        } else if ( exp <= 800000 ) {
                student->set("title","Ȩ������С�ܼ�");
                return ;
        } else if ( exp <= 2000000 ) {
                student->set("title","Ȩ�����ܼ�");
                return ;
        } else if ( exp <= 6000000 ) {
                student->set("title","Ȩ���︱�ܹ�");
                return ;
        } else if ( exp <= 12000000 ) {
                student->set("title","Ȩ�����ܹ�");
                return ;
        } else
                student->set("title","Ȩ���︱����");
                return ;
}
int accept_fight(object me)
{
        if(me->query("family/family_name") == query("family/family_name"))

        {
        command("say �ã���Ӯ���ң���Ϳ���ȥ�Ұ����ˣ�\n");
        return 1;
        }
        else
        {
        command("say û�գ�\n");
        return 0;
        }
}
void win_enemy(object loser)
{
command("say ���书���а���\n");
}
void lose_enemy(object winner)
{
command("say ��Ȼ�����������ȥ�Ұ����ˡ�\n");
winner->set_temp("won_kijy",1);
}