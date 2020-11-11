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
                        return notify_fail("你的精神无法集中。\n");
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
                        return notify_fail("你的精神无法集中。\n");
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
指令格式 : finger [使用者姓名]
 
这个指令, 如果没有指定使用者姓明, 会显示出所有正在线上玩家
的连线资料. 反之, 则可显示有关某个玩家的连线, 权限等资料.
 
see also : who
HELP
    );
    return 1;
}
 

