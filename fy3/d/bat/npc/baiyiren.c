// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_for_zigong();
void create()
{
        set_name("东海白衣人", ({ "white cloth man", "man"}) );
        set("gender", "男性");
    set("reward_npc", 1);
    set("difficulty", 150); 

        set("age", 32);
        set("title", HIC"一剑震神州"NOR);

        set("str", 40);
        set("agi", 45);
        set("int", 30);
	set("cor", 300);
	set("cps", 30);
	set("con", 30);

        set("max_gin", 90100);
        set("max_kee", 70000);
        set("eff_gin", 90100);
        set("eff_kee", 70000);
        set("gin", 90100);
        set("kee", 70000);

        set("max_force", 4000);
        set("force", 12000);
        set("force_factor", 90);

	set("attitude","heroism");

        set("long",
"这是一位武功盖世的东瀛武士，曾以一剑横扫中原武林,
所向无敌，后来败在紫衣侯的手中，遂不知其去向。\n"
	);
        create_family("樱花", 1, "武士");
	set("student_title","弟子");
        set("score", 200000);
        set("combat_exp", 10000000);

        set_skill("sword", 150);
        set_skill("dodge", 150);
        set_skill("unarmed", 100);
        set_skill("kongshoudao", 100);
        set_skill("ghosty-force", 100);
	set_skill("force", 200);
        set_skill("move", 150);
        set_skill("parry", 150);

       	map_skill("force", "ghosty-force");
       	map_skill("unarmed", "kongshoudao");
        set("chat_chance", 4);
        set("chat_msg", ({
		"东海白衣人轻蔑的道：你们中国武士真是不堪一击！\n",
		"东海白衣人傲然道：我代表大和武士向你挑战，敢不敢接受？\n",
		"东海白衣人冷冷道：我一剑就可以横扫你们的江湖！\n",
        }) );
	set("chat_chance_combat",90);
        set("chat_msg_combat", ({
		(: perform_action, "unarmed.yaozhan" :),
        }) );
        set_skill("sword", 150);
        set_skill("dodge", 150);
        set_skill("unarmed", 100);
        set_skill("kongshoudao", 100);
        set_skill("ghosty-force", 100);
	set_skill("force", 200);
        set_skill("move", 150);
        set_skill("parry", 150);

       	map_skill("force", "ghosty-force");
       	map_skill("unarmed", "kongshoudao");
        setup();
        carry_object(__DIR__"obj/wushidao")->wield();
        carry_object(__DIR__"obj/yinhua")->wear();
}

void attempt_apprentice(object ob)
{
        return;
}
void init()
{
//	add_action("do_decide", "yes");
//	add_action("do_pretend", "learn");
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yinghua");
}

int recognize_apprentice(object ob)
{
        if( !ob->query_temp("marks/master_chu") ){
                return 0;
        }

        return 1;
}

int accept_fight(object	me)
{
	command("say 好，让我们切磋一下武功！\n");
	return 1;
}
void win_enemy(object loser)
{
message_vision("\n东海白衣人「哼」地一声，说道：便是有这许多不堪一击的家伙....\n",this_object());
}

void lose_enemy(object winner)
{
message_vision("\n东海白衣人讶然道：终於遇见一个对手了， 高处不胜寒！\n",this_object());
winner->set("marks/won_baiyiren",1);
}
string ask_for_zigong()
{
	object me;

	me = this_player();

	if( me->query("marry") )
		return "你是有家室之人，何必开如此无聊的玩笑？\n";
	if( (string)me->query("gender") == "女性" )
		return "我最不喜欢和女性打交道，你走吧!\n";
	if (!me->query("marks/won_baiyiren"))
		return "这位小兄弟，以你的武艺没有办法了解这种武功。\n";
	if ((int)me->query_str() > 28 )
		return "这位好汉你力气太大了，学不了这种武功。\n";
        if(this_player()->query("overzigong")){
		me->set("shiziok",1);
return "这位小兄弟，相信你已经可以学习十字剑法了，要学的请回答 (learn)。\n";
}	me->set_temp("pending/zigong", 1);
	return "相传你们中原有种武功天下无敌，但是挥刀自宫。\n东海白衣人说道：本人虽然知道怎么学习，但是却不能过此大关。\n东海白衣人说道：如你要学我就告诉我，告诉我。决定了就回答(yes)。\n";
}
int do_decide()
{
	if( !this_player()->query_temp("pending/zigong") )
		return 0;
	if( this_player()->query("overzigong") )
		return 0;
	message_vision(
		"$N一咬牙，褪下中衣。\n\n"
		"$n伸出长剑插到$N两腿之间，飞速一剜，……\n\n"
		"$N顿时惨叫一声，昏了过去……\n\n",
		this_player(), this_object() );
        command("rumor 哈哈，终于有人学习十字剑法了！");
	command("hehe");
	this_player()->delete_temp("pending/zigong");	
	this_player()->set("gender","无性");
        this_player()->set("overzigong", 1);
	this_player()->set("combat_exp",this_player()->query("combat_exp")+100000);
	this_player()->unconcious();
	
	return 1;
}
int do_pretend()
{
	if( !this_player()->query("shiziok") )
		return 0;
	if( this_player()->query("okshizi") )
		return 0;
	message_vision(
		"$n细心的教导。\n\n"
		HIC"$N的[十字剑法]进步了！\n\n"NOR
		"$N顿时惨叫一声，昏了过去……\n\n",
		this_player(), this_object() );
	command("say 朋友我只能教你这么多了，你以后好自为之，要用到正义的地方！");
        this_player()->set_skill("shizi-sword", 1);
        this_player()->set("okshizi", 1);
	this_player()->set("combat_exp",this_player()->query("combat_exp")+100000);
	this_player()->unconcious();
	
	return 1;
}
