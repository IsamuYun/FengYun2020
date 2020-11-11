// yiru@hero

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIY "����" NOR, ({ "gold dragon", "dragon", "goose_money" }) );
	set("unit", "ֻ");
	set("value", 0);
	set("long", HIC"һֻ������������������Ľ�����\n
	�����ÿ����(checkdragon)һ�����Ƿ����µ���\n
	��סÿ��(ָ��Ϸ�е�һ��)ֻ����һ�ε����¹���ε��Ժ�Ͳ��������ˡ�\n\n"NOR);
	set_weight(10000);
	set("no_drop", 1);
	set("no_get", 1);
	set("check_num",0);
}

void init()
{
    add_action("do_check", "checkdragon");
}

int do_check(string arg)
{
	object gold;
    object me = this_player();
if( !objectp(present("dragon", me)) )
return notify_fail("������û������������\n");
        if( this_player()->query("id") != query("player_id") ) 
        {
                return 0;
        }

    if( query("check_num") >= 5 )
    {
    	write("��ֻ������ħ���Ѿ�ɥʧ�ˡ�\n");
    	destruct(this_object());
        return 1;
    }
        
    if( !arg || arg == "" ) 
        return notify_fail("��ʽ��checkgoose <pot/gold/exp>\n");
    
    if( time()-query("last_check") < 60*15*8 )
        return notify_fail("�����ղ���������,����Ҫ��Ϣ��\n");
            
    if( arg=="pot" )
    {
        set("last_check", time());
        add("check_num",1);
        me->add("potential", 10000+random(120000));
        tell_object(me, HIC"���Ǳ�������ˡ�\n"NOR);

	}
	else if( arg=="gold" )
	{
        set("last_check", time());
        add("check_num",1);
        gold = new("/obj/money/gold");
        gold->set_amount(1+random(14));
		gold->move(me);
        tell_object(me,
            HIY"ֻ��һ������������������������ƽ�\n"NOR);
        
    }
    else if( arg=="exp" )
    {
        set("last_check", time());
        add("check_num",1);
        me->add("combat_exp", 10000+random(180000));
        tell_object(me, HIM"��ľ��������ˡ�\n"NOR);
        
    }
    else
    {
        return notify_fail("��ʽ��checkgoose <pot/gold/exp>\n");
    }
       
    return 1;
    
}
