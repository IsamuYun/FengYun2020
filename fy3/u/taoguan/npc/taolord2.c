// taolord.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name( "������" , ({ "master ding", "master", "ding" }) );
        set("nickname",HIB "��հ���" NOR);
        set("gender", "Ů��");
	set("class","sanqing");
    set("reward_npc", 1);
    set("difficulty", 150); 
        set("age", 46);
        set("long",
                
"�������Ƕ��˷��ʦ�ã�Ҳ�Ƕ��˷�������á�����������ʱ�������������\n"
"�����������������ɱ�˰�����󵽴˳��ҡ�\n");

        set("combat_exp", 100000000);
        set("score", 200000);

        set("force", 20000);
        set("max_force", 10000);
        set("force_factor", 30);

        set("atman", 14000);
        set("max_atman", 14000);

        set("mana", 40000);
        set("max_mana", 20000);
        set("mana_factor", 5);

        set("inquiry", ([
                "�����ķ�": 
"�����ķ��������幬Ϊ�Կ�аħ����������ڹ��ķ���\n",
                "���幬": 
"�����幬������ʦ��ɽ�������������������Խ�����ħΪ���Ρ�\n"
        ]) );

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );

        create_family("���幬", 6, "Ů����");

        set_skill("literate", 150);
        set_skill("magic", 1000);
        set_skill("force", 150);
        set_skill("spells", 1000);
	set_skill("scratching",1000);
	set_skill("move", 300);
        set_skill("dodge", 500);
        set_skill("gouyee", 500);
        set_skill("notracesnow", 1000);
        set_skill("taoism", 1000);
        set_skill("necromancy", 1000);
	set_skill("scratmancy",1000);

        map_skill("spells", "necromancy");
        map_skill("move", "notracesnow");
        map_skill("dodge", "notracesnow");
        map_skill("scratching", "scratmancy");

        set_temp("apply/dodge", 20);
        set_temp("apply/armor", 20);

        setup();

        carry_object(__DIR__"obj/sword2")->wield();
        carry_object(__DIR__"obj/robe2")->wear();
        carry_object(__DIR__"obj/hat2")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}

void attempt_apprentice(object me)
{
	if( me->query("class") && me->query("class") != "sanqing")
	{
	command("stare");
	command("say ���Ѿ����Լ��������ˣ�\n");
	}
	else if( me->query("national") == "����" )
	{
	command("smile");
	command("say �ܺã������幬�Ϳ������������ˣ�\n");
            command("recruit " + me->query("id") );
	}
	else
	command("say ������ֻ�ղ���֮�ˣ�\n");
}

void do_recruit(object ob)
{
                command("say ��... ���������幬��Ҳ��....");
                command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "sanqing");
}

 
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("level");
        if( exp <= 10 ) {
                student->set("title","���幬Сͽ");
                return ;
        } else if ( exp <= 20 ) {
                student->set("title","���幬ʥ��");
                return ;
        } else if ( exp <= 30 ) {
                student->set("title","���幬ʩ����");
                return ;
        } else if ( exp <= 40 ) {
                student->set("title","���幬����");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","���幬����");
                return ;
        } else if ( exp <= 60 ) {
                student->set("title","���幬����");
                return ;
        } else if ( exp <= 70 ) {
                student->set("title","���幬������");
                return ;
        } else
                student->set("title","���幬����");
                return ;

}
