inherit NPC;
#include <ansi.h>
void create()
{
        set_name("������", ({ "eagle gulina", "gulina"}) );
        set("gender", "Ů��");
    set("reward_npc", 1);
    set("difficulty", 90); 

        set("age", 19);
        set("long","tt"); 
        set("vendetta_mark","pker");
        set("attitude", "heroism");
        set("nickname", HIY"�ϳ��ӥ"NOR);
        set("combat_exp", random(5000000)+5000000);
        set("eff_gin", 100000);
        set("eff_kee", 100000);
        set("eff_sen", 100000);
        set("max_gin", 100000);
        set("max_kee", 100000);
        set("max_sen", 100000);
        set("gin", 100000);
        set("kee", 100000);
        set("sen", 100000);
        set("str", 60);
        set("cps", 25);
        set("agi", 40);
        set("max_mana", 1000);
        set("mana", 1000);
        set("chat_chance_combat", 20);
        set("chat_msg_combat" , ({ /* sizeof() == 2 */
                "��ͻȻ�о�����������ζ....\n",
                (: cast_spell,       "freeze" :)
        }) );
        set("chat_chance", 30);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set_skill("spells", 100);
        set_skill("mapo", 100);
        set_skill("unarmed", random(100)+100);
        set_skill("dodge", random(100)+100);
        set_skill("parry", random(100)+100);
        set_skill("move", random(100)+100);
        map_skill("spells", "mapo");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

void kill_ob(object ob)
{
        ob->set("max_force",0);
        ::kill_ob(ob);
}


