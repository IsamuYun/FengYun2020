// drunk.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int limit;

	limit = (me->query("con") / 20) +1;

	if( duration > limit
	&&	living(me) ) {
		me->delete("statusnow");
		me->unconcious();
		return 0;
	} else if( duration > limit/2 ) {
		tell_object(me, "��������л����������пյ����ģ�ֱ��������˯һ����\n");
		message("vision", me->name() + "ҡͷ���Ե�վ��վ���ȣ���Ȼ�����ϱ������µķ��������ˡ�\n",
			environment(me), me);
	}

	me->apply_condition("sanqing_drug", duration + 1);
	if( duration > 60) 
		{
		me->delete("statusnow");
		return 0;
		}
	return 1;
}
