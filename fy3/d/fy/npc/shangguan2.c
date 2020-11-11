// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("�Ϲٽ��", ({ "master shangguan", "master", "master shang" }) );
        set("nickname", RED"����˫��"NOR);
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
        set("force_factor", 3);
	set("max_mana",1000);
	set("mana",1000);

        set("long",
"
һ������վ������ǰ�����ţ���ʱ������ھ����Ϲ��������ģ�����ż����¶��һ˿
�����Ц�ݡ�����վ�ŵġ�����Ϊһ����ֻҪ���������ͻ����Լ��ľ����ɳڣ�һ��
�˵ľ������ɳڣ���������ɴ���
\n"
	);
        create_family("��Ǯ��", 1, "����");

        set("combat_exp", 10000000);
        set("score", 200000);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.canglongyixian" :),
                (: perform_action, "dodge.canglongyixian" :),
                (: perform_action, "dodge.canglongyixian" :),
                (: perform_action, "dodge.canglongyixian" :),
                (: perform_action, "dodge.canglongyixian" :),
                (: perform_action, "dodge.canglongyixian" :),
                (: perform_action, "dodge.canglongyixian" :),
                (: perform_action, "dodge.canglongyixian" :),
                (: perform_action, "dodge.canglongyixian" :),
                (: perform_action, "dodge.canglongyixian" :),
                (: perform_action, "dodge.canglongyixian" :),
		(: cast_spell, "freeze" :),
        }) );
        set_skill("move", 70);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("literate", 60);
	set_skill("jingxing",120);
	set_skill("hammer", 150);
	set_skill("jinhong-steps",120);
	set_skill("longfenghuan",150);
        map_skill("dodge", "jinhong-steps");
	map_skill("hammer", "longfenghuan");
	map_skill("parry", "longfenghuan");
	map_skill("force", "jingxing");
	set_skill("spells",100);
	set_skill("mapo",100);
	map_skill("spells","mapo");

        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/longfenghuan")->wield();
}

void attempt_apprentice(object me)
{
	       if( (int)me->query("str") + (int)me->query("max_force") / 10 < 60 )
		{	message_vision("$N��$n˵������˫�����������ѧ�ҵ�����˫����\n", this_object(),me);
			return;
		}	
	
        command("recruit " + me->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "assassin");
}
 
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","��Ǯ�����");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","��Ǯ�︱����");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","��Ǯ������");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","��Ǯ�︱̳��");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","��Ǯ��̳��");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","��Ǯ�︱����");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","��Ǯ�����");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","��Ǯ�ﻤ��");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","��Ǯ��󻤷�");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","��Ǯ�ﳤ��");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","��Ǯ�����");
                return ;
        } else
                student->set("title","��Ǯ�︱����");
                return ;

}
