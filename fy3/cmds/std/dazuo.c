// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        int wimpy;
        mapping my;
        seteuid(getuid());
        my = me->query_entire_dbase();
        if( me->is_fighting() )
                return notify_fail("ս���в��ܴ��������߻���ħ�ġ�\n");
        if( environment(me)->query("no_dazuo") )
                return notify_fail("���ﲻ�������\n");
       if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ����ܴ�����\n");
        message_vision("$N���ȵ����ڵ��ϣ������۾���ʼ��Ϣ������\n",me);
      me->set_temp("disable_inputs",1);
      me->set_temp("block_msg/all",1);
        me->set_temp("is_unconcious",1);
      me->set("disable_type",HIG "<������>" NOR);
        me->set_temp("in_dazuo",1);
   if(my["food"]>2)
     if(my["water"]>2)
    {  my["water"]=(int)(my["water"]/2);
      my["food"]=(int)(my["food"]/2);
      my["gin"]=(int)(my["gin"]*2); if (my["gin"]>my["eff_gin"]) my["gin"]=my["eff_gin"];
      //my["kee"]=(int)(my["kee"]*2); if (my["kee"]>my["eff_kee"]) my["kee"]=my["eff_kee"];
      my["kee"]=(int)(my["eff_kee"]*2); if (my["kee"]>my["eff_kee"]) my["kee"]=my["eff_kee"];
      my["sen"]=(int)(my["sen"]*2); if (my["sen"]>my["eff_sen"]) my["sen"]=my["eff_sen"];
}
        me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me:), 
random(20 - (int) me->query_con()));
        return 1;
}

void remove_dazuo(object me)
{
   me->delete_temp("disable_inputs");
   me->delete("disable_type");
   me->delete_temp("block_msg/all");
        me->delete_temp("in_dazuo");
   me->delete_temp("is_unconcious");
   if(!me->is_ghost())
   message_vision("$N�����ҵľ����л����������������۾���\n",me);

}

int help(object me)
{
        write(@HELP
ָ���ʽ : dazuo

ʹ��������ҵĴ���״̬�У����ܿ������쾫������Ѫ��
���������������������Ļָ��ٶȡ�

HELP
        );
        return 1;
}
 


