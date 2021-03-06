// qiangdao  by tiandi

#include <ansi.h>

inherit NPC;
void create()
{

    set_name("东瀛人", ({ "japanese" }) );
    set("long", "一个身着奇异的家伙，可能不是来自中土。\n");
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
                "东瀛人道：偶尔来到中土武林，找点花姑娘玩玩，哈哈哈。\n",
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
			command("chat 中土的花姑娘都不见人，此般前来真是无趣。。。");
        else 
			command("chat 嘿嘿，尝尝我这一招。。。");
		remove_call_out("leave1");
		call_out("leave1",120);
}
void leave1()
{
        object ob = this_object();
        if (!ob->is_fighting()) 
			command("chat 这地方鸟不拉屎，人都没见几个。。。");
        else 
			command("chat 找不到花姑娘，砍两个人也不错啊。。。");
		remove_call_out("leave2");
		call_out("leave2",120);
}
void leave2()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
			CHANNEL_D->do_channel(ob, "rumor",sprintf("有人发现异族人在%s附近！",environment(ob)->query("short")));
			command("chat 越呆越无聊了。。。");
                }
        else 
			command("chat 巴呷亚路！");
		remove_call_out("leave3");
		call_out("leave3",120);
}
void leave3()
{
        object ob = this_object();
        if (!ob->is_fighting()) 
			command("chat 这次出来真是。。。先回去汇报了。");
			else 
				command("chat 中土人，记得，这次战斗还没完，下次再分胜负！");
            message_vision(HIC "东瀛人走了。\n" NOR,this_object());
            destruct(this_object());     
}
void die()
{
     object killer,owner;
	command("chat 啊～，大日本帝国会为我报仇的！");
	if( objectp(killer = query_temp("last_damage_from")) ) {
		if (owner = killer->query("possessed"))
			killer = owner;
		COMBAT_D->killer_reward(killer, this_object());
	}
	 destruct(this_object());
}
