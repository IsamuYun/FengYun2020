//by xgchen@zzfy
#include <ansi.h>
#include <combat.h>
inherit FORCE;
int valid_enable(string usage) { 
return (usage=="parry" || usage=="force");
}
int valid_learn(object me)
{
             if(me->query("gender")=="Ů��")
                return notify_fail("�㲻�����ֵ��Ӳ���ѧϰ�׽��\n");
             if(me->query("class") != "shaolin")
                return notify_fail("�㲻�����ֵ��Ӳ���ѧϰ�׽��\n");
return 1; 
}
int practice_skill(object me)
{
        return 
notify_fail("�׽ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("shaolin") + "/yijinjing/" + func;
}
int effective_level() { return 55;}
string *parry_msg = ({
       WHT"$n��ɫ̩Ȼ���������£�$N������ǧ����һ�о�δ������$nһ˿�½ǣ�\n"NOR,
});
string *unarmed_parry_msg = ({
       WHT"$n��ɫ̩Ȼ���������£�$N������ǧ����һ�о�δ������$nһ˿�½ǣ�\n"NOR,
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
BBLU HIY "\n����׽��������һ���µľ���............\n�Ժ��ƺ�������һ��������ɮ������������һ��\n����������书������ϲ�������εĽ�������\n���У���\n\n"HIC"��ɹ����������𷨡���\n" NOR);
                    me->set_skill("rulai-fofa",60);
                me->add("max_force",500);
                hb=new("/questobj/obj/hongbao2");
                hb->move(me);
                me->set("marks/yijin",1);
                me->add("score",500);
                
        } 
}


