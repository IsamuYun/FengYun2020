// goto.c

inherit F_CLEAN_UP;

int main(object me)
{
	if (!me->query("class"))
			return notify_fail("�������ɺ�ſ���ʹ�ø����\n");
	if (me->is_ghost())
			return notify_fail("���겻����ʹ�á�\n");
	if( me->is_fighting() )
			return notify_fail("ս���в�����ʹ�û�������\n");
	if (me->query("level")> 49)
	{
		if( me->query("lifetili")<2 )
			return notify_fail("��Ļ���������\n");
		if( me->query("force")<50 )
			return notify_fail("�������������\n");
		me->add("lifetili",-2);
		me->add("force",-50);
	}
			
	if (me->query("class")=="baiyun" || me->query("class")=="official" )
	{
		message_vision("$Nʹ���˻�������˲����ʧ�����˵���ǰ��\n", me);
		me->move("/d/fy/fqkhotel");
		message_vision("$Nʹ���˻��������ֳ��������˵���ǰ��\n", me);
		return 1;
	}
	if (me->query("class")=="dazhao" )
	{
		message_vision("$Nʹ���˻�������˲����ʧ�����˵���ǰ��\n", me);
		me->move("/u/guanwai/inn");
		message_vision("$Nʹ���˻��������ֳ��������˵���ǰ��\n", me);
		return 1;
	}
		if (me->query("class")=="sanqing" )
	{
		message_vision("$Nʹ���˻�������˲����ʧ�����˵���ǰ��\n", me);
		me->move("/u/taoguan/road5");
		message_vision("$Nʹ���˻��������ֳ��������˵���ǰ��\n", me);
		return 1;
	}
		if (me->query("class")=="wudang" )
	{
		message_vision("$Nʹ���˻�������˲����ʧ�����˵���ǰ��\n", me);
		me->move("/u/wudang/road1");
		message_vision("$Nʹ���˻��������ֳ��������˵���ǰ��\n", me);
		return 1;
	}
		if (me->query("class")=="tieflag" )
	{
		message_vision("$Nʹ���˻�������˲����ʧ�����˵���ǰ��\n", me);
		me->move("/d/tieflag/island");
		message_vision("$Nʹ���˻��������ֳ��������˵���ǰ��\n", me);
		return 1;
	}
		if (me->query("class")=="tianchui" )
	{
		message_vision("$Nʹ���˻�������˲����ʧ�����˵���ǰ��\n", me);
		me->move("/u/palace/palace_palace");
		message_vision("$Nʹ���˻��������ֳ��������˵���ǰ��\n", me);
		return 1;
	}
		if (me->query("class")=="mojiao" )
	{
		message_vision("$Nʹ���˻�������˲����ʧ�����˵���ǰ��\n", me);
		me->move("/d/daimiao/tongting");
		message_vision("$Nʹ���˻��������ֳ��������˵���ǰ��\n", me);
		return 1;
	}
		if (me->query("class")=="xingguo" )
	{
		message_vision("$Nʹ���˻�������˲����ʧ�����˵���ǰ��\n", me);
		me->move("/d/qianfo/chansi");
		message_vision("$Nʹ���˻��������ֳ��������˵���ǰ��\n", me);
		return 1;
	}


	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : backhome
 
��ʦ֮�����ʹ�ø�����ص�ʦ�����ڸ����ĵص㡣
 
HELP
    );
    return 1;
}