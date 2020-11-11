// 流星蝴蝶剑  written by tiandi。 
// 翻遍了武林外史，也找不到沈浪跟朱七七的武功名称，与其另外自己瞎编一个名字，不如用古龙自己取的。
// 再者，<天>一书中也没指出傅红雪是用天涯明月刀，只不过是个书名罢了。


inherit SKILL;

mapping *action = ({
        ([      "action":               
"在这刹那问，$n回头，只见一道剑光，如飞袭来!$N之剑！看来这一记是怒中之剑，$N已矢志要把$n先刺杀于剑下",
                "dodge":                -120,
                "damage":               130,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N这一退，临危不乱，风采依然，退得三步，架势不变，弓腿弹腰，“嗤”地抢攻出一剑，剑刺$n咽喉",
                "dodge":                -120,
                "damage":               130,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"一道极其尖锐的厉风，向$n飞袭而来！更可怕的是厉风所挟带的无声剑光！$N已全力出手",
                "dodge":                -130,
                "damage":               120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N剑近$n的脸门时，忽然划了三道剑花。三道剑花过后，才刺出一剑",
                "dodge":                -140,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"忽地又是一道电光，在霹雳未起之前，$N已像箭一般地，向$n标了过去",
                "dodge":                -240,
                "damage_type":  "刺伤"
        ]),
 
});

int valid_learn(object me)
{
        object ob;

        if ( me->query("gender") != "女性")
		  return notify_fail("只有女子才能练流星蝴蝶剑。\n");
	  if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		return notify_fail("以你目前的状况，还没有资格练此功夫。\n");

	 	if ( (int)me->query_skill("moshen-force",1) < 50)
		   return notify_fail("你的魔神诀不够。\n");        
	if( (int)me->query("max_force") < 200 )
                return notify_fail("你的内力不够，没有办法练流星蝴蝶剑。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("剑呢？\n");

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
notify_fail("你的内力或气不够，没有办法练习流星蝴蝶剑。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍流星蝴蝶剑。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("zhuge") + "/fallingstar-sword/" + action;
}
 
int effective_level() { return 18;}

string *parry_msg = ({
          "所有的水珠都变成了$n的剑花，$v把水珠串成点点飞剑，挡住了$N的攻击。\n",
        "在月色下，$v如神龙吐珠、游龙吸水一般吸出了$N的$w。\n",
 
});

string *unarmed_parry_msg = ({
   "$n既无法招架，又因势尽不能闪躲，人急生智，居然一张口，用牙齿咬住了剑锋！\n",
        "风摇花飞，$n身如落花，飞扬而去。\n",
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
	return -10;
}
int black_white_ness()
{
	return 15;
}

