 // void_sense.c
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
        int skill;
        int lv,msize,i;
		object *mem;
        
        if((int) me->query_skill("essencemagic",1) < 250)
                return notify_fail("��İ�ʶ��ͨ�������");
		mem = me->query_team();
		msize = sizeof(mem);
		if (msize < 2)
			return notify_fail("��ʶֻ���������ʹ�á�\n");
		if( me->query("atman") < 100*msize )
                return notify_fail("�������������\n");
        if( me->query("gin") <= 50*msize )
                return notify_fail("��ľ�������\n");
		skill= (int) me->query_skill("essencemagic",1);
        me->add("atman", -100*msize);
        me->receive_damage("gin", 50*msize);
        message_vision(HIY "$N˫�ֺ�ʮ����ü���ף��������� ...ɫ���ǿգ��ռ���ɫ����ʶ���Σ�Ψ����ͨ��\n" NOR, me);
     
		for(i=0;i<msize;i++)
		{
		if( environment(me) == environment(mem[i])&& mem[i]->query_temp("invoid")== 0)
			{
			 
			mem[i]->add_temp("apply/defense",skill*5);
			mem[i]->set_temp("invoid",1);
			seteuid(ROOT_UID);
			mem[i]->start_call_out( (: call_other, __FILE__, "remove_effect", me,mem[i], skill*5 :), skill/10);
			seteuid(getuid());
			message_vision(HIY"\n$N���ϱ������Ĺ�Ȧ�����ţ�$N�ķ������õ��˼�ǿ��\n" NOR,mem[i]);
			}
		}       
        me->start_busy(2);
        return 1;
} 
void remove_effect(object me,object target, int amount)
{
        target->add_temp("apply/defense", -amount);
        target->delete_temp("invoid");

        message_vision( HIR"$N����һ�ݣ����ϸ��ӵ�������ʧ�ˡ�\n" NOR, target);
}
int help(object me)
{
        write(YEL"\n��ʶ��֮ͨ��ʶ��"NOR"\n");
	write(@HELP

      �˹����µ��֮������ʱ��߶�����ҵķ�����

HELP
	);
	return 1;
}


    
       
