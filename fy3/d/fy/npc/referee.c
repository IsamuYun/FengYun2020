// referee.c

inherit NPC;
#include <ansi.h>;
void create()
{
        set_name("公平子", ({ "gongping zi", "zi", "referee" }) );
        set("gender", "男性");
        set("age", 35);
        set("long",
                "这是一位仙风道骨的中年道人，早年云游四方，性好任侠，公正无私。\n");
        set("combat_exp",60000);
        set("shen_type", 1);
        set_temp("kf_tufei",60);
              set("attitude", "friendly");
         set("inquiry", ([
"比武大会": "想比武是吗？（answer）\n",
        ]) );
        set("apply/attack", 50);
        set("apply/defense", 50);

        set("max_kee", 800);
        set("max_gin", 800);
        set("max_sen", 800);
        set("max_force", 800);

        set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("sword",80);
        set_skill("parry",80);
        set_skill("dodge", 80);

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}
 void init()
{
add_action("do_answer","answer");
}
int do_answer(string arg)
{
object me;
        object room;
        me = this_player();
        if( !me->query("family/family_name") )          return notify_fail("你没有拜过师不能去参加比武？\n");
if(arg == "是" ) {
command("say 好，你去吧！\n");
        message_vision("$N跟着公平子的后面，来到比武看台。\n", me);
                me->move("/d/fy/biwufang");
                me->set("biwuid",1);
//room = load_object("/d/fy/biwufang");
//                if(room) me->move(room);

                 }
}



