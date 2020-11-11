// yiru@hero

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIY "������" NOR, ({ "gold qilin", "qilin", "goose_money" }) );
	set("unit", "ֻ");
	set("value", 0);
	set("long", HIC"һֻ������������������Ľ����롣\n
	�����ÿ����(checkqilin)һ�����Ƿ����µ���\n
	��סÿ��(ָ��Ϸ�е�һ��)ֻ����һ�ε����¹���ε��Ժ�Ͳ��������ˡ�\n\n"NOR);
	set_weight(10000);
	set("no_drop", 1);
	set("no_get", 1);
	set("check_numb",0);
}

void init()
{
    add_action("do_check", "checkqilin");
}

int do_check(string arg)
{
	object gold;
    object me = this_player();
    
        if( this_player()->query("id") != query("player_id") ) 
        {
                return 0;
        }

    if( query("check_numb") >= 5 )
    {
    	write("��ֻ�������ħ���Ѿ�ɥʧ�ˡ�\n");
    	destruct(this_object());
        return 1;
    }
        
    if( !arg || arg == "" ) 
        return notify_fail("��ʽ��checkgoose <pot/gold/exp>\n");
    
    if( time()-query("last_check") < 60*15*4 )
        return notify_fail("������ղ���������,����Ҫ��Ϣ��\n");
            
    if( arg=="pot" )
    {
        set("last_check", time());
        add("check_numb",1);
        me->add("potential", 1000+random(60000));
        tell_object(me, HIC"���Ǳ�������ˡ�\n"NOR);

	}
	else if( arg=="gold" )
	{
        set("last_check", time());
        add("check_numb",1);
        gold = new("/obj/money/gold");
        gold->set_amount(100+random(6));
		gold->move(me);
        tell_object(me,
            HIY"ֻ��һ�������������������������ƽ�\n"NOR);
        
    }
    else if( arg=="exp" )
    {
        set("last_check", time());
        add("check_numb",1);
        me->add("combat_exp", 1000+random(80000));
        tell_object(me, HIM"��ľ��������ˡ�\n"NOR);
        
    }
    else
    {
        return notify_fail("��ʽ��checkgoose <pot/gold/exp>\n");
    }
       
    return 1;
    
}
