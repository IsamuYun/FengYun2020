// referee.c

inherit NPC;
#include <ansi.h>;

//int do_bihua();
string ask_me();
//int do_halt();

void create()
{
        set_name("公平子", ({ "gongping zi", "zi", "referee" }) );
        set("gender", "男性");
        set("age", 35);
        set("long",
                "这是一位仙风道骨的中年道人，早年云游四方，性好任侠，公正无私。\n");
        set("combat_exp",9000000);
        set("shen_type", 1);
        set_temp("kf_tufei",60);
              set("attitude", "friendly");

        set("apply/attack", 50);
        set("apply/defense", 50);

        set("max_kee", 8000);
        set("max_gin", 8000);
        set("max_sen", 8000);
        set("max_force", 8000);

        set_skill("force", 180);
        set_skill("unarmed", 100);
        set_skill("sword",180);
        set_skill("parry",280);
        set_skill("dodge", 280);

        set("inquiry", ([
                "比武大会"       : (: ask_me :),
        ]));

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}


void init()
{
        ::init();
        add_action("do_bihua", "bihua");
        add_action("do_bihua", "bi");
        add_action("do_bihua", "fight");
        add_action("do_halt", "halt");
        add_action("do_halt", "h");
}

string ask_me()
{
        object* ob;
        int i;
        ob = users();

        if ( !wizardp(this_player()) ) return "你无权召开比武大会！\n";

        for ( i=sizeof(ob); i>0; i-- ) {
                ob[i-1]->move("/d/fy/poemp");
        }

        return "好，现在比武大会正式开始，全体集合！\n";
}

int do_bihua(string arg)
{
        object ob1, ob2;
        object old_target;

        ob1 = this_player();

        if( !arg || arg=="" ) return 0;

        if ( arg == "gongping zi" || arg == "zi" || arg == "referee" )
           {
             command("say " + "你的武功还不够资格跟我比武！\n");
             command("smile");
             return 1;
            }

        if ( this_object()->query_temp("busy") )
                return notify_fail("已经有两个人在比武了。\n");

        if (!ob2 = present(arg,environment(ob1)) )
                return notify_fail("你想跟谁比武？\n");
        if (ob1 == ob2)    return notify_fail("你不能跟自己比武。\n");


        if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
                message_vision("\n$N对着$n说道"
                        + RANK_D->query_self(ob1)
                        + ob1->name() + "领教"
                        + RANK_D->query_respect(ob2) + "的高招ⅵ\n\n", ob1, ob2);
                if( objectp(old_target = ob1->query_temp("pending/fight")) )
                        tell_object(old_target, YEL + ob1->name() + "取消了和你比试的念头。\n" NOR);
                ob1->set_temp("pending/fight", ob2);
                tell_object(ob2, YEL "如果你愿意和对方进行比试请你也对" + ob1->name() + "("+(string)ob1->query("id")+")"+ "下一次 bihua 指令。\n" NOR);

                write(YEL "由於对方是由玩家控制的人物你必须等对方同意才能进行比试。\n" NOR);
                return 1;
        }

        ob1->delete_temp("halted");
        ob2->delete_temp("halted");

        remove_call_out("check");
        call_out("check",0, ob1, ob2);

//      ob1->set("kee",(int)ob1->query("max_kee"));
//      ob2->set("kee",(int)ob2->query("max_kee"));

        remove_call_out("fighting");
        call_out("fighting",2, ob1, ob2);

        return 1;
}

void fighting(object ob1, object ob2)
{
        ob1->fight_ob(ob2);
        ob2->fight_ob(ob1);
}

void check(object ob1, object ob2)
{
        this_object()->set_temp("busy",1);
        command("chat " + ob1->query("name")
                + "与" + ob2->query("name") + "，现在探花诗台上开始比武论剑！\n");
        call_out("observe",1,ob1,ob2);
}

int observe(object ob1,object ob2)
{
        object ob;

        if(ob1->is_fighting())
        {
                call_out("observe",1,ob1,ob2);
                return 1;
        }

        this_object()->delete_temp("busy");
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");

        if ( !present(ob1, environment()) )
        {
                command("chat " + ob1->query("name") + "落荒而逃了！\n");
                return 1;
        }

        if ( !present(ob2, environment()) )
        {
                command("chat " + ob2->query("name") + "落荒而逃了！\n");
                return 1;
        }

        if (ob1->query_temp("halted"))
         {
               ob1->delete_temp("halted");
               command("chat " + ob1->query("name") +
                       "中途放弃比武！\n");
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
               ob2->delete_temp("halted");
               command("chat " + ob2->query("name") +
                       "中途放弃比武！\n");
                return 1;
         }

        if ( ob1->query("kee")*2 > ob1->query("max_kee"))
        {
                if  (ob2->query("kee")*2 > ob2->query("max_kee")) {
                        command("chat " + ob1->query("name")
                                + "与" + ob2->query("name") + "比武不分胜负！\n");
                        return 1;
                }
                command("chat " + ob1->query("name")
                        + "比武战胜" + ob2->query("name") + "！\n");
                ob = new("clone/money/silver");
                ob->move(ob1);
        }
        else
        {
                command("chat " + ob2->query("name")
                        + "比武战胜" + ob1->query("name") + "！\n");
                ob = new("clone/money/silver");
                ob->set_amount(2);
                ob->move(ob2);
        }

        return 1;

}

int do_halt()
{
 object me = this_player();
if (me->is_fighting())
 me->set_temp("halted",1);
return 0;
}


