inherit NPC;
//written by Tiandi for lifeskills init
#include <ansi.h>
int do_ask();
void create(){       
set_name(HIG"角宿天君"NOR, ({ "tianjun" }) );
set("gender", "男性" );
set("age", 1233);
set("long", "为东方七宿之首，有两颗星如苍龙的两角。龙角，乃斗杀之首冲，故多凶。
角宿值日不非轻，祭祀婚姻事不成，埋葬若还逢此日，三年之内有灾惊。 \n");
set("combat_exp",20000000 );
set("attitude", "friendly");
set("chat_chance", 1 );
set("chat_chance_combat", 50 );
set("chat_msg", ({                "角宿天君道：我们二十八星，每一星都有自己的职责，而我的职责就是引导你们生活！\n",    }) );
set("chat_msg_combat", ({           "角宿天君怒道：敢在我这闹事，不想活了！\n",           "角宿天君道：我也好久没有舒展胫骨了！\n", }) );
set("inquiry", ([  "生活技能" : (: do_ask:),              "lifeskills" : (: do_ask :),              "东方七宿" : "东宫苍龙所属七宿是：角、亢、氐、房、心、尾、箕。"       ]));
setup();}
void init(){
object ob;
::init();
if( interactive(ob = this_player()) && !is_fighting() ) {           remove_call_out("greeting");     call_out("greeting", 1, ob);     }}
void greeting(object ob){
if( !ob || environment(ob) != environment() ) return;
say( "角宿天君惊讶地说道：几百年过去了，总于有人来我这里了。\n");
}
int do_ask(){
object me;
me=this_player();
if (me->query("max_lifetili") ) {       message_vision("$N说道：$n已经学会了生活技能，请下界为凡间造福吧。！\n",this_object(), me);                 return 1;     }
me->set("max_lifetili",250);
me->Set("lifetili",0);
me->set("lifecook",1);
me->set("lifedoctor",1);
me->set("lifeweapon",1);
me->set("lifearmor",1);
message_vision("$N说道:不错，$n经历了足够的人间阅历，咦？等等。。。不对！好像生活能力上$n还有\n些欠缺，好，我帮你开通这些能力，等你有了足够的经验后再来找我吧！\n",this_object(), me);
message_vision("$N轻按$n的脑袋，手心发出一束七彩之芒，金光一闪后，$n感觉对生活技能（lifeskills）似乎有些感悟！\n",this_object(), me);
write("你学会了烹饪（docook）。\n你学会了炼丹（dolian）。\n你学会了锻造（duanzao）。\n你学会了炼制（lianzhi）。\n");
return 1;}
