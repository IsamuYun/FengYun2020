inherit NPC;
void create()
{
        set_name("������˪������", ({ "oldman", "old man", "man" }) );
        set("gender", "����");
    set("reward_npc", 1);
    set("difficulty", 20); 

        set("age", 74);
        set("long",
"����һ��������˪�����ˣ�����˫Ŀ����̫��Ѩ�߸�¡��\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 1000000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "������˪������������ԶԶ��һ���������̸е�͸����������\n",
        }) );
        set("force", 4000);
        set("max_force", 2200);
        set("force_factor", 50);
        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 150);
        set_skill("parry", 100);
        set_skill("dodge", 80);
	set_skill("move", 150);

        set_skill("doomforce", 50);
        set_skill("doomstrike", 50);
        set_skill("doomsteps", 5);

        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("dodge", "doomsteps");


        setup();
	carry_object("/obj/cloth")->wear();
}
