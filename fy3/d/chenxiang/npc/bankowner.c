// banker.c

#include <ansi.h>

inherit NPC;
inherit F_BANKOWNER;
int ask_for();

void create()
{
        set_name("�Ϲ�ʮ����", ({ "nangong" }) );
        set("title", RED "Ǯׯ�ƹ�" NOR);
        set("gender", "����" );
        set("richness",100000);
        set("age", 52);
        set("long",
                
                "��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����Ϲ�ʮ��Ҳ���Ϲ�����
������\n");

        set("attitude", "friendly");

        set("max_atman", 1000);         set("atman", 1000);             
set("atman_factor", 3);
        set("max_force", 1000);         set("force", 1000);             
set("force_factor", 3);
        set("max_mana", 1000);          set("mana", 1000);              
set("mana_factor", 3);
    set("inquiry", ([
                "������װ" : (: ask_for :),
        ]) );

        set_skill("dodge", 10);
        set_skill("parry",100);
        setup();
        carry_object("/obj/cloth")->wear();
     //   add_money("gold", 1);
}

void init()
{
        ::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
        add_action("do_loan","loan");
}

int accept_object(object who, object ob)
{
  object silk;
  if(ob->query("id") == "goodguancai")
        {
command("say ��л��λ" + RANK_D->query_respect(who)+ "Զ���ѹײ���������û�뵽�ײĵ��ϰ�����ô�õ����գ�
���Ǹ���ĸ�л��\n");
silk = new("/questobj/big");
silk->move(who);
        tell_object(who,"�Ϲ�ʮ���ɸ���һ��"+silk->query("name")+"��\n");
//silk->move(this_object());
//command("give jin-nang to " + who->query("id"));
who->add("bigtasks",1);
        return 1;
        }
 if(ob->query("pname") != who->query("name")) 
   {
    tell_object(who,query("name") + "˵�����ⲻ����ģ�û�ա�\n");
    who->set_temp("nofly",0);
    return 1;
   }
 if(who->query("letter") < time())
   {
    tell_object(who,query("name") + "˵�����������ˣ��������ˣ�\n");
    who->set_temp("nofly",0);
    return 1;
   }
 if(ob->query("toname") == query("name"))
  {
   command("say ��л��λԶ�����ܺ����������Ǹ���Ļغ�,�м�Ҫ���ܺã���\n");
   who->set_temp("nofly",0);
   silk = new("/d/dali/obj/huihan");
   silk->set("pname",who->query("name"));
   silk->move(who);
   return 1;
  }
        tell_object(who,"�Ϲ�ʮ����˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
}

int ask_for()
{
	
	object ob,me,obj;
	me = this_player();
	ob = this_object();

	if (me->query("marks/newbie"))
		{
		message_vision("$n�ɻ��Ŷ���$N˵�����㲻���Ѿ��ù�������װ�ˣ�\n",me,ob);
		return 1;
		}
	if (!me->query_temp("askfornewbie"))
		{
		message_vision("$n�ɻ��Ŷ���$N˵����������ʲô��\n",me,ob);
		return 1;
		}
	else 	if (me->query_temp("askfornewbie")>0 && me->query_temp("askfornewbie") < 2)
		{
		me->set_temp("askfornewbie",2);
		message_vision(me->query("name")+"�����Ϲ�ʮ����˵������˵ʮ������Ƿ��������˵�һ�������ӣ��Ƿ����д��£�\n"+
"�Ϲ�ʮ���ɺ��ɻ�ؿ���"+me->query("name")+"��\n�Ϲ�ʮ���ɻش�"+me->query("name")+"����һ�������ӣ������Ѿ����Ҹ�ʮ���ɻ��������ͷ�ˣ���ô����ͷ���ǵ��ˣ�\n",me);
		return 1;
		}
	else if (me->query_temp("askfornewbie")>3 && me->query_temp("askfornewbie") < 5)
	{
	me->set_temp("askfornewbie",7);
	message_vision(me->query("name")+"�����Ϲ�ʮ����˵����ԭ�������������˸���ˣ��������ص�����ʮ����������Ǹ��\n�Ϲ�ʮ���ɳ���"+me->query("name")+"Ц��Ц������ͷ�Ӿ�Ȼ������������һ�ף�\n��һ������ˡ����ˣ�û���ˣ�����Ի�ȥ�����ˣ�\n",me);
	return 1;
	}
	message_vision("$n�ɻ��Ŷ���$N˵�����㻹��������ʲô��\n",me,ob);
	return 1;

}


