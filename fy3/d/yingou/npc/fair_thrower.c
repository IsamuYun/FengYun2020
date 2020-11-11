
#include <ansi.h>

inherit NPC;
void pay_him(object who, int amount);
void create()
{
	int i,amun;
	set_name( "������", ({ "huang", "huang ma zi" }) );
	set("long", "���������ķ���ְҵ���֣������ϵĹ�������뻯��\n");
	set("attitude", "friendly");
	set("title", HIW "������" NOR);
        set("force_factor", 30);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 99999);
        set("sen", 3000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);
	set("age", 33);
        set("gender", "����" );


	set("str", 35);
	set("cor", 30);
	set("cps", 25);
	set("per",5);
	set("lower_limit",1);
	set("too_late",0);
	set("first_dice",0);
        set("second_dice",0);
        set("third_dice",0);
	set("max_force",400000);
	set("force_factor",250);
	set_skill("throwing",200);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	set("combat_exp", 50000000);
	setup();
        carry_object(__DIR__"obj/yingoupao")->wear();
	carry_object(__DIR__"obj/guzi")->wield();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_bet", "bet");
	
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( "������Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����������֣������İɡ�\n");
                        break;
                case 1:
                        say( "�����ӻ��˻����е����ӣ��е�����λ" + RANK_D->query_respect(ob)
                                + "��С�Ŀ������Һ��ڣ���Ŀ��Զ���������ɣ�\n");
                        break;
                case 2:
                        say( "������˵������λ" + RANK_D->query_respect(ob)
                                + "�������������� �������ҵģ�\n");
                        break;
        }



	return;

}
 
string *dice = ({
"[31m
	�� 

[37m",
"	��

	    ��
",
"	��
	  �� 
	    ��
",
"	[31m��  ��

	��  ��
[37m",
"	��  ��
	  ��
	��  ��
",
"	�� ��
	�� ��
	�� ��
"
		});
int do_bet(string arg)
{
        int i,bet_amt;
        int bet_type;
        object me, gold;
        string message;
	if(!arg || !sscanf(arg, "%d %d",bet_type,bet_amt))
                return notify_fail("bet <����> <����>\n");
	if(bet_type>18 || bet_type < 0)
		return notify_fail("����ֻ�ɴ��㵽ʮ��\n");
	me = this_player();
	gold = present("gold_money", me);
	if(!gold) return notify_fail("������û�н��ӡ�\n");
	if((int) gold->query_amount() < bet_amt)
	return notify_fail("������û���������ӡ�\n");	
	if((int) this_object()->query("lower_limit") > bet_amt)
	return notify_fail("����̨����С��ע��"+chinese_number((int) this_object()->query("lower_limit"))+"�����ӡ�\n");
        if((int) this_object()->query("too_late") )
        return notify_fail("�����������ˣ������ְɣ�\n");
	if((int) me->query("gamble/amount"))
	{ 
	if(bet_type != (int) me->query("gamble/type"))
	return notify_fail("�㲻����һ�����²�ͬ��ע��\n");
        gold->add_amount(-bet_amt);
        me->start_busy(1);
        if(bet_type == 0)
                message = sprintf(RED"С"NOR);
        if(bet_type == 1)
                message = sprintf(RED"��"NOR);
        if(bet_type == 2)
                message = sprintf(RED"Χ��"NOR);
        if(bet_type >=3)
                message = sprintf(RED"%s"NOR,chinese_number(bet_type));
       message_vision(sprintf("$N�ִ������ó�%s���ƽ𣬼�ѹ��%s�ϣ�\n",
                                chinese_number(bet_amt), message), me);
        bet_amt += (int) me->query("gamble/amount");
                me->set("gamble/amount",bet_amt);

	}
	else
	{
	gold->add_amount(-bet_amt);
	me->start_busy(1);
	if(bet_type == 0)	
		message = sprintf(RED"С"NOR);
	if(bet_type == 1)
		message = sprintf(RED"��"NOR);
        if(bet_type == 2)
                message = sprintf(RED"Χ��"NOR);
	if(bet_type >=3)
                message = sprintf(RED"%s"NOR,chinese_number(bet_type));
	message_vision(sprintf("$N�������ó�%s���ƽ�ѹ��%s�ϣ�\n",
				chinese_number(bet_amt), message), me);
	me->set("gamble/type",bet_type);
	me->set("gamble/amount",bet_amt);
	}
	if( find_call_out("rolldice") == -1)
		call_out("rolldice",30);
	if( find_call_out("rolldice") >10 && find_call_out("advertise") == -1)
		call_out("advertise",random(5)+1);
return 1;
}
void advertise()
{
        switch( random(3) ) {
                case 0:
message_vision("$N����Ц��������ע����ע��һ����Ӯ��\n",this_object());
                        break;
                case 1:
message_vision("$N˵�����ٲ���ע���������ˣ�\n",this_object());
                        break;
                case 2:
message_vision("$N�����⣬�����Ŵ�ң��ӣ��ټӴ���Ķ�ע��һ��Ӯ��\n",this_object());

                        break;
        }

        if( find_call_out("rolldice") >=10)
                call_out("advertise",random(4)+5);
return;
}

void rolldice()
{
	this_object()->set("too_late",1);
	message_vision("$N�����е����¶�ע��˵�գ������е����������������\n",this_object());
	message_vision("\n������������������������ţ������ö�������������\n",this_object());
	call_out("first_dice",1);
return;
}

void first_dice()
{
	int first;
        switch( random(3) ) {
                case 0:
        message_vision("\nһ�����ӵ��˼��£�ͣ�ڣ�\n\n",this_object());
                        break;
                case 1:
        message_vision("\nһ�����ӣ����������������˼��£�������ͣ��������\n\n",this_object());
                        break;
                case 2:
        message_vision("\n���������໥һײ��һ��ֱ����ף�\n\n",this_object());

                        break;
        }

	first = random(6);
	message_vision(dice[first], this_object());
	this_object()->set("first_dice",first+1);
	call_out("second_dice",1);
return;
}

void second_dice()
{
	int second;
        switch( random(3) ) {
                case 0:
       message_vision("\n��һ�����ӻ�����ͣ��������\n\n",this_object());
                        break;
                case 1:
        message_vision("\n�ڶ��������������ת��ͣ�������ط��˸���\n\n",this_object());
                        break;
                case 2:
        message_vision("\n���������໥һײ������һ������һ����\n\n",this_object());

                        break;
        }
        second= random(6);
        message_vision(dice[second], this_object());
        this_object()->set("second_dice",second+1);
	call_out("third_dice",1);


return;
}
void third_dice()
{
        int third;
        switch( random(3) ) {
                case 0:
       message_vision("\n���һ�����������ﻬ�����£�����ͣ�ڣ�\n\n",this_object());
                        break;
                case 1:
        message_vision("\n�������һ�����������޵�ת����ͣ�������ڣ�\n\n",this_object());
                        break;
                case 2:
        message_vision("\n���һ������Ҳ����ͣ���ˣ�\n\n",this_object());

                        break;
        }
        third= random(6);
        message_vision(dice[third], this_object());
        this_object()->set("third_dice",third+1);
        call_out("end_the_round",1);


return;
}

void end_the_round()
{
	int tot,reward,i,first, second, third;
	object *inv;
	first = (int) this_object()->query("first_dice");
        second= (int) this_object()->query("second_dice");
        third = (int) this_object()->query("third_dice");

// announce results:
message_vision(sprintf("\n$N�����е���%s��%s��%s��",
		chinese_number(first),chinese_number(second),chinese_number(third)),
		this_object());
// see who is the winner!
if( second == first && third == first)
{
message_vision("��Сͨ�ԣ���\n",this_object());
inv = all_inventory(environment(this_object()));
        for(i=0; i<sizeof(inv); i++) {
	if( userp(inv[i]) && (int) inv[i]->query("gamble/amount") )
	{
		if((int) inv[i]->query("gamble/type") == 2)
		{
		message_vision("Ӯ�ң�$N��һ����ʮ������\n",inv[i]);
		reward = (int) inv[i]->query("gamble/amount") * 37 * 10000;
// also increae his betting skill
		inv[i]->improve_skill("betting", reward/10000);
		pay_him( inv[i],reward);
		}
		inv[i]->set("gamble/amount",0);
	}
        }


}
else
{
tot = first+second+third;
message_vision(sprintf("%s�㣬",chinese_number(tot)),this_object());
if( tot>10 )
message_vision("����С��\n",this_object());
else
message_vision("��С�Դ�\n",this_object());


inv = all_inventory(environment(this_object()));
        for(i=0; i<sizeof(inv); i++) {
        if( userp(inv[i]) && (int) inv[i]->query("gamble/amount") )
        {
		if((int) inv[i]->query("gamble/type") == tot)
		{
                message_vision("Ӯ�ң�$N��һ��ˣ�\n",inv[i]);
                reward = (int) inv[i]->query("gamble/amount") * 9 * 10000;
// also increae his betting skill
                inv[i]->improve_skill("betting", reward/10000);
                pay_him( inv[i],reward);
		}
		else {
                if(((int) inv[i]->query("gamble/type") == 0 && tot <=10 ) ||
			((int) inv[i]->query("gamble/type") == 1 && tot > 10 ))
                {
                message_vision("Ӯ�ң�$N��һ��һ��\n",inv[i]);
                reward = (int) inv[i]->query("gamble/amount") * 2 * 10000;
// also increae his betting skill
                inv[i]->improve_skill("betting", reward/10000);
                pay_him( inv[i],reward);
                }
		}
                inv[i]->set("gamble/amount",0);
        }
        }


}
this_object()->set("too_late",0);
this_object()->set("first_dice",0);
this_object()->set("second_dice",0);
this_object()->set("third_dice",0);

return;
}
void pay_him(object who, int amount)

{
        object ob;
        object cash, tencash, gold, silver, coin;

        if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}
int accept_object(object who, object ob)
{
	int bet_type;
	string message;
	
                if( ob->value() >= 10000) {
                        say("�����ӺǺǵ�Ц����л��...\n");
	message_vision("$N��$n�����ֹ��˼��䣮��\n",this_object(),who);
	bet_type = random(19);
        if(bet_type == 0)
                message = sprintf(RED"С"NOR);
        if(bet_type == 1)
                message = sprintf(RED"��"NOR);
        if(bet_type == 2)
                message = sprintf(RED"Χ��"NOR);
        if(bet_type >=3)
                message = sprintf(RED"%s"NOR,chinese_number(bet_type));

	tell_object(who,"���������ĸ����㣺���ֶ�ѹ"+message+"��һ��Ӯ��\n");
	message_vision("$N���ĵ�΢Ц��������\n",who);
	
                        return 1;
                } else {
                    say("������˵�������Ǯ�㻹���Լ��ðɣ�\n");
                        return 0;
                }
        return 0;
}

