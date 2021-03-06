// mihan.c

#include <ansi.h>
#include <login.h>

inherit ITEM;

void create()
{
	set_name( "密函", ({ "mi han", "han" }) );
	set_weight(2000);
	set("no_put", 1);			// 这样东西不能放入容量
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "封");
		set("long", "这是一封密函。\n");
	}
}

void init()
{
	add_action("do_give", "give");

	remove_call_out("attract_robber");
	call_out("attract_robber", 1);

	if(query("target") ) {
		remove_call_out("set_target");
		call_out("set_target", 4, query("target"));
		delete("target");		// add 4 seconds' delay, can't be so fast
	}
}

void set_target(string target)
{
	set("target", target);
}

int do_give(string arg)
{
	object me,ob,silver, home;
	string obj,target,msg;
	int i;

	if(!arg || sscanf(arg,"%s to %s", obj, target)!=2 )
		if(sscanf(arg,"%s %s", target, obj) !=2 )	
			return 0;

	if(!id(obj) )	return 0;

	me = this_player();

	if(!ob = present(target,environment(me)) ) {
		tell_object(me,"你想要把密函交给谁？\n");
		return 1;
	}
	if(ob->query("id") != query("target") ) {
		tell_object(me, "你不能把这样东西给这个人。\n");
		return 1;
	}
	if(ob->query_temp("unconcious") ) {
		tell_object(me,ob->query("name")+"已经无法收下这样东西了。\n");
		return 1;
	}

	if(!home = find_object(ob->query("startroom")) )
		home = load_object(ob->query("startroom"));

	if(ob->query("id") != "huang shang" && ob->query("id") != "dugu qiubai" 
	&&	!userp(ob) && base_name(environment(ob)) != ob->query("startroom") ) {
		tell_object(me, ob->query("name")+"说道：你还是到" + home->query("short") + "来找我吧。\n");
		return 1;
	}

	message_vision("$N拿出一封密函交给了" + ob->query("name") + "。\n", me);
	if((time()-me->query( "biao_start" ))>me->query( "biao_time" ) ) {
		message_vision("$N很生气地对$n说道：这么点儿事都办不好，真没用！\n", ob, me);
		tell_object(me, "你没有及时把密函送到" + ob->query("name") + "的手中，你的任务失败了！\n");
		me->set("biao_failed", 1);
	}
	else {
		tell_object(me, "你成功地将密函送到了" + ob->query("name") + "的手中。\n");
		i = 1 + random(me->query("kar") );
		tell_object(me, sprintf(WHT"你获得了%s点战斗经验！\n"NOR, chinese_number(i)) );
		me->add("combat_exp", i);
		i = 2 + random(me->query("kar") );
		tell_object(me,sprintf(WHT"你获得了%s点潜能！\n"NOR, chinese_number(i / 2)) );
		me->add("potential", i / 2);
		me->delete("biao_start");
		me->delete("biao_time");
	}

	me->receive_damage("gin", 30);
	me->receive_damage("sen", 30);

	destruct(this_object());

	return 1;
}

// 设置强盗
void attract_robber()
{
	object ob, robber, room;
	int i, n;

	if(!userp(ob = environment(this_object())) ) return;

	room = environment(ob);

	if(room->query("outdoors") && random(ob->query_kar()) < 1) {
		n = ( 30 - ob->query_kar() ) / 5;
		if( n < 0 ) n = 0;
		n = random( n + 1 ) + 1;
		for( i = 0; i < n; i ++ ) {
			robber = new("/obj/npc/robber");
			robber->move(room);
		}
		return;
	}

	remove_call_out("attract_robber");
	call_out("attract_robber", 1);
}

