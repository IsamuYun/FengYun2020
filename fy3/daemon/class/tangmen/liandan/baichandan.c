// wududan.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
        object newsheet;
        string err;

        if((int)me->query_skill("wudutoxin")< 30 )
                return notify_fail("����嶾���������ߣ�\n");

        if( sheet->name() != "����Ĥ" )
                return notify_fail("������Ʒ�޷����Ƴ���󸵤��\n");

     //   if( (int)me->query("mana") < 50 ) 

        //      return notify_fail("��ķ��������ˣ�\n");

        sheet->add_amount(-1);
        seteuid( geteuid(me));
        newsheet = new("/obj/dan2");
        newsheet->set_name(HIW "��󸵤" NOR, 
                ({ "baichandan", "dan"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "apply_medicine":));
        newsheet->move(me);
       // me->add("mana", -50);
        me->receive_damage("sen", 50);
        me->save();
        message_vision(HIG "$N������һ�赤ҩ��\n" NOR, me);
        return 1;
}