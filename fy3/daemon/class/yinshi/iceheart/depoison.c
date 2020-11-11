// recover.c

inherit SSERVER;

int exert(object me, object target, int amount)
{
        int force, lvl;
        int n1,n2;
        if( target != me ) return 
        notify_fail("��ֻ�����������Լ����ڶ��رƳ���\n");
        force =(int) me->query("force") - (int) me->query("max_force");
        if( force <=100) return notify_fail("����������㡣\n");
        lvl = me->query_skill("iceheart",1);
        if (random(lvl) < 35)
        {               me->add("force", -100  );
                        message_vision("$N�˹�������ͷ��ð������ĺ�������\n", me);
                        return notify_fail("��ʧ���ˡ�\n");
        }
        else
        {
                n1=me->query_condition("sxy-job");
                n2=me->query_condition("songxin_job");

                me->clear_condition();  
                write("��ɹ��ˣ�\n");

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
 

