#include <ansi.h>
inherit FORCE;

int valid_enable(string usage)
{
 return (usage=="iron-cloth" || usage=="force");
}

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("四照神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string perform_action_file(string action)
{
        return CLASS_D("moondoor") + "/four-force/" + action;
}


string exert_function_file(string func)
{
        return CLASS_D("moondoor") + "/four-force/" + func;
}
 
int effective_level() { return 25;}

string *absorb_msg = ({
        "$n施展出四照神功，浑身肌肤坚如寒冰。\n",
        "$n身型一顿，内力充斥了丈许空间。\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}
int bounce_ratio()
{
        return 20;

}
int learn_bonus()
{
        return 10;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 10;
}

void skill_improved(object me)
{
 if( ((int)me->query_skill("four-force", 1) >100) && (me->query("marry") || me->query("divorced")))
  {
   tell_object(me, HIR "\n你眼前幻出奇像！走火入魔了！！....\n\n" NOR);
   me->skill_death_penalty();

   me->delete_skill("four-force");
   me->unconcious();
  } 
}