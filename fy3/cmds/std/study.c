// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	mapping skill;
	string	book,liter;
	int cost, sena;
	int amount=0;
	int my_skill;

	if( me->is_fighting() )
		return notify_fail("���޷���ս����ר�������ж���֪��\n");
       if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ������ж���֪��\n");

       if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
                return notify_fail("ָ���ʽ��study <��Ʒ> <������>\n");

	if(!objectp(ob = present(book, me)) )
	if(!objectp(ob = present(book, environment(me))))
		return notify_fail("��Ҫ��ʲ�᣿\n");

	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("���޷�����������ѧ���κζ�����\n");
// added by tie
	if(stringp(skill["literate"])) liter = skill["literate"];
	else liter = "literate";
	if( !me->query_skill(liter, 1) )
		return notify_fail("�㿴����Ү��������ѧѧ"+to_chinese(liter)+"�ɡ�\n");

	message("vision", me->name() + "��ר�ĵ��ж�" + ob->name()
		+ "��\n", environment(me), me);
	if( me->query_skill(skill["name"], 1) /10 >= me->query("level") ) {
		write("�������ڵĵȼ����������Ҳû�á�\n");
		return 1;
	}
	notify_fail("����Ŀǰ����������û�а취ѧ������ܡ�\n");
	if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

	cost = skill["sen_cost"] + skill["sen_cost"] 
		* (skill["difficulty"] - (int)me->query_int())/20;
	cost = cost /2;
        if(cost < 1) cost = 1;
	if( cost > sena)
	return notify_fail("����Ŀǰ��������������Ҫ��"+chinese_number(cost)+"����\n");
	if( (int)me->query("sen") <= sena) {
		write("�����ڹ��ƣ�룬�޷�ר�������ж���֪��\n");
		return 1;
	}

	if( me->query_skill(skill["name"], 1) > skill["max_skill"] ) {
		write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
		return 1;
	}
	me->receive_damage("sen", sena);

	if( !me->query_skill(skill["name"], 1) )
		me->set_skill(skill["name"], 0);

	amount +=(int)me->query_skill(liter, 1)/5+1;
	if( amount < 1) amount = 1;
	amount = amount*sena/cost;
	me->improve_skill(skill["name"], amount);
	write("���ж��й�" + to_chinese(skill["name"]) + "�ļ��ɣ��ƺ��е��ĵá�\n");
	return 1;
}

int help(object me)
{
   write( @HELP
ָ���ʽ: study <��Ʒ����>

���ָ��ʹ����Դ����Ż�������Ʒ��ѧĳЩ����,
��ǰ����: ��һ��Ҫ�������ϵ����֡�

see also : learn
HELP
   );
   return 1;
}
