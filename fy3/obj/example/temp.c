
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "tieshao", "master","master tieshao" }) );
	set("gender", "����" );
        set("title", "���鵶��");
	set("age", 25);
	set("int", 30);
	set("per", 30);
        set("apprentice_available", 50);
        create_family("����", 0, "ׯ��");
	set("long",
		"���ٴ�ʮ���꿪ʼ�ͺͰ���ѩ����������������˵����ϱڣ�\n"
		"�����޵С���������������ʢ֮ʱ���ֺ�Ȼ�˳������������ڴˡ�\n"
		);
        set("force_factor", 200);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);

        set("combat_exp", 9999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("blade", 150);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("meihua-shou", 100);
	set_skill("shortsong-blade", 130);
	set_skill("qidaoforce", 150);
	set_skill("fall-steps", 100);

	map_skill("unarmed", "meihua-shou");
        map_skill("blade", "shortsong-blade");
        map_skill("force", "qidaoforce");
        map_skill("parry", "shortsong-blade");
        map_skill("dodge", "fall-steps");

	setup();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say ��ׯ�������Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "����" )
          {      command("say ��ֻ���е��ӣ��㻹��ȥ���ҵ����˰ɣ�");
          }
        else {

                command("smile");
                command("say ���պ���д�ɣ�");
                command("smile");
                command("recruit " + ob->query("id") );
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "legend");
        add("apprentice_availavble", -1);
}

int accept_fight(object me)
{
	object xiaocui;
	if( objectp(xiaocui = present("cui", environment(this_object()))) && living(xiaocui))
	{	
        command("smile");
        command("say ������С�����ɡ�");
        return 0;
	}
	else
		command("sigh");
		command("���������ĴӴ������վ���������������е���ɰ����");
		command("wield wangblade");
		command("say �룡");
		call_out("do_unwie", 3);
		return 1;
}
int do_unwie()
{
        if( !this_object()->is_fighting())
        {
                command("unwield wangblade");
                message_vision("$N����豭ǳ�һ�ڣ���������������ѩ���һ�ۣ�����������ϡ�\n", this_object());
		command("smile");
                return 1;
        }
        else
                call_out("do_unwie", 3);
}

void init()
{
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{
	
	object player, victim, weapon;
	string name;
	player = this_player();
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = victim->name();
		if( name == "ѩ���")
		{
		message_vision("$N����üͷ��\n", this_object());
		message_vision("$N����Ƥ�����г��һ��ɱ�����˵����µ��������С�\n", this_object());
		weapon = present("wangblade", this_object());
		weapon->wield();
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		call_out("do_unwie", 3);
		return 0;
		}
		if( name == "����")
		{
		message_vision("$N����üͷ��\n", this_object());
                message_vision("$N����Ƥ�����г��һ��ɱ�����˵����µ��������С�\n", this_object());
                weapon = present("wangblade", this_object());
                weapon->wield();
                call_out("do_unwie", 3);
		return 0;
		}
		return 0;
	}
	return 0;		
}
