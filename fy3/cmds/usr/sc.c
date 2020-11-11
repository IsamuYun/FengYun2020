// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
        object *user;
        int i;	mapping my;
	string line, str, skill_type, parry_type;
	object weapon;
	int attack_points, dodge_points, parry_points;

	seteuid(getuid(me));

	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("��ֻ���Բ쿴�Լ���״̬��\n");

	my = ob->query_entire_dbase();

//	line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1) );
        line = sprintf( "\n %s\n\n", ob->short(1) );
	line += sprintf(" ����һ%s%s%s���%s%s��%s����\n",
		ob->query("unit"),
		ob->query("national"),
		chinese_number(ob->query("age")), 
		ob->query("gender"),
		ob->query("race"),
		CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
        line += sprintf(" ���ܹ�ɱ��%s���ˣ�%s����ң���ɱ��%s�Ρ�\n",
                chinese_number(my["MKS"] + my["PKS"]), chinese_number(my["PKS"]),chinese_number(my["KILLED"]));

line += sprintf(" ���ܹ������%s���������%s����������%s����������\n",
                chinese_number(my["bbquest"]), chinese_number(my["QUEST"]),chinese_number(ob->query("tiejob")));

line += sprintf(" ���ܹ������%s�κ���������%s����������\n",
                chinese_number(my["killhyr"]), chinese_number(my["hubiaojob"]));

line += sprintf(" ���ܹ������%s����������%s�������ϸ����\n",
                chinese_number(my["mengzhujob"]), chinese_number(my["kf_worked"]));

line += sprintf(" ���ܹ������%s���Ͳ�����%s��ͨ������\n",
                chinese_number(my["tea"]), chinese_number(my["ftongji"]));

line += sprintf(" ���ܹ������%s�λ���С����������%s���ּұ���������\n",
                chinese_number(my["get_lin_end"]), chinese_number(my["succ_letter_num"]));

line += sprintf(" �㵽ĿǰΪֹ�ܹ������%s��ʹ��������%s������ʹ����\n",
                chinese_number(my["TASK"]),  chinese_number(ob->query("bigtasks"))); 

line += sprintf(" �㵽ĿǰΪֹ�ܹ������%s��ת��������\n",
                chinese_number(ob->query("reborned"))); 

line += sprintf(" ��ϸ��������� [help job.txt] \n\n");

line += sprintf(HIW" �� %d\n\n" NOR, ob->query("deposit"));
line += sprintf(HIW" Ǳ�ܣ� %d\n\n" NOR, ob->query("pot_deposit"));

 line += sprintf(HIW" ���ɹ��ף� %d\n\n" NOR, ob->query("gongxian"));
 
	write(line);
	return 1;
}

string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%3d /%3d" NOR, value,gift );
	else if( value < gift ) return sprintf( HIR "%3d /%3d" NOR, value,gift );
	else return sprintf("%3d /%3d", value,gift);
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 100;

	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : score
           

���ָ�������ʾ��Ļ������ϣ�

 ��ͨ���� С��(Xiaofei)

 ����һλ�ɹ���ʮ����������࣬�����������ʮһ����ʱ��������
 ���ܹ�ɱ������ˣ������ң���ɱ����Ρ�
 �㵽ĿǰΪֹ�ܹ���������ʹ����

 ���ǣ� 10 / 10         ���ʣ� 10 / 10
 ���ԣ� 10 / 10         ������ 10 / 10
 ������ 10 / 10         ������ 20 / 20
 ������  5 /  5         ���ԣ� 20 / 20
 �ٶȣ�  5 /  5         ������ 10 / 10
 ������ 10 / 10         ������ 10 / 10

 ������Ʒ�� 0           ���췿�䣺 0

 �������� 3             �������� 3
 ɱ������ 0             �������� 1

 �� �� �㣺 5


see also : hp
HELP
    );
    return 1;
}