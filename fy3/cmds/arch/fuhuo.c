// by xgchen
inherit F_CLEAN_UP;

int main(object me, string str)
{ 
  object ob;
  if (!str) return notify_fail("usage: fuhuo <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("���������?\n");
  if (ob->is_ghost()) 
           tell_object(ob,"�������ȫ������...\n");
       else 
           return notify_fail("��...����˺����ǻ�ģ�\n");
  tell_object(ob,"�����ϣ����ǹ�!��Ҫ���㸴��ұ����ϴε�һ�С�\n");
  tell_room(environment(ob),"һ�����ͻȻ��������£�������"+
       (string)ob->query("name")+"����Χ��\n", ob);
  tell_object(ob,"ͻȻһ����������������𣬡������....��������\n��ʼ���ٲ��ǻ���ˡ�����ͻȻ�е�һ�����...\n");
  ob->reincarnate();
  ob->query_temp("last_damage_from");  
  tell_object(ob,"�ܺã����ָ����ˣ�ԭ������ʦ�����㣡\n");
  write("Ok.\n");
        if ( userp(ob))
        write_file("/log/static/FUHUO",sprintf("%s   ��   %s ���� on %s\n",
        me->name(1),ob->name(1), ctime(time()) ));
  return 1;    
}

int help(object me)
{
write(@HELP
ָ���ʽ : fuhuo <ĳ��>

������ĳ������������
HELP
    );
    return 1;
}