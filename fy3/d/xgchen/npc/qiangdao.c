inherit NPC;
#include <ansi.h>
void move();

void create()
{
        set_name(BLU "蒙面黑衣人" NOR, ({ "heiyi ren", "robber", "ren", "heiyi" }));
        set("gender", "男性");
        set("age", 28);
        set("long", "他是一个专靠打劫营生的盗贼。\n");
        
        set("combat_exp",1000);
        set("score", -10);

        set("attitude", "peaceful");
        set("no_arrest", 1)
        set_skill("sword", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 1000000);
        set_temp("apply/defense", 300);
        
         set("str",20);
         set("no_arrest",1);
         set("per",1);
         set("cps",90);
         set("agi",80);
         set("food",400);
         set("water",400);

        setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{
        call_out("leave",150);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "神秘人钻进路边的杂草，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",10);
}

void die()
{
        object me = this_object()->query_temp("last_damage_from");
        object corpse, money;      
        int kar, exp, pot,reb;
        reb = me->query("reborned");  // update by Tiandi 200712031145
        kar = random(me->query("kar"));
//        shen1 =  300+random(100);
//        shen2 =  random(50);
        exp = 500 + random(700);
        exp = exp + exp/5*reb;
        pot = 100 + random(100);
        pot = pot + pot/5*reb;

        message_vision(HIR "\n神秘人倒在地上，挣扎了几下就死了。\n" NOR,me);
        if (me->query("kill_qiangdao") == 1 && this_object()->query_temp("owner/id") == me->query("id")) {
                message_vision(HIW "$N被奖励了：\n"
                + chinese_number(exp) + "点实战经验，\n"
                + chinese_number(pot) + "点潜能，\n"
               + chinese_number(2) + "点评价。\n" NOR, me);
                me->add("combat_exp", exp);
                me->add("potential", pot);
              me->add("score", 2);
              me->add("killhyr",1);
                me->delete("quest");
                me->delete("kill_qiangdao");
                }
        else {
                message_vision(HIC "\n由于$N你乱杀人，官府决定处罚你：\n"
                + chinese_number(200) + "点实战经验，\n"
                + chinese_number(100) + "点潜能，\n"
               + chinese_number(5) + "点评价作为惩罚。\n" NOR, me);
                me->add("combat_exp", -200);
                me->add("potential", -100);
              me->add("score",-5);
                }
        me->add("MKS", 1);

        destruct(this_object());
}
