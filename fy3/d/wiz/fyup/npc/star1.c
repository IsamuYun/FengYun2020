inherit NPC;
//written by Tiandi for lifeskills init
#include <ansi.h>
int do_ask();
void create(){       
	set_name(HIG"�������"NOR, ({ "tianjun" }) );
	set("gender", "����" );
	set("age", 1233);
	set("title","�����������ʦ");
	set("long", "Ϊ��������֮�ף�������������������ǡ����ǣ��˶�ɱ֮�׳壬�ʶ��ס�
		����ֵ�ղ����ᣬ��������²��ɣ�������������գ�����֮�����־��� \n");
	set("combat_exp",20000000 );
	set("attitude", "friendly");
	set("chat_chance", 1 );
	set("chat_chance_combat", 50 );
	set("chat_msg", ({               
		"��������������Ƕ�ʮ���ǣ�ÿһ�Ƕ����Լ���ְ�𣬶��ҵ�ְ������������ǽ������\n",    }) );
	set("chat_msg_combat", ({           
		"�������ŭ���������������£�������ˣ�\n",           
		"�������������Ҳ�þ�û����չ�ֹ��ˣ�\n", }) );
	set("inquiry", ([ 
		"�����" : (: do_ask:),              
		"lifeskills" : (: do_ask :),              
		"��������" : "�����������������ǣ��ǡ�����ص�������ġ�β������"       ]));
	setup();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {           
		remove_call_out("greeting");     
		call_out("greeting", 1, ob);     
		}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "�������˵�����������д�����û���������в�ͨ�ġ�\n");
}
int do_ask()
{
	object me;
	me=this_player();
	if (me->query("level") < 5 ) 
		{
		message_vision("$N˵����$n��ȥĥ��ĥ���ɣ����㵽���弶�������ң�\n",this_object(), me);
		return 1;
		}
	if (me->query("longstory")>=4)
	{
		message_vision("$N˵��������ѧ�������գ�Ҳ����Ҫ��һ���ض����ģ�\n",this_object(), me);
		return 1;
	}
	if (me->query("longstory")!=3)
	{
		message_vision("$N˵�����ҵ�������Ҫ���ڸ���Ե֮�˵ģ������㻹û�����Ե�֣�\n",this_object(), me);
		return 1;
	}
	me->set("longstory",4);
	me->set("lifecook",1);
	me->set("lifedoctor",1);
	me->set("lifeweapon",1);
	me->set("lifearmor",1);
	me->set("lifexiang",1);
	me->set("lifecombine",1);
	message_vision("$N˵��:����$n�Ѿ������˿���ѧϰ����ܵĵȼ��ˣ��Ҿʹ�������Щ���ܰɣ�\n",this_object(), me);
	message_vision("$N�ᰴ$n���Դ������ķ���һ���߲�֮â�����һ����$n�о�������ܣ�lifeskills���ƺ���Щ����\n",this_object(), me);
	write("��ѧ������⿣�docook����\n��ѧ����������dolian����\n��ѧ���˶��죨duanzao����\n��ѧ�������ƣ�lianzhi����\n��ѧ���˺ϳɣ�combine����\n��ѧ������Ƕ��xiang����\n");
	return 1;
}
