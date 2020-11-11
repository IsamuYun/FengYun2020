// qiangdao  by tiandi

#include <ansi.h>

inherit NPC;
void create()
{

    set_name("�����", ({ "japanese" }) );
    set("long", "һ����������ļһ���ܲ�������������\n");
	set("level",50+random(50));
	set("no_arrest",1);
	set("issmallboss",1);
	set("max_gin",500000);
	set("max_kee",600000);
	set("max_sen",500000);
	set("max_atman",5000);
	set("max_force",500000);
	set("max_mana",5000);
	set("force",500000);
	set("atman",5000);
	set("mana",5000);
	set("tianwaifeixian",6);
	set("jinganghuti",6);
	set("str",query("level")*2);
	set("cor",query("level")*7);
	set("int",query("level")*7);
	set("spi",query("level")*7);
	set("cps",query("level")*7);
	set("per",query("level")*7);
	set("con",query("level")*7);
	set("kar",query("level")*7);
	set("agi",query("level")*7);
	set("dur",query("level")*7);
	set("fle",query("level")*7);
	set("tol",query("level")*7);
	set_skill("literate", query("level")*10);
	set_skill("daode", query("level")*10);
    set_skill("sword", query("level")*10);
    set_skill("parry", query("level")*10);
    set_skill("dodge", query("level")*10);
    set_skill("move", query("level")*10);
//	set_skill("feixianforce", query("level")*10);
    set_skill("feixian-sword", query("level")*2);
    set_skill("feixian-steps", query("level")*10);

    set_skill("force", query("level")*10);
	map_skill("literate","daode");
    map_skill("sword","feixian-sword");
    map_skill("dodge","feixian-steps");

    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: perform_action, "dodge.tianwaifeixian" :),
		(: perform_action, "literate.jinganghuti" :),
      }) );
    set("chat_chance", 5);
    set("chat_msg", ({
                "����˵���ż�������������֣��ҵ㻨�������棬��������\n",
	              (: random_move :),
        }) );

    setup();

    carry_object("/obj/weapon/sword")->wield();
}
void init()
{
		remove_call_out("leave");
        call_out("leave",120);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) 
			command("chat �����Ļ����ﶼ�����ˣ��˰�ǰ��������Ȥ������");
        else 
			command("chat �ٺ٣���������һ�С�����");
		remove_call_out("leave1");
		call_out("leave1",120);
}
void leave1()
{
        object ob = this_object();
        if (!ob->is_fighting()) 
			command("chat ��ط�����ʺ���˶�û������������");
        else 
			command("chat �Ҳ����������������Ҳ������������");
		remove_call_out("leave2");
		call_out("leave2",120);
}
void leave2()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
			CHANNEL_D->do_channel(ob, "rumor",sprintf("���˷�����������%s������",environment(ob)->query("short")));
			command("chat Խ��Խ�����ˡ�����");
                }
        else 
			command("chat ������·��");
		remove_call_out("leave3");
		call_out("leave3",120);
}
void leave3()
{
        object ob = this_object();
        if (!ob->is_fighting()) 
			command("chat ��γ������ǡ������Ȼ�ȥ�㱨�ˡ�");
			else 
				command("chat �����ˣ��ǵã����ս����û�꣬�´��ٷ�ʤ����");
            message_vision(HIC "��������ˡ�\n" NOR,this_object());
            destruct(this_object());     
}
void die()
{
     object killer,owner;
	command("chat ���������ձ��۹���Ϊ�ұ���ģ�");
	if( objectp(killer = query_temp("last_damage_from")) ) {
		if (owner = killer->query("possessed"))
			killer = owner;
		COMBAT_D->killer_reward(killer, this_object());
	}
	 destruct(this_object());
}