//by tiandi 200806

#include <ansi.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet)
{
   	object newsheet;
  	string err;
	  int lv;
	 lv = (int)me->query("far");
	if (!lv)   me->set("far",1);
	lv = (int)me->query("far");

        if((int)me->query_skill("scratching") < 50 )
                return notify_fail("��ķ�֮�������ߣ�\n");

        if( sheet->name() != "�ҷ�ֽ" ) 
                return notify_fail("��ͨ�۷�Ҫ�����ҷ�ֽ�ϣ�\n");

        if( (int)me->query("mana") < 50 ) 
                return notify_fail("��ķ��������ˣ�\n");
        if(me->query("lifetili")< 11 - lv)
	   return notify_fail("��Ļ���������\n");

   	if ( random(100)+lv*10 >= 50) 
	{
        sheet->add_amount(-1);
        seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "��ͨ�۷�" NOR, 
                ({ "far-vision sheet", "sheet"}));      
        newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
        newsheet->move(me);
        me->add("mana", -50);
		me->add("lifetili",-11 + lv);
        me->receive_damage("sen", 5);
        me->save();
        message_vision("$Nд��һ����ͨ�۷���\n" NOR, me);
			if(me->query("far") < (me->query("level")/10) && userp(me))
		{
		  me->add("far_exp",1);
	      tell_object(me, "��ġ���ͨ�۷��������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("far_exp") > (me->query("far")*me->query("far")*100)&&(me->query("far")<10))
			{
		me->add("far",1);
		me->set("far_exp",0);
	      tell_object(me, HIW"��ġ���ͨ�۷������������ˡ�\n"NOR);
			}
		}
	}
	else
		 tell_object(me, "���ڲ����������㻭��ʧ���ˡ�\n"NOR);
 
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
 int help(object me)
{
        write(YEL"\n�������֮����ͨ��"NOR"\n");
	write(@HELP

      �ѶԷ�������д�ڴ˷����ϣ��ٵ�ȼ�����ܿ����Է�����Χ�����

      ����ͨÿ����һ�������ӻ����ĳɹ���5%��

HELP
	);
	return 1;
}



