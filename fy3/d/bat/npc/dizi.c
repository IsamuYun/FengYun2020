// garrison.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("���𵺵���", ({ "dizi" }) );
        set("long",
                "����һλ����ר�ŵ��α���֮��ĵ��ӡ�\n");
        set("attitude", "killer");

        set("str", 30);
        set("cor", 30);
        set("cps", 25);

        set("combat_exp", random(600000)+200000);

        
        set_skill("sword", 100+random(50));
        set_skill("parry", 70+random(50));
        set_skill("dodge", 70+random(50));
        set_skill("move", 100+random(50));

        
/*        set("chat_chance", 1);
        set("chat_msg", ({
"���𵺵��Ӻȵ����󵨣������ô����𵺣�\n"
        }) );*/

        setup();

       
        carry_object("obj/weapon/sword")->wield();
}

