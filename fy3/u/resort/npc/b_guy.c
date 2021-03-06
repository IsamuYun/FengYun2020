#include <ansi.h>
inherit NPC;

void create()
{
        set_name("白袍公", ({ "oldguy" }) );
        set("gender", "男性" );
    set("reward_npc", 1);
    set("difficulty", 20); 

        set("age", 65);
        set("str", 46);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);

        set("attitude", "peaceful");

        set("force_factor", 10);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);

        set("long",     "白袍公除了下棋，什么也不做\n");


        set("combat_exp", 999999);

        set_skill("unarmed", 120);
        set_skill("throwing", 100);
	set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);

        set_skill("qidaoforce", 100);
        set_skill("meihua-shou", 80);
        set_skill("fall-steps", 10);

        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");

        setup();

        carry_object(__DIR__"obj/bqi")->wield();
        carry_object(__DIR__"obj/wcloth")->wear();
}

int accept_object(object who, object ob)
{
  object silk;
  if(ob->query("id") == "goodqipan")
        {
           command("smile");
           command("say 这位" + RANK_D->query_respect(who)+ "，谢谢你了老夫一直想找到它，这是给你的奖励！\n");
silk = new("/questobj/big");
silk->move(who);
        tell_object(who,"白袍公给你一个"+silk->query("name")+"。\n");
//silk->move(this_object());
//command("give jin-nang to " + who->query("id"));
who->add("bigtasks",1);
        return 1;
        }
        tell_object(who,"白袍公说道：这不是我想要的。\n");
        return 0;
}
