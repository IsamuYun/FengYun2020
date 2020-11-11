// yufeng.c

#include <ansi.h>

inherit SSERVER;

int exert(object me, object target)
{
        if(environment(me)->query("no_magic")) 
        {
                return notify_fail("Õâ¸öµØ·½ÎŞ·¨ÁéÉñ·ÉĞĞ¡£\n");
        }

        if( me->query_temp("nofly") || me->query("job/sxy") )
                return notify_fail("ÄãÓĞÈÎÎñÔÚÉí²»ÄÜÊ¹ÓÃÕâ¸öÍâ¹¦¡£\n");
        if( me->is_fighting() )
		return notify_fail("Õ½¶·ÖĞÎŞ·¨ÁéÉñ·ÉĞĞ£¡\n");
        if( me->query("force") < 200 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¡\n");
        if( me->query("gin") < 100 )
                return notify_fail("ÄãµÄ¾«²»¹»£¡\n");
	if( me->is_ghost())
		return notify_fail("¹í»êÎŞ·¨ÁéÉñ·ÉĞĞ£¡\n"); 	
        if((int) me->query_skill("lingshenforce",1) < 120)
                return notify_fail("ÄãµÄÁéÉñ¾÷²»¹»¸ßÉî£¡");
		write(BLINK"[1;34mÄãÒªÁéÉñµ½ÄÄ¶ù£¿[2;37;0m");

	input_to( (: call_other, __FILE__, "select_target", me :));

		return 1;
}


void select_target(object me, string name)
{
	object ob;

	if( !name || name=="" ) {
		write("[1;35mÖĞÖ¹ÁéÉñ[1;34m¡£\n");
		return;
	}

	ob = find_player(name);
	if( !ob || !me->visible(ob) || wizardp(ob) )
		ob = find_living(name);
	if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob) || !ob->query("max_force") || !ob->query("force")) {
		write("ÄãÎŞ·¨¸ĞÊÜµ½Õâ¸öÈËµÄÄÚÁ¦ ....\n");
		write("ÄãÒªÒÆ¶¯µ½ÄÄÒ»¸öÈËÉí±ß£¿");
		input_to( (: call_other, __FILE__, "select_target", me :));
		return;


		}
	if( me->is_fighting() ) {
		write("[1;31mÕ½¶·ÖĞÎŞ·¨Ê¹ÓÃÔ¦·ç·ÉĞĞ[2;37;0m£¡\n");
		return;
        } else if( me->query("force") < 200 ) {
		write("ÄãµÄÄÚÁ¦²»¹»£¡\n");
		return;
	}

        me->add("force", -150);
        me->receive_damage("gin", 80);
	
	message_vision( HIC "$NÄıÉñÄÚÊÓ£¬¿ªÊ¼Ê©Õ¹µÀ¼ÒµÄÔ¦·ç·ÉĞĞ ....\n" NOR, me);
        if( random(ob->query("force")) < (int)me->query("force") / 10 ) {
		write("Äã¸ĞÊÜµ½¶Ô·½µÄÄÚÁ¦£¬µ«ÊÇ²»¹»Ç¿ÁÒ¡£\n");
		return;
	}
  if( random(me->query_skill("lingshenforce")) < (int)ob->query("force") / 500 ) {
		write("ÄãÒòÎª²»¹»ÊìÁ·¶øÊ§°ÜÁË¡£\n");
		return;
	}
        if( random(80) > (int)(me->query_skill("lingshenforce",1))){
                write("ÄãÒòÎª²»¹»ÊìÁ·¶øÊ§°ÜÁË¡£\n");
                return;
        }
	if(environment(ob)->query("no_magic")) {
		write("ÄãÏëÒªÁéÉñµÄµØ·½²»¿ÉÒÔÈ¥£¡\n");
		return;
	}
	message( "vision", HIM "\nÍ»È»¼äÔÆË¿¼¯½á,Æ®Ïò" + me->name() 
		+ "£¬ÂıÂıµÄÆ®ÉÏÔÆË¿,×ªÑÛ¼äÒÑÏûÊ§ÎŞ×Ù£¡\n\n" NOR, environment(me), ({ me }) );
        me->move(environment(ob));
        me->start_busy(2);
	message( "vision", HIW "\nÍ»È»¼ä£¬Ìì±ßÆ®À´Ò»Ë¿²ÊÔÆ,ÔÆÉÏÓ°Ô¼ÓĞ¸öÈËÓ°ÕıÔÚÒÔÄãÎŞ·¨ÏëÏóµÄËÙ¶ÈÏòÄãÆ®À´£¡\n\n" NOR,
		environment(ob), ({ me }) );
}

