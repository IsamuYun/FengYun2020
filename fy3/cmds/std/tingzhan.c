#include <ansi.h>
inherit SKILL;
int main(object me, string arg)
{
        string who;
      	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;

	seteuid(getuid());

    if ( (!(myfam = me->query("family")) || myfam["family_name"] != "������") )
        return notify_fail("ֻ�������µ��˲�����ͣս��\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("����û���˴򶷣�\n");

	if( me->query_temp("tianzhan") )
		return notify_fail("���Ѿ���Ȱ�˼Ұն��ˣ�\n");
        if ((int)me->query_skill("chanting",1) < 60 ) 
		return notify_fail("����о��ȼ�������\n");
	if( !arg || sscanf(arg, "%s halt", who)!=1 ) return
		notify_fail("ָ���ʽ��tingzhan <����> halt\n");

	victim = present(who, environment(me));

	if( !victim || victim == me) return notify_fail("�����ҵĶ��������\n");

	if( !living(victim) || !objectp(victim))
		return notify_fail("��ҪȰ˭ͣս��\n");

    if ( (vtfam = victim->query("family")) && vtfam["family_name"] == "������" )
        return notify_fail("�㲻�����ɵ�ʹ��ͣս��\n");

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("��Ҳ���Ȱ��ʦͣս��\n");
       if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ�����ʹ��ͣս��\n");
	if( me->is_fighting() )
                return notify_fail("һ�ߴ��һ��Ȱ����ͣս����������α�����ˣ�\n");


	sp = (int)me->query_skill("chanting") * 15 + (int)me->query("kar") * 5;
	if( sp < 1 ) sp = 1;
	dp = (int)victim->query("gin");

	tell_object(me, "����" + victim->name() + "�߹�ȥ��˫�ֺ�ʮ����ʼ���з�"
			+ "...\n\n");
	tell_object(victim, me->name() + "�����߹�����˫�ֺ�ʮ��˵�����ҷ�ȱ�, ����" + RANK_D->query_respect(victim) + "ͣ��,�������������سɷ�� ...��\n\n");

	message("vision", "ֻ��" + me->name() + "��" 
		+ victim->name() + "�߹�ȥ��\n��˫�ֺ�ʮ��˵��: ��"
		+ RANK_D->query_respect(victim) + "��ͣ�ְɣ��������������سɷ��  ...��\n\n", environment(me), ({ me, victim }) );

	call_out( "compelete_dushi", 3, me, victim, ob, sp, dp);

	return 1;
}

void compelete_dushi(object me, object victim, object ob, int sp, int dp)
{
	me->delete_temp("tingzhan");

	if( environment(victim) != environment(me) ) {
		tell_object(me, "̫��ϧ�ˣ���Ҫ�ҵ����Ѿ����ˡ�\n");
		return;
	}

	if( living(victim) && (random(sp+dp) > dp) ) 
	{
		victim ->remove_all_enemy();
		tell_object(me, victim->name() + "��ͷ����һ�ᣬ�ֿ��˿��㣬������򶯣�ֹͣ�˴򶷡�\n");
		tell_object(victim, "������֮����������һ�����֮�����������������ȥ�ˡ�\n");

		me->improve_skill("chanting", random(me->query("int")));
		if(((int)me->query("learned_points") + 120) > (int)me->query("potential"))
			me->add("potential",1);
		me->add("combat_exp",2);
		me->add("gin",50);
		me->start_busy(3);
	} 
	else 
	{
		if( random(sp) > dp/2 ) {
			message_vision(victim->name() + "�ݺݵص���$Nһ�ۣ��ȵ����Ҷ������˸������ˣ���ͣս��! $Nת��������ˡ�\n", me);
			
			return;
		}
	
		tell_object(me, victim->name() + "һ����ս��������������\n");
		tell_object(victim, "����������ͷ����" + me->name() + "������\n");
		message("vision", victim->name() + "һ����ս������" + me->name() + "������\n", 
			environment(me), ({ me, victim }) );

	}
}

int help(object me)
{
write(@HELP
ָ���ʽ : tingzhan <ĳ��> halt
�����ö���ֹͣս���������㲻������ս����ʹ�á�
HELP
    );
    return 1;
}
