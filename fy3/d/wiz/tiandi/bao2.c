// bao.c
// by xgchen@zzfy
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_me();
int ask_stop();

void create()
{
        set_name("林忠平", ({ "lin zhongping", "lin" , "zhongping"}) );
        set("gender", "男性" );
        set("age", 54);
        set("long",
                "这就是大名鼎鼎的刑部尚书，铁面无私，断案如神。\n");
	 set("max_force", 50000);
        set("force", 50000);
        set("combat_exp", 40000000);
        set("attitude", "friendly");
        set("title", "朝廷刑部尚书");
        set("nickname", HIW"铁面无私"NOR);
        set_temp("apply/attack",300);
        set_temp("apply/damage",30000);
        set_skill("dodge", 500);
        set_skill("unarmed",500);
        set_skill("parry", 500);
        set_skill("force",500);
        set_skill("literate", 500);
        set("str", 500);

        setup();
        carry_object(__DIR__"obj/mangpao")->wear();
       add_money("gold",300);
	set("inquiry", ([
		"任务": (: ask_me :),
		"捕快": (: ask_me :),
		"work": (: ask_me :),
		"效力": (: ask_me :),
		"quest": (: ask_me :),
		"放弃": (: ask_stop :),
		"stop": (: ask_stop :),
		]) );
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_answer", "answer");
}
int ask_me()
{
        object ob,me;
        me = this_player();
        if (!(int)me->query("kaifengfu")){
        command("say 这位"+ RANK_D->query_respect(me)
               + "若有意为朝廷效力，不妨到殷大人那里报名！\n");
        return 1;
         }
        command("say 你身为朝廷官员，不能白吃国家俸禄，须得努力工作(work)才是啊。\n每次办差归来须如实向本府汇报(finish)。");
        return 1;
}
int ask_stop()
{
        object ob,me;
        me = this_player();
        if(me->query_condition("kf_stop") > 0)
        {
        	return notify_fail("什么？\n");
        }
        
        if (!(int)me->query("kf_working")){
        command("say 这位"+ RANK_D->query_respect(me)
               + "若不愿意为朝廷效力，本府也不勉强！\n");
        return 1;
         }
        command("say 你真的没有抓到罪犯吗？(answer yes或answer no)");
        me->set_temp("kf_stop",1);
        return 1;

}
int do_answer(string arg)
{
        object ob,me;
        me = this_player();
        if (!me->query_temp("kf_stop") || me->query_condition("kf_stop") > 0)
             return notify_fail("什么？\n");
        if (!arg || (arg !="yes"&&arg !="no")){
        command("say 你吞吞吐吐的在说什么啊！\n");
        return 1;
         }
        if (arg =="no")
        {                               //113
        command("say 罪犯既已抓到了你还要放弃什么？\n");
        return 1;
         }
        message_vision (BLU"林忠平不由大怒，拍案而起。\n"NOR,me);
        command("say 大胆！汝身为朝廷官员，食国家俸禄，办差如此不力，休怪本府无情。");
        command("say 来啊，与我重责二十大板。");
        message_vision (HIB"四下里顿时拥出几个如狼似虎的衙役将"+me->query("name")+"按翻在地。\n"NOR,me);
        me->delete_temp("kf_stop");
        me->add("combat_exp", -1000);
        me->apply_condition("kf_stop", 10+random(10));
        me->set("startroom", base_name(environment(me)));
        return 1;
}
