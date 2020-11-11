// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int wimpy;
	if(me->query("class") != "bandit") return
        notify_fail("不是天枫派的人不可以装死！\n");
        seteuid(getuid());
        if( !me->is_fighting() )
                return notify_fail("你不在战斗中，不需要假装死。\n");
        if( me->is_busy())
                return notify_fail("你现在正忙，不能假装死。\n");
        wimpy = (int)me->query("env/wimpy");
         if(random(me->query("kar"))>20)
{
        message_vision("$N惨叫一声，一头栽倒在地下。\n$N死了。\n",me);
      me->set_temp("disable_inputs",1);
      me->set_temp("block_msg/all",1);
      me->set("disable_type",HIG "<假死中>" NOR);
        me->remove_all_killer();
	me->remove_all_enemy();
        me->delete("env/wimpy");
        me->strat_busy(5);
        me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me, wimpy :), 
random(50 - (int) me->query_con()));
}
else{
        message_vision("惨了！$N假死被揭穿了。看来要真死了!\n",me);
        me->strat_busy(4);
}
        return 1;
}
void remove_dazuo(object me, int wimpy)
{
   me->delete_temp("disable_inputs");
   me->delete("disable_type");
   me->delete_temp("block_msg/all");
        me->set("env/wimpy",wimpy);
        me->strat_busy(4);
   	message_vision("$N在地上悄悄地翻了个身，小心翼翼地睁开了眼。\n",me);
        me->move(environment(me),1);
}

int help(object me)
{
        write(@HELP
指令格式 : jiasi
让你在战斗中装死，创造逃生的机会。
名门正派的人不可以装死。

HELP
        );
        return 1;
}
 
