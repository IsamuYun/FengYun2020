//light@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int level;
        int orforce;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        extra = me->query_skill_eff_lvl("yingzhaogong");
        level = me->query_skill("yingzhaogong",1);
        if ( level < 50) return notify_fail("��Ĵ���ӥצ�����������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷ֽ����֣�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add("force_factor",extra);
        orforce = (int) me->query("force");
        me->add("force",extra*2);
        me->add_temp("apply/attack",extra*2);
        me->add_temp("apply/damage",extra*2);
        weapon = me->query_temp("weapon");
        msg = HIR  "$Nʹ��ӥצ���ľ����۷ֽ����֣ݣ�һ��������ʽ��$n������\n" NOR;
        message_vision(msg,me,target);
        msg = HIY  "[ �ɿ����� ! ] \n$N����һ�������ƺ���������$n��������ָ���$n��ߣ�ͻȻ�Ϸ���ץ��$n�ĺ�ͷ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "[ Ц����� ! ] \n$N���񲻶�������$nϮ���ؿڣ�������ƫ�������õ��ֱۣ����ֱ���ץ����ߣ��������գ����⼱��$n���ؽڣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "[ ׳ʿ���� ! ] \n$N˫�ֶ��ͣ�б��һ����������ץ$n������������$n�ⲿ��ǰһ�ͣ���һŤ������һ����$n����ؽ���ʱ�ѳ�!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "[ ��������! ] \n$N������$n�����ϼ����������ϲ����������$n�Ҹ��´��룬���ַ���������ͬʱ��������$n�ʺ�!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIR  "$N����΢�࣬������������һ�ģ�����б�ɶ�����һ��[������һ]��ž��һ�����صĻ���$n��С��!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(2);
        me->set("force_factor",0);
        me->set("force", orforce);
        me->add_temp("apply/attack",-extra*2);
        me->add_temp("apply/damage",-extra*2);
return 1;
}

