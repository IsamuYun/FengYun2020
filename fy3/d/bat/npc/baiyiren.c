// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_for_zigong();
void create()
{
        set_name("����������", ({ "white cloth man", "man"}) );
        set("gender", "����");
    set("reward_npc", 1);
    set("difficulty", 150); 

        set("age", 32);
        set("title", HIC"һ��������"NOR);

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
"����һλ�书�����Ķ����ʿ������һ����ɨ��ԭ����,
�����޵У������������º�����У��첻֪��ȥ��\n"
	);
        create_family("ӣ��", 1, "��ʿ");
	set("student_title","����");
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
		"��������������ĵ��������й���ʿ���ǲ���һ����\n",
		"���������˰�Ȼ�����Ҵ��������ʿ������ս���Ҳ��ҽ��ܣ�\n",
		"�������������������һ���Ϳ��Ժ�ɨ���ǵĽ�����\n",
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
	command("say �ã��������д�һ���书��\n");
	return 1;
}
void win_enemy(object loser)
{
message_vision("\n���������ˡ��ߡ���һ����˵���������������಻��һ���ļһ�....\n",this_object());
}

void lose_enemy(object winner)
{
message_vision("\n������������Ȼ�����������һ�������ˣ� �ߴ���ʤ����\n",this_object());
winner->set("marks/won_baiyiren",1);
}
string ask_for_zigong()
{
	object me;

	me = this_player();

	if( me->query("marry") )
		return "�����м���֮�ˣ��αؿ�������ĵ���Ц��\n";
	if( (string)me->query("gender") == "Ů��" )
		return "���ϲ����Ů�Դ򽻵������߰�!\n";
	if (!me->query("marks/won_baiyiren"))
		return "��λС�ֵܣ����������û�а취�˽������书��\n";
	if ((int)me->query_str() > 28 )
		return "��λ�ú�������̫���ˣ�ѧ���������书��\n";
        if(this_player()->query("overzigong")){
		me->set("shiziok",1);
return "��λС�ֵܣ��������Ѿ�����ѧϰʮ�ֽ����ˣ�Ҫѧ����ش� (learn)��\n";
}	me->set_temp("pending/zigong", 1);
	return "�ഫ������ԭ�����书�����޵У����ǻӵ��Թ���\n����������˵����������Ȼ֪����ôѧϰ������ȴ���ܹ��˴�ء�\n����������˵��������Ҫѧ�Ҿ͸����ң������ҡ������˾ͻش�(yes)��\n";
}
int do_decide()
{
	if( !this_player()->query_temp("pending/zigong") )
		return 0;
	if( this_player()->query("overzigong") )
		return 0;
	message_vision(
		"$Nһҧ�����������¡�\n\n"
		"$n��������嵽$N����֮�䣬����һ�࣬����\n\n"
		"$N��ʱ�ҽ�һ�������˹�ȥ����\n\n",
		this_player(), this_object() );
        command("rumor ��������������ѧϰʮ�ֽ����ˣ�");
	command("hehe");
	this_player()->delete_temp("pending/zigong");	
	this_player()->set("gender","����");
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
		"$nϸ�ĵĽ̵���\n\n"
		HIC"$N��[ʮ�ֽ���]�����ˣ�\n\n"NOR
		"$N��ʱ�ҽ�һ�������˹�ȥ����\n\n",
		this_player(), this_object() );
	command("say ������ֻ�ܽ�����ô���ˣ����Ժ����Ϊ֮��Ҫ�õ�����ĵط���");
        this_player()->set_skill("shizi-sword", 1);
        this_player()->set("okshizi", 1);
	this_player()->set("combat_exp",this_player()->query("combat_exp")+100000);
	this_player()->unconcious();
	
	return 1;
}