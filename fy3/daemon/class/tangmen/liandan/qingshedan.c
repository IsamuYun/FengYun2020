// wududan.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
        object newsheet;
        string err;

        if((int)me->query_skill("wudutoxin") < 20 )
                return notify_fail("������Ŷ��������ߣ�\n");

        if( sheet->name() != "������Ƥ" )
                return notify_fail("������Ʒ�޷����Ƴ����ߵ���\n");

     //   if( (int)me->query("mana") < 50 ) 

        //      return notify_fail("��ķ��������ˣ�\n");

        sheet->add_amount(-1);
        seteuid( geteuid(me));
        newsheet = new("/obj/dan1");
        newsheet->set_name(HIG "���ߵ�" NOR, 
                ({ "qingshedan", "dan"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "apply_medicine":));
        newsheet->move(me);
       // me->add("mana", -50);
        me->receive_damage("sen", 50);
        me->save();
        message_vision("$N������һ�赤ҩ��\n" NOR, me);
        return 1;
}