// taolord.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ʯ��", ({ "master shi", "master", "shi" }) );
        set("nickname", "��������");
        set("gender", "����");
    set("reward_npc", 1);
    set("difficulty", 250); 

        set("age", 62);
        set("long",
"ʯ���˵����䵱���ţ�����̫���ķ������Ž����������˼��ߵľ��硣\n"
                "�����侫̫ͨ�����У������������ǵ�����˫�������˳ƣ��������ˣݡ�\n");
        set("combat_exp", 100000000);
        set("score", 20000);

        set("class", "wudang");

        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 30);

        set("inquiry", ([
                "̫���ķ�": 
"̫���ķ��˵������ŵĻ����ķ����ܹ��������ڵ�����������\n����ֻҪ��֮�Ժ㣬��������κ������ڹ���\n",
                "�䵱��": 
"���䵱���������˿�ɽ����������������������������Ϊ���Ρ�\n",
		"���Ƿ�" :
"���Ƿ���Ϊ����ȴֻ�����������Ǿ���hanxing���ͻ��Ǿ���jixing����\n",
		"qixing" :
"���Ƿ���Ϊ����ȴֻ�����������Ǿ���hanxing���ͻ��Ǿ���jixing����\n",
        ]) );

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.nianzijue" :),

        }) );

        create_family("�䵱��", 57, "������");
	set("no_arrest",1);
	set("nianzijue",10);
	set_temp("apply/armor",6000);
        set_skill("literate", 800);
        set_skill("force", 300);
        set_skill("move", 1000);
        set_skill("unarmed", 800);
        set_skill("sword", 200);
        set_skill("three-sword", 1000);
	set_skill("taijiforce", 1000);
	set_skill("taiji", 1000);
	set_skill("five-steps", 1000);
	set_skill("spells",200);
	set_skill("qixing",1000);
	map_skill("spells","qixing");
        map_skill("sword", "three-sword");
        map_skill("force", "taijiforce");
        map_skill("unarmed", "taiji");
        map_skill("move", "five-steps");

        setup();

	carry_object(__DIR__"obj/msword")->wield();
        carry_object(__DIR__"obj/mcloth")->wear();
        carry_object(__DIR__"obj/mhat")->wear();
}

void attempt_apprentice(object me)
{
	if( me->query("class"))
	{
	command("stare");
	command("say ���Ѿ����Լ��������ˣ�\n");
	}
	else if( me->query("national") == "����" )
	{
	command("smile");
	command("say �ܺã��䵱�˵������ֵڶ������ɣ����ѡ��ʮ�����ǰ���\n");
            command("recruit " + me->query("id") );
	}
	else
	command("say ���䵱ֻ�պ���֮�ˣ�\n");
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
}

int accept_object(object who, object ob)
{
	object 		book;

        if((string)ob->name() != "���Ʒɵ��غ�") return 0;
	command("say ��л��λ" + RANK_D->query_respect(who));
	command("say �Ȿ������������ɡ�");
	book = new(__DIR__"obj/wubook");
	book->move(this_object());
	command("give book to " + who->query("id"));
        return 1;
}


void re_rank(object student)
{
        int exp;
        exp = (int) student->query("level");
        if( exp <= 10 ) {
                student->set("title","�䵱�ɵ�ʿ");
                return ;
        } else if ( exp <= 20 ) {
                student->set("title","�䵱��С����");
                return ;
        } else if ( exp <= 30 ) {
                student->set("title","�䵱������");
                return ;
        } else if ( exp <= 40 ) {
                student->set("title","�䵱��С��ʦ");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","�䵱����ʦ");
                return ;
        } else if ( exp <= 60 ) {
                student->set("title","�䵱�ɴ���ʦ");
                return ;
        } else if ( exp <= 70 ) {
                student->set("title","�䵱�ɸ�����");
                return ;
        } else
                student->set("title","�䵱������");
                return ;
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if(ob) 
        ob->set_temp("killed_master_shi",1);
        ::die();
}
