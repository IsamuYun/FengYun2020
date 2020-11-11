// by Tiandi for upgrading lifexiang
inherit NPC;
#include <ansi.h>
void create()
{
	set_name(HIG"β�����"NOR, ({ "tianjun" }) );
	set("gender", "����" );
	set("age", 1233);
	set("title","��Ƕ��ʦ");
	set("long", "Ϊ���������ޣ�β�޾ſ����γɲ���֮β����β���Ƕ�ɱ�������ܵ�������λ���ʶ��ס� \Nβ��֮�ղ�����һ���˹��з������ǻ����ô��գ�����֮���б����� \n");
	set("combat_exp",20000000 );
	set("attitude", "friendly");
	set("chat_chance", 1);
	set("chat_chance_combat", 50 );
	set("chat_msg", ({   "β����������칬��ʮ���ǣ�ÿһ�Ƕ����Լ���ְ�𣬶��ҵ�ְ�����������Ƕ������\n",}) );
	set("chat_msg_combat", ({"β�����ŭ���������ҵĵ������£�������ˣ�\n", "β�����������Ҳ�þ�û����չ�ֹ��ˣ�\n", }) );
	set("inquiry", (["��Ƕ��" : "ÿһ�Ѿ����ɳ�������װ����������Ƕ��ǿ��ʯ���ﵽ���õ���������ʮ�����У�ֻ�����������������(upgrade)��Ƕ���ɡ�",   
		           "��������" : "�����������������ǣ��ǡ�����ص�������ġ�β������" ,
		           "��Ƕ�ص�" : "��Ƕ����װ��ֻ��������¯�ĵط����С�" ,
			"������Ƕ��": "������Ƕ������Ҫ���ľ��飬Ǳ���Լ����ۡ�" ]));
	setup();
}
void init(){
	object ob;
     	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	 {
		 remove_call_out("greeting");
		 call_out("greeting", 1, ob);
	  }
	add_action("do_upgrade", "upgrade");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) 
		return;
	say( "β�����˵����������Ƕ������Ҫ����һ�����۵ģ�����ѡ�񰡡�����\n");
}
int do_upgrade()
{
	object me;
	me=this_player();
	if (!me->query("lifexiang"))  
	{
	message_vision("$N˵����$n��������Ƕ���ɣ���������ΰ�����������\n",this_object(), me);    
           	return 1;  
	}
	if (me->query("lifexiang") > 19)
	{	
	write("�����Ƕ�������������ˡ�\n"); 
			return 1;
	}
	if (me->query("combat_exp") < 7000 *me->query("lifexiang"))
	 {
	 	write("��ľ��鲻��"+chinese_number(7000 *me->query("lifexiang"))+"��\n"); 
		return 1;
	}
	if (((int)me->query("potential") - (int) me->query("learned_points")) < 1000*me->query("lifexiang"))    
	{
		write("���Ǳ�ܲ���"+chinese_number(1000 *me->query("lifexiang"))+"��\n");
		return 1;
	}
	if (me->query("score") < 20*me->query("lifexiang"))    
	{
		write("������۲���"+chinese_number(20 *me->query("lifexiang"))+"��\n");
		return 1;
	}
	if((int)me->query("lifexiang_exp") < ((int)me->query("lifexiang") * (int)me->query("lifexiang"))  )
	{
		write("Ŀǰ����Ƕ�����㻹û����ȫ���գ���ȥ����һ�°�\n");
		return 1;
	}
	me->add("max_lifetili",10);

	me->add("combat_exp",-7000 *me->query("lifexiang"));
	me->add("potential",-1000*me->query("lifexiang"));
	me->set("lifexiang_exp",0);
	me->add("lifexiang",1);
	me->add("score",-20*me->query("lifexiang"));
	message_vision("$N����$nһ����Ƕ���ĵã�$n��ʱé���ٿ���$N����$n���Դ�˵�������ӿɽ̰���\n",this_object(), me);
	write(HIW"�����Ƕ���ɽ����ˡ�\n"NOR);
	if (me->query("lifexiang")==20)
		message("system",HIC "\n�����ַ��ơ���������"+me->query("name")+"����Ƕ������ͻ���ͽ��������"HIY"�����������塿"HIC"�ĳƺš�\n" NOR,users());

	return 1;
}
