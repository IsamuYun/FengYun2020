
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object soldier;
        int strategy,leadership, exp, MAX_GUARD, i;
        
        if ((string)me->query("class") != "dali")
        return notify_fail("�㲻�Ǵ������Ա��û�е���������Ȩ����\n");
//        if ( me->is_busy() )
//        return notify_fail("��������æ���޷��������ӡ�\n");
        if( !me->is_fighting() )
        return notify_fail("����û����Ҫɱ�㣡\n");

        strategy = (int)me->query_skill("strategy");
        leadership = (int)me->query_skill("leadership");
        exp = (int)me->query("combat_exp");
        if(strategy < 20 || leadership < 20)
        return notify_fail("�����������֮��̫���ˣ�û��Ը�����㣡\n"); 
        
        MAX_GUARD = (strategy+leadership)/60 + 1;
		if(MAX_GUARD > 8)
		{
			MAX_GUARD = 8;	
		}
		
        if( me->query_temp("max_guard") > 0 )
                return notify_fail("�������Ѿ��ܵ��㹻�ı����ˣ�\n");

        if((int)me->query("sen")< 100*MAX_GUARD)
        	return notify_fail("�����̫���ˣ�\n");

        seteuid(getuid());
        me->receive_damage("sen",100*MAX_GUARD);
        soldier= new("/obj/npc/bingtou");
        message_vision(HIC "\n$N�ӻ����ó�һ���죬����������ǰ������\n" NOR, me);   
        soldier->move(environment(me));
        message_vision(HIC "\n$N����һС�ӻ���Ӧ��������\n" NOR, soldier);
        soldier->invocation(me, (leadership+strategy));
        soldier->set("possessed", me);
        
        for(i=0;i<MAX_GUARD;i++)
        {
	        soldier= new("/obj/npc/bing");
	        soldier->move(environment(me));
	        soldier->invocation(me, (leadership+strategy));
	        soldier->set("possessed", me);
	    }

        me->set_temp("max_guard",MAX_GUARD+1);
//        me->remove_all_killer();
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��diaoji
 
���ָ���ô����Ա����һС�ӻ����������Լ���
���������ʾ�Ҫ����ҹ�ְ�Ĵ�С�ˡ�
 
HELP

    );
    return 1;
}

