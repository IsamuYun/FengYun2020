inherit NPC;
//written by Tiandi for uplevel duanzao
#include <ansi.h>
int do_up();
void create(){       
	set_name(HIG"ţ�����"NOR, ({ "tianjun" }) );
	set("title", "��Ƕ��ʦ");
	set("gender", "����" );
	set("age", 1233);
	set("long", "ţ��Ϊ�����ڶ��ޣ�������Ⱥ�����ţ�Ƕ���������������������֯Ů��ǣţ�ǣ�\n
	��Ȼţ����֯Ů�����갮���������������ĸж���Ȼ���ջ����޷����ѱ����ԵĽ�֣���ţ�޶��ס�\n
		ţ��ֵ�������࣬һ���������ֶ࣬���������ô��գ�������ׯ������  \n");
	set("combat_exp",20000000 );
	set("attitude", "friendly");
	set("chat_chance", 1 );
	set("chat_chance_combat", 50 );
	set("chat_msg", ({
		"ţ������������Ƕ�ʮ���ǣ�ÿһ�Ƕ����Լ���ְ�𣬶��ҵ�ְ�����������Ƕ���ܣ�\n",    }) );
	set("chat_msg_combat", ({
        "ţ�����ŭ���������������£�������ˣ�\n",           "ţ����������ǵñ��ҳ����\n", }) );
	set("inquiry", ([
		"��������" : "������Ƕ������Ҫ����Ǳ�ܣ����ۺͽ�Ǯ��",
        "ȷ������" : (: do_up :),
        "��������" : "�����������������ǣ�ţ,ţ,Ů,��,Σ,��,�ڡ�"       ]));
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
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "ţ�����˵����������Ƕ������Ҫ����һ���ƽ�����ۡ�����\n");
}
int do_up()
{
	object me,gold;
	me=this_player();
	if (!me->query("lifexiang"))  
	{
		message_vision("$N˵����$n��������Ƕ�ɣ���������ΰ�����������\n",this_object(), me);                 return 1;  
	}
	if (me->query("lifexiang") > 19)
	{
		write("�����Ƕ�����������ˡ�\n"); return 1;
	}

	if (((int)me->query("potential") - (int) me->query("learned_points")) < 100*me->query("lifexiang"))
		{
		write("���Ǳ�ܲ��㡣\n");
		return 1;
		}
	if (me->query("score") < 10*me->query("lifexiang"))
		{
		write("������۲��㡣\n");
		return 1;
		}
	gold = present("gold_money", me);
    if(!gold) {
				printf("������û�н��ӡ�\n"); 
				return 1;
			}
    if((int) gold->query_amount() < 20*me->query("lifexiang"))
	{
				printf("������û��%s���ƽ�\n",chinese_number(20*me->query("lifexiang")));
				return 1;
	}
	if((int)me->query("lifexiang_exp") < (int)me->query("lifexiang") * 10  )
	{
		write("Ŀǰ����Ƕ�����㻹û����ȫ���գ���ô����ѧ���߼��Ķ�����\n");
		return 1;
		}
	me->add("lifexiang",1);
	gold->add_amount(-20*me->query("lifexiang"));
	me->add("potential",-100*me->query("lifexiang"));
	me->set("lifexiang_exp",0);
	me->add("score",-10*me->query("lifexiang"));
	message_vision("$N����$nһ����Ƕ���ĵã�$n��ʱé���ٿ���$N����$n���Դ�˵�������ӿɽ̰���\n",this_object(), me);
	write(HIW"�����Ƕ���ܽ����ˡ�\n"NOR);
	if (me->query("lifexiang")==20)
		message("system",HIC "\n�����ַ��ơ���������"+me->query("name")+"����Ƕ������ͻ���ͽ��������"HIY"����ʯ�����塿"HIC"�ĳƺš�\n" NOR,users());
return 1;
}
