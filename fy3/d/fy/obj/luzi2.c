//by tiandi for lifeskill
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("打铁炉", ({ "lu"}) );
        set_weight(5000000);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "只");
                set("long", "一只热热的打铁炉，你可以用它来\n 锻造(duanzao)武器。\n 炼制(lianzhi)装备。\n 合成(combine)强化石。\n 镶嵌(xiang)  强化石。\n 修理(repair) 防具。\n");
		set("value", 10000);
	}
}
void init(){
	add_action("do_combine", "combine");
	add_action("do_xiang", "xiang");
	add_action("do_repair", "repair");
}
int do_combine(string arg)
{
	object me, ob,*inv,obj;
	int lv,flag,lv2,exp,tili,tili_cost;
	me = this_player();
	
	lv2 = (int)me->query("lifecombine");
      exp = me->query("lifecombine_exp");
      if (lv2 < 1)
      	return notify_fail("你还不会合成之术。\n");
	if( me->is_fighting() )
                    return notify_fail("战斗中搞合成？你厉害！\n");

	if( !arg ) 
		return notify_fail("你要合成什麽东西？\n");
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这东西。\n");
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");
	if( !ob->query("qianghua") )
		return notify_fail("你只能合成带有强化属性的石头。\n");
//	score = me->query("score");
//	if (score < 10)
//		return notify_fail("你的评价不够10点。\n");
	lv= ob->query("qianghua");
	if ( lv > lv2)
                    return notify_fail("你想要合成这个级别的强化石，还得再磨练磨练。\n");
	if ( lv > 19)
                    return notify_fail(ob->query("name")+"已经不能再合成了。\n");
          tili = (int)me->query("lifetili");
      tili_cost = 50*lv;
          if( me->query("lifetili") < tili_cost )
                    return notify_fail("活力不够。\n");

	me->set("lifetili",tili-tili_cost);

     	inv = all_inventory(me);
    	obj = first_inventory(me);
            while(obj)
		{
		  reset_eval_cost();
		 if (obj->query("qianghua") ==  lv)
			{
			flag ++;
                  obj = next_inventory(obj);
			continue;
			}
		  obj = next_inventory(obj);
		}
	 if(flag <2)
  		return notify_fail("你身上没有同样的两块强化石。\n");

	if(random(lv2+1)>=lv)
		{
		message_vision(HIG"$N把两块手中的"+chinese_number(lv)+"级强化石扔进炉子里炼化，只见两块强化石逐渐融化在了一起，合成了一块"+chinese_number(lv+1)+"级强化石。\n"NOR,me);
		obj = new("/d/wiz/fyup/obj/qh"+(lv+1));	
		obj ->move(me);	
		me->add("lifecombine_exp",lv);
		me->add("stoneok",1);
		flag = 0;
		}
	  else
		{
		message_vision("$N把两块手中的"+chinese_number(lv)+"级强化石扔进炉子里炼化，只见两块强化石逐渐融化在了一起，竟然又变回了一块"+chinese_number(lv)+"级强化石。\n",me);
		//me->add("lifecombine_exp",lv);
		me->add("stonefail",1);
		flag = 1;
		}
		obj = first_inventory(me);
  	 	while(obj)
		{
		  reset_eval_cost();

		if (obj->query("qianghua") ==  lv)
			{
			flag ++;
			if (flag < 3)
				{
				destruct(obj);
                  			obj = first_inventory(me);
				continue;
				}
			else break;
			}
		  obj = next_inventory(obj);
		}
	
	return 1;
	
}

int do_xiang(string arg)
{
	object me, ob,ob2;
	int lv,flag,lv2,lv3,exp,tili,tili_cost,gong,gongjili,rig;
	string ctype,cstone;
	me = this_player();
	
	lv2 = (int)me->query("lifexiang");
     	exp = me->query("lifexiang_exp");
    	if (lv2 < 1)
      	return notify_fail("你还不会镶嵌之术。\n");
	if( me->is_fighting() )
                    return notify_fail("战斗中搞镶嵌？你厉害！\n");
	if( !arg ) 
		return notify_fail("你要镶嵌什麽东西？\n");
	if(!arg || sscanf(arg,"%s %s",ctype,cstone) != 2)
                     return notify_fail("请输入正确的格式，xiang <item> <stone>。\n");
	if( !objectp(ob = present(ctype, me)) )
		return notify_fail("你身上没有这种准备镶嵌的物品。\n");
	if( !objectp(ob2 = present(cstone, me)) )
		return notify_fail("你身上没有这种强化石。\n");
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");
	if( ob->query("equipped") )
		return notify_fail("这个东西正装备着呢。\n");
	lv = ob->query("leveled");
	if( !ob->query("level") )
		return notify_fail("你只能镶嵌带有成长的武器装备。\n");
	if( !ob2->query("qianghua") )
		return notify_fail("你只能镶嵌强化石。\n");
	lv3 = ob2->query("qianghua");
//	score = me->query("score");
//	if (score < 10)
//		return notify_fail("你的评价不够10点。\n");
	if(ob->query("level")<= lv)
		return notify_fail(ob->query("name")+"的镶嵌次数已经达到上限了。\n");
	if(lv > lv2)
		return notify_fail("你的的镶嵌技巧还不够熟练。\n");
	if ( lv > 19)
                      return notify_fail(ob->query("name")+"已经不能再镶嵌了。\n");
	if(lv3 <= lv)
		return notify_fail("你的的强化石等级不够。\n");
	
          tili = (int)me->query("lifetili");
        tili_cost = 50*lv;
          if( me->query("lifetili") < tili_cost )
                    return notify_fail("活力不够。\n");

	me->set("lifetili",tili-tili_cost);
	if((lv+1) < 5 ||(random(lv2)+1)>lv )
		{
		message_vision(HIG"$N从火炉旁拿出一把大铁锤，“当当当当”地把手中的强化石镶嵌到"+ob->query("name")+HIG"上，看来"+ob->query("name")+HIG"又厉害了一点。\n"NOR,me);
		gongjili = ob->query("base_damage");
		seteuid(ROOT_UID);
		if (!gongjili)
		{
			gongjili = ob->query("base_armor");
			ob->set("base_armor",gongjili*11/10);
		}
		else
			ob->set("base_damage",gongjili*11/10);
		rig = ob->query("rigidity");
		ob->add("leveled",1);
		ob->add("rigidity",100);
		
		//ob->add("weapon_prop/damage",random(50));
		ob->save();
     	ob->restore();
		seteuid(getuid());
     		if(ob->move(me))
			{
	        me->start_busy(1);
			lv = ob->query("leveled");
			me->add("xiangok",1);
			me->add("lifexiang_exp",lv);		 
			destruct(ob2);
				
			}
		}
	else if (random(3))
		{
		message_vision("$N从火炉旁拿出一把大铁锤，“当当当当”地试图把手中的强化石敲在"+ob->query("name")+"上，结果只听“叭”的一声，强化石碎了。\n"NOR,me);
		me->add("xiangfail",1);
		destruct(ob2);
		}
	else
		{
		message_vision("$N从火炉旁拿出一把大铁锤，“当当当当”地试图把手中的强化石敲在"+ob->query("name")+"上，结果只听“叭叭”两声，强化石和"+ob->query("name")+"都碎了。\n"NOR,me);
		destruct(ob2);
		me->add("xiangfail",1);
		if (ob->query("selfmaking"))
			{
			seteuid(ROOT_UID);
			rm(base_name(ob) + ".o");
			rm(base_name(ob) + ".c");
			ob->move(environment(me));
			destruct(ob);
			seteuid(getuid());
			}
		}
	return 1;
}
int do_repair(string arg)
{
	object me, ob;
	int lv,flag,score,lv2,lv3,exp,tili,tili_cost;
	string ctype,ll;
	me = this_player();
	
	lv2 = (int)me->query("lifearmor");
    	if (lv2 < 1)
      	return notify_fail("你还不会炼制之术，怎么修理东西？\n");

	if( me->is_fighting() )
                    return notify_fail("战斗中搞修理？你厉害！\n");
	if( !arg ) 
		return notify_fail("你要修理什麽东西？\n");
	if(!arg || sscanf(arg,"%s",ctype) != 1)
                     return notify_fail("请输入正确的格式，repair <item>。\n");
	if( !objectp(ob = present(ctype, me)) )
		return notify_fail("你身上没有这种准备修理的物品。\n");
	if(ob->query("id")!="cloth" && ob->query("id")!="head" && ob->query("id")!="shield"
	     && ob->query("id")!="finger" && ob->query("id")!="neck"
		  && ob->query("id")!="wrists" && ob->query("id")!="waist" && ob->query("id")!="boots")
			 return notify_fail("这里只能修理防具。\n");
	if(ob->query("limited_lv")/10 > lv2)
		return notify_fail("按你目前的锻造等级无法修理"+ob->query("name")+"。\n");
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");
	if( ob->query("equipped") )
		return notify_fail("这个东西正装备着呢。\n");
	if( ob->query("repairfail") >= 3 )
		return notify_fail("此物品已经修理失败三次了，不能再修理了。\n");
	if( !ob->query("selfmaking") )
		return notify_fail("你只能修理玩家制造的防具。\n");
	if (ob->query("abradability") >= 500)
		return notify_fail("这件防具还不需要马上修理吧。\n");
	score = me->query("score");
	if (score < 50)
		return notify_fail("你的评价不够50点。\n");

    tili = (int)me->query("lifetili");
    tili_cost = 50*lv2;
          if( me->query("lifetili") < tili_cost )
                    return notify_fail("活力不够。\n");

	me->set("lifetili",tili-tili_cost);
	if(random(lv2+10) > ob->query("limited_lv")/10 )
		{
		message_vision(HIG"$N从火炉旁拿出一把大铁锤，“当当当当”地往手中已经破损的"+ob->query("name")+HIG"砸了几下，"+ob->query("name")+HIG"片刻顿时亮了起来。\n"NOR,me);
		seteuid(ROOT_UID);
		
		ob->set("abradability",500);
		me->add("score",-50);
		
		ob->save();
     	ob->restore();
		seteuid(getuid());
     		if(ob->move(me))
			{
	        me->start_busy(2);
			}
		}
	else 
		{
		message_vision(HIG"$N从火炉旁拿出一把大铁锤，“当当当当”地往手中已经破损的"+ob->query("name")+HIG"砸了几下，由于不够熟练，许久后才修理完毕。\n"NOR,me);
		seteuid(ROOT_UID);
		
		ob->set("abradability",300);
		me->add("score",-50);
		
		ob->save();
     	ob->restore();
		seteuid(getuid());
     		if(ob->move(me))
			{
	        me->start_busy(2);
			}
		}
		/*
	else
		{
		message_vision(HIG"$N从火炉旁拿出一把大铁锤，“当当当当”地往手中已经破损的"+ob->query("name")+HIG"砸了几下，但是由于不够熟练修理失败了。\n"NOR,me);
		seteuid(ROOT_UID);
		
		ob->set("abradability",500);
		me->add("score",-100);
		ob->add("repairfail",1);
		ll = ob->query("long");
		ob->set("long","修理失败"+chinese_number(ob->query("repairfail"))+"次。"+ll);
		
		ob->save();
     	ob->restore();
		seteuid(getuid());
     		if(ob->move(me))
			{
	        me->start_busy(2);
			}
		}
		*/
	return 1;
}

