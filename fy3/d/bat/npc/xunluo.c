// garrison.c

#include <ansi.h>

inherit NPC;
string kill_passenger(object who);
void create()
{
        set_name("����ͳ��", ({ "shiwei" }) );
        set("long",
                "����һλ����ר�ŵ���Ѳ��֮�������ͳ�졣\n");
        set("attitude", "killer");        
        set("str", 30+random(10));
        set("cor", 30);
        set("cps", 25);

        set("combat_exp", random(700000)+200000);

        
        set_skill("blade", 100+random(100));
        set_skill("parry", 100+random(50));
        set_skill("dodge", 70+random(50));
        set_skill("move", 150+random(50));
		set_skill("bat-blade", 100+random(50));
		map_skill("blade", "bat-blade");


        
      set("chat_chance", 1);
        set("chat_msg", ({
"����ͳ��ȵ����󵨣������ô����𵺣�\n"
        }) );

        setup();

        carry_object("obj/cloth")->wear();
        carry_object(__DIR__"obj/xueblade")->wield();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) 
                kill_ob(ob);
        
}

