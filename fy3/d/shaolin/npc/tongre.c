
inherit NPC;

void create()
{
        set_name("����ͭ��", ({ "tongren" }) );
	set("gender", "����" );
	set("age", 42);
	set("long",
                "һ����ɫ��ͭ�ˣ�����������ࡣ\n");
        set("combat_exp", 2500000);
        set("per",10);
        set("max_kee",10000);
        set("kee",10000);
        set("max_atman",100);
        set("atman",100);
        set("sen",5000);
        set("max_sen",5000);
	set("attitude", "friendly");
	set_skill("iron-cloth", 200);
	set_skill("jin-gang",100);
	set_skill("unarmed", 100);
	set_skill("bloodystrike", 100);
	map_skill("unarmed", "bloodystrike");
	map_skill("iron-cloth", "jin-gang");
	setup();
}

void die()
{
        object me;
        me=this_object()->query_temp("last_damage_from");
        if(objectp(me))
        me->set_temp("marks/menggu",1);
::die();
}

