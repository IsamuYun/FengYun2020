#include <ansi.h>
inherit NPC;
int showpower();
int wieldblade();
void create()
{
        set_name("丁鹏", ({ "ding peng" }) );
        set("gender", "男性");
    set("reward_npc", 1);
    set("difficulty", 50); 

	set("age",35);
        set("combat_exp", 1000000);
        set("long",
		"丁鹏已经变了，已经不是以前那个冲动无知的年轻人。现在不但
成熟而稳重，而且带着种超越一切的自信。\n"
	);
	set("max_force",3000);
	set("force",3000);
	set("force_factor",30);
	set_skill("move",100);
        set_skill("parry", 250);
	set_skill("blade",250);
	set_skill("dodge",1);
	set_skill("shenji-steps",50);
	map_skill("dodge","shenji-steps");
	set_skill("shenji-blade",100);
	map_skill("blade","shenji-blade");
	map_skill("parry","shenji-blade");
        set("chat_chance", 15);
	set("arrive_msg","施施然走过来");
	set("leave_msg","已走出很远，看来还是在漫步，可是一瞬间就已走出很远");
        set("chat_msg", ({
	(: random_move :),
       (: random_move :),
        (: random_move :),
     (: random_move :),
	(: showpower :)
        }) );




        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: wieldblade  :),
        }) );
        setup();
	carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/wandao");
}
int showpower()
{
command("wield moonblade");
tell_object(environment(this_object()),"可是这把刀已出鞘。刀光一闪，
带着种奇异的弧度，往路边的青石劈了下去。那块看来比钢铁
还硬的青石，竟然在刀光下被劈成两半！\n");
command("unwield moonblade");
return 1;
}
int wieldblade()
{
command("wield moonblade");
perform_action("blade.jichulianhuan");
command("unwield moonblade");
return 1;
}
