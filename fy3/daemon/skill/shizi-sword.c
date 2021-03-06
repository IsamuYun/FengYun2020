//by xgchen@fy

inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":               "$N合掌跌坐，$w自怀中跃出，如疾电般射向$n的$l",
                "damage":               50,
                "dodge":                -20,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N手中$w嗡嗡微振，幻成一条白光刺向$n的$l",
                "parry":                             -200,
                "damage":                 70,
                "force":               200,
                "dodge":                -200,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，刺向$n的$l",
                "parry":                             -250,
                "damage":                 90,
                "dodge":                -250,
                "force":               220,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
                "parry":                             -200,
                "damage":                 50,
                "dodge":                -200,
                "force":               100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N纵身轻轻跃起，$w光芒如水，一泻千里，洒向$n的$l",
                "parry":                             -300,
                "damage":                 150,
                "dodge":                -200,
                "force":               250,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N手中$w斜指苍天，剑芒吞吐，，对准$n的$l斜斜击出",
                "parry":                             -100,
                "damage":                 50,
                "dodge":                -100,
                "force":               150,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("int") < 100 )
                return notify_fail("你的没有办法学习十字剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的内力或气不够，没有办法练习十字剑法。\n");
        if(me->query("gender")!="无性" )
                return 
notify_fail("你没有办法练习十字剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍十字剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("newski") + "/shizi-sword/" + action;
}
 
int effective_level() { return 20;}

string *parry_msg = ({
        "$n随风轻轻飘落，手中$v平指，缓缓拍向$N脸颊，\n",
        "$n随意挥洒， 轻而易举的架住了$N的$w。\n",
        "$n深吸一口气，手中的$v化作千百剑芒，护住了全身。\n",
        "$n手中的$v急剧抖动，封住了$N的所有攻势。\n",
});

string *unarmed_parry_msg = ({
      "$n随风轻轻飘落，手中$v平指，缓缓拍向$N脸颊，\n",
        "$n随意挥洒，$v轻而易举的架住了$N的攻势。\n",
        "$n深吸一口气，手中的$v化作千百剑芒，护住了全身。\n",
        "$n手中的$v急剧抖动，封住了$N的所有攻势。\n",

});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return -10;
}

void skill_improved(object me)
{      
        object hb;
        if( (int)me->query_skill("shizi-sword", 1)  > 220 &&  !me->query("marks/shizi1") ) {
                tell_object(me,
HIW "\n你突然间只觉得突然一震，刹那间全身冰冻起来！！走火入魔了，霎那间你把十字剑法遗忘了....\n\n" NOR);
                me->delete_skill("shizi-sword");
                me->add("max_force",300);
                hb=new("/questobj/obj/hongbao2");
                hb->move(me);
                me->set("marks/shizi1",1);
                me->add("score",500);
                me->unconcious();
        } 
}

