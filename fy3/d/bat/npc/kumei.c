// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("��÷��ʦ", ({ "master kumei", "master", "kumei" }) );
        set("nickname", HIW"���ɹ�"NOR);
    set("reward_npc", 1);
    set("difficulty", 20); 


        set("gender", "Ů��" );
        set("age", 56);
        set("int", 40);
        set("spi", 21);
        set("cor", 15);
        set("con", 20);
		set("per", 15);
		set("str", 30);
		
	    set("attitude","peaceful");
        set("max_force", 9500);
        set("force", 19000);
        set("force_factor", 30);
		set("max_gin",5000);
        set("max_kee",100000);
		set("max_sen",500);
        set("long",
"����һ���׷��ԲԵ��ϸ���һ�Ÿɿ����������������˰̣�����ȱ�˰����
�۾�Ҳ����һֻ��ʣ�µ�һֻ�۾��뿪��ϣ�����֮�䣬���Ⱪ�䣬����˭Ҳ
���ұ��ӡ������Ӻ���С����ȴ����˵�����������ϣ�����˭��ֻҪ������ 
һ�ۣ���˵������������ѹ��Щ��\n"
	);
//        set("chat_chance", 1);
//        set("chat_msg", ({
//                "ԭ�����ߵ��ٱߣ�һ����������ˮ������Ӵ���ָ�������
//���伺�кܾ�û�й�����ö��������ˡ�\n",
//        }) );

        create_family("��ɽ��", 16, "����");


        set("combat_exp", 1100000);
        set("chat_chance_combat", 80);
     set("chat_msg_combat", ({
            (: perform_action, "sword.poqi" :),
        }) );

        set_skill("move", 100);
        set_skill("parry", 90);
        set_skill("dodge", 100);
        set_skill("force", 90);
	    set_skill("unarmed", 70);
	    set_skill("wuzheng-force",200);
        set_skill("literate", 100);
	    set_skill("sword",150);
	    set_skill("dugu-sword",180);
      set_skill("meng-steps",220);
        
	    map_skill("force", "wuzheng-force");
	   map_skill("parry","dugu-sword");
        map_skill("sword","dugu-sword");
        map_skill("dodge","meng-steps");
      map_skill("move","meng-steps"); 
     	

        setup();
        carry_object("/obj/weapon/sword")->wear();
        carry_object(__DIR__"obj/cloth1")->wield();
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
                ob->set("class", "huashan");
}
void do_recruit(object ob)
{
 if( (int)ob->query_skill("sword") < 200 )
 {
  command("say ��Ľ������軹�����ߣ�\n");
  return;
 }
 if( (int)ob->query("PKS") > 30 )
 {
  command("say ��ɱ��̫���ˣ����������ˣ�\n");
  return;
 }
 command("smile");
 command("say �ܺã��ܺã��ܺá�");
 command("recruit " + ob->query("id") );
}
 
void re_rank(object student)
{
       
                student->set("title","��ɽ�ɵ���");
                return ;

}
*/
