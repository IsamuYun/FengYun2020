// wei.c

inherit NPC;

#include <ansi.h>
int go_dahai(object);
void create()
{
	set_name("����", ({ "ding feng" }) );
    set("reward_npc", 1);
    set("difficulty", 80); 

	set("gender", "����" );
	set("age", 24);
	set("title",HIC  "�����ٷ�" NOR);
	set("long",
		"��������������ƮƮ�������������������Ҳ���ú�Ӣ����
���ϸ���Զ������Ц�ݡ�\n");
    set("chat_msg", ({
            "����΢Ц���������ʮ��ʽ��������ڡ��嵭������,���������ǣ��������ޣ�
��ʵ���飬�Ʊ�δ�� ��\n",
    }) );

	set("combat_exp", 700000);
	set("attitude", "friendly");
	set("per",30);
	set("force",100);
	set("max_force",100);	
	set_skill("dodge",50);
    set_skill("unarmed",250);
    set_skill("sword",100);
set_skill("dugu-sword",240);
    set_skill("meng-steps", 100);
    map_skill("sword", "dugu-sword");
    map_skill("dodge", "meng-steps");
	        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "sword.pocan" :),
                 (: perform_action, "sword.poqi" :),
        }) );
setup();
	carry_object("/obj/cloth")->wear();
    carry_object("obj/weapon/sword")->wield();

}

int accept_object(object who, object ob)
{
    
	object paper;

    if( ob->name()!="���ʮ��ʽ" )
      return 0;
    else 
	{
      remove_call_out("go_dahai");
      call_out("go_dahai", 1, ob);

      return 1;
    }
}
go_dahai()
{
      object me,room;
      string myfile;
	  me=this_player();
      say("��������Ц��Ц��\n");
      command("say �ã���������������Ҫ�ҵ����ˣ���������\n");
      tell_object(me,HIC"���ϲ��������������ĸ��Ŷ��������˴󺣴�.......\n");
	  tell_object(me,"����һ�������ϴ���æ����һ��������ඣ�
�������𷫣������򶫷����С�\n");
      room = load_object("/d/bat/dahai");
	  if(room) me->move(room);
	  
      return 1;
}

