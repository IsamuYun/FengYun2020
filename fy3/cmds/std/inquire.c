// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
string *skill_level_desc = ({
	BLU "��ѧէ��" NOR,
	HIB "��ͨƤë" NOR,
	HIB "��������" NOR,
	HIB "������" NOR,
	HIB "�������" NOR,
	CYN "�������" NOR,
	CYN "����似" NOR,
	CYN "�����뻯" NOR,
	HIC "�Ƿ��켫" NOR,
	HIC "һ����ʦ" NOR,
	HIW "��ɲ�" NOR
});
string *knowledge_level_desc = ({
	BLU "��ѧէ��" NOR,
	HIB "�����ž�" NOR,
	HIB "��֪һ��" NOR,
	HIB "������" NOR,
	HIB "����С��" NOR,
	CYN "�������" NOR,
	CYN "��Ȼ���" NOR,
	CYN "��Ȼ��ͨ" NOR,
	HIC "������˫" NOR,
	HIC "������" NOR,
	HIW "��ɲ�" NOR
});
string skill_level(string, int);
int main(object me, string arg)
{
	object ob, man, *all;
	mapping fam, skl, lrn, map;
	string *sname, *mapped;
	int sp, dp;
	int i, cost;
        seteuid(getuid());
	all = all_inventory(environment(me));
	for(i=0; i<sizeof(all); i++) {
		if( living(all[i]) && !userp(all[i]) ) man = all[i];
	}

        

	if ( !objectp(man) )
		return notify_fail("��Χû���ܰ���ȥ���ֱ��˵ļ��ܣ�\n");
	if ( !arg )
		return notify_fail("��Ҫ����˭�ļ��ܣ�\n");
	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("��Ҫ����˭�ļ��ܣ�\n");

	if ( ob == me )
		return notify_fail("������ָ��������\n");
        if ( present(ob, environment(me)) )
                return notify_fail("��Ҫ�������˾��������\n");
	cost = me->query("max_gin")/(me->query_skill("inquiry",1)/10 + 1);

	if ( me->query("gin") <= cost )
		return notify_fail("������̫���ˣ��޷�ȥ�������˵ļ��ܡ�\n");

	tell_object(me, "�������" + man->name() + "��������" + ob->name() + "���书�����\n\n");
	message("vision", "ֻ��" + me->name() + "��ͷ�Ӷ��ظ�" + man->name() + "˵�Ż��������ڴ���Щʲô��\n\n", 
		environment(me), ({ me, man }) );

	sp = me->query_skill("inquiry")*10 + me->query("kar")*5 + me->query("gin") + man->query("gin");
	dp = ob->query("kar")*10 + ob->query("gin")*3;
	
	if ( random(sp) < random(dp) )
		return notify_fail( man->name() + "ҡ��ҡͷ��˵���������ҿɲ������"
		 	+ RANK_D->query_respect(me) + "����ȥ����˴���һ�°ɣ�\n");

	me->receive_damage("gin", cost );

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( man->name() + "�����㣺 " + ob->name() + "ʲô�����ᣡ\n");
		return 1;
	}
	write( man->name() + "�����㣺 " + ob->name() +"Ŀǰ��ѧ���ļ��ܣ�\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	i = random(sizeof(skl));

	printf("%s%s%-40s" NOR " - %-10s \n", 
		(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
		(member_array(sname[i], mapped)==-1? "  ": "��"),
		to_chinese(sname[i]) + " (" + sname[i] + ")",
		skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
	);

	write("\n");
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 10;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int help(object me)
{
	write(@HELP
ָ���ʽ : inquire <ĳ��>

���ָ������������������ѧ���ļ��ܡ�


������Ϊؤ�����ר�ã�����ѧϰ����֮����

HELP
    );
    return 1;
}
