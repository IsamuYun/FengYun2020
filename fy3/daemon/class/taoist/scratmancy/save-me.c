// haunt.c

#include <ansi.h>

inherit F_CLEAN_UP;
#define MAX_GUARD 4
int scribe(object me, object sheet)
{
   	object newsheet;
  	string err;

        if((int)me->query_skill("scratching") < 90 )
                return notify_fail("��ķ�֮�������ߣ�\n");

        if( sheet->name() != "�ҷ�ֽ" ) 
                return notify_fail("��ʦ��Ҫ�����ҷ�ֽ�ϣ�\n");

        if( (int)me->query("mana") < 75 ) 
                return notify_fail("��ķ��������ˣ�\n");

        sheet->set_amount((int)sheet->query_amount() - 1);
	seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "��ʦ��" NOR, 
                ({ "save-me sheet", "sheet"}));      
        newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
        newsheet->move(me);
        me->add("mana", -75);
        me->receive_damage("sen", 10);
        me->save();
        message_vision("$Nд��һ����ʦ����\n" NOR, me);
        return 1;
}

int do_burn(object sheet)
{ 
        object obj, soldier, me;
	int	spells;

	me = this_player();
        if( !me->is_fighting() )
                return notify_fail("û����Ҫɱ�㣡\n");
        if( me->query_temp("max_guard") > MAX_GUARD )
                return notify_fail("���Ѿ��ٻ�̫����������ˣ�\n");
        message_vision("$N���о��񣬼�����ζ�������һ��" + sheet->name() +
     		"����������\n", this_player());
        me->receive_damage("sen", 20);
        if( random(me->query("mana")) < 200 ) {
                message("vision", "����ʲ��Ҳû�з�����\n", environment(me));
                return 1;
        }
	spells = me->query_skill("scratching");
        seteuid(getuid());
        if( random(10) < 5 )
                soldier = new("/obj/npc/heaven_soldier");
        else
                soldier = new("/obj/npc/hell_guard");
        soldier->move(environment(me));
        soldier->invocation(me, spells);
	soldier->set("possessed", me);
	me->add_temp("max_guard",1);
	me->remove_all_killer();
        message_vision(HIB "\n$N����$n�ı��󺰵�������ɱ��\n" NOR, me, soldier );
        message_vision(HIB "\n$n��$N��ס�����е��˵Ĺ�����\n" NOR, me, soldier );
        return 1;
}
