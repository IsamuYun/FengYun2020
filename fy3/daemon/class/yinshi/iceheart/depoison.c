// recover.c

inherit SSERVER;

int exert(object me, object target, int amount)
{
        int force, lvl;
        int n1,n2;
        if( target != me ) return 
        notify_fail("你只能用真气将自己体内毒素逼出。\n");
        force =(int) me->query("force") - (int) me->query("max_force");
        if( force <=100) return notify_fail("你的真气不足。\n");
        lvl = me->query_skill("iceheart",1);
        if (random(lvl) < 35)
        {               me->add("force", -100  );
                        message_vision("$N运功抗毒，头上冒出豆大的汗．．．\n", me);
                        return notify_fail("你失败了。\n");
        }
        else
        {
                n1=me->query_condition("sxy-job");
                n2=me->query_condition("songxin_job");

                me->clear_condition();  
                write("你成功了！\n");

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
 

