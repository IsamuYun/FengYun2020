//TIE @ FY3
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "qinwei", "wei" }) );
        set("long",
                "һȺ�����ƻ������ɻ���\n");

        set("attitude", "heroism");
        set("combat_exp", random(500000)+1000000);
        	  set_temp("kf_tufei",72);
        set("pursuer", 1);
set_skill("unarmed", 70+random(200));
        set_skill("parry", 70+random(200));
        set_skill("dodge", 70+random(200));
        set_skill("move", 100+random(200));

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30+random(100));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
"�����ŵ�����ƽ�����������˾�������������\n"
        }) );

        setup();

        carry_object("/obj/cloth")->wear();
}

