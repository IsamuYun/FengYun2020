// who3.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
    object ob, *ob_list;
    int i;
    seteuid(getuid());

    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    str = HIG" 玩家      才智 体质 灵性 魅力 勇气 力量 耐力 韧性 速度 气量 运气 定力\n"NOR;
    str += "—--------—————————————————————————————————----\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        str += sprintf(NOR"%-10s  ",ob->name());
        str += sprintf(HIR"%-2d   ",ob->query_int());
        str += sprintf(GRN"%-2d   ",ob->query_con());
        str += sprintf(HIM"%-2d   ",ob->query_spi());
        str += sprintf(YEL"%-2d   ",ob->query_per());
        str += sprintf(HIG"%-2d   ",ob->query_cor());
        str += sprintf(BLU"%-2d   ",ob->query_str());
        str += sprintf(HIW"%-2d   ",ob->query_dur());
        str += sprintf(CYN"%-2d   ",ob->query_fle());
        str += sprintf(HIB"%-2d   ",ob->query_agi());
        str += sprintf(MAG"%-2d   ",ob->query_tol());
        str += sprintf(HIC"%-2d   ",ob->query_kar());
        str += sprintf(NOR"%-2d \n",ob->query_cps());
    }
    str += "—————------------—————————————————————————————\n";
//    str = sprintf("%s共有 %d 位使用者连线中。\n", str, sizeof(ob_list));
    me->start_more(str);
    return 1;
}
int sort_user(object ob1, object ob2)
{
        if( wizardp(ob1) && !wizardp(ob2) ) return -1;
        if( wizardp(ob2) && !wizardp(ob1) ) return 1;
        if( wizardp(ob1) && wizardp(ob2) )
                return (int)SECURITY_D->get_wiz_level(ob2)
                        - (int)SECURITY_D->get_wiz_level(ob1);

        return (int)ob2->query("mud_age") - (int)ob1->query("mud_age");
}
int help(object me)
{
        write(@HELP
指令格式：who3

玩家信息查询。
HELP
        );
        return 1;
}            

