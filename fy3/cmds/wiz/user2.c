// user2.c ���������ĳ�����Խ�������
//by tmpa 2002.1

inherit F_CLEAN_UP;
#include <ansi.h>
string sort_arg;
int main(object me, string arg)
{
    object where, ob, *ob_list;
    int i;
    string stri,str;
    seteuid(getuid());

    if( !arg ) {
    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    str = HIG"   �������           ��          ��         ��        ����ֵ   Ǳ��\n"NOR;
    str += "------------------------------------------------------------\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
	if( !environment(ob) ) continue;
        where = environment(ob);

        str += sprintf(WHT"%16s:  ",ob->name()+"("+ob->query("id")+")");
        str += sprintf(RED"%5d/%5d ", ob->query("gin"), ob->query("max_gin"));
        str += sprintf(HIM"%5d/%5d ", ob->query("kee"), ob->query("max_kee"));
        str += sprintf(YEL"%5d/%5d ", ob->query("sen"), ob->query("max_sen"));
        str += sprintf(MAG"%8d ", ob->query("combat_exp"));
        str += sprintf(CYN"%5d \n"NOR, ob->query("potential")-ob->query("learned_points"));
    }
    str += "------------------------------------------------------------\n";
    str = sprintf("%s���� %d λʹ���������С�\n", str, sizeof(ob_list));
    me->start_more(str);

        } 
    else {
    sort_arg=arg;
    ob_list = users();
    ob_list = sort_array(users(), "sort_data", this_object());
    str = HIG"   �������           ";
    str +=sprintf(WHT"���� %s:  \n"NOR,arg);
    str += "------------------------------------------------------------\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
	if( !environment(ob) ) continue;
        where = environment(ob);
        str += sprintf(WHT"%16s:  ",ob->name()+"("+ob->query("id")+")");
	if(!stringp(ob->query(arg)))
    	    str += sprintf(MAG"   %d \n", ob->query(arg));
	else 
    	    str += sprintf(MAG"   %s \n", ob->query(arg));
	
    }
    str += "------------------------------------------------------------\n";
    str = sprintf("%s���� %d λʹ���������С�\n", str, sizeof(ob_list));
    me->start_more(str);

        }

    return 1;
}
int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);
	
	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}
int sort_data(object ob1, object ob2)
{
	if(stringp(ob1->query(sort_arg))||stringp(ob2->query(sort_arg)))return 0;
	return (int)ob2->query(sort_arg) - (int)ob1->query(sort_arg);
}
int help(object me)
{
        write(@HELP
ָ���ʽ��user2 <��������>

�����Ϣ��ѯ��
HELP
        );
        return 1;
}
