inherit NPC;
#include <ansi.h>
int send_shu();
void create()
{
        set_name("����ˮ", ({ "qiushui", "xiao qiushui" }) );
set("long","һ��������һ��������ΪѰ�Һ��֪���Ʒ����س�������\n");
        set("nickname", RED"һ������"NOR);
        set("attitude", "heroism");
        create_family("���ݽ���",1,"����");
set("str", 80);
        set("cor", 80);
        set("cps", 80);
        set("agi",80);
	set("int",80);
        set("combat_exp", 10000000);
	 set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 30);
       set("inquiry", ([
"Ȩ����" : (: send_shu :),
"quanli" : (: send_shu :), ]));
set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
    "����ˮ�ʵ�������λС�ֵܣ��Ƿ񿴼��Ʒ���\n",
    "����ˮ�ʵ�������λС����Ƿ񿴼��Ʒ���\n",
     (: random_move :),        }) );
        set("chat_chance", 80);

set("chat_msg_combat", ({
                (: perform_action, "sword.jingtianyijian" :),
  (: perform_action, "dodge.hongyeluanfei" :),
  (: perform_action, "sword.jingtianyijian" :),
   (: exert_function, "junwang" :),
 (: exert_function, "jinduan" :),
        }) );
	set_temp("apply/damage",500);
	set_skill("sword",150);
	set_skill("force",100);
        set_skill("parry",120);
        set_skill("dodge",100);
	set_skill("noloveforce",120);
       set_skill("literate",100);
	set_skill("huanhua-sword",200);
       set_skill("huanhua-steps",200);
	map_skill("dodge","huanhua-steps");
	map_skill("force","noloveforce");
	map_skill("sword","huanhua-sword");
        setup();

        carry_object("/obj/shu");
        carry_object("/obj/ruxue")->wield();
       carry_object("/obj/oldskin")->wear();
}
void attempt_apprentice(object me)
{
        if(me->query_temp("for_xiao"))
	{
        command("say �ðɣ���Ȼ���Ʒ������ѣ�������ɣ�һͬ�������Ԫ˧��\n");
       command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("shake");
        command("say �����Ц�ģ��������ʸ�����Ϊͽ��\n");
	}
	}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shenzhou");
}

void init()
{add_action("do_look","look");

        }
int accept_object(object me, object obj)
{
	if(obj->query("for_xiao"))
	{
	me->set_temp("for_xiao",1);
        command("ack");
        command("say �����Ʒ��Ľ�ָ���������Ʒ�����������Ϊͽ��\n");
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
student->set("title","���ݽ������");
                return ;
        } else if ( exp <= 10000 ) {
           student->set("title","���ݽ������");
                return ;
 } else if ( exp <= 18000 ) {
student->set("title","���ݽ���С��");
                return ;
 } else if ( exp <= 30000) {
student->set("title","���ݽ�������");
                return ;
        } else if ( exp <= 60000 ) {
       student->set("title","���ݽ��帱̳��");
                return ;
        } else if ( exp <= 120000 ) {
             student->set("title","���ݽ���̳��");
                return ;
        } else if ( exp <= 300000 ) {
                student->set("title","���ݽ��帱����");
                return ;
        } else if ( exp <= 800000 ) {
                student->set("title","���ݽ�������");
                return ;
        } else if ( exp <= 2000000 ) {
          student->set("title","���ݽ����ܹ�");
                return ;
        } else if ( exp <= 6000000 ) {                student->set("title","���ݽ��廤��");
                return ;
        } else if ( exp <= 12000000 ) {                student->set("title","���ݽ����ܻ���");
                return ;
        } else                student->set("title","���ݽ��帱����");
                return ;

}
int accept_fight(object me)
{
        command("fear");
        command("say ������֪���Ƕ��֣����ñ��ˡ�");
        return 0;
}
int do_look(string arg)
{
if (arg == "oldman" )
{
write("һ������ɨ�ص���ͷ��\n");
write("��������Լ��ʮ���ꡣ\n");
write("�书��������������С�ɣ������ƺ����ᡣ\n");
return 1;
}
return 0;
}
int send_shu()
{
        object shu,me;
	me = this_player();
say("����ˮ˵������λ" + RANK_D->query_respect(me) +"����ξ�ٶ��������İɣ��������Ÿ��������Ի����ס�\n");
	if( shu = present("shu", this_object())) {;	;	       shu->move(me);
message_vision(HIY "$N��һ���Ž�����$n���ֿ�ʼɨ���ˡ�\n" NOR, this_object(), me );
	}
        return 1;
}
