// by Tiandi for open max weapon of lifeskill
inherit NPC;
#include <ansi.h>
void create()
{
	set_name(HIG"�������"NOR, ({ "tianjun" }) );
	set("gender", "����" );
	set("age", 1233);
	set("title","�ɳ��о���ʦ");
	set("long", "�Ƕ��������ޣ�Ϊ�����ľ���������������֮���������ߴ���ȫ���ʶ༪�� ����֮���¿��󣬻�����������ͷ������س��йٹ󣬿��ŷ�ˮ�����\n");
	set("combat_exp",20000000 );
	set("attitude", "friendly");
	set("chat_chance", 1);
	set("chat_chance_combat", 50 );
	set("chat_msg", ({   "������������칬��ʮ���ǣ�ÿһ�Ƕ����Լ���ְ�𣬶��ҵ�ְ�������������װ�������������\n",}) );
	set("chat_msg_combat", ({"�������ŭ���������ҵĵ������£�������ˣ�\n", "�������������Ҳ�þ�û����չ�ֹ��ˣ�\n", }) );
	set("inquiry", (["����" : "ÿһ�Ѷ�������ı������׶��Ǵ���һ���ɳ��ռ�ģ����˶��뷽�跨�������ǵ����������\n��ȴ��֪������ʮ�����У�ֻ�����������������(uplevel)���ǵĳɳ��ռ䡣",   
		           "��������" : "�����������������ǣ��ǡ�����ص�������ġ�β������" ,
			"�鿴":"��������Ұ���鿴(check)��Ʒ�ĳɳ����ԡ�" ]));
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
	add_action("do_jifa", "uplevel");
	add_action("do_jifa2", "check");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) 
		return;
	say( "�������������˵���������ĳɳ��ɷ�Ϊ��ʮ���׶Ρ�����\n");
}
int do_jifa(string arg)
{
	object me, ob,gold;
	int lv,score,itemlv;
	me = this_player();
	if( !arg ) 
		return notify_fail("��Ҫ����ʲ�ᶫ����������\n");
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");
	if(me->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");
	if( !ob->query("selfmaking") )
		return notify_fail("��ֻ����������������ƵĶ�����\n");
	if( ob->query("equipped") )
		return notify_fail("���������װ�����ء�\n");
	//   if( !ob->query("owner") )
	// return notify_fail("�ⶫ����������Ū�����İɡ�\n");
	lv = ob->query("level");
	if( !objectp(gold = present("level sheet", me)) )
		return notify_fail("������û��ұ������\n");
	score=me->query("score");
	if (score < 10)
		return notify_fail("������۲���10�㡣\n");

	message_vision("$n�Ϲ��Ͼ��ذ����е�"+ob->query("name")+"����$N��Ц�����ض�$N˵�����ǾͰ���������ҿ���"+ob->query("name")+"�Ƿ���ʣ����������Կ�ͨ�İɡ�\n"NOR,this_object(),me);
	if(lv>19)
		{
      	message_vision(HIB"$N�ӹ�$n���е�"+ob->query("name")+"��һ�߿�һ�ߵ����ⶫ���Ѿ������������������û��ʲô�ɳ��ռ��ˡ�\n"NOR,this_object(),me);
		message_vision("$N��"+ob->name()+"�黹����$n��\n",this_object(),me);
		return 1;
		}
	else
		{
		message_vision(HIB"$N�ӹ�$n���е�"+ob->query("name")+"�����Ǽ�"+ob->query("name")+"�����ޱ�Ѥ����ɫ�ʣ���������һ�㣬�Զ����ص�$n�����С�\n"NOR,this_object(),me);
		ob->set("level",lv+1);
		
		message_vision("$N˵�������ˡ�"+ob->query("name")+"�Ѿ��ɳ�Ϊ��"+chinese_number(ob->query("level"))+"�׶Ρ�\n"NOR,this_object(),me);
		
		me->start_busy(1);
		seteuid(ROOT_UID);
		ob->save();
		ob->restore();
		if(ob->move(me))
			{
			message_vision("$N��"+ob->name()+"�黹����$n��\n",this_object(),me);
			write ("��������10�����ۡ�\n");
			me->add("score",-10);
			}
 		seteuid(getuid());
		destruct(gold);
		return 1;
		}
}

int do_jifa2(string arg)
{
	object me, ob;
	me = this_player();
         if( !arg ) 
		return notify_fail("��Ҫ�鿴ʲ�ᶫ����\n");
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");
	if(me->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");
	if( !ob->query("selfmaking") )
		return notify_fail("��ֻ���˲鿴��������Ƶ���Ʒ�ɳ��ȡ�\n");
	write(ob->query("name")+"�ĳɳ���Ϊ��"+chinese_number(ob->query("level"))+"�׶Ρ�\n");
 	me->start_busy(1);
return 1;
}
