//����Ӣ��
//updated by lion@hero
//backup.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object link_ob;
       object* inv;
        int i, cur_time;
        seteuid(getuid());

        if( !objectp(link_ob = me->query_temp("link_ob")) )
                return notify_fail("�㲻�Ǿ����������߽��룬���ܴ��档\n");
       cur_time=time();    
       if( cur_time - me->query("last_backup") < 900 )
       return notify_fail("������һ�α��ݻ�����15����!\n");
        if((int)link_ob->save()&&(int)me->save()){
        tell_object(me,"����������ϡ�\n");
        if((int)me->backup()&&(int)link_ob->backup()){
        me->set("last_backup", cur_time);
        me->set("last_save", cur_time);
        tell_object(me,"�������ݱ��ݳɹ�.\n");
       //������Ʒ���ݡ�
       inv = all_inventory(me);
       for(i=0; i<sizeof(inv); ++i)  {       
       if(inv[i]->query("owner") == getuid(me)&&
       (inv[i]->query_backup_file())){
       inv[i]->unequip();  
       if( (int)inv[i]->backup() ) 
       tell_object(me,"������Ʒ���ݳɹ�.\n");
            }
       
       }
     }   
     else tell_object(me,"����ʧ��!\n");
        return 1;
        } else {
                tell_object(me,"����ʧ�ܡ�\n");
                return 0;
        }
}

int help(object me)
{
        write(@HELP
ָ���ʽ��backup

�����������ݣ������ĵ������������ƻ�ʱ�����ñ����������ظ���
HELP
        );
        return 1;
}

