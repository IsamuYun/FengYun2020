// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int wimpy;
	if(me->query("class") != "bandit") return
        notify_fail("��������ɵ��˲�����װ����\n");
        seteuid(getuid());
        if( !me->is_fighting() )
                return notify_fail("�㲻��ս���У�����Ҫ��װ����\n");
        if( me->is_busy())
                return notify_fail("��������æ�����ܼ�װ����\n");
        wimpy = (int)me->query("env/wimpy");
         if(random(me->query("kar"))>20)
{
        message_vision("$N�ҽ�һ����һͷ�Ե��ڵ��¡�\n$N���ˡ�\n",me);
      me->set_temp("disable_inputs",1);
      me->set_temp("block_msg/all",1);
      me->set("disable_type",HIG "<������>" NOR);
        me->remove_all_killer();
	me->remove_all_enemy();
        me->delete("env/wimpy");
        me->strat_busy(5);
        me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me, wimpy :), 
random(50 - (int) me->query_con()));
}
else{
        message_vision("���ˣ�$N�������Ҵ��ˡ�����Ҫ������!\n",me);
        me->strat_busy(4);
}
        return 1;
}
void remove_dazuo(object me, int wimpy)
{
   me->delete_temp("disable_inputs");
   me->delete("disable_type");
   me->delete_temp("block_msg/all");
        me->set("env/wimpy",wimpy);
        me->strat_busy(4);
   	message_vision("$N�ڵ������ĵط��˸���С��������������ۡ�\n",me);
        me->move(environment(me),1);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : jiasi
������ս����װ�������������Ļ��ᡣ
�������ɵ��˲�����װ����

HELP
        );
        return 1;
}
 
