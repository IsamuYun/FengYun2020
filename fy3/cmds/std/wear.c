// wear.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("��Ҫ����ʲ�᣿\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wear(me, inv[i]) ) count ++;
		}
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ�װ�����ˡ�\n");

	return do_wear(me, ob);
}

int do_wear(object me, object ob)
{
	string str;

	if( ob->query("female_only")
	&&	(string)me->query("gender") != "Ů��" )
		return notify_fail("����Ů�˵���������һ��������Ҳ�봩����Ҳ���ߣ�\n");

//        if(!ob->query("limited_lv") && userp(me))
//                    return notify_fail("�˷�������û��ĥ��ȣ���Ҳ���װ����\n");

//        if(ob->query("limited_lv")>me->query("level")&& userp(me))
//                    return notify_fail("�ȼ�����������װ����\n");

//        if(ob->query("abradability")< 1 && userp(me))
//                    return notify_fail("�˷����Ѿ���ȫ���ˣ�����ȥ����.\n");

	if( ob->wear() ) {
		if( !stringp(str = ob->query("wear_msg")) )
			switch( ob->query("armor_type") ) {
				case "cloth":                 
				case "armor":                    
				case "boots":
					str = YEL "$N����һ" + ob->query("unit") + "$n��\n" NOR;
					break;
				case "head":
				case "neck":
				case "wrists":
				case "finger":
				case "hands":
					str = YEL "$N����һ" + ob->query("unit") + "$n��\n" NOR;
					break;
				case "waist":
					str = YEL "$N��һ" + ob->query("unit") + "$n" +  "�������䡣\n" NOR;
					break;
				default:
					str = YEL "$Nװ��$n��\n" NOR;
			}
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��wear <װ������>
 
���ָ������װ��ĳ�����ߡ�
 
HELP
    );
    return 1;
}
