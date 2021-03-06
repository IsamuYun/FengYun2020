#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
        if( me->query_temp("nofly") || me->query("job/sxy"))
                return notify_fail("有重要的任务在身，不能乱跑！\n");
        if( me->is_fighting() )
                return notify_fail("战斗中无法使用唤龙诀！\n");
        if( me->query("atman") < 100 )
                return notify_fail("你的灵力不够！\n");
        if( me->query("atman") < 100 )
                return notify_fail("你的灵力不够！\n");
        if( me->query("gin") <= 100 )
                return notify_fail("你的精不够！\n");
        if( me->is_ghost())
                return notify_fail("鬼魂无法呼唤神龙！\n");     
        if((int) me->query_skill("huanlong",1) < 151)
                return notify_fail("你的唤龙诀还不够纯熟！");

        if( target )
                return notify_fail("唤龙诀只能对自己使用！\n");
        write("你要御龙到哪一个人身边？");
        input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
}

void select_target(object me, string name)
{
        object ob;

        if( !name || name=="" ) {
                write("中止呼唤神龙。\n");
                return;
        }

        ob = find_player(name);
        if( !ob || !me->visible(ob) || wizardp(ob) )
                ob = find_living(name);
        if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob)

        || !ob->query("max_force") || !ob->query("force")) {
                write("你无法感受到这个人的内力 ....\n");
                write("你要御龙到哪一个人身边？");
                input_to( (: call_other, __FILE__, "select_target", me :));
                return;
        }
        if( me->is_fighting() ) {
                write("战斗中无法使用唤龙诀！\n");
                return;
        } else if( me->query("atman") < 100 ) {
                write("你的灵力不够，无法召唤神龙！\n");
                return;
        }

        me->add("atman", -75);
        me->receive_damage("gin", 30);
        
        message_vision( HIG "$N念了一段奇怪的灵咒，开始呼唤神龙....\n" NOR, me);
        if( random(me->query_skill("magic")) < (int)ob->query("atman") / 50 ) {
                write("的呼唤毫无效果，可能是你因为不够熟练。\n");

                return;
        }
        if( random(50) > 
        (int)(me->query_skill("huanlong",1))){
                write("的呼唤毫无效果，可能是你因为不够熟练。\n");
                return;
        }
        if(environment(ob)->query("no_magic")) {
              write("你想要御龙去的地方不可以用唤龙决！\n");
              return;
        }
                message( "vision", HIC "\n一条金鳞巨龙从天而降，恭敬地驮起" + me->name() + "，长吟后飞入云霄！\n\n" NOR, environment(me), ({ me }) );
        me->move(environment(ob));
        me->start_busy(random(2));
        message( "vision", HIC "\n你的上空突然出现一条金鳞巨龙，巨龙的身上隐约站着个人！
看上去好象就是"+me->name()+"。\n\n" NOR,
                environment(ob), ({ me }) );
}
