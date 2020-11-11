//by tiandi for lifeskill
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("����¯", ({ "lu"}) );
        set_weight(5000000);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "ֻ");
                set("long", "һֻ���ȵĴ���¯�������������\n ����(duanzao)������\n ����(lianzhi)װ����\n �ϳ�(combine)ǿ��ʯ��\n ��Ƕ(xiang)  ǿ��ʯ��\n ����(repair) ���ߡ�\n");
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
      	return notify_fail("�㻹����ϳ�֮����\n");
	if( me->is_fighting() )
                    return notify_fail("ս���и�ϳɣ���������\n");

	if( !arg ) 
		return notify_fail("��Ҫ�ϳ�ʲ�ᶫ����\n");
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û���ⶫ����\n");
	if(me->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");
	if( !ob->query("qianghua") )
		return notify_fail("��ֻ�ܺϳɴ���ǿ�����Ե�ʯͷ��\n");
//	score = me->query("score");
//	if (score < 10)
//		return notify_fail("������۲���10�㡣\n");
	lv= ob->query("qianghua");
	if ( lv > lv2)
                    return notify_fail("����Ҫ�ϳ���������ǿ��ʯ��������ĥ��ĥ����\n");
	if ( lv > 19)
                    return notify_fail(ob->query("name")+"�Ѿ������ٺϳ��ˡ�\n");
          tili = (int)me->query("lifetili");
      tili_cost = 50*lv;
          if( me->query("lifetili") < tili_cost )
                    return notify_fail("����������\n");

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
  		return notify_fail("������û��ͬ��������ǿ��ʯ��\n");

	if(random(lv2+1)>=lv)
		{
		message_vision(HIG"$N���������е�"+chinese_number(lv)+"��ǿ��ʯ�ӽ�¯����������ֻ������ǿ��ʯ���ڻ�����һ�𣬺ϳ���һ��"+chinese_number(lv+1)+"��ǿ��ʯ��\n"NOR,me);
		obj = new("/d/wiz/fyup/obj/qh"+(lv+1));	
		obj ->move(me);	
		me->add("lifecombine_exp",lv);
		me->add("stoneok",1);
		flag = 0;
		}
	  else
		{
		message_vision("$N���������е�"+chinese_number(lv)+"��ǿ��ʯ�ӽ�¯����������ֻ������ǿ��ʯ���ڻ�����һ�𣬾�Ȼ�ֱ����һ��"+chinese_number(lv)+"��ǿ��ʯ��\n",me);
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
      	return notify_fail("�㻹������Ƕ֮����\n");
	if( me->is_fighting() )
                    return notify_fail("ս���и���Ƕ����������\n");
	if( !arg ) 
		return notify_fail("��Ҫ��Ƕʲ�ᶫ����\n");
	if(!arg || sscanf(arg,"%s %s",ctype,cstone) != 2)
                     return notify_fail("��������ȷ�ĸ�ʽ��xiang <item> <stone>��\n");
	if( !objectp(ob = present(ctype, me)) )
		return notify_fail("������û������׼����Ƕ����Ʒ��\n");
	if( !objectp(ob2 = present(cstone, me)) )
		return notify_fail("������û������ǿ��ʯ��\n");
	if(me->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");
	if( ob->query("equipped") )
		return notify_fail("���������װ�����ء�\n");
	lv = ob->query("leveled");
	if( !ob->query("level") )
		return notify_fail("��ֻ����Ƕ���гɳ�������װ����\n");
	if( !ob2->query("qianghua") )
		return notify_fail("��ֻ����Ƕǿ��ʯ��\n");
	lv3 = ob2->query("qianghua");
//	score = me->query("score");
//	if (score < 10)
//		return notify_fail("������۲���10�㡣\n");
	if(ob->query("level")<= lv)
		return notify_fail(ob->query("name")+"����Ƕ�����Ѿ��ﵽ�����ˡ�\n");
	if(lv > lv2)
		return notify_fail("��ĵ���Ƕ���ɻ�����������\n");
	if ( lv > 19)
                      return notify_fail(ob->query("name")+"�Ѿ���������Ƕ�ˡ�\n");
	if(lv3 <= lv)
		return notify_fail("��ĵ�ǿ��ʯ�ȼ�������\n");
	
          tili = (int)me->query("lifetili");
        tili_cost = 50*lv;
          if( me->query("lifetili") < tili_cost )
                    return notify_fail("����������\n");

	me->set("lifetili",tili-tili_cost);
	if((lv+1) < 5 ||(random(lv2)+1)>lv )
		{
		message_vision(HIG"$N�ӻ�¯���ó�һ�Ѵ��������������������ذ����е�ǿ��ʯ��Ƕ��"+ob->query("name")+HIG"�ϣ�����"+ob->query("name")+HIG"��������һ�㡣\n"NOR,me);
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
		message_vision("$N�ӻ�¯���ó�һ�Ѵ�����������������������ͼ�����е�ǿ��ʯ����"+ob->query("name")+"�ϣ����ֻ�����ȡ���һ����ǿ��ʯ���ˡ�\n"NOR,me);
		me->add("xiangfail",1);
		destruct(ob2);
		}
	else
		{
		message_vision("$N�ӻ�¯���ó�һ�Ѵ�����������������������ͼ�����е�ǿ��ʯ����"+ob->query("name")+"�ϣ����ֻ�����Ȱȡ�������ǿ��ʯ��"+ob->query("name")+"�����ˡ�\n"NOR,me);
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
      	return notify_fail("�㻹��������֮������ô��������\n");

	if( me->is_fighting() )
                    return notify_fail("ս���и�������������\n");
	if( !arg ) 
		return notify_fail("��Ҫ����ʲ�ᶫ����\n");
	if(!arg || sscanf(arg,"%s",ctype) != 1)
                     return notify_fail("��������ȷ�ĸ�ʽ��repair <item>��\n");
	if( !objectp(ob = present(ctype, me)) )
		return notify_fail("������û������׼���������Ʒ��\n");
	if(ob->query("id")!="cloth" && ob->query("id")!="head" && ob->query("id")!="shield"
	     && ob->query("id")!="finger" && ob->query("id")!="neck"
		  && ob->query("id")!="wrists" && ob->query("id")!="waist" && ob->query("id")!="boots")
			 return notify_fail("����ֻ��������ߡ�\n");
	if(ob->query("limited_lv")/10 > lv2)
		return notify_fail("����Ŀǰ�Ķ���ȼ��޷�����"+ob->query("name")+"��\n");
	if(me->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");
	if( ob->query("equipped") )
		return notify_fail("���������װ�����ء�\n");
	if( ob->query("repairfail") >= 3 )
		return notify_fail("����Ʒ�Ѿ�����ʧ�������ˣ������������ˡ�\n");
	if( !ob->query("selfmaking") )
		return notify_fail("��ֻ�������������ķ��ߡ�\n");
	if (ob->query("abradability") >= 500)
		return notify_fail("������߻�����Ҫ��������ɡ�\n");
	score = me->query("score");
	if (score < 50)
		return notify_fail("������۲���50�㡣\n");

    tili = (int)me->query("lifetili");
    tili_cost = 50*lv2;
          if( me->query("lifetili") < tili_cost )
                    return notify_fail("����������\n");

	me->set("lifetili",tili-tili_cost);
	if(random(lv2+10) > ob->query("limited_lv")/10 )
		{
		message_vision(HIG"$N�ӻ�¯���ó�һ�Ѵ����������������������������Ѿ������"+ob->query("name")+HIG"���˼��£�"+ob->query("name")+HIG"Ƭ�̶�ʱ����������\n"NOR,me);
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
		message_vision(HIG"$N�ӻ�¯���ó�һ�Ѵ����������������������������Ѿ������"+ob->query("name")+HIG"���˼��£����ڲ�����������ú��������ϡ�\n"NOR,me);
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
		message_vision(HIG"$N�ӻ�¯���ó�һ�Ѵ����������������������������Ѿ������"+ob->query("name")+HIG"���˼��£��������ڲ�����������ʧ���ˡ�\n"NOR,me);
		seteuid(ROOT_UID);
		
		ob->set("abradability",500);
		me->add("score",-100);
		ob->add("repairfail",1);
		ll = ob->query("long");
		ob->set("long","����ʧ��"+chinese_number(ob->query("repairfail"))+"�Ρ�"+ll);
		
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

