inherit NPC;
//written by Tiandi for uplevel duanzao
#include <ansi.h>
int do_up();
void create(){       
set_name(HIG"ص�����"NOR, ({ "tianjun" }) );
set("title", "����");
set("gender", "����" );
set("age", 1233);
set("long", "ص���Ƕ������һ�ޣ�Ϊ��β�ڶ�������֮���硣��ص�޺÷磬һ���ر�������������Ԥ�ף�\n
����ִ����õ�Ū�Ƿǵ����������֮�󣬹ʶ��ס�ص��ֵ�պ���Ů���ٷǿ�����������һ�����첻������\n
	�����¶��ؿշ���  \n");
set("combat_exp",20000000 );
set("attitude", "friendly");
set("chat_chance", 1 );
set("chat_chance_combat", 50 );
set("chat_msg", ({                "ص������������Ƕ�ʮ���ǣ�ÿһ�Ƕ����Լ���ְ�𣬶��ҵ�ְ������������켼�ܣ�\n",    }) );
set("chat_msg_combat", ({           "ص�����ŭ���������������£�������ˣ�\n",           "ص����������ǵñ��ҳ����\n", }) );
set("inquiry", ([  "��������" : "�������켼����Ҫ����һ���ľ��飬Ǳ�ܣ��ƽ�����ۡ�������",
              "ȷ������" : (: do_up :),
              "��������" : "�����������������ǣ��ǡ�����ص�������ġ�β������"       ]));
setup();}
void init(){
object ob;
::init();
if( interactive(ob = this_player()) && !is_fighting() ) {           remove_call_out("greeting");     call_out("greeting", 1, ob);     }}
void greeting(object ob){
if( !ob || environment(ob) != environment() ) return;
say( "ص�����˵�����������켼����Ҫ����һ���ľ��飬Ǳ�ܣ��ƽ�����ۡ�����\n");
}
int do_up()
{
object me,gold;
me=this_player();
if (!me->query("lifeweapon"))  
{
message_vision("$N˵����$n���������ɣ���������ΰ�����������\n",this_object(), me);                 return 1;  
}
if (me->query("lifeweapon") > 9)
{
	write("��Ķ��첻���������ˡ�\n"); return 1;
}
if (me->query("level") <= me->query("lifeweapon")*8) {   write("��ĵȼ�����������\n"); return 1;}
if (me->query("combat_exp") < me->query("lifeweapon")*5000*me->query("lifeweapon")) {   write("��ľ��鲻��������\n"); return 1;}
if (((int)me->query("potential") - (int) me->query("learned_points")) < 1000*me->query("lifeweapon"))    {write("���Ǳ�ܲ��㡣\n");return 1;}
if (me->query("score") < 100*me->query("lifeweapon"))    {write("������۲��㡣\n");return 1;}
 gold = present("gold_money", me);
            if(!gold) {
				printf("������û�н��ӡ�\n"); 
				return 1;
			}
            if((int) gold->query_amount() < 20*me->query("lifeweapon"))
	{
				printf("������û��%s���ƽ�\n",chinese_number(20*me->query("lifeweapon")));
				return 1;
	}
if((int)me->query("lifeweapon_exp") < (int)me->query("lifeweapon") * (int)me->query("lifeweapon")   )
{write("Ŀǰ�Ķ��켼���㻹û����ȫ���գ���ô����ѧ���߼��Ķ�����\n");return 1;}

me->add("combat_exp",-5000*me->query("lifeweapon")*me->query("lifeweapon"));
gold->add_amount(-20*me->query("lifeweapon"));
me->add("potential",-1000*me->query("lifeweapon"));
me->set("lifeweapon_exp",0);
me->add("lifeweapon",1);
me->add("score",-100*me->query("lifeweapon"));
message_vision("$N����$nһ�������ĵã�$n��ʱé���ٿ���$N����$n���Դ�˵�������ӿɽ̰���\n",this_object(), me);
write(HIW"��Ķ��켼�ܽ����ˡ�\n"NOR);
	if (me->query("lifeweapon")==100)
		message("system",HIC "\n�����ַ��ơ���������"+me->query("name")+"�ڶ��켼����ͻ���ͽ��������"HIY"�������ʦ��"HIC"�ĳƺš�\n" NOR,users());

return 1;}