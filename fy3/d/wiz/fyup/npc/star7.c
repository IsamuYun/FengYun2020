inherit NPC;
//written by Tiandi for uplevel duanzao
#include <ansi.h>
int do_up();
void create(){       
set_name(HIG"�������"NOR, ({ "tianjun" }) );
set("title", "����");
set("gender", "����" );
set("age", 1233);
set("long", "�����Ƕ��������ޣ�Ϊ����֮�أ������������Ȼ���ġ����أ�����֮��
��Ҫ��������֮�أ��ʶ༪�� ����֮�Ǽ���࣬�еú�ƺ��й���������������գ�
һ��֮�ڽ�Ǯ�ơ� \n");
set("combat_exp",20000000 );
set("attitude", "friendly");
set("chat_chance", 1 );
set("chat_chance_combat", 50 );
set("chat_msg", ({                "��������������Ƕ�ʮ���ǣ�ÿһ�Ƕ����Լ���ְ�𣬶��ҵ�ְ������������Ƽ��ܣ�\n",    }) );
set("chat_msg_combat", ({           "�������ŭ���������������£�������ˣ�\n",           "������������ǵñ��ҳ����\n", }) );
set("inquiry", ([  "��������" : "�������Ƽ�����Ҫ���ľ��飬Ǳ�ܣ����ۺͽ�Ǯ��",
              "ȷ������" : (: do_up :),
              "��������" : "�����������������ǣ��ǡ��������������ġ�β������"       ]));
setup();}
void init(){
object ob;
::init();
if( interactive(ob = this_player()) && !is_fighting() ) {           remove_call_out("greeting");     call_out("greeting", 1, ob);     }}
void greeting(object ob){
if( !ob || environment(ob) != environment() ) return;
say( "�������˵�����������Ƽ�����Ҫ����һ���ƽ�����ۡ�����\n");
}
int do_up()
{
object me,gold;
me=this_player();
if (!me->query("lifearmor"))  
{
message_vision("$N˵����$n���������ưɣ���������ΰ�����������\n",this_object(), me);                 return 1;  
}
if (me->query("lifearmor") > 9)
{
	write("������Ʋ����������ˡ�\n"); return 1;
}
if (me->query("level") <= me->query("lifearmor")*8) {   write("��ĵȼ�����������\n"); return 1;}
if (me->query("combat_exp") < me->query("lifearmor")*5000*me->query("lifearmor")) {   write("��ľ��鲻��������\n"); return 1;}
if (((int)me->query("potential") - (int) me->query("learned_points")) < 1000*me->query("lifearmor"))    {write("���Ǳ�ܲ��㡣\n");return 1;}
if (me->query("score") < 100*me->query("lifearmor"))    {write("������۲��㡣\n");return 1;}
 gold = present("gold_money", me);
            if(!gold) {
				printf("������û�н��ӡ�\n"); 
				return 1;
			}
            if((int) gold->query_amount() < 20*me->query("lifearmor"))
	{
				printf("������û��%s���ƽ�\n",chinese_number(20*me->query("lifearmor")));
				return 1;
	}
if((int)me->query("lifearmor_exp") < (int)me->query("lifearmor") * (int)me->query("lifearmor") )
{write("Ŀǰ�����Ƽ����㻹û����ȫ���գ���ô����ѧ���߼��Ķ�����\n");return 1;}

me->add("combat_exp",-5000*me->query("lifearmor")*me->query("lifearmor"));
gold->add_amount(-20*me->query("lifearmor"));
me->add("potential",-1000*me->query("lifearmor"));
me->set("lifearmor_exp",0);
me->add("lifearmor",1);
me->add("score",-100*me->query("lifearmor"));
message_vision("$N����$nһ�����Ƶ��ĵã�$n��ʱé���ٿ���$N����$n���Դ�˵�������ӿɽ̰���\n",this_object(), me);
write(HIW"������Ƽ��ܽ����ˡ�\n"NOR);
	if (me->query("lifearmor")==100)
		message("system",HIC "\n�����ַ��ơ���������"+me->query("name")+"�����Ƽ�����ͻ���ͽ��������"HIY"���Ƽ���ͯ��"HIC"�ĳƺš�\n" NOR,users());

return 1;}