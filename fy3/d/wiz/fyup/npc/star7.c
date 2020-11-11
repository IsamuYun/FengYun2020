inherit NPC;
//written by Tiandi for uplevel duanzao
#include <ansi.h>
int do_up();
void create(){       
set_name(HIG"箕宿天君"NOR, ({ "tianjun" }) );
set("title", "铠神");
set("gender", "男性" );
set("age", 1233);
set("long", "箕宿是东方第三宿，为苍龙之胸，万事万物皆了然于心。龙胸，乃龙之中
心要害，重中之重，故多吉。 箕宿之星吉庆多，招得横财贺有功，葬埋若还逢此日，
一年之内进钱财。 \n");
set("combat_exp",20000000 );
set("attitude", "friendly");
set("chat_chance", 1 );
set("chat_chance_combat", 50 );
set("chat_msg", ({                "箕宿天君道：我们二十八星，每一星都有自己的职责，而我的职责就是提升炼制技能！\n",    }) );
set("chat_msg_combat", ({           "箕宿天君怒道：敢在我这闹事，不想活了！\n",           "箕宿天君道：非得逼我出手嘛！\n", }) );
set("inquiry", ([  "提升技能" : "提升炼制技能需要消耗经验，潜能，评价和金钱。",
              "确认提升" : (: do_up :),
              "东方七宿" : "东宫苍龙所属七宿是：角、亢、箕、房、心、尾、箕。"       ]));
setup();}
void init(){
object ob;
::init();
if( interactive(ob = this_player()) && !is_fighting() ) {           remove_call_out("greeting");     call_out("greeting", 1, ob);     }}
void greeting(object ob){
if( !ob || environment(ob) != environment() ) return;
say( "箕宿天君说道：提升炼制技能是要付出一定黄金和评价。。。\n");
}
int do_up()
{
object me,gold;
me=this_player();
if (!me->query("lifearmor"))  
{
message_vision("$N说道：$n还不会炼制吧，你让我如何帮你提升啊！\n",this_object(), me);                 return 1;  
}
if (me->query("lifearmor") > 9)
{
	write("你的炼制不能再提升了。\n"); return 1;
}
if (me->query("level") <= me->query("lifearmor")*8) {   write("你的等级不足提升。\n"); return 1;}
if (me->query("combat_exp") < me->query("lifearmor")*5000*me->query("lifearmor")) {   write("你的经验不足提升。\n"); return 1;}
if (((int)me->query("potential") - (int) me->query("learned_points")) < 1000*me->query("lifearmor"))    {write("你的潜能不足。\n");return 1;}
if (me->query("score") < 100*me->query("lifearmor"))    {write("你的评价不足。\n");return 1;}
 gold = present("gold_money", me);
            if(!gold) {
				printf("你身上没有金子。\n"); 
				return 1;
			}
            if((int) gold->query_amount() < 20*me->query("lifearmor"))
	{
				printf("你身上没有%s两黄金。\n",chinese_number(20*me->query("lifearmor")));
				return 1;
	}
if((int)me->query("lifearmor_exp") < (int)me->query("lifearmor") * (int)me->query("lifearmor") )
{write("目前的炼制技能你还没有完全掌握，怎么可以学更高级的东西？\n");return 1;}

me->add("combat_exp",-5000*me->query("lifearmor")*me->query("lifearmor"));
gold->add_amount(-20*me->query("lifearmor"));
me->add("potential",-1000*me->query("lifearmor"));
me->set("lifearmor_exp",0);
me->add("lifearmor",1);
me->add("score",-100*me->query("lifearmor"));
message_vision("$N教了$n一遍炼制的心得，$n顿时茅塞顿开。$N拍着$n的脑袋说道：孺子可教啊！\n",this_object(), me);
write(HIW"你的炼制技能进步了。\n"NOR);
	if (me->query("lifearmor")==100)
		message("system",HIC "\n【快乐风云】谜题任务："+me->query("name")+"在炼制技巧上突飞猛进，获得了"HIY"【制甲神童】"HIC"的称号。\n" NOR,users());

return 1;}
