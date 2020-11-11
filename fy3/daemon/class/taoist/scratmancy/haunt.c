// haunt.c

#include <ansi.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet)
{
   	object newsheet;
  	string err;

        if((int)me->query_skill("scratching") < 10 )
                return notify_fail("��ķ�֮�������ߣ�\n");

        if( sheet->name() != "�ҷ�ֽ" )
                return notify_fail("��ʬ׷���Ҫ�����ҷ�ֽ�ϣ�\n");

        if( me->is_fighting() ) 
                return notify_fail("������ս���У�\n");
        
        if( (int)me->query("mana") < 20 ) 
                return notify_fail("��ķ��������ˣ�\n");

        sheet->set_amount((int)sheet->query_amount() - 1);
	seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "��ʬ׷���" NOR, 
                ({ "haunting sheet", "sheet"}));      
        newsheet->set("attach_func", (: call_other, __FILE__, "do_haunt" :));
        newsheet->move(me);
        me->add("mana", -20);
        me->receive_damage("sen", 10);
        me->save();
        message_vision("$Nд��һ����ʬ׷�����\n" NOR, me);
        return 1;
}

int do_haunt(object sheet, object who)
{ 
        string target;
        object dest, owner;

        if( !who->is_zombie() )
                return notify_fail(YEL "��ʬ׷���" NOR 
"ֻ�����ڽ�ʬ���ϡ�\n");

	owner = who->query("possessed");
        if( objectp(owner) && owner!=this_player() )
                return notify_fail("��������÷�����ס" + who->name() + 
"����ʹ���������\n");

        if( !(sheet->query("targetname")) )
                return notify_fail("�����������" NOR 
"׷˭�Ļꣿ\n");

        target = sheet->query("targetname");
        dest = present(target, environment(who));
        if( !dest ) dest = find_player(target);
        if( !dest ) dest = find_living(target);
        if (userp(dest) && dest->query("combat_exp")<1000000)
                return notify_fail("�㲻�ܶ���������ʹ�á�\n");
        if( objectp(dest) ) {
		who->set("haunttar", dest);
                if( environment(dest)==environment(who) ) {
	                who->kill_ob(dest);
       			message_vision("$N�۾���Ȼ�������૵�˵����" RED 
"ɱ....��....$n....\n" NOR,
                        who, dest);
	                who->set_leader(dest);
                        dest->fight_ob(who);
                }
 		else {
			who->set("haunt", 1);
               }
        } else {
           message_vision("$N�۾���Ȼ�������૵�˵����" RED 
"ɱ....ɱ....ɱ....\n" NOR,
                        who);
                if( this_player() ) {
                        who->kill_ob(this_player());
                        who->set_leader(this_player());
                        this_player()->fight_ob(who);
                }
        }
        return 1;
}
