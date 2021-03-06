#include <ansi.h>
inherit NPC;
void create()
{
        set_name("山西土匪", ({ "tufei", "shanxi tufei" }) );
        set("long",
"一个满脸伤疤加横肉的家伙。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
        set("per", 1);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 100000+random(4000000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                "山西土匪喝道：今天老子要钱又要命！！\n",
                "山西土匪笑道：贼娘的，去死吧！\n",
		(: random_move :),
        }) );
        set("chat_chance", 80);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set_skill("unarmed", 70+random(200));
        set_skill("blade", 70+random(200));
        set_skill("parry", 70+random(200));
        set_skill("dodge", 70+random(200));
        set_skill("move", 100+random(200));

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 30+random(400));
        set_temp("apply/move", 100);

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/guiblade")->wield();
}
void init()
{
        remove_call_out("hunting");
	if(!environment()->query("no_fight"))
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
		if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}
void die()
{
        object me = this_object()->query_temp("last_damage_from");
        object corpse, money,book,owner;      
        int kar, exp, pot;
        kar = random(me->query("kar"));
        exp = 100 + random(200);
        pot = 50 + random(50);
		me = this_object()->query_temp("last_damage_from");
		if(owner = me->query("possessed"))  
		me = owner;

        message_vision(HIR "\n山西土匪倒在地上，挣扎了几下就死了。\n" NOR,me);
                message_vision(HIW "$N被奖励了：\n"
                + chinese_number(exp) + "点实战经验，\n"
                + chinese_number(pot) + "点潜能，\n"
               + chinese_number(2) + "点评价。\n" NOR, me);
                me->add("combat_exp", exp);
                me->add("potential", pot);
              me->add("score", 2);
        me->add("MKS", 1);
        switch(random(3))
        {
        case 1:
        book = new("/obj/money/thousand-cash.c");
        message_vision("$N的包袱里好像多了点什么东西。\n",me);
        book->move(me);
      break;
        case 2:
        book = new("/d/wiz/fyup/obj/hongbao.c");
        message_vision("$N的包袱里好像多了点什么东西。\n",me);
        book->move(me);
        break;
        default:
        break;
       }
        destruct(this_object());
}

