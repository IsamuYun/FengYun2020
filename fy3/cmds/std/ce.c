// ce.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

        void create() {seteuid(getuid());}

int main(object me, string arg)
{
      object obj;

      if(!me->query("marry")) return help(me);

        obj = find_player(me->query("marry"));

        if(!obj)
                return notify_fail("��İ������ڲ�����....\n");

        if( !arg ){
        message_vision(HIM "\n$N��ô˼��"+obj->query("name")+"��...\n"NOR, me);

 tell_object(obj,sprintf(HIM"���"+obj->query("name")+"��˼����... ...\n" NOR));
                }
      else {
          write(HIM "�����ĸ������" + obj->query("name") + "��" + arg + "\n" NOR);
          tell_object(obj, sprintf( HIM "���%s���ĸ����㣺%s\n" NOR,
                  me->query("name"), arg)); }

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��ce [<ѶϢ>]

����������ָ�����İ���˵���Ļ���

HELP
        );
        return 1;
}
