// teacher.c

inherit NPC;

void create()
{
	set_name("����", ({ "chi song", "song" }) );
	set("title", "��������");
	set("gender", "����" );
	set("age", 52);
	set("skill_public",1);
	set("int", 30);
        create_family("����", 21, "����");
	set("long",
		"���ɱ��Ǹ��׸�ɮ�ĵ������ӣ����Ǳ����ݺ���������Ϊ��͵\n"
		"�������ӣ��������ʦ�ţ����ڴ˹ȣ���������˫�㣬����˵��\n"
		"�����ӵ����䡣��˵�������ӵ����䣬�����ɻز���������\n"
		);
       set("chat_chance", 5);
        set("chat_msg", ({
                "����˵����˭�����һ������ӣ��ҽ�ȫ���򴫸�����\n",
        }) );

	set("inquiry", ([
		"������": "��....������һ������ʦ�����ɵ��ߵġ�\n",
		"����": "�����ڲ��������ǵĴ������",
	]) );
	set("attitude", "peaceful");
	set_skill("iron-cloth", 100);
	set_skill("unarmed", 70);
	set_skill("bloodystrike", 60);
	set_skill("force", 80);
	set_skill("bolomiduo", 75);
	map_skill("unarmed", "bloodystrike");
	map_skill("force", "bolomiduo");
	set("combat_exp", 900000);
	setup();
  carry_object("/questobj/obj/huaxue");
}

int recognize_apprentice(object ob)
{
        if( !ob->query("marks/song") ){
                say("����˵������ֻ�а����һ������ӣ��ҲŻ����....\n");
                return 0;
        }

        return 1;
}

int accept_object(object who, object ob)
{
	int bonus;
	if( ob->name() != "������")
	{
	               say("����˵����������Ҫ����������....\n");
			return 1;
	}
	if (ob->query("nature")!= "real" )
        {
                       say("����˵����������Ҳ������ƭ�ˣ����������Ǽٵ�....\n");
                        return 1;
        }
	else
	{
		who->set("marks/song", 1);
		say("����˵�����ã��ã��ã�̫���ˣ��ҵ�ԩ���ڼ�������....\n");
        bonus = random(50);
        who->add("combat_exp", bonus);
        bonus = bonus + random(10);
        who->add("potential", bonus );
        if(!who->query("m_success/����"))
        {
                who->set("m_success/����",1);
                who->add("score",400);

        }

			return 1;	
	}
		return 1;
}
