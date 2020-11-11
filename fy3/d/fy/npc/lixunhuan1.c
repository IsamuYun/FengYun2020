// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("��Ѱ��", ({ "master li", "master", "master li xunhuan" }) );
        set("nickname", RED"С��ɵ�"NOR);
        set("gender", "����" );
        set("age", 44);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
	set("courage",1000);
        set("force_factor", 3);

        set("rank_info/respect", "��̽��");

        set("long",
"��Ѱ�������̽�������н����º�С��ɵ���
һ�ַɵ��������ڰ������ı����������е�����
�������ѣ��������鷢��\n"                
	);
        create_family("����һ��", 2, "�˽�");
	set("student_title","�˽�");
        set("combat_exp", 10000000);
        set("score", 200000);

        set("chat_chance", 10);
        set("chat_msg", ({
                "��Ѱ����ͣ���ڿȣ��������һ˿��Ѫ��\n",
                "��Ѱ������ɫԽ���԰��ˡ�\n",
"��Ѱ��̾���������������������ľ��\n",
        }) );
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("throwing", 300);
	set_skill("feidao", 220);
        set_skill("force", 40);
        set_skill("literate", 200);
       	map_skill("throwing", "feidao");
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
}

void attempt_apprentice(object ob)
{
	if((int) ob->query("force_factor") < 100)
	{
	 message_vision("$NЦ��������书���˽⻹����������\n",
        this_object());
	return;

	}
        command("sigh");
        command("say �ܺã�" + RANK_D->query_respect(ob) + 
"�����в���Ϊ��������\n");
        command("recruit " + ob->query("id") );
	ob->delete("betrayer");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "traveller");
	set("already",1);
}
void reset()
{
	set("already",0);
} 
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}
void heart_beat()
{
object feidao;
object target;
if(!query_temp("weapon") && is_fighting())
{
	feidao = new(__DIR__"obj/xlfd_knife");
	feidao->move(this_object());
	command("wield flying blade");
        target = offensive_target(this_object());
        if(target)
        (CLASS_D("traveller") + "/feidao/xiaoli-feidao")->kill_him(this_object(),target);
	WEAPON_D->throw_weapon(this_object(),target,feidao,0);
	return;
}
else
return ::heart_beat();
}
