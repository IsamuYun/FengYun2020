//by xgchen@fy

inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":               "$N���Ƶ�����$w�Ի���Ծ�����缲�������$n��$l",
                "damage":               50,
                "dodge":                -20,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����$w����΢�񣬻ó�һ���׹����$n��$l",
                "parry":                             -200,
                "damage":                 70,
                "force":               200,
                "dodge":                -200,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��ָ�����㣬����$w�Ƴ�����ѩ����â������$n��$l",
                "parry":                             -250,
                "damage":                 90,
                "dodge":                -250,
                "force":               220,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
                "parry":                             -200,
                "damage":                 50,
                "dodge":                -200,
                "force":               100,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N��������Ծ��$w��â��ˮ��һкǧ�����$n��$l",
                "parry":                             -300,
                "damage":                 150,
                "dodge":                -200,
                "force":               250,
                "damage_type":  "����"
        ]),
        ([      "action":               "$N����$wбָ���죬��â���£�����׼$n��$lбб����",
                "parry":                             -100,
                "damage":                 50,
                "dodge":                -100,
                "force":               150,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("int") < 100 )
                return notify_fail("���û�а취ѧϰʮ�ֽ�����\n");

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
notify_fail("�����������������û�а취��ϰʮ�ֽ�����\n");
        if(me->query("gender")!="����" )
                return 
notify_fail("��û�а취��ϰʮ�ֽ�����\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�㰴����ѧ����һ��ʮ�ֽ�����\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("newski") + "/shizi-sword/" + action;
}
 
int effective_level() { return 20;}

string *parry_msg = ({
        "$n�������Ʈ�䣬����$vƽָ����������$N���գ�\n",
        "$n��������� ����׾ٵļ�ס��$N��$w��\n",
        "$n����һ���������е�$v����ǧ�ٽ�â����ס��ȫ��\n",
        "$n���е�$v���綶������ס��$N�����й��ơ�\n",
});

string *unarmed_parry_msg = ({
      "$n�������Ʈ�䣬����$vƽָ����������$N���գ�\n",
        "$n���������$v����׾ٵļ�ס��$N�Ĺ��ơ�\n",
        "$n����һ���������е�$v����ǧ�ٽ�â����ס��ȫ��\n",
        "$n���е�$v���綶������ס��$N�����й��ơ�\n",

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
HIW "\n��ͻȻ��ֻ����ͻȻһ��ɲ�Ǽ�ȫ��������������߻���ħ�ˣ����Ǽ����ʮ�ֽ���������....\n\n" NOR);
                me->delete_skill("shizi-sword");
                me->add("max_force",300);
                hb=new("/questobj/obj/hongbao2");
                hb->move(me);
                me->set("marks/shizi1",1);
                me->add("score",500);
                me->unconcious();
        } 
}

