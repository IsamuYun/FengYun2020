
inherit NPC;

void create()
{
        set_name("����" ,({ "man"}) );
        set("gender", "����" );
        set("agi", 62);
set("str",1);
        set("long", "����һ�����ˡ�");
        set("combat_exp", 10000000);
        set("sen",1000);
set("eff_sen",1000);
set("max_sen",1000);
set("attitude", "friendly");
        set_skill("move", 590);
	set_skill("dodge", 200);
        set("chat_chance_combat", 10);
set("chat_chance", 1);
        set("chat_msg", ({
                "���˵������µ�һ������\n",
        }) );
	
	setup();
	
}

