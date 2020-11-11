
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("���촸", ({ "master lan", "lan","master" }) );
	set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 150); 

        set("title",HIB "��������" NOR);
        create_family("�촸ɽׯ", 1, "ׯ��");
	set("long",
		"���촸��һ�����õĳ����뻯������
ÿ�궼�͵�����������һս���½�ʤ�����֣� 
���촸��Ƣ�������һ𣬾�����Ե�޹ʵĽ����Ӵ�����˻����ǽ�ţ�\n"
		);
        set("chat_chance", 1);
        set("chat_msg", ({
"���촸Ц�����������϶����ֺ�������ʤ����\n",
        }) );
        set("combat_exp", 99999999);
        set("score", 90000);
        set_skill("unarmed", 1000);
        set_skill("hammer", 1000);
        set_skill("force", 500);
        set_skill("parry", 100);
        set_skill("literate", 700);
		set("max_force",50000);
		set("force",50000);
	set_skill("dodge", 300);
	set("class","tianchui");

	set_skill("pangu-hammer", 1000);
	set_skill("pofeng-strike", 1000);
	set_skill("putiforce", 1000);
	set_skill("nodust-steps", 1000);

	map_skill("unarmed", "pofeng-strike");
        map_skill("hammer", "pangu-hammer");
        map_skill("force", "putiforce");
        map_skill("parry", "pangu-hammer");
        map_skill("dodge", "nodust-steps");
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "hammer.kaitianpidi" :),
		(: cast_spell, "shrink" :),
        }) );
	setup();
        carry_object(__DIR__"obj/bluecloth")->wear();
        carry_object(__DIR__"obj/jumbohammer")->wield();
}

void attempt_apprentice(object ob)
{
	if( ob->query("class")&&ob->query("class") != "tianchui")
	{
	command("stare");
	command("say ���Ѿ����Լ��������ˣ�\n");
	}
	else if( ob->query("national") == "�ɹ���" )
	{
	command("smile");
	command("say �ܺã����촸ɽׯ�Ϳ������������ˣ�\n");
            command("recruit " + ob->query("id") );
	}
	else
	command("say �촸ɽׯֻ���ɹ����ˣ�\n");
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tianchui");
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("level");
        if( exp <= 10 ) {
                student->set("title","�촸�ɵ���");
                return ;
        } else if ( exp <= 20 ) {
                student->set("title","�촸��С��");
                return ;
        } else if ( exp <= 30 ) {
                student->set("title","�촸������");
                return ;
        } else if ( exp <= 40 ) {
                student->set("title","�촸�ɴ���");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","�촸������");
                return ;
        } else if ( exp <= 60 ) {
                student->set("title","�촸�ɳ���");
                return ;
        } else if ( exp <= 70 ) {
                student->set("title","�촸��Ԫ��");
                return ;
        } else
                student->set("title","�촸�ɸ�����");
                return ;
}

