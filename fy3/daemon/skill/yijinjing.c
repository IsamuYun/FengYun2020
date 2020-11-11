//by xgchen@zzfy
#include <ansi.h>
#include <combat.h>
inherit FORCE;
int valid_enable(string usage) { 
return (usage=="parry" || usage=="force");
}
int valid_learn(object me)
{
             if(me->query("gender")=="女性")
                return notify_fail("你不是少林弟子不能学习易筋经！\n");
             if(me->query("class") != "shaolin")
                return notify_fail("你不是少林弟子不能学习易筋经！\n");
return 1; 
}
int practice_skill(object me)
{
        return 
notify_fail("易筋经只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("shaolin") + "/yijinjing/" + func;
}
int effective_level() { return 55;}
string *parry_msg = ({
       WHT"$n神色泰然，恍若无事，$N那力道千钧的一招竟未能扬起$n一丝衣角！\n"NOR,
});
string *unarmed_parry_msg = ({
       WHT"$n神色泰然，恍若无事，$N那力道千钧的一招竟未能扬起$n一丝衣角！\n"NOR,
});
string query_parry_msg(object weapon)
{
        if(weapon)
                return parry_msg[random(sizeof(parry_msg))];
else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int learn_bonus()
{
         return -500;
}

int practice_bonus()
{
        return -3000;
}

int black_white_ness()
{
        return 200;
}
void skill_improved(object me)
{      
        object hb;
        if( (int)me->query_skill("yijinjing", 1)  > 200 &&  !me->query("marks/yijin") ) {
                tell_object(me,
BBLU HIY "\n你的易筋经又迈上了一个新的境界............\n脑海似乎出现了一个少林老僧，象是在演练一种\n极其神奇的武功，你欣喜若狂，牢牢的将它记在\n心中！！\n\n"HIC"你成功领悟「如来佛法」！\n" NOR);
                    me->set_skill("rulai-fofa",60);
                me->add("max_force",500);
                hb=new("/questobj/obj/hongbao2");
                hb->move(me);
                me->set("marks/yijin",1);
                me->add("score",500);
                
        } 
}


