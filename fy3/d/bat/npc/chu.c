// servant.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int answer_inquiry();
//string kill_passenger(object who);
void create()
{
        set_name("������", ({ "master chu", "chu", "master" }) );
        set("title", "��˧");
		set("nickname", HIY "�������" NOR);
    set("reward_npc", 1);
    set("difficulty", 150); 

        set("gender", "����");
        set("age", 34);       
        create_family("����Ʈ��", 1, "��ʿ");

        set("long",
"��˫ü���泤�������������������������˫�峺�����磬ȴ�����������ݡ�������
ֱͦ��������ǿ�����ϵ���ʯ�ĳ������Ǳ����ģ�������̵��죬����Ҳ��Щ��ᣬ��
ֻҪ��һЦ��������ǿ�ͱ������ᣬ���Ҳ����ͬ�飬��������ů�Ĵ��紵���˴�ء�\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 100000000);
       
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luori" :),
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������������ǰ������÷��ʦһ�Σ��Ǵ��������ض�����ȥ�λ�ɽʱԶԶ�ƹ���һ�ۡ� \n",
        }) );
      

        set("force", 77000);
        set("max_force", 7700);
        set("force_factor", 70);
        set("skill_public", 1);

        set("inquiry", ([
                "����": (: answer_inquiry :),
        ]) );

        set_skill("force", 150);
        set_skill("unarmed", 120);
        set_skill("parry", 150);
        set_skill("dodge", 320);
 	    set_skill("move", 320);
 	    set_skill("literate", 150);

        set_skill("bibo-force", 150);
        set_skill("luoriquan", 200);
     set_skill("fengyu-piaoxiang", 320);
	    set_skill("stealing",320);

        map_skill("force", "bibo-force");
        map_skill("unarmed", "luoriquan");
        map_skill("dodge", "fengyu-piaoxiang");
     map_skill("move", "fengyu-piaoxiang");


        setup();

        carry_object(__DIR__"obj/whitecloth")->wear();

}
int answer_inquiry()
{
	object ob,room;
	ob=this_player();
    say("������ͻȻ���зų������Ĺ�â���૵���
���𵺣�Ŷ�����������ˣ�������������������Ҫȥ�ǰ�һ����Ҫ�������飬
�������Ҳ����Ȥ������ȥ����֮�����š�\n\n");
   message_vision("$N��������һ������ʱ���˼������Ȥ���Ͻ���������ȥ.....\n", ob); 
   room = load_object("/d/bat/bfd1");
   if(room) ob->move(room);


    return 1;
	

}

void init()
{
//  object ob;
  ::init();
  add_action("do_qiecuo", "qiecuo");
/*  ob=this_player();
  if(ob->query("marks/killed_hu")) 
                kill_ob(ob);*/
 
}
void attempt_apprentice(object ob)
{

 command("say Ϊ��ʦ���ǲ��ҵ��ģ��������ˣ�
����������(qiecuo)һ�£��������������Ƿ�����˵��ң�");

}

int recognize_apprentice(object ob)
{
  if(!ob->query("marks/win_chu_time"))
	  return 0;
  if((time() - ob->query("marks/win_chu_time") ) > 900)
  {
    say("������˵�����������ѧ�˲����ˣ�������������(qiecuo)һ�°ɣ�\n");
    return 0;
  }
 return 1;
}

int do_qiecuo()
{
    mapping guild;
    int skee,dkee;
    object me,target;
	
	me=this_player();
	target=this_object();
	skee=target->query("kee");
	//if who have win master chu,and the time is not beyond 900 sec,then do this way
	if((time()-me->query("marks/win_chu_time"))<900)
	{
     command("say ��Ĺ����治�����������д�����\n");
	 return 1;
	}
	//if who have qiecuo,and the time have beyond 2 hours,then he can qiecuo
	if(time() - me->query("marks/qiecuo_last_time")>72000)
	{
     
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
	 say("\n������Ц��������һ�У�������\n");
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
     say("\n������Ц�����������У�������\n");
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
     say("\n������Ц�����������У�������\n");
	 dkee=target->query("kee");
     if(!(dkee<skee)) 
	 {
      say("������Ц�������������ѹ�����������Щ�����ɣ�\n");
	  me->set("marks/qiecuo_last_time",time());
     }
	 else
	 {
            
      say("\n������˵������Ĺ����治�����ӽ��Ժ����Ǿ��໥ѧϰ�ɣ�\n");
	  me->set("marks/win_chu_time",time());
	 }
	 return 1;
	}
    say("������˵�����㲻��ǰ������ң��������ٱȰɣ�\n");
    return 1;
}

