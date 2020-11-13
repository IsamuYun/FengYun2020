#include <skill.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
        int gin_cost;   
        int my_skill;
        int pot;
        int old_pot;
        string skill;
        int amount;
        if ( me->is_fighting() ) {
                return notify_fail("��ս���и��о���\n");
        }
        if ( !arg || sscanf(arg, "%s %d", skill, pot) != 2 )
                return notify_fail("ָ���ʽ��research <����> <����>\n");
        if ( !(int)my_skill = me->query_skill(skill, 1) )
                return notify_fail("��Դ����һ����֪����θ��о���\n");
                                                                                
        if ( !SKILL_D(skill)->valid_learn(me) ) {
                return 0;
        }
//      if( !SKILL_D(skill)->valid_research(me) ) return 0;
        

        old_pot = (int)me->query("potential") - (int) me->query("learned_points");
        if (pot < 0) {
                return notify_fail("������1��Ǳ��\n");
        }
        if (pot > old_pot) {
                return notify_fail("��û���㹻��Ǳ��\n");
        }
        
        if (( me->query_skill(skill, 1) * 10) > me->query("score") ) {
	        return notify_fail("��û���㹻�����ۡ�\n");
        }
        
        if ( me->query_skill(skill, 1) > me->query("level") * 30 )
        {
		return notify_fail("��ĵȼ�̫���ˣ��о�������˸���ļ��ܡ�\n");
        }
        amount = my_skill * SKILL_D(skill)->black_white_ness() / 100;
        amount += SKILL_D(skill)->learn_bonus() + (int)me->query_int() + me->query("level") * 10;
        amount = pot + (amount + random(amount)) * random(200);
	//amount = pot * (amount + random(amount));
	me->add("learned_points", pot);
        me->research_skill(skill, amount);
        write("���" + to_chinese(skill) + "����һ�����׵��о���\n");
        return 1;
}

int help(object me)
{
   write( @HELP
ָ���ʽ: research <����> <����>

��һָ��������һ����Ǳ�ܶ�ĳ�����������о���
�о�ʱ��������۵����ƣ��о����ĵ����ۺͼ��ܵȼ�
�����ȣ��о�����������ͨѧϰ��1.5����
HELP
   );
   return 1;
}

