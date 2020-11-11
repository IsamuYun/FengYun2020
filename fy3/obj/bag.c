
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIY "包裹" NOR, ({ "bag"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
	    set("no_drop",1);
	    set("no_get",1);
	   set("long","一件包裹。");
        }
        setup();
}
void init()
{
        add_action("do_finish", "finish");
}

int do_finish(string arg)
{
        object ob,money,me,target;
        int gold, combatexp,pot;
        string file,location,*roomlines,objid,output;

		  me = this_player();
		  if (!arg) return notify_fail("请使用finish <id>。\n");

        ob = present(arg, environment(this_player()));
        if( !ob ) return notify_fail("这里没有这个人。\n");

        if (userp(ob)) return notify_fail("这是任务道具，只能交给NPC。\n");
	    if (ob->query("name") != me->query("hubiao"))
		return notify_fail("你看看清楚，到底是给谁的包裹！\n");
	    combatexp = me->query("level");
                gold = combatexp ;
                gold = gold*2;
				pot = combatexp*50;
	    money = new("/obj/money/gold");
	    money->set_amount(gold);
	    money->move(me);
		me->add("potential",pot);
                message_vision("$N高兴的说道：谢谢$n送来的包裹，这是给$n的酬劳，请收下！\n",ob,me);
                write (HIY"你获得了"+pot+"点潜能和"+gold+"两黄金！\n你的气血恢复到最大值！\n"NOR);	
	    me->delete("hubiao");
	    me->add("hubiaojob",1);
		me->set("eff_kee",me->query("max_kee")+me->query_temp("apply/addeffkee"));
		me->set("kee",me->query("eff_kee"));
                me->apply_condition("biaojob", 0);
	    me->delete("no_fly");
	   if (!random(5))
		{
      		  file = read_file("/quest/dynamic_location");
       		  roomlines = explode(file,"\n"); 
    	              location = roomlines[random(sizeof(roomlines))];

            	    if( catch(load_object(location)) || !load_object(location) )
              		  {
                    		    write("刷新地点出现问题，请汇报WIZ。地点是"+location+"。\n");
                  		      return 1;               
          			      }
		target = new ("/d/wiz/fyup/npc/jiefei");
		target->move(location);
		message("rumor", HIM"【谣言惑众】某人：听说拦路劫匪在"+ environment(target)->query("short")+"附近专门打劫护镖的人，请各位英雄速速前去围剿，他们身上可能携带意想不到的财物。\n" NOR,users());
	}
	 destruct(this_object());
        return 1;
}


