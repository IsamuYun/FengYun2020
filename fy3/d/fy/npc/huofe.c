
inherit NPC;

void create()
{
	set_name("���", ({ "huofe", "huo","fe" }) );
	set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 20); 

	set("age", 109);
	set("int", 30);
	set("long",
		"�����𣬵���ԭ�����Σ�\n"
		);
        set("combat_exp", 1000000);
        set("score", 90000);
        set_skill("unarmed", 150);
	set_skill("move", 100);
        set_skill("staff", 150);
        	  set_temp("kf_tufei",29);
        set("pursuer", 1);
set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("literate", 150);
	set_skill("iron-cloth", 150);
	set_skill("magic", 150);

	set_skill("bloodystrike", 150);
	set_skill("cloudstaff", 150);
	set_skill("bolomiduo", 150);
	set_skill("buddhism", 150);
	set_skill("essencemagic", 150);
        set_skill("jin-gang", 150);


	map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("magic", "essencemagic");

	setup();
}
int accept_object(object who, object ob)
{
        if( ob->value() >= 1000000)
        {
message_vision("$N��$n˵������лʩ����\n",
this_object(),who);
/*
	who->add("potential",(int) ob->value()/3000000);
	log_file("HUOFO",sprintf("%s %s %d\n",ctime(time()),who->query("id"),
	(int) ob->value()/3000000));
*/
                return 1;
        }
        return 0;
}

