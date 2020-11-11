// taolord.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name( "丁白云" , ({ "master ding", "master", "ding" }) );
        set("nickname",HIB "晴空白云" NOR);
        set("gender", "女性");
	set("class","sanqing");
    set("reward_npc", 1);
    set("difficulty", 150); 
        set("age", 46);
        set("long",
                
"丁白云是丁乘风的师妹，也是丁乘风的亲妹妹。丁白云年轻时遭白天羽抛弃，\n"
"伤心欲绝，于是设计杀了白天羽后到此出家。\n");

        set("combat_exp", 100000000);
        set("score", 200000);

        set("force", 20000);
        set("max_force", 10000);
        set("force_factor", 30);

        set("atman", 14000);
        set("max_atman", 14000);

        set("mana", 40000);
        set("max_mana", 20000);
        set("mana_factor", 5);

        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我三清宫为对抗邪魔外道所创的内功心法。\n",
                "三清宫": 
"我三清宫自张天师开山立派至今，世世代代皆以降妖伏魔为己任。\n"
        ]) );

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );

        create_family("三清宫", 6, "女主持");

        set_skill("literate", 150);
        set_skill("magic", 1000);
        set_skill("force", 150);
        set_skill("spells", 1000);
	set_skill("scratching",1000);
	set_skill("move", 300);
        set_skill("dodge", 500);
        set_skill("gouyee", 500);
        set_skill("notracesnow", 1000);
        set_skill("taoism", 1000);
        set_skill("necromancy", 1000);
	set_skill("scratmancy",1000);

        map_skill("spells", "necromancy");
        map_skill("move", "notracesnow");
        map_skill("dodge", "notracesnow");
        map_skill("scratching", "scratmancy");

        set_temp("apply/dodge", 20);
        set_temp("apply/armor", 20);

        setup();

        carry_object(__DIR__"obj/sword2")->wield();
        carry_object(__DIR__"obj/robe2")->wear();
        carry_object(__DIR__"obj/hat2")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}

void attempt_apprentice(object me)
{
	if( me->query("class") && me->query("class") != "sanqing")
	{
	command("stare");
	command("say 你已经有自己的门派了！\n");
	}
	else if( me->query("national") == "藏族" )
	{
	command("smile");
	command("say 很好！我三清宫就靠你来发扬光大了！\n");
            command("recruit " + me->query("id") );
	}
	else
	command("say 我三清只收藏族之人！\n");
}

void do_recruit(object ob)
{
                command("say 嗯... 想入我三清宫？也好....");
                command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "sanqing");
}

 
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("level");
        if( exp <= 10 ) {
                student->set("title","三清宫小徒");
                return ;
        } else if ( exp <= 20 ) {
                student->set("title","三清宫圣者");
                return ;
        } else if ( exp <= 30 ) {
                student->set("title","三清宫施恩者");
                return ;
        } else if ( exp <= 40 ) {
                student->set("title","三清宫道尊");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","三清宫神尊");
                return ;
        } else if ( exp <= 60 ) {
                student->set("title","三清宫菩萨");
                return ;
        } else if ( exp <= 70 ) {
                student->set("title","三清宫副主持");
                return ;
        } else
                student->set("title","三清宫主持");
                return ;

}
