// haunt.c

#include <ansi.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet)
{
   	object newsheet;
  	string err;
	  int lv;
	 lv = (int)me->query("haunt");
	if (!lv)   me->set("haunt",1);
	lv = (int)me->query("haunt");

        if((int)me->query_skill("scratching") < 10 )
                return notify_fail("��ķ�֮�������ߣ�\n");

        if( sheet->name() != "�ҷ�ֽ" )
                return notify_fail("��ʬ׷���Ҫ�����ҷ�ֽ�ϣ�\n");

        if( me->is_fighting() ) 
                return notify_fail("������ս���У�\n");
        
        if( (int)me->query("mana") < 20 *lv) 
                return notify_fail("��ķ��������ˣ�\n");
        if(me->query("lifetili")< 10 )
	   return notify_fail("��Ļ���������\n");

   	if ( random(100)+lv*10 >= 70) 
	{

        sheet->set_amount((int)sheet->query_amount() - 1);
	seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "��ʬ׷���" NOR, 
                ({ "haunting sheet", "sheet"}));      
        newsheet->set("attach_func", (: call_other, __FILE__, "do_haunt" :));
        newsheet->move(me);
        me->add("mana", -20*lv);
        me->add("lifetili",-10);
        me->receive_damage("sen", 10);
        me->save();
        message_vision("$Nд��һ����ʬ׷�����\n" NOR, me);
			if(me->query("haunt") < (me->query("level")/10) && userp(me))
		{
		  me->add("haunt_exp",1);
	      tell_object(me, "��ġ���ʬ׷����������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("haunt_exp") > (me->query("haunt")*me->query("haunt")*100)&&(me->query("haunt")<10))
			{
		me->add("haunt",1);
		me->set("haunt_exp",0);
	      tell_object(me, HIW"��ġ���ʬ׷��������������ˡ�\n"NOR);
			}
		}
	}
	else
		 tell_object(me, "���ڲ����������㻭��ʧ���ˡ�\n"NOR);
         me->start_busy(1);
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
 int help(object me)
{
        write(YEL"\n�������֮��ʬ׷�����"NOR"\n");
	write(@HELP
    

     ��ʦ��ÿ����һ�������ӻ����ĳɹ���10%��

HELP
	);
	return 1;
}

