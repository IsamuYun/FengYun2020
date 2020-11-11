// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int test_array();
void create()
{
        int cox;
        cox=30000+random(30000);
        set_name("叶孤城", ({ "master ye", "master", "master gucheng" }) );
        set("nickname", HIW "白云城主"NOR);
        set("gender", "男性" );
        set("age", 34);
        set("str", 30);
        set("hit_always_on", 1);
        set("no_parry", 1);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
                (: test_array :),
                (: test_array :),
                (: test_array :),
                (: test_array :),
                (: test_array :),
                  HIW"叶孤城盯着西门吹雪,这种神态从来没有在他身上出现过！\n"NOR
        }) );
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 300);
        set("max_kee",cox);
        set("max_gin",999999);
        set("max_sen",999999);
        set("eff_kee",cox);
        set("kee",cox);
        set("long",
"
白云城主以前充满了尊荣和光采．．．．
\n"
	);
        create_family("白云城", 2, "城主");

        set("combat_exp", 100000000);
        set("score", 200000);

        set_skill("move", 100);
	set_skill("daode",150);
        set_skill("parry", 120);
        set_skill("dodge", 80);
        set_skill("force", 40);
        set_skill("literate", 60);
	set_skill("sword", 100);
	set_skill("unarmed",40);
	set_skill("changquan",100);
        set_skill("feixian-steps",60);
        set_skill("feixian-sword",80);
	set_skill("jingyiforce",60);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");


        setup();
        carry_object("/d/stone/npc/obj/whitecloth")->wear();
        carry_object("/d/stone/npc/obj/bsword")->wield();
        carry_object("/d/stone/npc/obj/bcloth")->wear();

}


void killed_enemy(object who)
{
        command("say 西门吹雪,你已有情,不再是一个剑神了！倘若无情,胜负犹未可知！\n");
}

void die()
{
        object ob;
        ob=new("/obj/guardleader");
        command("chat 叶孤城今日败于西门吹雪之手,死于西门吹雪之手,死而无憾！\n");
        message_vision("叶孤城仰天长笑,缓缓倒在地上！\n", this_object());
        ob->ccommand("chat 西门吹雪胜！");
        destruct(this_object());
}

 
int test_array()
{
          message_vision(HIC"叶孤城凝神应战！\n"NOR, this_object());
}

