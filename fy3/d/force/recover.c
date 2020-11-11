// recover.c

inherit SSERVER;

int exert(object me, object target, int amount)
{
        if( target != me ) return 
notify_fail("��ֻ�����ڹ������Լ�����Ϣ��\n");

	if(amount == -1) amount = 20;
	else if(amount < 20 ) 
                return notify_fail("�����ö�ʮ������\n");

        if( (int)me->query("force") < amount )
                return notify_fail("�������������\n");

        me->receive_heal("kee", (10 + (int)me->query_skill("force")/10)*amount/20 );
        me->add("force", -amount);

        message_vision("$N�������˼���������ɫ�������ö��ˡ�\n", me);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}
 
