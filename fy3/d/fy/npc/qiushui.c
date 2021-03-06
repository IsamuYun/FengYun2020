inherit NPC;
#include <ansi.h>
int send_shu();
void create()
{
        set_name("萧秋水", ({ "qiushui", "xiao qiushui" }) );
set("long","一代大侠，一脸正气，为寻找红粉知己唐方而重出江湖。\n");
        set("nickname", RED"一代大侠"NOR);
        set("attitude", "heroism");
        create_family("神州结义",1,"盟主");
set("str", 80);
        set("cor", 80);
        set("cps", 80);
        set("agi",80);
	set("int",80);
        set("combat_exp", 10000000);
	 set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 30);
       set("inquiry", ([
"权力帮" : (: send_shu :),
"quanli" : (: send_shu :), ]));
set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
    "萧秋水问道：“这位小兄弟，是否看见唐方？\n",
    "萧秋水问道：“这位小姑娘，是否看见唐方？\n",
     (: random_move :),        }) );
        set("chat_chance", 80);

set("chat_msg_combat", ({
                (: perform_action, "sword.jingtianyijian" :),
  (: perform_action, "dodge.hongyeluanfei" :),
  (: perform_action, "sword.jingtianyijian" :),
   (: exert_function, "junwang" :),
 (: exert_function, "jinduan" :),
        }) );
	set_temp("apply/damage",500);
	set_skill("sword",150);
	set_skill("force",100);
        set_skill("parry",120);
        set_skill("dodge",100);
	set_skill("noloveforce",120);
       set_skill("literate",100);
	set_skill("huanhua-sword",200);
       set_skill("huanhua-steps",200);
	map_skill("dodge","huanhua-steps");
	map_skill("force","noloveforce");
	map_skill("sword","huanhua-sword");
        setup();

        carry_object("/obj/shu");
        carry_object("/obj/ruxue")->wield();
       carry_object("/obj/oldskin")->wear();
}
void attempt_apprentice(object me)
{
        if(me->query_temp("for_xiao"))
	{
        command("say 好吧，既然是唐方的朋友，我收你吧，一同抗金救岳元帅！\n");
       command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("shake");
        command("say 你别开玩笑的，我哪有资格收你为徒。\n");
	}
	}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shenzhou");
}

void init()
{add_action("do_look","look");

        }
int accept_object(object me, object obj)
{
	if(obj->query("for_xiao"))
	{
	me->set_temp("for_xiao",1);
        command("ack");
        command("say 这是唐方的戒指，看样子唐方想让我收你为徒。\n");
        command("recruit " + me->query("id") );
	return 1;
	}
	return 0;
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
      if( exp <= 4000 ) {
student->set("title","神州结义弟子");
                return ;
        } else if ( exp <= 10000 ) {
           student->set("title","神州结义帮众");
                return ;
 } else if ( exp <= 18000 ) {
student->set("title","神州结义小侠");
                return ;
 } else if ( exp <= 30000) {
student->set("title","神州结义香主");
                return ;
        } else if ( exp <= 60000 ) {
       student->set("title","神州结义副坛主");
                return ;
        } else if ( exp <= 120000 ) {
             student->set("title","神州结义坛主");
                return ;
        } else if ( exp <= 300000 ) {
                student->set("title","神州结义副旗主");
                return ;
        } else if ( exp <= 800000 ) {
                student->set("title","神州结义旗主");
                return ;
        } else if ( exp <= 2000000 ) {
          student->set("title","神州结义总管");
                return ;
        } else if ( exp <= 6000000 ) {                student->set("title","神州结义护法");
                return ;
        } else if ( exp <= 12000000 ) {                student->set("title","神州结义总护法");
                return ;
        } else                student->set("title","神州结义副盟主");
                return ;

}
int accept_fight(object me)
{
        command("fear");
        command("say 在下自知不是对手，不用比了。");
        return 0;
}
int do_look(string arg)
{
if (arg == "oldman" )
{
write("一个负责扫地的老头。\n");
write("他看起来约四十多岁。\n");
write("武功看起来好象略有小成，出手似乎极轻。\n");
return 1;
}
return 0;
}
int send_shu()
{
        object shu,me;
	me = this_player();
say("萧秋水说道：这位" + RANK_D->query_respect(me) +"，是尉迟二派你来的吧，你把这封信给他，他自会明白。\n");
	if( shu = present("shu", this_object())) {;	;	       shu->move(me);
message_vision(HIY "$N将一封信交给了$n，又开始扫地了。\n" NOR, this_object(), me );
	}
        return 1;
}
