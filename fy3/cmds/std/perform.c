// perform.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object weapon;
        string martial, skill;
        int result;
        
        seteuid(getuid());

        if( me->is_busy() )
                return notify_fail("������һ��������û����ɣ�����ʩ���⹦���� \n");

        if( environment(me)->query("no_fight") )   return notify_fail("���ﲻ׼ʹ���⹦��\n");
        if( !arg ) return notify_fail("��Ҫ���⹦��ʲ�᣿\n");

        if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
                if( weapon = me->query_temp("weapon") )
                        martial = weapon->query("skill_type");
                else if( weapon = me->query_temp("secondary_weapon") )
			martial = weapon->query("skill_type");
		else
                        martial = "unarmed";
        }
	else{
	if( martial == "axe" || 
	    martial == "blade" ||
            martial == "dagger" ||
            martial == "fork" ||
            martial == "hammer" ||
            martial == "parry" ||
            martial == "unarmed" ||
            martial == "staff" ||
            martial == "sword" ||
            martial == "throwing" ||
            martial == "spear" ||
            martial == "whip" ) 
		return notify_fail("�����⹦����ָ���书���࣡\n");
	}
        if( stringp(skill = me->query_skill_mapped(martial)) ) {
                notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
	//			write ("skill:"+SKILL_D(skill)->belong()+"\n");
	//			write ("class:"+me->query("class"));
        //if(SKILL_D(skill)->belong()!=me->query("class")&& userp(me))
	//return notify_fail("ֻ�иü��ܵ����ɳ�Ա�ſ���ʹ�á�\n");
	//	if(!SKILL_D(skill)->belong()&& userp(me))
	//return notify_fail("�˼��ܾ�����û���š�\n");
                if( SKILL_D(skill)->perform_action(me, arg) ) {
                        if( random(120) < (int)me->query_skill(skill) )
                                me->improve_skill(skill, 1, 1);
                        return 1;
                } else if( SKILL_D(martial)->perform_action(me, arg) ) {
                        if( random(120) < (int)me->query_skill(martial, 1) )
                                me->improve_skill(martial, 1, 1);
                        return 1;
                }
                return 0;
        }

        return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��⹦��\n");
}

int help (object me)
{
        write(@HELP
ָ���ʽ��perfrom [<�书����>.]<��ʽ����> [<ʩ�ö���>]

�������ѧ���⹦(ȭ�š�����������....)��һЩ����Ĺ�����ʽ����ʽ������
�����ָ����ʹ�ã���������� enable ָ��ָ����ʹ�õ��书����ָ���书��
��ʱ�����ֵ��⹦��ָ���ȭ�Ź���ʹ������ʱ���Ǳ��е��书��

��������⹦�������಻ͬ��������ʽ������ͬ�ģ����߲����ȭ�Ÿ���������
���书(���Ṧ)�������� <�书>.<��ʽ>  �ķ�ʽָ�����磺

perform sword.powerfocus 
perform move.reflexion

���仰˵��ֻҪ�� enable �е��书��������ʽ�ģ������������ָ��ʹ�á�
HELP
        );
        return 1;
}
 
