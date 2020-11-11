// give.c
#include <ansi.h>
inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
            object obj, who, *inv, obj2;
        string no_accept;
        int i, amount;
	if(!arg) return notify_fail("��Ҫ��˭ʲ�ᶫ����\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("��Ҫ��˭ʲ�ᶫ����\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("����û������ˡ�\n");
        if (interactive(me) && stringp(no_accept = who->query("env/no_accept")))
        {
                if ((no_accept == "all" || no_accept == "ALL" ||
                     me->query("id")==who->query("env/no_accept")) )
                {
                        return notify_fail("�˼����ڲ���Ҫ��Ķ�������\n");
                }
        }

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("������û������������\n");
		if( obj->query("no_drop") ||obj->query_temp("no_drop"))
			return notify_fail("�����������������ˡ�\n");
 
                if( !obj->query_amount() )      
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("��û��������" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
     if(!do_give(me,obj2,who))
obj->set_amount( (int)obj->query_amount() + amount );
return 1;
}
	}


	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
	if( obj->query("no_drop") )
		return notify_fail("�����������������ˡ�\n");
// check for dynamic_quests
        if(obj->query("dynamic_quest"))
        if(TASK_D->quest_reward(me,who,obj))
        return 1;
	if( !interactive(who) && !who->accept_object(me, obj) )
		return notify_fail("��ֻ�ܰѶ����͸�������Ҳ��ݵ����\n");

      if( !userp(who) && !who->query("can_carry") ) {
		  if (obj)
		  {
		tell_object(me,"���ó�" + obj->short() + "��" + who->name()+"��\n");
		destruct(obj);
		  }
		return 1;
	} else if( obj->move(who) ) {
		printf("���%sһ%s%s��\n", who->name(), obj->query("unit"),
			obj->name());
		message("vision", sprintf("%s����һ%s%s��\n", me->name(),
			obj->query("unit"), obj->name()), who );
		message("vision", sprintf("%s��%sһ%s%s��\n", me->name(), who->name(),
			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
  	        if (wizardp(me)&&userp(who)){
	        message("channel:chat",HIR"��ϵͳ���桿�۲�����"+"��˵"+who->query("name")+"����"+me->query("name")+"�����"+obj->query("name")+HIR"������ע��ල��\n"NOR,users());
                     }// Tiandi update no logs
       	  // log_file( "GIVE_LOG", sprintf("(%s) %s give %s(%s) to %s\n", ctime(time()), me->query("id"), obj->query("name"), base_name(obj), who->query("id")));
	return 1;
	}
	else return 0;
}
int help(object me)
{
write(@HELP
ָ���ʽ : give <��Ʒ����> to <ĳ��>
      �� : give <ĳ��> <��Ʒ����>
 
���ָ��������㽫ĳ����Ʒ������, ��Ȼ, ������Ҫӵ��������Ʒ.
 
HELP
    );
    return 1;
}