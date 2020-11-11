inherit NPC;
//written by Tiandi for uplevel duanzao
#include <ansi.h>
int do_up();
void create(){       
set_name(HIG"氐宿天君"NOR, ({ "tianjun" }) );
set("title", "匠神");
set("gender", "男性" );
set("age", 1233);
set("long", "氐宿是东方第三宿，为苍龙之胸，万事万物皆了然于心。龙胸，乃龙之中
心要害，重中之重，故多吉。 氐宿之星吉庆多，招得横财贺有功，葬埋若还逢此日，
一年之内进钱财。 \n");
set("combat_exp",20000000 );
set("attitude", "friendly");
set("chat_chance", 1 );
set("chat_chance_combat", 50 );
set("chat_msg", ({                "氐宿天君道：我们二十八星，每一星都有自己的职责，而我的职责就是提升锻造技能！\n",    }) );
set("chat_msg_combat", ({           "氐宿天君怒道：敢在我这闹事，不想活了！\n",           "氐宿天君道：非得逼我出手嘛！\n", }) );
set("inquiry", ([  "提升技能" : "提升锻造技能需要消耗1M经验，1万潜能以及2000点评价。",
              "确认提升" : (: do_up :),
              "东方七宿" : "东宫苍龙所属七宿是：角、亢、氐、房、心、尾、箕。"       ]));
setup();}
void init(){
object ob;
::init();
if( interactive(ob = this_player()) && !is_fighting() ) {           remove_call_out("greeting");     call_out("greeting", 1, ob);     }}
void greeting(object ob){
if( !ob || environment(ob) != environment() ) return;
say( "氐宿天君说道：提升锻造技能是要付出一定代价的，慎重选择啊。。。\n");
}
int do_up()
{
object me;
me=this_player();
if (!me->query("lifeweapon"))  
{
message_vision("$N说道：$n还不会锻造吧，你让我如何帮你提升啊！\n",this_object(), me);                 return 1;  
}
if (me->query("combat_exp") < 1000000) {   write("你的经验不足。\n"); return 1;}
if (((int)me->query("potential") - (int) me->query("learned_points")) < 10000)    {write("你的潜能不足。\n");return 1;}
if (me->query("score") < 2000)    {write("你的评价不足。\n");return 1;}
if((int)me->query("lifeweapon_exp") < ((int)me->query("lifeweapon") * (int)me->query("lifeweapon"))  )
{write("目前的锻造技能你还没有完全掌握，怎么可以学更高级的东西？\n");return 1;}
me->add("max_lifetili",10);
me->add("lifeweapon",1);
me->add("combat_exp",-1000000);
me->add("potential",-10000);
me->set("lifeweapon_exp",0);
me->add("score",-2000);
message_vision("$N教了$n一遍锻造的心得，$n顿时茅塞顿开。$N拍着$n的脑袋说道：孺子可教啊！\n",this_object(), me);
write(HIW"你的锻造技能进步了。\n"NOR);
return 1;}
