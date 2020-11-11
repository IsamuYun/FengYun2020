// yiru@hero

inherit SKILL;

int valid_enable(string usage) 
{ 
    return usage=="scratching";

}

int valid_learn(object me)
{
        if( me->query("family/family_name") != "蜀山剑派")
               return notify_fail("只有蜀山弟子可以修习蜀山符术。\n");
        if( (int)me->query_skill("taoism",1) < (int)me->query_skill("pal-scratching",1))
                return notify_fail("你的天师正道修为不够，无法领悟更高深的蜀山符术。\n");
        return 1;
}

string scribe_spell_file(string spell)
{
        seteuid(getuid());
        return CLASS_D("xianren") + "/pal-scratching/" + spell;
}

int practice_skill(object me)
{       
        object bug;

        if( bug = me->query_temp("mind_bug") )
                return notify_fail("你的魂魄还没有全部收回，赶快杀死你的"
                        + bug->name() + "吧！\n");

        if( (int)me->query("atman") < 10 )
                return notify_fail("你的灵力不够。\n");

        if( (int)me->query("gin") < 3 )
                return notify_fail("你的精力无法集中。\n");

        me->add("atman", -10);
        me->receive_damage("gin", 3);

        write("你闭目凝神，神游物外，开始修习蜀山符术中的法术....\n");
        if( random((int)me->query("gin")) < 30 ) {
                int rnd;

                rnd = random(me->query_skill("magic", 1));
                if( rnd < 10 )  bug = new("/obj/npc/mind_bug");
                else                    bug = new("/obj/npc/mind_beast");

                write("可是你心思一乱，变出了一只面目狰狞的" + bug->name() + "！\n");
                bug->move(environment(me));
                bug->kill_ob(me);
                me->fight(bug);
                me->set_temp("mind_bug", bug);
                bug->set("owner", me->query("id"));
                return notify_fail("你的魂魄正被" + bug->name() + "缠住，快把它除掉吧！\n");
        }       
        else return 1;
}

int effective_level() { return 15;}

int learn_bonus()
{
        return 10;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 10;
}
