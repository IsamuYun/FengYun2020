//by tiandi for lifeskill
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIY"寄存箱"NOR, ({ "deposit box","box"}) );
        set_weight(5000000);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "只");
        set("long", "一只为玩家准备的箱子，你可以把你身上下线可能会消失的物品临时寄存(tempin)在此处。下次上线的时候再去取(tempout)出来，\n但是谨记只有24小时之内有效，超过24小时物品就被系统回收了。\n");
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
		return notify_fail("按照你目前的等级，不能再寄存物品了。\n");
	if (me->query("score") < 20)
		return notify_fail("寄存需要消耗20点评价。\n");
	if( !arg ) 
		return notify_fail("你要寄存什麽东西？\n");
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这东西。\n");
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");
	if( ob->query("value") < 4 )
		return notify_fail("你只能寄存有价值的东西。\n");
	if( ob->query("selfmaking") )
		return notify_fail("你不能寄存自造物品。\n");
//	score = me->query("score");
//	if (score < 10)
//		return notify_fail("你的评价不够10点。\n");
	me->add("score",-20);
	ob->move(this_object());
	ob->set_temp("ownerid",me->query("id"));
	ob->set_temp("oldname",ob->query("name"));
	ob->set("name",me->query("name")+"的"+ ob->query("name"));
	ob->set_temp("intime",time() + 60*60*24);
	this_object()->add("already_deposit/"+me->query("id"),1);
	message_vision("$N把$n放进了寄存箱内。\n",me,ob);
	return 1;
	
}

int do_out(string arg)
{
	object me, ob;
	int lv,already_deposit;
	me = this_player();
	if( !arg ) 
		return notify_fail("你要取回什麽东西？\n");
	if( !objectp(ob = present(arg, this_object())) )
		return notify_fail("寄存箱里没有这东西。\n");
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");
	if(ob->query_temp("ownerid")!= me->query("id"))
		return notify_fail("这个东西不是你寄存的。\n");
	if(time() - ob->query_temp("intime") > 0)
	{
		destruct(ob);
		return notify_fail("这件物品存放的时间已经超过了24小时，系统自动删除。\n");
	}
	ob->move(me);
	ob->delete_temp("ownerid");
	ob->set("name",ob->query_temp("oldname"));
	this_object()->add("already_deposit/"+me->query("id"),-1);
	message_vision("$N把$n从寄存箱内取了出来。\n",me,ob);
	return 1;
}
