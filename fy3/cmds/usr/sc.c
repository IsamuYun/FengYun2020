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
		if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else
		return notify_fail("你只可以察看自己的状态。\n");

	my = ob->query_entire_dbase();

//	line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1) );
        line = sprintf( "\n %s\n\n", ob->short(1) );
	line += sprintf(" 你是一%s%s%s岁的%s%s，%s生。\n",
		ob->query("unit"),
		ob->query("national"),
		chinese_number(ob->query("age")), 
		ob->query("gender"),
		ob->query("race"),
		CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
        line += sprintf(" 你总共杀了%s个人，%s个玩家，被杀了%s次。\n",
                chinese_number(my["MKS"] + my["PKS"]), chinese_number(my["PKS"]),chinese_number(my["KILLED"]));

line += sprintf(" 你总共完成了%s次天机任务，%s次天宗任务，%s次忠义任务。\n",
                chinese_number(my["bbquest"]), chinese_number(my["QUEST"]),chinese_number(ob->query("tiejob")));

line += sprintf(" 你总共完成了%s次黑衣人任务，%s次运镖任务。\n",
                chinese_number(my["killhyr"]), chinese_number(my["hubiaojob"]));

line += sprintf(" 你总共完成了%s次盟主任务，%s次消灭奸细任务。\n",
                chinese_number(my["mengzhujob"]), chinese_number(my["kf_worked"]));

line += sprintf(" 你总共完成了%s次送茶任务，%s次通缉任务。\n",
                chinese_number(my["tea"]), chinese_number(my["ftongji"]));

line += sprintf(" 你总共完成了%s次护送小公主的任务，%s次林家堡送信任务。\n",
                chinese_number(my["get_lin_end"]), chinese_number(my["succ_letter_num"]));

line += sprintf(" 你到目前为止总共完成了%s个使命。其中%s个特殊使命。\n",
                chinese_number(my["TASK"]),  chinese_number(ob->query("bigtasks"))); 

line += sprintf(" 你到目前为止总共完成了%s次转世重生。\n",
                chinese_number(ob->query("reborned"))); 

line += sprintf(" 详细任务请参阅 [help job.txt] \n\n");

line += sprintf(HIW" 存款： %d\n\n" NOR, ob->query("deposit"));
line += sprintf(HIW" 潜能： %d\n\n" NOR, ob->query("pot_deposit"));

 line += sprintf(HIW" 门派贡献： %d\n\n" NOR, ob->query("gongxian"));
 
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
指令格式 : score
           

这个指令可以显示你的基本资料：

 普通百姓 小飞(Xiaofei)

 你是一位蒙古族十岁的男性人类，甲申年八月三十一日午时三刻生。
 你总共杀了零个人，零个玩家，被杀了零次。
 你到目前为止总共完成了零个使命。

 才智： 10 / 10         体质： 10 / 10
 灵性： 10 / 10         魅力： 10 / 10
 勇气： 10 / 10         力量： 20 / 20
 耐力：  5 /  5         韧性： 20 / 20
 速度：  5 /  5         气量： 10 / 10
 运气： 10 / 10         定力： 10 / 10

 自造物品： 0           自造房间： 0

 攻击力： 3             防御力： 3
 杀伤力： 0             保护力： 1

 参 数 点： 5


see also : hp
HELP
    );
    return 1;
}
