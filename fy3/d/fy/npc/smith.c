#include <ansi.h>

inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg);
string ask_me(); //����ask_me
int do_gu(string arg); 
int do_dapi(string arg); 
int do_cuihuo(string arg); 
void reward(object me); 

void create()
{
        set_name("������", ({ "zhang" }) );
        set("gender", "����" );
        set("age", 52);
        set("long","������һ���������������鴫��������������������ã�\n");
        	  set_temp("kf_tufei",56);
        set("pursuer", 1);
		set("combat_exp", 5);
        set("attitude", "friendly");
		set("inquiry", ([ 
			"����" : (: ask_me :), 
			"job" : (: ask_me :), 
		]));

		setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{	
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

add_action("do_gu", "gu"); 
add_action("do_dapi", "dapi"); 
add_action("do_cuihuo", "cuihuo"); 

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "����������������˵������λ" + RANK_D->query_respect(ob)
                                + "�����˼������������ˣ����Լ����Աߵ�¯�Ӷ���ɡ�\n");
                        break;
                case 1:
                        say( "������������ˮ˵������λ" + RANK_D->query_respect(ob)
                                + "����̫æ�ˣ��ﲻ���㡣\n");
                        break;
        }
}

string ask_me() 
{ 
object me = this_player(); 

if (!me->query("longstory"))
{
	me->set("longstory",1);
	write( YEL"��λ���Ѹ�̤�뽭���ɣ����������е���ѧ�ˣ���������������������ʶ��\n"
	+ "����ɳ���ͬʱ�������ѡ������(upgrade)����������ĳЩ�����ʱ���õı�����ܾͻ���֮ǰ��ͬ�ˡ�\n"
		+ "ÿ������������������������ɷ���(distribute)������������ĸ������ϾͿ����˰����ˡ�\n"
		+ "�����ڽ������Ҳ��Ҫ���Ľ�Ǯ�ģ�����û��Ǯ�ǲ��еģ�Ȼ��Ǯ������ô�������ġ�\n"
		+ "�����������������򹤣���������и���ؿ��Ե��㣬���������ǿ�������Ŷ��\n"NOR);
}

if (this_object()->is_busy()) //��鳡���Ƿ�busy
return "�����ں�æ����Ȼ�ɣ�"; 
if (me->query("level") > 5 ) //���lv
return "�����ϸ����δ�������˰ɣ�"; 

if (me->query("workforzhang") > 100 ) //���lv
return "�����ϸ����δ�������˰ɣ�"; 

if (me->query("kee") < 50) //�����
return "�㻹��Ъ����ɣ�Ҫ�ǳ��������ҿɳе�����"; 


if (me->query_temp("smith/gu")) //�����
return "����ķ��䣬����ô��ĥ��(gu)��"; 

if (me->query_temp("smith/dapi")) 
return "�������������û��(dapi)��"; 


switch(random(3))//���������������
{ 
case 0: 
me->set_temp("smith/gu", 1); 
return "�ã�����ҹ�һ�������(gu)��"; 

case 1: 
me->set_temp("smith/dapi", 1); 
return "�����ɣ�����Ҵ�һ������(dapi)��"; 

case 2:
me->set_temp("smith/cuihuo", 1); 
return "ȥ���Ұ���Щ�ճ�¯�Ĵ�һ�»�(cuihuo)��"; 
} 
} 

int do_gu(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("��������æ��\n"); 

if (! me->query_temp("smith/gu")) 
{ 
message_vision("$n��͵͵������ķ�������˼���硣" 
"������$N��$n��ȵ����������Ҹ�ʲô��\n", 
this_object(), me); 
return 1; 
} 

message_vision("$n����ķ��ƴ������������$N���˵��˵�ͷ��\n", 
this_object(), me); 
reward(me); 
return 1; 
} 

int do_dapi(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("��������æ��\n"); 

if (! me->query_temp("smith/dapi")) 
{ 
message_vision("$n���𼸿���������������˵ࡣ" 
"������$N��$n��ȵ������£��Ҹ�ʲô��\n", 
this_object(), me); 
return 1; 
} 

message_vision("$n���Ŵ��ӶԸճ�¯�Ļ��ȵ����������ô��ţ�" 
"$N���š���һ��������ȥ��Щ���⡣\n", 
this_object(), me); 
reward(me); 
return 1; 
} 

int do_cuihuo(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("��������æ��\n"); 

if (! me->query_temp("smith/cuihuo")) 
{ 
message_vision("$n�ճ���һ������õ����ӣ�" 
"������$N��$n��ȵ������£�����Ҹ㻵�ˡ�\n", 
this_object(),me);
return 1; 
} 

message_vision("$N����ǯ����һ��������ӣ������ˮ" 
"�أ����ꡱ��һ��������ð��\n", 
me); 
reward(me); 
return 1; 
} 

void reward(object me) //�������������佱�ͣ��Ƴ����
{ 
object coin; 
int lv,exp;
lv= me->query("level");
me->delete_temp("smith/gu"); 
me->delete_temp("smith/dapi"); 
me->delete_temp("smith/cuihuo"); 


this_object()->start_busy(2);
message_vision("$N��$n�������Ǹ���Ĺ�Ǯ��\n", 
this_object(), me); 
if (me->query("level") < 6) 
{
	exp = 10*lv + random(20);
	coin = new("/obj/money/coin"); 
coin->set_amount(exp *2); 
coin->move(this_player()); 
me->add("combat_exp", exp); 
me->add("potential", exp/7);
me->add("workforzhang",1);
write("������\n"+chinese_number(exp)+"�㾭�顣\n");
write(chinese_number(exp/7)+"��Ǳ�ܡ�\n");
write(chinese_number(exp*2)+"��Ǯ��\n");
} 
me->receive_damage("kee", 30); 
me->start_busy(4); 
} 