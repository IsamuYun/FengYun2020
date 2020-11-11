// earth.c by tiandi 200805

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
        object newsheet;
        string err;
	  int lv;
	 lv = (int)me->query("earth");
	if (!lv)   me->set("earth",1);
	lv = (int)me->query("earth");

	 

        if((int)me->query_skill("scratching") < 20 )
                return notify_fail("��ķ�֮�������ߣ�\n");

        if( sheet->name() != "�ҷ�ֽ" )
                return notify_fail("���紫�ͷ�Ҫ�����ҷ�ֽ�ϣ�\n");

        if( (int)me->query("mana") < 50 ) 
                return notify_fail("��ķ��������ˣ�\n");
        if(me->query("lifetili")< 11 - lv)
	   return notify_fail("��Ļ���������\n");
   	if ( random(100)+lv*10 >= 50) 
	{
        sheet->add_amount(-1);
        seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "���紫�ͷ�" NOR, 
                ({ "earth sheet", "sheet"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "do_warp":));
        newsheet->move(me);
        me->add("mana", -50);
        me->add("lifetili",-11 + lv);
        me->receive_damage("sen", 10);
        me->save();
        message_vision("$Nд��һ�����紫�ͷ���\n" NOR, me);
		if(me->query("earth") < (me->query("level")/10) && userp(me))
		{
		  me->add("earth_exp",1);
	      tell_object(me, "��ġ����紫�ͷ��������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("earth_exp") > (me->query("earth")*me->query("earth")*100)&&(me->query("earth")<10))
			{
		me->add("earth",1);
		me->set("earth_exp",0);
	      tell_object(me, HIW"��ġ����紫�ͷ������������ˡ�\n"NOR);
			}
		}
	}
	else
		 tell_object(me, "���ڲ����������㻭��ʧ���ˡ�\n"NOR);
         me->start_busy(1);
        return 1;
}

int do_warp(string target, object who)
{
        object env;

        if( this_player()->query_temp("nofly") || this_player()->query_temp("noburn") )
                return notify_fail("����Ҫ��������������ʹ�÷�����\n");
        if( who && who!=this_player() )
                return notify_fail("���紫�ͷ�ֻ�ܶ��Լ�ʹ�á�\n");
	this_player()->start_busy(random(3)+1);
        env = environment(this_player());
        message("vision",
                HIB + this_player()->name() + "����һ�����紫�ͷ���\n"
"��Ȼ���ܴ�����һ�����쬵����磬����֮���ݷ��������Ӱ�ڻζ�...\n"
                "Ȼ��һ����ͻȻ����\n" NOR, env);
        message("vision", "����...." + this_player()->name() + 
"�Ѿ������ˡ�\n", environment(this_player()), ({this_player()}));
 this_player()->start_busy(4);
call_out("move_him",1+random(4),this_player());
 return 1;
}
 
int move_him(object me)
{
  message("vision",
 CYN 
"��ֻ�������Ӳ�����׹��һֱ��׹��һֱ��׹��һֱ��׹��һֱ��׹ .....\n"
  NOR     
"��֪��ʲ��ʱ���㷢������ʵһֱ��վ�ڼ�Ӳ�ĵ����ϣ��������ܵľ���\n"
                "ȴ��һ����....\n", me);
  me->move(DEATH_ROOM);
 return 1;
}
 int help(object me)
{
        write(YEL"\n�������֮���䴫�ͷ���"NOR"\n");
	write(@HELP

      ��ȼ�������˷������䡣

      ���䴫�ͷ�ÿ����һ�������ӻ����ĳɹ���10%�������ͻ�������һ�㡣

HELP
	);
	return 1;
}




