// xgchen@zzfy
// to.c


int main(object me, string arg)
{
        if(time()-(int)me->query("toover") <60)
                return notify_fail("ϵͳ�ڴ�Ϣ�С�������������\n");

        me->edit( (: call_other, this_object(), ({ "do_to", me, arg }) :) );
        me->set("toover",time());
	return 1;
}

void do_to(object me, string arg, string str)
{
	seteuid(getuid());
        if(sizeof(str)>=550){//��������ǲ��Գ����ġ��Ǻ�
            tell_object(me,"�ַ�̫���ˡ��޷�����.\n");
            return ;
        }
        if(arg) me->force_me(arg + " " + str);
	else me->force_me(str);
}

int help(object me)
{
write(@HELP
ָ���ʽ : to <ָ��>

����һ������������ϵ�����, <ָ��>ͨ�������ѶϢ��ָ����
say , tell , chat , new ........�ȡ�
���� : 
 to say
 �����뿪�� '.'��ȡ�������� '~q'��ʹ���ڽ��б༭���� '~e'��
 ����������������������������������������������������������
 12345
67890
 .

�����өĻ�ϵĽ������ :

12345
67890
HELP
    );
    return 1;
}

