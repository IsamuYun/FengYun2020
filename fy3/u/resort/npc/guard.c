

inherit NPC;
string kill_passenger(object who);
void create()
{
        set_name("����", ({ "guard" }) );
        set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 50); 

        set("age", 68);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 99999);
        set("sen", 3000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_mana", 300);
        set("mana", 300);

        set("max_force", 10000);
        set("force", 5000);
        set("force_factor", 500);

        set("attitude", "peaceful");

        set("long","����һλ�þ���˪�����ˡ�\n");

        set("combat_exp", 200000);
        set("score", 50);
        set_skill("unarmed", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100);

        set_skill("meihua-shou", 100);
        set_skill("qidaoforce", 150);
        set_skill("fall-steps", 100);

        map_skill("unarmed", "meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge", "fall-steps");


	setup();
        add_money( "silver" , 50);
}

void init()
{
	add_action("do_gogo", "go");
}

int do_gogo(string arg)
{
	object me;
	me = this_player();
	if( arg == "north" )
	{
		if( me->query("class") ) 
		if( me->query("class") != "legend") {
	command("sigh");
	command("say ���������ڽ�����������Ī�����");
	write("��������·�����ŵ�ס�� ��\n");
	return 1;
		}
		else
			return 0;		
	}
	return 0;
}
