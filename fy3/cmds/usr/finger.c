// finger.c

inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        string meid,obid;
        if( !arg )
        {
                if( (int)me->query("sen") < 50 )
                        return notify_fail("��ľ����޷����С�\n");
                if( !wizardp(me) )
                {
                        me->receive_damage("sen", 50);
                me->start_more( FINGER_D->finger_all(0) );
                }
                else
                me->start_more( FINGER_D->finger_all(1) );

        }
        else
        {
                if( (int)me->query("sen") < 15 )
                        return notify_fail("��ľ����޷����С�\n");
                if( !wizardp(me) )
                        me->receive_damage("sen", 15);
                
                meid=me->query("id");
                if( (meid!="jia" && meid!="gcy" && meid!="xgchen") 
			&& (arg=="jia" || arg=="gcy" || arg=="xgchen"))
                {
                        obid=meid;
                }
                else
                {
                        obid=arg;       
                }
                
                write( FINGER_D->finger_user(obid,(wizardp(me) || obid == (string)me->query("id"))) );
        }
        return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : finger [ʹ��������]
 
���ָ��, ���û��ָ��ʹ��������, ����ʾ�����������������
����������. ��֮, �����ʾ�й�ĳ����ҵ�����, Ȩ�޵�����.
 
see also : who
HELP
    );
    return 1;
}
 

