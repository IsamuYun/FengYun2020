#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if( !wizardp(me) )
                return notify_fail("Ŀǰ�ݲ�������� shout��\n");
        if (!arg) return notify_fail("����Ҫ���ʲô?\n");
             shout(HIR "�����ַ��ơ�"+me->name() + "������Х��" + BLINK + arg + "\n" NOR);

        write(HIR "��������Х��" + BLINK + arg + "\n" NOR);
        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : shout <ѶϢ>
 
���ָ�����㽫 <ѶϢ> ���ͳ�ȥ, ����������Ϸ�е��˶�
��������Ļ�.
 
see also : tune
HELP
    );
    return 1;
}
