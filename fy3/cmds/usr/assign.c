#define SCORE_COST 50000
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object who;
	if( !arg ) return notify_fail("ָ���ʽ : assign <id>");
	if(me->query("family/privs") != -1) 
	return notify_fail("��û������Ȩ����\n");
        if(!objectp(who = present(arg, environment(me))) 
	|| !living(who)
	|| !userp(who)
	|| me == who)
        return notify_fail("����û�������ҡ�\n");
	if(who->query("class") != me->query("class"))
	return notify_fail( who->query("name") + "������" + 
	me->query("family/family_name") + "��һ���ӡ�\n");
	if((int)me->query("family/generation") >= (int)who->
	query("family/generation"))
	return notify_fail(who->query("name") +
	"�ı��ݱ������ͣ�\n");
	if((int)who->query("score") < SCORE_COST)
	return notify_fail( who->query("name") + "�����۲���"+
	chinese_number(SCORE_COST)+"�㡣\n");

      if((int)who->query("combat_exp") < 20000000)
	return notify_fail( who->query("name") + "�ľ��鲻��20M\n");

        who->assign_apprentice((string)me->query("family/title"),-1);
	me->assign_apprentice("ǰ��"+(string)me->query("family/title"),0);
	who->add("score",-SCORE_COST);
       who->add("combat_exp",-10000000);
	message_vision(sprintf("$N��%s֮λ����$n��\n",who->query("family/title")),me,who);

	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : assign <id>
 
���ָ��������㴫��һ��֮���ĵ�λ����������
��Ȼ����λ�����Ҫ��һ������������������,�Ӱ��
����һ�����������ۺ�10m�ľ��顣
HELP
        );
        return 1;
}