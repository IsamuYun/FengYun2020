inherit NPC;
//written by Tiandi for uplevel duanzao
#include <ansi.h>
int do_up();
void create(){       
set_name(HIG"ص�����"NOR, ({ "tianjun" }) );
set("title", "����");
set("gender", "����" );
set("age", 1233);
set("long", "ص���Ƕ��������ޣ�Ϊ����֮�أ������������Ȼ���ġ����أ�����֮��
��Ҫ��������֮�أ��ʶ༪�� ص��֮�Ǽ���࣬�еú�ƺ��й���������������գ�
һ��֮�ڽ�Ǯ�ơ� \n");
set("combat_exp",20000000 );
set("attitude", "friendly");
set("chat_chance", 1 );
set("chat_chance_combat", 50 );
set("chat_msg", ({                "ص������������Ƕ�ʮ���ǣ�ÿһ�Ƕ����Լ���ְ�𣬶��ҵ�ְ������������켼�ܣ�\n",    }) );
set("chat_msg_combat", ({           "ص�����ŭ���������������£�������ˣ�\n",           "ص����������ǵñ��ҳ����\n", }) );
set("inquiry", ([  "��������" : "�������켼����Ҫ����1M���飬1��Ǳ���Լ�2000�����ۡ�",
              "ȷ������" : (: do_up :),
              "��������" : "�����������������ǣ��ǡ�����ص�������ġ�β������"       ]));
setup();}
void init(){
object ob;
::init();
if( interactive(ob = this_player()) && !is_fighting() ) {           remove_call_out("greeting");     call_out("greeting", 1, ob);     }}
void greeting(object ob){
if( !ob || environment(ob) != environment() ) return;
say( "ص�����˵�����������켼����Ҫ����һ�����۵ģ�����ѡ�񰡡�����\n");
}
int do_up()
{
object me;
me=this_player();
if (!me->query("lifeweapon"))  
{
message_vision("$N˵����$n���������ɣ���������ΰ�����������\n",this_object(), me);                 return 1;  
}
if (me->query("combat_exp") < 1000000) {   write("��ľ��鲻�㡣\n"); return 1;}
if (((int)me->query("potential") - (int) me->query("learned_points")) < 10000)    {write("���Ǳ�ܲ��㡣\n");return 1;}
if (me->query("score") < 2000)    {write("������۲��㡣\n");return 1;}
if((int)me->query("lifeweapon_exp") < ((int)me->query("lifeweapon") * (int)me->query("lifeweapon"))  )
{write("Ŀǰ�Ķ��켼���㻹û����ȫ���գ���ô����ѧ���߼��Ķ�����\n");return 1;}
me->add("max_lifetili",10);
me->add("lifeweapon",1);
me->add("combat_exp",-1000000);
me->add("potential",-10000);
me->set("lifeweapon_exp",0);
me->add("score",-2000);
message_vision("$N����$nһ�������ĵã�$n��ʱé���ٿ���$N����$n���Դ�˵�������ӿɽ̰���\n",this_object(), me);
write(HIW"��Ķ��켼�ܽ����ˡ�\n"NOR);
return 1;}
