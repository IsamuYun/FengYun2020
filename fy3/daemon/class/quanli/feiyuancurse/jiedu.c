// recover.c

inherit SSERVER;

int perform(object me, object target, int amount)
{
        int force, lvl;
                int n1,n2;
        force =(int) me->query("force") - (int) me->query("max_force");
        if( force <=100) return notify_fail("你的真气不足。\n");
        lvl = me->query_skill("herb");
        if (random(lvl) < 50)
        {               me->add("force", -100  );
                        message_vision("$N运功抗毒，准备把$n的毒素逼出体外．．．\n", me, me);
                        return notify_fail("你失败了。\n");
        }
        else
        {
                        n1=me->query_condition("sxy-job");
                        n2=me->query_condition("songxin_job");
                
                me->clear_condition();      
            message_vision("随着一大口鲜血被吐了出来，$N成功地逼出了$n体内的巨毒！\n", me ,me);

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
 


