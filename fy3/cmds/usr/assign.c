#define SCORE_COST 50000
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object who;
	if( !arg ) return notify_fail("指令格式 : assign <id>");
	if(me->query("family/privs") != -1) 
	return notify_fail("你没有这种权力。\n");
        if(!objectp(who = present(arg, environment(me))) 
	|| !living(who)
	|| !userp(who)
	|| me == who)
        return notify_fail("这里没有这个玩家。\n");
	if(who->query("class") != me->query("class"))
	return notify_fail( who->query("name") + "并不是" + 
	me->query("family/family_name") + "的一份子。\n");
	if((int)me->query("family/generation") >= (int)who->
	query("family/generation"))
	return notify_fail(who->query("name") +
	"的辈份必须比你低！\n");
	if((int)who->query("score") < SCORE_COST)
	return notify_fail( who->query("name") + "的评价不够"+
	chinese_number(SCORE_COST)+"点。\n");

      if((int)who->query("combat_exp") < 20000000)
	return notify_fail( who->query("name") + "的经验不够20M\n");

        who->assign_apprentice((string)me->query("family/title"),-1);
	me->assign_apprentice("前任"+(string)me->query("family/title"),0);
	who->add("score",-SCORE_COST);
       who->add("combat_exp",-10000000);
	message_vision(sprintf("$N将%s之位传给$n。\n",who->query("family/title")),me,who);

	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : assign <id>
 
这个指令可以让你传让一帮之主的地位给另外的人物。
当然，这位玩家需要有一定的做帮主先提条件,接帮后
的玩家会减掉所有评价和10m的经验。
HELP
        );
        return 1;
}
