// haunt.c

#include <ansi.h>

inherit F_CLEAN_UP;
#define MAX_GUARD 4
int scribe(object me, object sheet)
{
   	object newsheet;
  	string err;
	  int lv;
	 lv = (int)me->query("saveme");
	if (!lv)   me->set("saveme",1);
	lv = (int)me->query("saveme");

        if((int)me->query_skill("scratching") < 90 )
                return notify_fail("��ķ�֮�������ߣ�\n");

        if( sheet->name() != "�ҷ�ֽ" ) 
                return notify_fail("��ʦ��Ҫ�����ҷ�ֽ�ϣ�\n");

        if( (int)me->query("mana") < 75*lv ) 
                return notify_fail("��ķ��������ˣ�\n");
        if(me->query("lifetili")< 10*lv)
	   return notify_fail("��Ļ���������\n");

   	if ( random(100)+lv*10 >= 70) 
	{
        sheet->add_amount(-1);
        seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "��ʦ��" NOR, 
                ({ "save-me sheet", "sheet"}));      
        newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
        newsheet->move(me);
        me->add("mana", -75*lv);
        me->add("lifetili",-10*lv);
        me->receive_damage("sen", 10);
        me->save();
        message_vision("$Nд��һ����ʦ����\n" NOR, me);
			if(me->query("saveme") < (me->query("level")/10) && userp(me))
		{
		  me->add("saveme_exp",1);
	      tell_object(me, "��ġ���ʦ���������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("saveme_exp") > (me->query("saveme")*me->query("saveme")*100)&&(me->query("saveme")<10))
			{
		me->add("saveme",1);
		me->set("saveme_exp",0);
	      tell_object(me, HIW"��ġ���ʦ�������������ˡ�\n"NOR);
			}
		}
	}
	else
		 tell_object(me, "���ڲ����������㻭��ʧ���ˡ�\n"NOR);
         me->start_busy(1);
        return 1;
}

int do_burn(object sheet)
{ 
        object obj, soldier, me;
	int	spells;

	me = this_player();
        if( !me->is_fighting() )
                return notify_fail("û����Ҫɱ�㣡\n");
        if( me->query_temp("max_guard") > me->query("saveme")/2+1 )
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
 int help(object me)
{
        write(YEL"\n�������֮��ʦ����"NOR"\n");
	write(@HELP

      ��ȼ�������ٻ��������ֵ����˹�����

     ��ʦ��ÿ����һ�������ӻ����ĳɹ���10%�������������Χ��
     ��ʦ��ÿ�������������ӿ��ٻ������һ����

HELP
	);
	return 1;
}


