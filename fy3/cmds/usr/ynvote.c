// TIE@FY3
#include <ansi.h>
#include <vote.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string who,what;
	string msg;
	object victim;
	int result;
	int diff;
	seteuid(getuid());
	if(!arg) return notify_fail("ָ���ʽ��vote <what> on <who>\n");
	if(sscanf(arg,"%s on %s",what,who)	!= 2)
	return notify_fail("ָ���ʽ��vote <what> on <who>\n");
        if((int)me->query("mud_age") < NEW_PERIOD)
        return notify_fail("�㻹û�е���ͶƱ����ͣ�\n");
        if(me->query("vote_denied"))
        return notify_fail("���Ѿ���������ͶƱ��Ȩ����\n");
	if(what == "on" || what == "off")
	{
		if(who != "chat" && who != "rumor" && who != "fy" &&
			who != "new")
		return notify_fail("����Ƶ��ֻ������chat,fy,new,rumor��\n");	

	}
	else if ( what == "redis" )
	{
		if( who != "tasks")
		return notify_fail("����ɢ����ֻ������tasks��\n");

	}
	else
	{
	victim= LOGIN_D->find_body(who);
        if (!victim) return notify_fail("�ף��������������\n");
	}
	if(me==victim)
	return notify_fail("�㲻����Ͷ�Լ���Ʊ��\n");
	switch(what) 
	{
	case "redis":
         if(!wizardp(me)) {
         if( CRON_D->query_last_hard_dis() > time() - 3600*3)
	 return notify_fail("���ϴ˴��·ֲ�����������Сʱ��\n");
	 result = VOTE_D->add_vote(me,what,who);
         if(!result)
         return notify_fail("���Ѿ�Ͷ��Ʊ�ˣ�\n");
	 log_file("VOTE",sprintf("%s %s (%s) vote redis on tasks\n",ctime(time()), me->query("id"),query_ip_number(me),));
	 diff = sizeof(users())/2 - result + 1;
         if(diff > 0)
         {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ���·ֲ����е�ʹ��������%sƱ��\n"NOR,
                                me->name(),
                                chinese_number(diff));
         }
         else
        {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ���·ֲ����е�ʹ�������ͨ����\n"NOR,
                                me->name());
	seteuid(ROOT_UID);
	TASK_D->init_dynamic_quest(1);
	CRON_D->set_last_hard_dis();
	VOTE_D->delete(who+"/"+what);
        }                                
        message("system",msg,users()); 
           }
                  else
            {
         msg = sprintf(HIR"\n��ͶƱ�������%sͶƱǿ�����·ֲ����е�ʹ����ʹ�����·ֲ�������\n\n"NOR,
                                me->name());
	seteuid(ROOT_UID);
	TASK_D->init_dynamic_quest(1);
	CRON_D->set_last_hard_dis();
	VOTE_D->delete(who+"/"+what);
        message("system",msg,users());  
           }                                
        
           
        break;
	case "right":
	 if(!victim->query("vote_denied") || wizardp(victim))
	 return notify_fail("��/����û�б�����ͶƱ��Ȩ����\n");
	 result = VOTE_D->add_vote(me,what,who);
	 if(!result)
	 return notify_fail("���Ѿ�Ͷ��Ʊ�ˣ�\n");	
	log_file("VOTE",sprintf("%s %s (%s) vote right on %s\n",ctime(time()), me->query("id"),query_ip_number(me),victim->query("id")));
	 diff = right_no - result;
	 if(diff > 0)
	 {
	 msg = sprintf(HIY"��ͶƱ�������%sͶƱ����%s��%s��ͶƱ��Ȩ��������%sƱ��\n"NOR,
				me->name(),victim->name(),victim->query("id"),
				chinese_number(diff));
	 }
	 else
	{
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ����%s��%s��ͶƱ��Ȩ�������ͨ����\n"NOR,
                                me->name(),victim->name(),victim->query("id"));
	victim->delete("vote_denied");
	}                                
	message("system",msg,users());
	break;
        case "noright":
         if(victim->query("vote_denied") || wizardp(victim))
         return notify_fail("��/���Ѿ�������ͶƱ��Ȩ����\n");
         result = VOTE_D->add_vote(me,what,who);
         if(!result)
         return notify_fail("���Ѿ�Ͷ��Ʊ�ˣ�\n");
	 log_file("VOTE",sprintf("%s %s (%s) vote noright on %s\n",ctime(time()),me->query("id"),query_ip_number(me),victim->query("id")));
         diff = noright_no - result;
         if(diff > 0)
         {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ����%s��%s��ͶƱ��Ȩ��������%sƱ��\n"NOR,
                                me->name(),victim->name(),victim->query("id"),
                                chinese_number(diff));
         }
         else
        {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ����%s��%s��ͶƱ��Ȩ�������ͨ����\n"NOR,
                                me->name(),victim->name(),victim->query("id"));
        victim->set("vote_denied",1);
        }                                
        message("system",msg,users());
        break;
        case "kickout":
	 if(wizardp(victim))
         return notify_fail("�㲻���԰�����/�����κ�Ȩ����\n");
         result = VOTE_D->add_vote(me,what,who);
         if(!result)
         return notify_fail("���Ѿ�Ͷ��Ʊ�ˣ�\n");
	 log_file("VOTE",sprintf("%s %s (%s) vote kickout on %s\n",ctime(time()), me->query("id"),query_ip_number(me),victim->query("id")));
         diff = kickout_no - result;
         if(diff > 0)
         {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ����%s��%s��������Ƶ�Ȩ��������%sƱ��\n"NOR,
                                me->name(),victim->name(),victim->query("id"),
                                chinese_number(diff));
         }
         else
        {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ����%s��%s��������Ƶ�Ȩ�������ͨ����\n"NOR,
                                me->name(),victim->name(),victim->query("id"));
        victim->set("kickout_time",time());
        }                                
        message("system",msg,users());
	if(diff <=0)
	{
	victim->save();
	seteuid(ROOT_UID);
	destruct(victim);
	}
        break;
        case "block":
         if(victim->query("chblk_on") || wizardp(victim))
         return notify_fail("��/���Ѿ���������ʹ�ù���Ƶ����Ȩ����\n");
         result = VOTE_D->add_vote(me,what,who);
         if(!result)
         return notify_fail("���Ѿ�Ͷ��Ʊ�ˣ�\n");
	 log_file("VOTE",sprintf("%s %s (%s) vote block on %s\n",ctime(time()), me->query("id"),query_ip_number(me),victim->query("id")));
         diff = block_no - result;
         if(diff > 0)
         {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ����%s��%s��ʹ�ù���Ƶ����Ȩ��������%sƱ��\n"NOR,
                                me->name(),victim->name(),victim->query("id"),
                                chinese_number(diff));
         }
         else
        {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ����%s��%s��ʹ�ù���Ƶ����Ȩ�������ͨ����\n"NOR,
                                me->name(),victim->name(),victim->query("id"));
        victim->set("chblk_on",1);
	victim->save();
        }                                
        message("system",msg,users());
        break;
        case "noblock":
         if(!victim->query("chblk_on") || wizardp(victim))
         return notify_fail("��/��û�б�������ʹ�ù���Ƶ����Ȩ����\n");
         result = VOTE_D->add_vote(me,what,who);
         if(!result)
         return notify_fail("���Ѿ�Ͷ��Ʊ�ˣ�\n");
	 log_file("VOTE",sprintf("%s %s (%s) vote noblock on %s\n",ctime(time()), me->query("id"),query_ip_number(me),victim->query("id")));
         diff = noblock_no - result;
         if(diff > 0)
         {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ����%s��%s��ʹ�ù���Ƶ����Ȩ��������%sƱ��\n"NOR,
                                me->name(),victim->name(),victim->query("id"),
                                chinese_number(diff));
         }
         else
        {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ����%s��%s��ʹ�ù���Ƶ����Ȩ�������ͨ����\n"NOR,
                                me->name(),victim->name(),victim->query("id"));
        victim->delete("chblk_on");
	victim->save();
        }                                
        message("system",msg,users());
        break;
        case "robot":
         if(wizardp(victim))
         return notify_fail("��/���ǹ���Ա�����ǻ����ˣ�\n");
         result = VOTE_D->add_vote(me,what,who);
         if(!result)
         return notify_fail("���Ѿ�Ͷ��Ʊ�ˣ�\n");
	 log_file("VOTE",sprintf("%s %s (%s) vote robot on %s\n",ctime(time()), me->query("id"),query_ip_number(me),victim->query("id")));
         diff = robot_no -result;
         if(diff > 0)
         {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ���%s��%s��Ϊ�����ˣ�����%sƱ��\n"NOR,
                                me->name(),victim->name(),victim->query("id"),
                                chinese_number(diff));
         }
         else
        {
	object room;
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ���%s��%s��Ϊ�����ˣ����ͨ����\n"NOR,
                                me->name(),victim->name(),victim->query("id"));
        message_vision(HIY"��Ȼһ��������ס��$N��\n"NOR,victim);
        victim->set_temp("last_location", base_name(environment(victim)));
        room = load_object("/d/wiz/courthouse");
        victim->move(room);
        }                                
        message("system",msg,users());
        break;
        case "imprison":
         if(wizardp(victim))
         return notify_fail("��/���ǹ���Ա������û�ã�\n");
	if(base_name(environment(victim)) == "/d/wiz/jail")
	return notify_fail("��/���Ѿ��ڷ��������ˣ�\n");
         result = VOTE_D->add_vote(me,what,who);
         if(!result)
         return notify_fail("���Ѿ�Ͷ��Ʊ�ˣ�\n");
         log_file("VOTE",sprintf("%s %s (%s) vote imprison on %s\n",ctime(time()), me->query("id"),query_ip_number(me),victim->query("id")));
         diff = imprison_no -result;
         if(diff > 0)
         {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ����%s��%s��������%sƱ��\n"NOR,
                                me->name(),victim->name(),victim->query("id"),
                                chinese_number(diff));
         }
         else
        {
        object room;
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ����%s��%s�������ͨ����\n"NOR,
                                me->name(),victim->name(),victim->query("id"));
        message_vision(HIY"��Ȼһ��������ס��$N��\n"NOR,victim);
        room = load_object("/d/wiz/jail");
        victim->move(room);
        }                                
        message("system",msg,users());
        break;
        case "ban":
         if(wizardp(victim))
         return notify_fail("�㲻���Զ���/����ô����\n");
         result = VOTE_D->add_vote(me,what,who);
         if(!result)
         return notify_fail("���Ѿ�Ͷ��Ʊ�ˣ�\n");
log_file("VOTE",sprintf("%s %s (%s) vote ban on %s\n",ctime(time()), me->query("id"),query_ip_number(me),victim->query("id")));
         diff = ban_no - result;
         if(diff > 0)
         {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ��ֹ%s��%s��վ�����ߵ�Ȩ��������%sƱ��\n"NOR,
                                me->name(),victim->name(),victim->query("id"),
                                chinese_number(diff));
         }
         else
        {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ��ֹ%s��%s��վ�����ߵ�Ȩ�������ͨ����\n"NOR,
                                me->name(),victim->name(),victim->query("id"));
        }                                
        message("system",msg,users());
        if(diff <=0)
        {
        victim->save();
        seteuid(ROOT_UID);
	BAN_D->dynamic_add(query_ip_number(victim));
        destruct(victim);
        }
        break;
	case "on" :
	if( !CHANNEL_D->query("block_"+who))
	return notify_fail(who+"Ƶ���Ѿ��ǿ����ġ�\n");
         result = VOTE_D->add_vote(me,what,who);
         if(!result)
         return notify_fail("���Ѿ�Ͷ��Ʊ�ˣ�\n");
	 log_file("VOTE",sprintf("%s %s (%s) vote on on %s\n",ctime(time()), me->query("id"),query_ip_number(me),who));
         diff = on_no - result;
         if(diff > 0)
         {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ����%sƵ��������%sƱ��\n"NOR,
                                me->name(),who,
                                chinese_number(diff));
         }
         else
        {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ����%sƵ�������ͨ����\n"NOR,
                                me->name(),who);
	 CHANNEL_D->set_block(who,0);
         EMOTE_D->set_block(who,0);
        }                                
        message("system",msg,users());
	break;
	case "off" :
        if( CHANNEL_D->query("block_"+who))
        return notify_fail(who+"Ƶ���Ѿ��ǹرյġ�\n");
         result = VOTE_D->add_vote(me,what,who);
         if(!result)
         return notify_fail("���Ѿ�Ͷ��Ʊ�ˣ�\n");
         log_file("VOTE",sprintf("%s %s (%s) vote off on %s\n",ctime(time()), me->query("id"),query_ip_number(me),who));
         diff = off_no - result;
         if(diff > 0)
         {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ�ر�%sƵ��������%sƱ��\n"NOR,
                                me->name(),who,
                                chinese_number(diff));
         }
         else
        {
         msg = sprintf(HIY"��ͶƱ�������%sͶƱ�ر�%sƵ�������ͨ����\n"NOR,
                                me->name(),who);
         CHANNEL_D->set_block(who,1);
         EMOTE_D->set_block(who,1);
        }                                
        message("system",msg,users());
	break;
	default:
		return notify_fail("ָ���ʽ��vote <what> on <who>\n");

	}
	return 1;
}
int help(object me)
{
  write(@HELP

����ָ�����������û�й�����Ա���ߵ�ʱ��������
Υ�������������˵ģ���Ҫ������������㹻Ʊ���ſ�����Ч��

ָ���ʽ��vote <what> on <who>

����<what>�����������е�һ� 

right:		����ͶƱ��Ȩ������Ҫ��Ʊ��
noright:	����ͶƱ��Ȩ������ҪʮƱ��
kickout:	���������Ƶ�Ȩ������Ҫ��Ʊ��
block:		����ʹ�ù���Ƶ����Ȩ������Ҫ��Ʊ��
noblock:	����ʹ�ù���Ƶ����Ȩ������Ҫ��Ʊ��
robot:		���Ϊ�����ˣ���Ҫ��Ʊ��
imprison	��ĳ�˼����������Ҫ��Ʊ��
ban:		��ֹվ�����ߵ�Ȩ����site ban������Ҫʮ��Ʊ��
off:		�رչ���Ƶ�������е�who������chat,fy,new,rumor����ҪʮƱ��
on:		��������Ƶ�������е�who������chat,fy,new,rumor����Ҫ��Ʊ��
redis:		���·ֲ����У���ɺ�û��ɣ���ʹ����������󣩣���Ҫ����������ң�

ע�����е�ͶƱ����м�¼����������ͶƱ����һ���������
���շ����������ã�

HELP
    );
    return 1;
}
