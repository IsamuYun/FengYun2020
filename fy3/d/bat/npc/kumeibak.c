// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("��÷��ʦ", ({ "master kumei", "kumei", "master"}) );
        set("gender", "Ů��");
        set("age", 59);
        set("nickname", HIW"���ɹ�"NOR);
        set("title", "��ɽ�ɵ�ʮ��������");

        set("str", 30);
        set("agi", 50);
        set("int", 40);
	set("per", 40);

        set("max_gin", 2000);
        set("max_kee", 50000);
        set("max_sen", 549);
        set("eff_gin", 2000);
        set("eff_kee", 50000);
        set("eff_sen", 549);
        set("gin", 2000);
        set("kee", 50000);
        set("sen", 549);

        set("max_force", 9000);
        set("force", 9000);
        set("force_factor", 30);

	set("attitude","friendly");

        set("long",
"����һ���׷��ԲԵ��ϸ���һ�Ÿɿ����������������˰̣�����ȱ�˰����
�۾�Ҳ����һֻ��ʣ�µ�һֻ�۾��뿪��ϣ�����֮�䣬���Ⱪ�䣬����˭Ҳ
���ұ��ӡ������Ӻ���С����ȴ����˵�����������ϣ�����˭��ֻҪ������ 
һ�ۣ���˵������������ѹ��Щ��\n"
	);
        create_family("��ɽ��", 16, "����");
	set("student_title","����");
        set("combat_exp", 1500000);

	set("chat_chance_combat",50);
        set("chat_msg_combat", ({
		(: perform_action,"sword.pochan" :),
		(: perform_action,"sword.poqi" :),
        }) );

        set_skill("sword", 150);
        set_skill("wuzheng-force", 220);
        set_skill("literate", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 70);
	set_skill("dugu-sword", 140);
	set_skill("meng-steps", 150);
	set_skill("force", 90);
        set_skill("parry", 90);
        set_skill("move", 100);

       	map_skill("sword", "dugu-sword");
       	map_skill("parry", "dugu-sword");
       	map_skill("dodge", "meng-steps");
       	map_skill("move", "meng-steps");
       	map_skill("force", "wuzheng-force");

        setup();
        carry_object(__DIR__"obj/landuan")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}

void attempt_apprentice(object me)
{
	if(me->query_skill("sword",1)<100)
	{
	command("say ��Խ�����֪���٣���Ȼ�������ң�");
		return;
	}
	if(me->query_skill("dodge",1)<100)
	{
	command("say ���µ����ƺ�����ѧ�䰡��");
		return;
	}
	if(me->query("marks/ɱ������"))
	{
	command("smile");
        command("recruit " + me->query("id") );
        me->delete("marks/ɱ������");
		return;
	}
	else
	{
		command("say �����ڴ����ϳ�ҵ����ֻ࣬��һ�˻ỵ�ҵĴ���");
		return;
	}
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","��ɽ�ɵ���");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","��ɽ��С��");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","��ɽ������");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","��ɽ�ɴ���");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","��ɽ������");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","��ɽ�ɳ���");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","��ɽ��Ԫ��");
                return ;
        } else
                student->set("title","��ɽ�ɸ�����");
                return ;
}