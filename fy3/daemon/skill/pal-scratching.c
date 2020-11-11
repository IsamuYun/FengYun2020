// yiru@hero

inherit SKILL;

int valid_enable(string usage) 
{ 
    return usage=="scratching";

}

int valid_learn(object me)
{
        if( me->query("family/family_name") != "��ɽ����")
               return notify_fail("ֻ����ɽ���ӿ�����ϰ��ɽ������\n");
        if( (int)me->query_skill("taoism",1) < (int)me->query_skill("pal-scratching",1))
                return notify_fail("�����ʦ������Ϊ�������޷�������������ɽ������\n");
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
                return notify_fail("��Ļ��ǻ�û��ȫ���ջأ��Ͽ�ɱ�����"
                        + bug->name() + "�ɣ�\n");

        if( (int)me->query("atman") < 10 )
                return notify_fail("�������������\n");

        if( (int)me->query("gin") < 3 )
                return notify_fail("��ľ����޷����С�\n");

        me->add("atman", -10);
        me->receive_damage("gin", 3);

        write("���Ŀ�����������⣬��ʼ��ϰ��ɽ�����еķ���....\n");
        if( random((int)me->query("gin")) < 30 ) {
                int rnd;

                rnd = random(me->query_skill("magic", 1));
                if( rnd < 10 )  bug = new("/obj/npc/mind_bug");
                else                    bug = new("/obj/npc/mind_beast");

                write("��������˼һ�ң������һֻ��Ŀ������" + bug->name() + "��\n");
                bug->move(environment(me));
                bug->kill_ob(me);
                me->fight(bug);
                me->set_temp("mind_bug", bug);
                bug->set("owner", me->query("id"));
                return notify_fail("��Ļ�������" + bug->name() + "��ס������������ɣ�\n");
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
