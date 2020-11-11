inherit NPC;
//written by Tiandi for uplevel duanzao
#include <ansi.h>
int add_attribute(object user,int tol, int fle, int agi, int dur, int intt, int str, int con, int spi, int per, int cor, int cps, int kar);

void create(){       
	set_name(HIG"�������"NOR, ({ "tianjun" }) );
	set("title", "Ͷ̥ת��");
	set("gender", "����" );
	set("age", 1233);
	set("long", "������Ϊ����֮���ޣ�������Ⱥ���״�綷�������������ֳơ����������������ӵ��ǡ�\n
	����֮�ǳ����ǲ�������ð���ģ��ʶ��ס�����ֵ�ղ��������������벻���������񲻿��ô��գ�\n
	�ٰ����������ꡣ  \n");
	set("combat_exp",20000000 );
	set("attitude", "friendly");
	set("chat_chance", 1 );
	set("chat_chance_combat", 50 );
	set("chat_msg", ({
		"��������������Ƕ�ʮ���ǣ�ÿһ�Ƕ����Լ���ְ�𣬶��ҵ�ְ����Ǹı����壡\n",    }) );
	set("chat_msg_combat", ({
        "�������ŭ���������������£�������ˣ�\n",           "������������ǵñ��ҳ����\n", }) );
	set("inquiry", ([
		"�ı�����" : "ֻ����ͨ���ղſ��Ըı����壨change)��ÿ����������ʱϵͳ�Զ��ӵ�ķ�ʽ�Բ�ͬŶ��",
        "��������" : "�����������������ǣ���,ţ,Ů,��,Σ,��,�ڡ�"       ]));
	setup();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) 
		{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
		}
	add_action("do_change","change");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "�������˵����Ϊ�˷��㲿���������ѡ�������ûڲ��ѡ�����\n");
}
int do_change(string arg)
{
	object me;
	int lv;
	string national;
	me=this_player();
	lv = me->query("level");
	if  (me->query("class"))   
	{
		message_vision("$N˵����$n�Ѿ�������ͨ�����ˣ���������ı����壡\n",this_object(), me);    
		return 1;  
	}
	if( !arg ) return notify_fail("��Ҫ�ı��ʲô���壿(Etc:change ���� \n");
	if (arg != "����" && arg !="�ɹ���" && arg!="����")
		return notify_fail("��ʱû�����"+arg+"������塣\n");
	me->set("tol",1);
	me->set("fle",1);
	me->set("agi",1);
	me->set("dur",1);
	me->set("int",1);
	me->set("str",1);
	me->set("con",1);
	me->set("spi",1);
	me->set("per",1);
	me->set("cor",1);
	me->set("cps",1);
	me->set("kar",1);
	switch(arg){
		case "����":  
			add_attribute(me,6*lv,6*lv,6*lv,6*lv,6*lv,6*lv,6*lv,6*lv,6*lv,6*lv,6*lv,6*lv);  
			break;
		case "����":  
			add_attribute(me,6*lv,9*lv,3*lv,9*lv,6*lv,6*lv,6*lv,3*lv,3*lv,9*lv,9*lv,3*lv);
			break;
		case "�ɹ���":
			add_attribute(me,9*lv,9*lv,6*lv,6*lv,3*lv,9*lv,6*lv,6*lv,9*lv,3*lv,3*lv,3*lv);
            break;
	}
	me->set("gift_points",lv*5);
	me->set("used_gift_points",0);
	me->set("national",arg);
	message_vision("$N˵�������ˣ����Ѿ��ɹ���ת�����"+me->query("national")+"��\n",this_object(), me);
	message("system",HIY "\n�����ַ��ơ�����ת����"+me->query("name")+"������ѡ���壬�ش����뽫����ĳ���"HIC+arg+HIY"��\n" NOR,users());
return 1;
}
int add_attribute(object user,int tol, int fle, int agi, int dur, int intt, int str, int con, int spi, int per, int cor, int cps, int kar)
{
user->add("tol",tol);
user->add("fle",fle);
user->add("agi",agi);
user->add("dur",dur);
user->add("int",intt);
user->add("str",str);
user->add("con",con);
user->add("spi",spi);
user->add("per",per);
user->add("cor",cor);
user->add("cps",cps);
user->add("kar",kar);
return 1;
}
