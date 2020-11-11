
// add by atu for LSFY 2000/01/10
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("仙鹤花纹", ({ "xlidxhe"}) );
        set("gender", "男性" );
        set("age", 34);
        set("long",
                "这是全身都罩在黑纱中的神秘人，全身散发着一股阴森的气息。\n");
        set("max_kee", 550000);
        set("max_gin", 35000);
        set("max_sen", 35000);
        set("combat_exp", 4000000);
        set("attitude", "friendly");
        set("title", "");

       set("cps", 100);
       set("agi", 100);
       set("cor", 100);

       set("no_see", 1);

        set_skill("dodge", 500);
        set_skill("move", 500);
        set_skill("unarmed",500);
        set_skill("iron-cloth",500);
        set_skill("parry", 500);
        set_skill("force",500);
        set_skill("literate", 500);
        set_skill("wuzheng-force", 500);
        set_skill("bat-blade", 150);
        set_skill("blade", 150);
        set_skill("meng-steps", 500);

       map_skill("force", "wuzheng-force");
       map_skill("dodge", "meng-steps");
       map_skill("move", "meng-steps");
       map_skill("blade", "bat-blade");
       map_skill("parry", "bat-blade");

       set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "blade.shiwanshenmo" :),
                (: perform_action, "blade.shiwanshenmo" :),
                (: perform_action, "dodge.huanyingqianchong" :),
        }) );
        setup();
        carry_object("/obj/weapon/blade")->wield();
}

void init()
{
	add_action("do_souxun", "souxun");
}

void do_souxun()
{
	object me = this_player();
	object obj = this_object();
	object ob1 = present("ling pai",me);
	
	if (interactive(me) && objectp(ob1) && me->query("kf_working") 
		&& obj->query_temp("owner/id") == me->query("id"))
	{
		message_vision (HIR"$n大叫一声揭开伪装，露出本来面目。\n"NOR,me,obj);
		message_vision (HIM"$N终于找到了$n，立刻扑上去逮捕。\n"NOR,me,obj);
		obj->delete("no_see");
        obj->kill_ob(me);
        me->kill_ob(obj);
	}
}

int heal_up()
{
        if( environment()) 
        {
                call_out("leave", 700);
                return 1;
        }
        
        return ::heal_up() + 1;
}

void leave()
{
	command("rumor "+this_object()->query_temp("owner/name")+"负责搜寻逮捕的"+this_object()->query("name")+"逃跑了。");
    destruct(this_object());
}
// int active_died()
void die()
{
    object me = this_object()->query_temp("last_damage_from");
        	
    if (!objectp(me))
    {
        ::die();
        return;
    }
    // 如果是用其他如大内等杀的，要做如此转换
    if (!userp(me))
        me = find_player(geteuid(me));

		message_vision(HIC+""+this_object()->query("name")+"倒在地上，死了。\n"NOR,me);

        if (me->query("kf_working") && this_object()->query_temp("owner/id") == me->query("id")) 
        {
	        me->set_temp("kf_finish",1);
        }
		else
		{
            message_vision(HIC "\n由于$N你乱杀人，官府决定处罚你：\n"
                + chinese_number(500) + "点实战经验，\n"
                + chinese_number(200) + "点潜能，\n"
               + chinese_number(10) + "点评价作为惩罚。\n" NOR, me);
            me->add("combat_exp", -500);
            me->add("potential", -200);
            me->add("pot_deposit", -200);
            me->add("score",-10);			
		}

        me->add("MKS", 1);
        destruct(this_object());
}
