// dodge.c

inherit SKILL;

string *dodge_msg = ({
	"���Ǻ�$p$lƫ�˼��硣\n",
	"���Ǳ�$p����ض㿪�ˡ�\n",
	"����$n����һ�࣬���˿�ȥ��\n",
	"���Ǳ�$p��ʱ�ܿ���\n",
	"����$n����׼�������Ų�æ�Ķ㿪��\n",
});

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int effective_level() { return 5;}
int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 100;
}
string belong()
{
	return "common";
}