//by tiandi for lifeskill
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIY"�Ĵ���"NOR, ({ "deposit box","box"}) );
        set_weight(5000000);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "ֻ");
        set("long", "һֻΪ���׼�������ӣ�����԰����������߿��ܻ���ʧ����Ʒ��ʱ�Ĵ�(tempin)�ڴ˴����´����ߵ�ʱ����ȥȡ(tempout)������\n���ǽ���ֻ��24Сʱ֮����Ч������24Сʱ��Ʒ�ͱ�ϵͳ�����ˡ�\n");
		set("value", 10000);
		set("no_clean_up", 1);
	}
}
void init(){
	add_action("do_in", "tempin");
	add_action("do_out", "tempout");
}
int do_in(string arg)
{
	object me, ob;
	int lv,already_deposit;
	me = this_player();
	already_deposit = this_object()->query("already_deposit/"+me->query("id"));
	lv = (int)me->query("level");
    if ( lv /10 < already_deposit )
		return notify_fail("������Ŀǰ�ĵȼ��������ټĴ���Ʒ�ˡ�\n");
	if (me->query("score") < 20)
		return notify_fail("�Ĵ���Ҫ����20�����ۡ�\n");
	if( !arg ) 
		return notify_fail("��Ҫ�Ĵ�ʲ�ᶫ����\n");
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û���ⶫ����\n");
	if(me->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");
	if( ob->query("value") < 4 )
		return notify_fail("��ֻ�ܼĴ��м�ֵ�Ķ�����\n");
	if( ob->query("selfmaking") )
		return notify_fail("�㲻�ܼĴ�������Ʒ��\n");
//	score = me->query("score");
//	if (score < 10)
//		return notify_fail("������۲���10�㡣\n");
	me->add("score",-20);
	ob->move(this_object());
	ob->set_temp("ownerid",me->query("id"));
	ob->set_temp("oldname",ob->query("name"));
	ob->set("name",me->query("name")+"��"+ ob->query("name"));
	ob->set_temp("intime",time() + 60*60*24);
	this_object()->add("already_deposit/"+me->query("id"),1);
	message_vision("$N��$n�Ž��˼Ĵ����ڡ�\n",me,ob);
	return 1;
	
}

int do_out(string arg)
{
	object me, ob;
	int lv,already_deposit;
	me = this_player();
	if( !arg ) 
		return notify_fail("��Ҫȡ��ʲ�ᶫ����\n");
	if( !objectp(ob = present(arg, this_object())) )
		return notify_fail("�Ĵ�����û���ⶫ����\n");
	if(me->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");
	if(ob->query_temp("ownerid")!= me->query("id"))
		return notify_fail("�������������Ĵ�ġ�\n");
	if(time() - ob->query_temp("intime") > 0)
	{
		destruct(ob);
		return notify_fail("�����Ʒ��ŵ�ʱ���Ѿ�������24Сʱ��ϵͳ�Զ�ɾ����\n");
	}
	ob->move(me);
	ob->delete_temp("ownerid");
	ob->set("name",ob->query_temp("oldname"));
	this_object()->add("already_deposit/"+me->query("id"),-1);
	message_vision("$N��$n�ӼĴ�����ȡ�˳�����\n",me,ob);
	return 1;
}
