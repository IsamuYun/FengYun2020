#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ο�", ({ "master kuang", "master","kuang" }) );
        set("long",
                "���ֵ�һ���ˣ��Ѿ�������ʮ���ˣ���˵��ʮ��ǰ��ʤ���ľ�ֻ�е�ʱ�Ĵ���������\n");
	set("nickname", RED"���ֵ�һ����"NOR);
	 create_family("���˰�",2,"����");
      set("str", 40);
        set("cor", 40);
        set("cps", 40);
		  set_temp("kf_tufei",45);
        set("pursuer", 1);
set("agi",40);
	set("int",50);
       set("attitude","friendly");
          set("max_force", 25000);
        set("force", 25000);
        set("force_factor", 3);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               (: random_move :),
 (: perform_action, "unarmed.suixinsuoyu" :),
        }) );
        set("combat_exp", 10000000);
	set_temp("apply/damage",500);
        set_skill("unarmed", 60);
	set_skill("force",230);
        set_skill("parry",120);
        set_skill("dodge",140);
	set_skill("yiqiguanforce",50);
       set_skill("move",100);
	set_skill("literate",210);
       set_skill("zhibiao",200);
	map_skill("unarmed","zhibiao");
	map_skill("force","yiqiguanforce");
        setup();
}

void attempt_apprentice(object me)
{
        if(me->query_temp("for_ok"))
	{
	 command("sigh");
        command("cry");
        command("say �ã��ã����ҵ����ͽ���ϰ�����ʬ�壬������Ϊͽ��\n");
        command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("sigh");
        command("say ˭�ǿ��˰��һ�ΰ�����\n");
	command("say �����������ҵ����ˣ��Ϸ������Ϊͽ��\n");
}
	}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xianren");
}
 
void init()
{
        add_action("give_quest", "quest");
}
int accept_object(object me, object obj)
{
	if(obj->query("for_ok"))
	{
	me->set_temp("for_ok",1);
        command("sigh");
        command("cry");
        command("say �ã��ã����ҵ����ͽ���ϰ�����ʬ�壬������Ϊͽ��\n");
        command("recruit " + me->query("id") );
	return 1;
	}
	return 0;
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 4000 ) {
                student->set("title","������ͽ");
                return ;
        } else if ( exp <= 10000 ) {
                student->set("title","���˰����");
                return ;
        } else if ( exp <= 18000 ) {
                student->set("title","���˰︱����");
                return ;
        } else if ( exp <= 30000) {
                student->set("title","���˰�����");
                return ;
        } else if ( exp <= 60000 ) {
                student->set("title","���˰︱̳��");
                return ;
        } else if ( exp <= 120000 ) {
                student->set("title","���˰�̳��");
                return ;
        } else if ( exp <= 300000 ) {
                student->set("title","���˰︱����");
                return ;
        } else if ( exp <= 800000 ) {
                student->set("title","���˰�����");
                return ;
        } else if ( exp <= 2000000 ) {
                student->set("title","���˰��ܹ�");
                return ;
        } else if ( exp <= 6000000 ) {
                student->set("title","���˰ﻤ��");
                return ;
        } else if ( exp <= 12000000 ) {
                student->set("title","���˰��ܻ���");
                return ;
        } else
                student->set("title","���˰︱����");
                return ;

}

