// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("Ҷ�³�", ({ "master ye", "master", "master gucheng" }) );
        set("nickname", HIW "���Ƴ���"NOR);
        set("gender", "����" );
set("reward_npc", 1);
	set("class","baiyun");
    set("difficulty", 230); 
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 100);
	set("max_kee",99999999);
        set("max_gin",999999);
        set("max_sen",999999);
	set("eff_kee",999999);
	set("kee",999999);
	set("tianwaifeixian",10);
	set("inquiry", (["Ѱ��" : "��˵��һȺ��Ĺ�ߴӻ������õ��˲��ٽ����鱦���ٸ����Ϸ���Э��������£�����Ȥ֮ʿ���Բμӡ�(job)",   
		"Ѱ��ʧ��" : "�����������á�(jobfail)",  
						]));

        set("chat_chance", 1);
        set("chat_msg", ({
                "Ҷ�³Ǵӵ��Ѫ�ߵİ���˺��һ��������\nҶ�³��ôӵ��Ѫ�ߵİ���˺�µĲ������Լ����ˡ�\n",
        }) );

        set("long",
"
���Ƴ�����ǰ���������ٺ͹�ɣ������ڣ�����
��֪���Ǳ����Ű������˵��˿�����ȫ���ã�����
\n"
	);
        create_family("���Ƴ�", 2, "����");

        set("combat_exp", 100000000);
        set("score", 200000);
       set("no_arrest",1);
        set_skill("move", 500);
	set_skill("daode",1000);
        set_skill("parry", 1000);
        set_skill("dodge", 500);
        set_skill("force", 500);
        set_skill("literate", 800);
	set_skill("sword", 1000);
	set_skill("feixian-steps",1000);
	set_skill("feixian-sword",1000);
        set_skill("jingyiforce",1000);
        set_skill("feixianforce",1000);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");


        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/bsword")->wield();
	carry_object(__DIR__"obj/bcloth")->wear();

}
void init()
{
	add_action("do_quest", "job");
	add_action("do_questfail", "jobfail");
}


void attempt_apprentice(object me)
{
	if( me->query("class")&&me->query("class") != "baiyun")
	{
	command("stare");
	command("say ���Ѿ����Լ��������ˣ�\n");
	}
	else if( me->query("national") == "����" )
	{
	command("smile");
	command("say �ܺã��Ұ��ƳǾͿ������������ˣ�\n");
            command("recruit " + me->query("id") );
	}
	else
	command("say ���Ƴ�ֻ�պ���֮�ˣ�\n");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "baiyun");
}
 
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("level");
        if( exp <= 10 ) {
                student->set("title","���Ƴǵ���");
                return ;
        } else if ( exp <= 20 ) {
                student->set("title","���Ƴ����");
                return ;
        } else if ( exp <= 30 ) {
                student->set("title","���Ƴ�С�ܼ�");
                return ;
        } else if ( exp <= 40 ) {
                student->set("title","���Ƴǹܼ�");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","���ƳǴ�ܼ�");
                return ;
        } else if ( exp <= 60 ) {
                student->set("title","���Ƴ��ܹ�");
                return ;
        } else if ( exp <= 70 ) {
                student->set("title","���ƳǴ��ܹ�");
                return ;
        } else
                student->set("title","���ƳǸ�����");
                return ;

}
int do_questfail()
{
	if (this_player()->query("score")<100)
		return notify_fail("�����;���ϣ��Ͻ�ȥ�������\n");
	this_player()->add("score",-100);
	command("say �ðɣ��۳���һ�ٵ�������Ϊ�ͷ���");
	this_player()->delete("inyequest");
	return 1;
}


int do_quest()
{
	object me,ob;
	string place,placename;
	int lv,i;
	me = this_player();
	lv = me->query("level");
	if (lv < 71)
		return notify_fail("��ĵȼ���������ʮһ����\n");
	if (me->query("inyequest"))
		return notify_fail("���Ѿ��������񣬸Ͽ�ȥ������ī����ɶѽ��\n");

	ob = new("/d/wiz/fyup/npc/daomu");
	i = random(100);
	if (i < 10)
	{
		place = "/d/xj/zhenlong";
		placename = "�������½���������";
		me->set_temp("daomu",1);
	}
	else if (i < 20)
	{
		place = "/d/bat/ren3";
		placename = "�����������ϵĹ·����";
		me->set_temp("daomu",2);
	}
	else if (i < 30)
	{
		place = "/d/taishan/nantian";
		placename = "������̩ɽ�ϵ�������";
		me->set_temp("daomu",3);
	}
	else if (i < 40)
	{
		place = "/u/guanwai/inn";
		placename = "�����˹����ӭ÷��ջ";
		me->set_temp("daomu",4);
	}
	else if (i < 50)
	{
		place = "/u/wudang/zhixiao";
		placename = "�������䵱��������";
		me->set_temp("daomu",5);
	}
	else if (i < 60)
	{
		place = "/u/resort/back_yard";
		placename = "��������ѩ��ɽׯ��Ժ";
		me->set_temp("daomu",6);
	}
	else if (i < 70)
	{
		place = "/u/palace/dating";
		placename = "�����˵����ȵĴ���";
		me->set_temp("daomu",7);
	}
	else if (i < 80)
	{
		place = "/d/tieflag/rock0";
		placename = "�����˳������Ľ�ʯ";
		me->set_temp("daomu",8);
	}
	else if (i < 90)
	{
		place = "/d/shenshui/ruanhong";
		placename = "��������ˮ�������ɽׯ";
		me->set_temp("daomu",9);
	}
		else 
	{
		place = "/d/qingping/garden";
		placename = "��������ƽɽׯ�ĺ�԰";
		me->set_temp("daomu",10);
	}

	ob->set("owner",me->query("name"));
	command("say �ӳ�͢��������Ϣ����˵ĳһ�����ķ�Ĺ��"+placename+"���������������һ�������˴����ĵ�Ĺ�ߣ��ٸ�������ƥ��Ĺ���Ѿ������ˡ�");
	command("say ������ǰȥ����Ĺ�ߵ��ֵı����أ�");
	ob->move(place);
	ob->set("owner",me->query("id"));
	ob->set("name",me->query("name")+"�������õĵ�Ĺ��");
	me->set("inyequest",1);
	me->apply_condition("daomujob", 99);
	
	return 1;
}
int accept_object(object who, object ob)
{
        object gift,gold;
        int  exp, pot, score, val,lv, extra, reb,ti,doubletime,doubletype;
	string test,file,*name;
	mapping quest;

	if(ob->query("name") == "�߲�˿�д�" && ob->query("realsilk"))
{
	command("say ���������ˣ������㻭ױ����ȥ�ɣ�\n");
	command("say �����书��΢��������\n");
	command("say �˹����µ��������ҵĺ��ѣ�Ҳ�����ɰ����㣮\n");
	who->set_temp("marks/ye",1);
	return 1;
}
        if(!(quest =  who->query("inyequest")))
	{
        tell_object(who,"Ҷ�³�˵�������н����������ô��\n");
	return 0;
	}
        if( (string)ob->query("id") != "money box")
        {
        tell_object(who,"Ҷ�³�˵�����������ʲô�Ʊ��ɡ�\n");
        return 0;
        }
	if( ob->is_character())
        {
        tell_object(who,"Ҷ�³�˵�������ѣ�������ʲô��˼��\n");
        return 0;
        }
        else
        {
        tell_object(who,"Ҷ�³�˵�����úúã���Ȼ�����û��˵����ĲƱ������¿���͢���˻���ʲô����Ҷĳ���ʱȣ�\n");
	lv = who->query("level");
	reb = who->query("reborned");
    exp = who->query("level");
	doubletime = who->query("doubletime");
	doubletype = (int)who->query("doubletype");
	ti = who->query_temp("yejobtemp");
	exp = 100*exp;
	exp = exp + exp/10*ti;
	exp = exp + exp/5*reb;
	//write(exp+"/20000*"+ti);
	if (doubletime - time() > 0)
		exp = exp*(doubletype+1);
	pot = exp /7;
	score = reb+1;  

	who->add("combat_exp",exp);
	who->add("potential",pot);
    who->add("score",score);
  	tell_object(who,HIW"�㱻�����ˣ�\n" +
	chinese_number(exp) + "��ʵս����\n"+
	chinese_number(pot) + "��Ǳ��\n"+
	chinese_number(score)+"������\n" NOR);
	if (ti==10)
		{
		if ( who->query("level")>89)
				gift=new("/d/wiz/fyup/obj/hongbao5");
		else if ( who->query("level")>79)
				gift=new("/d/wiz/fyup/obj/hongbao4");
		else if ( who->query("level")>69)
				gift=new("/d/wiz/fyup/obj/hongbao3");
		else if ( who->query("level")>59)
				gift=new("/d/wiz/fyup/obj/hongbao2");
		else if ( who->query("level")>49)
				gift=new("/d/wiz/fyup/obj/hongbao1");	
		else gift=new("/d/wiz/fyup/obj/hongbao");
		gift->move(who);
		score = 60 + random(40);
		score = score + score/5*reb;
		gold=new("/obj/money/gold");
	    gold->set_amount(lv);
	    gold->move(who);
		who->add("score",score);
		who->add("combat_exp",exp);
		who->add("potential",pot);
  		tell_object(who,HIY"�㱻���⽱���ˣ�\n" +
		chinese_number(exp) + "��ʵս����\n"+
		chinese_number(pot) + "��Ǳ��\n"+
		chinese_number(lv) + "���ƽ�\n"+
		chinese_number(score)+"������\n" NOR);
		tell_object(who,HIY"���������һ�ֶᱦ����Ҷ�³�������һֻ��������������С�\n"NOR);
		}
	ti ++;
	if (!ti) ti = 1;
	if (ti >10) ti = 1;
	who->set_temp("yejobtemp", ti );
          who->add("yejob", 1 );
	who->set("inyequest",0);
            return 1;
        }
                return 1;
}
