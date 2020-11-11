// banker.c

#include <ansi.h>

inherit NPC;

#define MAX_POT_DEPOSIT		90000000

void create()
{
        set_name("����ʦ", ({ "laowushi" }) );
        set("title", HIY "ͨ�쳹��" NOR);
        set("gender", "Ů��" );
        set("age", 80);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("long",                
"һ������ͨ�쳹�׵�����ʦ������԰�Ǳ�ܴ洢�������\n pot_deposit \n pot_balance \n pot_withdraw\n\n");

        set("combat_exp", 50000000);
        set("attitude", "friendly");

        set("max_atman", 900000);         set("atman", 90000);             
set("atman_factor", 3);
        set("max_force", 900000);         set("force", 9000000);             
set("force_factor", 10000);
        set("max_mana", 900000);          set("mana", 90000);              
set("mana_factor", 3);

        set("chat_chance", 3 );
        set("chat_msg", ({
                (: exert_function, "powerfade" :),
        }) );

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set_skill("unarmed", 500);
        set_skill("dodge", 500);
        set_skill("force", 500);
        set_skill("celestrike", 500);
        set_skill("celestial", 500);
        set_skill("chaos-steps", 500);
		set_temp("apply/damage",100000);
        map_skill("force", "celestial");
        map_skill("unarmed", "celestrike");
        map_skill("dodge", "chaos-steps");

        setup();

}

void init()
{
        ::init();
        add_action("do_pot_deposit", "pot_deposit");
        add_action("do_pot_balance", "pot_balance");
        add_action("do_pot_withdraw", "pot_withdraw");
}

int do_pot_deposit(string arg)
{
	int pot;
	int old_pot;
    
    if( this_player()->is_busy() )
                return notify_fail("��Ķ�����û����ɣ����ܴ洢Ǳ�ܡ�\n");
    
    if( !arg || !sscanf(arg, "%d", pot) )
                return notify_fail("ָ���ʽ��pot_deposit <����>\n");

    if( this_player()->query("pot_deposit") >= MAX_POT_DEPOSIT )
                return notify_fail("��洢��Ǳ���Ѿ��ﵽ�˼��ޡ�\n");
	
	if( pot < 1000)
		return notify_fail("�洢��ô�ٵ�Ǳ�ܾͲ�Ҫ�˷�����ʦ�ľ�����!\n");
	
    old_pot = (int)this_player()->query("potential") - (int)this_player()->query("learned_points");

    if(pot>old_pot)
    	return notify_fail("��û����ô��Ǳ��.\n");

	this_player()->add("pot_deposit", pot);
	this_player()->add("potential", -pot);
	
	message_vision(sprintf("$N������%s��Ǳ�ܡ�\n", chinese_number(pot)), this_player());

    this_player()->save();
    this_player()->start_busy(1);

	return 1;

}

int do_pot_balance(string arg)
{
	int pot;

    if( this_player()->is_busy() )
                return notify_fail("��Ķ�����û����ɣ����ܲ鿴Ǳ�ܴ洢�����\n");

	pot = (int) this_player()->query("pot_deposit");
    if(pot <= 0)
    {
        tell_object(this_player(),"������û�д洢Ǳ�ܡ�\n");
		return 1;
	}
	
	if(pot > MAX_POT_DEPOSIT)
	{
		this_player()->set("pot_deposit",MAX_POT_DEPOSIT);
		pot = MAX_POT_DEPOSIT;
	}
	
	if(pot > 0) 
		tell_object(this_player(),"�������ܹ��洢��"+chinese_number(pot)+"��Ǳ�ܡ�\n");

	this_player()->start_busy(1);
	return 1;
}

int do_pot_withdraw(string arg)
{
	int pot;
	int old_pot;
    
    if( this_player()->is_busy() )
                return notify_fail("��Ķ�����û����ɣ�������ȡǱ�ܡ�\n");
    
    if( !arg || !sscanf(arg, "%d", pot) )
                return notify_fail("ָ���ʽ��pot_withdraw <����>\n");
	
	if( pot < 1000)
		return notify_fail("��ȡ��ô�ٵ�Ǳ�ܾͲ�Ҫ�˷�����ʦ�ľ�����!\n");
	
	old_pot = (int)this_player()->query("pot_deposit");
	if(old_pot > MAX_POT_DEPOSIT)
	{
		this_player()->set("pot_deposit",MAX_POT_DEPOSIT);
		old_pot = MAX_POT_DEPOSIT;
	}

	if(pot > old_pot)
		return notify_fail("��û�д洢��ô��Ǳ��.\n");
	
	this_player()->add("pot_deposit", -pot);
	this_player()->add("potential", pot);
	
	message_vision(sprintf("$N��ȡ��%s��Ǳ�ܡ�\n", chinese_number(pot)), this_player());

    this_player()->save();
    this_player()->start_busy(1);

	return 1;

}


