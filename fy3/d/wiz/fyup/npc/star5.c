// by Tiandi for upgrading lifecombine
inherit NPC;
#include <ansi.h>
void create()
{
	set_name(HIG"�������"NOR, ({ "tianjun" }) );
	set("gender", "����" );
	set("age", 1233);
	set("title","�ϳɴ�ʦ");
	set("long", "Ϊ���������ޣ�Ϊ������������Ϊ�����ļ���һ����Ӧ������ޣ����ͷ������ã�\N���޶���Ԫ�Ǻᣬ������Ů�����ˣ����᲻���ô��գ�����֮�ڼ����� ��\n");
	set("combat_exp",20000000 );
	set("attitude", "friendly");
	set("chat_chance", 1);
	set("chat_chance_combat", 50 );
	set("chat_msg", ({   "������������칬��ʮ���ǣ�ÿһ�Ƕ����Լ���ְ�𣬶��ҵ�ְ����������ϳ�������\n",}) );
	set("chat_msg_combat", ({"�������ŭ���������ҵĵ������£�������ˣ�\n", "�������������Ҳ�þ�û����չ�ֹ��ˣ�\n", }) );
	set("inquiry", (["�ϳ���" : "ÿһ��ǿ��ʯ������ͬ��ǿ��ʯ�ϳ�Ϊ���߼���ǿ��ʯ����ʮ�����У�ֻ�����������������(upgrade)�ϳɼ��ɡ�",   
		           "��������" : "�����������������ǣ��ǡ�����ص�������ġ�β������" ,
		           "�ϳɵص�" : "�ϳ�ǿ��ʯֻ��������¯�ĵط��ſ��ԡ�" ,
			"�����ϳ���": "�����ϳɼ�����Ҫ���ľ��飬Ǳ���Լ����ۡ�" ]));
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
	say( "�������˵���������ϳɼ�����Ҫ����һ�����۵ģ�����ѡ�񰡡�����\n");
}
int do_upgrade()
{
	object me;
	me=this_player();
	if (!me->query("lifecombine"))  
	{
	message_vision("$N˵����$n������ϳɼ��ɣ���������ΰ�����������\n",this_object(), me);    
           	return 1;  
	}
	if (me->query("lifecombine") > 19)
	{	
	write("��ĺϳ��������������ˡ�\n"); 
			return 1;
	}
	if (me->query("combat_exp") < 7000 *me->query("lifecombine"))
	 {
	 	write("��ľ��鲻��"+chinese_number(7000 *me->query("lifecombine"))+"��\n"); 
		return 1;
	}
	if (((int)me->query("potential") - (int) me->query("learned_points")) < 1000*me->query("lifecombine"))    
	{
		write("���Ǳ�ܲ���"+chinese_number(1000 *me->query("lifecombine"))+"��\n");
		return 1;
	}
	if (me->query("score") < 20*me->query("lifecombine"))    
	{
		write("������۲���"+chinese_number(20 *me->query("lifecombine"))+"��\n");
		return 1;
	}
	if((int)me->query("lifecombine_exp") < ((int)me->query("lifecombine") * (int)me->query("lifecombine"))  )
	{
		write("Ŀǰ�ĺϳɼ����㻹û����ȫ���գ���ȥ����һ�°�\n");
		return 1;
	}
	me->add("max_lifetili",10);
	me->add("combat_exp",-7000 *me->query("lifecombine"));
	me->add("potential",-1000*me->query("lifecombine"));
	me->set("lifecombine_exp",0);
	me->add("lifecombine",1);
	me->add("score",-20*me->query("lifecombine"));
	message_vision("$N����$nһ��ϳɵ��ĵã�$n��ʱé���ٿ���$N����$n���Դ�˵�������ӿɽ̰���\n",this_object(), me);
	write(HIW"��ĺϳɼ��ɽ����ˡ�\n"NOR);
	if (me->query("lifecombine")==20)
		message("system",HIC "\n�����ַ��ơ���������"+me->query("name")+"�ںϳɼ�����ͻ���ͽ��������"HIY"���Զ໻�١�"HIC"�ĳƺš�\n" NOR,users());

	return 1;
}

