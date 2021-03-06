inherit NPC;
void use_poison();

void create()
{
        set_name("白蟾", ({ "bai chan" }) );
        set("race", "野兽");
        set("age", 4);
        set("yes_carry", 1);
        set("long", "一只罕见的白色蟾蜍，常年生活在温泉水中。\n");

        set("limbs", ({ "头部", "身体", "四肢", "眼睛" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 100);
        set_skill("unarmed",100);
        set("combat_exp", random(600000));
        set("bellicosity", 300 );
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );

        setup();
        carry_object(__DIR__"obj/chanchumo");

}
void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        tell_object(ob,
"你被白蟾的毒液喷中,觉得一阵麻木。\n");
                ob->apply_condition("unknown", 
                (int)this_player()->query_condition("unknown")
                + random(3)+3);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}