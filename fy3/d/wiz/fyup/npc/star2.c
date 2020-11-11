inherit NPC;
//written by Tiandi for uplevel duanzao
#include <ansi.h>
int do_up();
void create(){       
set_name(HIG"氐宿天君"NOR, ({ "tianjun" }) );
set("title", "匠神");
set("gender", "男性" );
set("age", 1233);
set("long", "氐宿是东方最后一宿，为龙尾摆动所引发之旋风。故氐宿好风，一旦特别明亮就是起风的预兆，\n
因此又代表好调弄是非的人物、主口舌之象，故多凶。氐宿值日害男女，官非口舌入门来，一切修造不用利，\n
	婚姻孤独守空房。  \n");
set("combat_exp",20000000 );
set("attitude", "friendly");
set("chat_chance", 1 );
set("chat_chance_combat", 50 );
set("chat_msg", ({                "氐宿天君道：我们二十八星，每一星都有自己的职责，而我的职责就是提升锻造技能！\n",    }) );
set("chat_msg_combat", ({           "氐宿天君怒道：敢在我这闹事，不想活了！\n",           "氐宿天君道：非得逼我出手嘛！\n", }) );
set("inquiry", ([  "提升技能" : "提升锻造技能是要付出一定的经验，潜能，黄金和评价。。。。",
              "确认提升" : (: do_up :),
              "东方七宿" : "东宫苍龙所属七宿是：角、亢、氐、房、心、尾、箕。"       ]));
setup();}
void init(){
object ob;
::init();
if( interactive(ob = this_player()) && !is_fighting() ) {           remove_call_out("greeting");     call_out("greeting", 1, ob);     }}
void greeting(object ob){
if( !ob || environment(ob) != environment() ) return;
say( "氐宿天君说道：提升锻造技能是要付出一定的经验，潜能，黄金和评价。。。\n");
}
int do_up()
{
object me,gold;
me=this_player();
if (!me->query("lifeweapon"))  
{
message_vision("$N说道：$n还不会锻造吧，你让我如何帮你提升啊！\n",this_object(), me);                 return 1;  
}
if (me->query("lifeweapon") > 9)
{
	write("你的锻造不能再提升了。\n"); return 1;
}
if (me->query("level") <= me->query("lifeweapon")*8) {   write("你的等级不足提升。\n"); return 1;}
if (me->query("combat_exp") < me->query("lifeweapon")*5000*me->query("lifeweapon")) {   write("你的经验不足提升。\n"); return 1;}
if (((int)me->query("potential") - (int) me->query("learned_points")) < 1000*me->query("lifeweapon"))    {write("你的潜能不足。\n");return 1;}
if (me->query("score") < 100*me->query("lifeweapon"))    {write("你的评价不足。\n");return 1;}
 gold = present("gold_money", me);
            if(!gold) {
				printf("你身上没有金子。\n"); 
				return 1;
			}
            if((int) gold->query_amount() < 20*me->query("lifeweapon"))
	{
				printf("你身上没有%s两黄金。\n",chinese_number(20*me->query("lifeweapon")));
				return 1;
	}
if((int)me->query("lifeweapon_exp") < (int)me->query("lifeweapon") * (int)me->query("lifeweapon")   )
{write("目前的锻造技能你还没有完全掌握，怎么可以学更高级的东西？\n");return 1;}

me->add("combat_exp",-5000*me->query("lifeweapon")*me->query("lifeweapon"));
gold->add_amount(-20*me->query("lifeweapon"));
me->add("potential",-1000*me->query("lifeweapon"));
me->set("lifeweapon_exp",0);
me->add("lifeweapon",1);
me->add("score",-100*me->query("lifeweapon"));
message_vision("$N教了$n一遍锻造的心得，$n顿时茅塞顿开。$N拍着$n的脑袋说道：孺子可教啊！\n",this_object(), me);
write(HIW"你的锻造技能进步了。\n"NOR);
	if (me->query("lifeweapon")==100)
		message("system",HIC "\n【快乐风云】谜题任务："+me->query("name")+"在锻造技巧上突飞猛进，获得了"HIY"【铸造大师】"HIC"的称号。\n" NOR,users());

return 1;}
