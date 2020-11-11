// haunt.c

#include <ansi.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet)
{
   	object newsheet;
  	string err;

        if((int)me->query_skill("scratching") < 50 )
                return notify_fail("��ķ�֮�������ߣ�\n");

        if( sheet->name() != "�ҷ�ֽ" ) 
                return notify_fail("��ͨ�۷�Ҫ�����ҷ�ֽ�ϣ�\n");

        if( (int)me->query("mana") < 5 ) 
                return notify_fail("��ķ��������ˣ�\n");

        sheet->set_amount((int)sheet->query_amount() - 1);
	seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "��ͨ�۷�" NOR, 
                ({ "far-vision sheet", "sheet"}));      
        newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
        newsheet->move(me);
        me->add("mana", -5);
        me->receive_damage("sen", 5);
        me->save();
        message_vision("$Nд��һ����ͨ�۷���\n" NOR, me);
        return 1;
}

int do_burn(object sheet)
{ 
        string target;
        object obj;

        if( !(sheet->query("targetname")) )
                return notify_fail("�����������" NOR 
"�����\n");
        message_vision("$N���о��񣬼�����ζ�������һ��" + sheet->name() +
     		"����������\n", this_player());
	this_player()->receive_damage("sen", 5);
        target = sheet->query("targetname");
        obj = find_player(target);
        if(!obj) obj = find_living(target);
     if(!obj || wizardp(obj)){
        	message("vision", "��е��۾�����ģ�ȴʲôҲû������\n", this_player());
        } else
        {
        	message("vision", "����˸�Ļ���У��㿴����\n", this_player());
		"/cmds/std/look"->look_room(this_player(), environment(obj));
        	message("vision", "��е����ӷ������ڰ���������˫�۾������㣡\n", obj);
        	message("vision", "����ϸ�ؿ���һ�����ܣ�ȴʲôҲû�У�\n", obj);
        }
        return 1;
}
