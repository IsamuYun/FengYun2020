// by Tiandi for jifa weapon of lifeskill
inherit NPC;
#include <ansi.h>
void create()
{
    set_name(HIG"亢宿天君"NOR, ({ "tianjun" }) );
set("gender", "男性" );
set("age", 1233);
set("title","潜在能力大师");
set("long", "是东方第二宿，为苍龙的颈。龙颈，有龙角之护卫，变者带动全身，故多吉。 
亢宿之星事可求，婚姻祭祀有来头，葬埋必出有官贵，开门放水出公侯。\n");
set("combat_exp",20000000 );
set("attitude", "friendly");
set("chat_chance", 1);
set("chat_chance_combat", 50 );
set("chat_msg", ({   "亢宿天君道：天宫二十八星，每一星都有自己的职责，而我的职责就是激发武器的潜能！\n",}) );
set("chat_msg_combat", ({"亢宿天君怒道：敢在我的地盘闹事，不想活了！\n", "亢宿天君道：我也好久没有舒展胫骨了！\n", }) );
set("inquiry", (["激发" : "每一把锻造而来的兵刃铠甲都可能有潜在的能力存在于兵器之内，普通的人是没有办法开启\n他们的，二十八星中，也只有我有这个能力激发(jifa)这种属性。",              "东方七宿" : "东宫苍龙所属七宿是：角、亢、氐、房、心、尾、箕。","查询" : "如果你想了解(liaojie)自己手中兵刃铠甲的潜在能力的话，找我就对了。"  ]));
setup();
}
void init(){
object ob;     ::init();
if( interactive(ob = this_player()) && !is_fighting() ) { remove_call_out("greeting"); call_out("greeting", 1, ob);  }add_action("do_jifa", "jifa");add_action("do_jifa2", "liaojie");}
void greeting(object ob){
if( !ob || environment(ob) != environment() ) return;
say( "亢宿天君缓缓地说道：兵器也是一种生命，凡人就是不懂得珍惜使用，只把他们当作暴力的工具，可惜啊。。。\n");
}
int do_jifa(string arg){object me, ob;me = this_player();
if( !arg ) return notify_fail("你要激发什麽东西？\n");
if( !objectp(ob = present(arg, me)) )
return notify_fail("你身上没有这样东西。\n");
if(me->is_busy())
return notify_fail("你上一个动作还没有完成。\n");
if( !ob->query("selfmaking") )
return notify_fail("你只能激发锻造或者炼制的东西。\n");
if( ob->query("equipped") )
return notify_fail("这个东西正装备着呢。\n");
//   if( !ob->query("owner") )
// return notify_fail("这东西好像不是你弄出来的吧。\n");
if(ob->query("fuct")>0)
 return notify_fail(ob->query("name")+"已经没有什么潜在能力可以激发了。\n");
ob->set("fuct",random(100));
if (ob->query("fuct")<1){
ob->set("fuct",1);
}
if (ob->query("fuct")>89&&ob->query("fuct")<94){
 message_vision(HIB"$N接过$n手中的"+ob->query("name")+"，仔细地揣摩了起来，忽然$N眼睛亮了一下，笑嘻嘻地对$n说道：成呖！\n"NOR,this_object(),me);
}
else
{
 message_vision(HIB"$N接过$n手中的"+ob->query("name")+"，仔细地揣摩了起来，不一会$N摇着头对$n说道：唉，平平凡凡才是真。。。拿去吧。\n"NOR,this_object(),me);
}
me->start_busy(1);
seteuid(ROOT_UID);
ob->save();
ob->restore();
if(ob->move(me))
message_vision("$N把"+ob->name()+"归还给了$n。\n",this_object(),me);
 seteuid(getuid());
return 1;
}

int do_jifa2(string arg)
{
object me, ob;
me = this_player();
        if( !arg ) return notify_fail("你要了解什麽东西？\n");
if( !objectp(ob = present(arg, me)) )
return notify_fail("你身上没有这样东西。\n");
if(me->is_busy())
return notify_fail("你上一个动作还没有完成。\n");
if( !ob->query("selfmaking") )
return notify_fail("你只能了解锻造或者炼制的东西。\n");
if(ob->query("fuct")<1)
return notify_fail(ob->query("name")+"还未被激发它的潜在能力，先去激发了再说。\n");
else if(ob->query("fuct")>89&&ob->query("fuct")<94)
return notify_fail(ob->query("name")+"具有战斗特殊功能的潜在能力。\n");

write("真是可惜，"+ob->query("name")+"不具备任何潜在能力。\n");
 me->start_busy(1);
return 1;
}
