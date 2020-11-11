#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    object ob,ob2,bag;
	int i;
	string arg;
	me = this_player();	
	arg = me->query("name")+"的拦路土匪";
	bag = present("bag",me);

	ob2 = present("gangster",environment(me));
	if (duration <1)
		return 0;
	if(!bag)
	{
		if (me->query("hubiao"))
		{
		me->delete("no_fly");
		}
		return 0;
	}
	if (duration %10)
		{
		me->apply_condition("biaojob", duration - 1);
		return 1;
		}
	 if (!ob2)
	{	
	           for (i=0;i<=random(2)+1;i++)
       		{ 
	   	 ob=new("/d/fy/npc/gangster2");
                	 ob->move(environment(me));
                	 ob->kill_ob(me);
               	 me->kill_ob(ob);
               	 ob->set_leader(me);
         		 ob->set("kee",me->query("max_kee"));
        		 ob->set("max_kee",me->query("max_kee"));
        		 ob->set("max_gin",me->query("max_gin"));
       		 ob->set("gin",me->query("max_gin"));
       		 ob->set("sen",me->query("max_sen"));
       		 ob->set("max_sen",me->query("max_sen"));
       		 ob->set("eff_gin",me->query("max_gin"));
       		 ob->set("eff_kee",me->query("max_kee"));
       		 ob->set("eff_sen",me->query("max_sen"));
       		 ob->set("force",me->query("max_force"));
             	 ob->set("level", me->query("level"));
               	 ob->set("str", me->query("str"));
               	 ob->set("int", me->query("int"));
               	 ob->set("cor", me->query("cor"));
               	 ob->set("cps", me->query("cps"));
               	 ob->set("kar", me->query("kar"));
               	 ob->set("con", me->query("con"));
               	 ob->set("spi", me->query("spi"));
               	 ob->set("con", me->query("dur"));
               	 ob->set("spi", me->query("tol"));
    		 ob->set("name",arg);
		}
            tell_object(me, HIW "你走着走着，突然发现对面跳出了一群人对你大喊：此山是我开，此树是我栽，要想从此过，留下买路财！\n" NOR );
   	}
	else if(ob2->query("name") != arg )
	{
		   for (i=0;i<=random(2)+1;i++)
       		{ 
	   	 ob=new("/d/fy/npc/gangster2");
                	 ob->move(environment(me));
                	 ob->kill_ob(me);
               	 me->kill_ob(ob);
               	 ob->set_leader(me);
         		 ob->set("kee",me->query("max_kee"));
        		 ob->set("max_kee",me->query("max_kee"));
        		 ob->set("max_gin",me->query("max_gin"));
       		 ob->set("gin",me->query("max_gin"));
       		 ob->set("sen",me->query("max_sen"));
       		 ob->set("max_sen",me->query("max_sen"));
       		 ob->set("eff_gin",me->query("max_gin"));
       		 ob->set("eff_kee",me->query("max_kee"));
       		 ob->set("eff_sen",me->query("max_sen"));
       		 ob->set("force",me->query("max_force"));
             	 ob->set("level", me->query("level"));
               	 ob->set("str", me->query("str"));
               	 ob->set("int", me->query("int"));
               	 ob->set("cor", me->query("cor"));
               	 ob->set("cps", me->query("cps"));
               	 ob->set("kar", me->query("kar"));
               	 ob->set("con", me->query("con"));
               	 ob->set("spi", me->query("spi"));
               	 ob->set("con", me->query("dur"));
               	 ob->set("spi", me->query("tol"));
    			 ob->set("name",arg);
			}
			tell_object(me, HIW "你走着走着，突然发现对面跳出了一群人对你大喊：此山是我开，此树是我栽，要想从此过，留下买路财！\n" NOR );

	}
	me->apply_condition("biaojob",duration -1);
	return 1;
}

