// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("ԭ����", ({ "master yuan", "master", "yuan" }) );
        set("nickname", HIR"������"NOR);

        set("gender", "����" );
        set("reward_npc", 1);
        set("difficulty", 150); 

        set("age", 26);
        set("int", 40);
        set("spi", 21);
        set("cor", 15);
        set("con", 20);
		set("per", 40);
		set("str", 30);
		
	    set("attitude","peaceful");
        set("max_force", 9500);
        set("force", 19000);
        set("force_factor", 100);
		set("max_gin",5000);
        set("max_kee",100000);
		set("max_sen",500);
        set("long",
"��Ц����������У���һ˫�۾��ȴ������˵�����Ŀ��顢��į������
֮��, �Ǹ�����������˹�ĵ����꣬�����仪������ȴ������\n"
	);
        set("chat_chance", 1);
        set("chat_msg", ({
                "ԭ�����ߵ��ٱߣ�һ����������ˮ������Ӵ���ָ�������
���伺�кܾ�û�й�����ö��������ˡ�\n",
        }) );

        create_family("����ɽׯ", 1, "��ׯ��");


        set("combat_exp", 80000000);
        set("chat_chance_combat", 80);
     set("chat_msg_combat", ({
            (: perform_action, "blade.shiwanshenmo" :),
        }) );

        set_skill("move", 100);
        set_skill("parry", 90);
        set_skill("dodge", 100);
        set_skill("force", 90);
	    set_skill("unarmed", 70);
	    set_skill("wuzheng-force",220);
        set_skill("literate", 150);
	    set_skill("blade",150);
	    set_skill("bat-blade",150);
      set_skill("meng-steps",220);
        
	    map_skill("force", "wuzheng-force");
	   map_skill("parry","bat-blade");
        map_skill("blade","bat-blade");
        map_skill("dodge","meng-steps");
      map_skill("move","meng-steps"); 
     	

        setup();
        carry_object(__DIR__"obj/ruanjia")->wear();
        carry_object(__DIR__"obj/yunblade")->wield();
}

/*
void attempt_apprentice(object ob)
{
//	command("smile");
	call_out("do_recruit", 1, ob);
//        command("recruit " + ob->query("id") );

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wuzheng");
}
void do_recruit(object ob)
{
 if( (int)ob->query_cor() < 30 )
 {
  command("say �ҴӲ��յ�С֮�ˣ�����ذɣ�\n");
  return;
 }
 if( (int)ob->query_skill("force",1) < 150 )
 {
  command("say ԭ����˵��������ڹ�̫����,����ŬŬ�������һ�°�!\n");
  return;
 }
 if(ob->query("marks/killed_hu")!=1)
 {
  command("say ԭ����˵��������û�����赶ɱ����仰 �������������µĵ�������\n");
  return;
 }
//ԭ����˵��������û�����赶ɱ����仰 �������������µĵ�������

 command("smile");
 command("say �ܺã��ܺã��ܺá�");
 command("recruit " + ob->query("id") );
}
 
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","���𵺵���");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","���𵺵���");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","���𵺵���");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","����������");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","����������");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","������ȸ��");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","������ȸ��");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","���𵺰׻���");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","���𵺰׻���");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","����������");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","����������");
                return ;
        } else
                student->set("title","����ɽׯ��ׯ��");
                return ;

}

*/