// recover.c

inherit SSERVER;

int perform(object me, object target, int amount)
{
        int force, lvl;
                int n1,n2;
        force =(int) me->query("force") - (int) me->query("max_force");
        if( force <=100) return notify_fail("����������㡣\n");
        lvl = me->query_skill("herb");
        if (random(lvl) < 50)
        {               me->add("force", -100  );
                        message_vision("$N�˹�������׼����$n�Ķ��رƳ����⣮����\n", me, me);
                        return notify_fail("��ʧ���ˡ�\n");
        }
        else
        {
                        n1=me->query_condition("sxy-job");
                        n2=me->query_condition("songxin_job");
                
                me->clear_condition();      
            message_vision("����һ�����Ѫ�����˳�����$N�ɹ��رƳ���$n���ڵľ޶���\n", me ,me);

                        if(n1>0)
                        {
                                me->apply_condition("sxy-job",n1);
                        }
        
                        if(n2>0)
                        {
                                me->apply_condition("songxin_job",n2);
                        }

                return 1;
        }
}
 


