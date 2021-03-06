#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("张军", ({ "master oldgun", "master","oldgun" }) );
        set("long",
                "风云中最菜鸟的人，功夫有多低没人知道\n");
	set("nickname", GRN"我是流氓我怕谁"NOR);
        create_family("玩家联盟会",2,"主席");
	 set("str", 1);
        set("cor", 1);
        set("cps", 1);
	set("agi",1);
	set("int",1);
       set("attitude","friendly");
        set("max_force", 100);
        set("force", 100);
        set("force_factor", 1);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                        }) );
        set("combat_exp", 10000000);
	set_temp("apply/damage",500);
        set_skill("unarmed", 50);
	set_skill("sword",50);
	set_skill("force",50);
        set_skill("parry",50);
        set_skill("dodge",50);
	 set_skill("move",50);
	set_skill("literate",50);
	set_skill("spells",50);
       set_skill("magic",50);
     set_skill("hammer",50);
     set_skill("iron-cloth",50);
    set_skill("staff",50);
    set_skill("blade",50);
    set_skill("stealing",500);
            set("chat_chance", 4);
set("chat_msg", ({
                "张军说道：向我开炮。\n",
                "张军说道：你不拜我为师，别后悔。\n",
      "张军说道：在风云里受我欺压的杀人狂，现在拿我出气吧。\n",  }) );

    setup();

        carry_object(__DIR__"obj/hengbing")->wield();
      carry_object("/obj/glass");
}

void attempt_apprentice(object me)
{
        command("recruit " + me->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "oldgun");
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
                student->set("title","玩家联盟会会员");
                return ;
        } else if ( exp <= 10000 ) {
                student->set("title","玩家联盟会注册会员");
                return ;
        } else if ( exp <= 18000 ) {
                student->set("title","玩家联盟会小管家");
                return ;
        } else if ( exp <= 30000) {
                student->set("title","玩家联盟会管家");
                return ;
        } else if ( exp <= 60000 ) {
                student->set("title","玩家联盟会小长老");
                return ;
        } else if ( exp <= 120000 ) {
                student->set("title","玩家联盟会中长老");
                return ;
        } else if ( exp <= 300000 ) {
                student->set("title","玩家联盟会大长老");
                return ;
        } else if ( exp <= 800000 ) {
                student->set("title","玩家联盟会老长老");
                return ;
        } else if ( exp <= 2000000 ) {
                student->set("title","玩家联盟会左护法");
                return ;
        } else if ( exp <= 6000000 ) {
                student->set("title","玩家联盟会右护法");
                return ;
        } else if ( exp <= 12000000 ) {
                student->set("title","玩家联盟会总护法");
                return ;
        } else
                student->set("title","玩家联盟会小秘");
                return ;
}
