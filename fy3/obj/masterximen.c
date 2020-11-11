// servant.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int test_array();
void create()
{
        int cox;
        cox=30000+random(30000);
        set_name("西门吹雪", ({ "master ximen", "ximen", "master" }) );
        set("title", "万梅庄主");
        set("gender", "男性");
        set("age", 34);
        set("long",
"西门吹雪乃是当代绝顶高手之一．剑法已经到达了＂无剑＂的境界．．\n"
               ); 

        set("attitude", "peaceful");
        set("hit_always_on", 1);
        set("no_parry", 1);
        set("combat_exp", 100000000);
        set("agi",25);
        set("int",40);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hunranyijian" :),
                (: perform_action, "dodge.feitiantui" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: test_array :),
                (: test_array :),
                (: test_array :),
                (: test_array :),
                (: test_array :),
                 HIR"西门吹雪冷冷的盯着叶孤城,这种神态从来没有在他身上出现过！\n"NOR
        }) );
        set("str", 30);
        set("int", 30);
        set("cor", 300);
        set("cps", 30);
        set("con", 30);
              set("force_factor", 300);
        set("force", 4000);
        set("max_force", 2200);
        set("max_gin",999999);
        set("max_sen",999999);
        set("kee",cox);
              set("eff_kee",cox);
             set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 150);
        set_skill("parry", 100);
        set_skill("dodge", 80);
        set_skill("throwing", 50);
	 set_skill("move", 150);

        set_skill("doomforce", 100);
        set_skill("doomstrike", 100);
        set_skill("doomsteps", 90);
	 set_skill("doomsword",120);

        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("sword", "doomsword");
        map_skill("dodge", "doomsteps");



        setup();

        carry_object("/d/wanmei/npc/obj/xuejian")->wield();
        carry_object("/d/wanmei/npc/obj/cloth")->wear();
}

void killed_enemy(object who)
{
        command("say 叶、孤、城！你今日之败,只是存必死之心！今日真正败者,是我！\n");
}

void die()
{
        object ob;
        ob=new("/obj/guardleader");
        command("chat 我西门吹雪今日败于叶孤城之手,心服口服！\n");
        message_vision("西门吹雪仰天长笑,化作一道剑气冲天而起,消失不见了！\n", this_object());
        ob->ccommand("chat 叶孤城胜！");
        destruct(this_object());
}

int test_array()
{
          message_vision(HIC"西门吹雪凝神应战！\n"NOR, this_object());
}

