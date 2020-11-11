// score.c
//by tiandi 2008.5.15
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
        object ob,marryid;
        mapping my;
        string line, str, skill_type, parry_type,groupname,cityname;
        object weapon,map;
        int attack_points, dodge_points, parry_points,damage_points,mattack_points,mdodge_points, mparry_points,mdamage_points,move_points;

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
		printf(HIY"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"NOR);
        line = sprintf(HIY"┃                                                              ┃"NOR"\n"HIY"┃"NOR" %-60s "HIY"┃\n", ob->short(1) );
	if (!ob->query("group")) 
		groupname = "无";
	else
		groupname = ob->query("group") + "\t社团等级：" + chinese_number(ob->query("grouplv"));
	if (!ob->query("city"))
		cityname = "无";
	else
		cityname = ob->query("city")+ "\t城市等级：" + chinese_number(ob->query("citylv"));
;
	if(ob->query("groupname")||ob->query("cityname")) line += sprintf("\n"HIY"┃"NOR" 社团： %20s        \n 城市： %20s\n\n",groupname,cityname);
            if(ob->query("biqi_top")<50&&ob->query("biqi_top")>0)  line += sprintf(" %s的最新兵器谱排名是%s名 \n"NOR,
                           ob==me?"你":ob->name(1),
                           chinese_number(ob->query("biqi_top")));
        line += sprintf(HIY"┃"NOR" 你是一%2s%6s%6s岁的%s%s，                          "HIY" ┃\n"HIY"┃ "NOR"%-30s生。"HIY"\t\t\t        ┃\n",
                ob->query("unit"),
                ob->query("national"),
                chinese_number(ob->query("age")), 
                ob->query("gender"),
                ob->query("race"),
                CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
        line += sprintf(HIY"┃"NOR" 你总共杀了%8d个人，其中%7d个玩家，被杀了%7d次。"HIY" ┃\n",
                my["MKS"] + my["PKS"], my["PKS"],my["KILLED"]);
        line += sprintf(HIY"┃"NOR" 你到目前为止总共完成了%8d个使命和%10d个特殊使命。"HIY" ┃\n",
                my["TASK"],ob->query("bigtasks")); 
         line += sprintf(HIY"┃"NOR" 你到目前为止叛师记录是%3d次。",ob->query("betrayer")); 
        if( !my["family"] )
				 line = sprintf("%s 你目前没有师傅。\t       "HIY" ┃\n",line);
          else
				 line = sprintf("%s 你的师父是%18s。"HIY" ┃\n",line, my["family"]["master_name"] );
         if (ob->query("marry") != 0) 
               { 
                               line += sprintf(HIY"┃"NOR" 你的伴侣是: "YEL"%-18s(%8s)"HIY"                    ┃"NOR,ob->query("marryname"),ob->query("marry"));
                   }
               else
                         {
                     line += sprintf(HIY"┃"NOR" 你的婚姻状况：未婚                                "HIY"           ┃");
                          }
        line += sprintf(HIY"\n┃"NOR" 自造武器： " HIR "%4d\t" NOR, ob->query("created_weapon") );
        line += sprintf("\t 自造防具： " HIR "%4d                "HIY"┃\n" NOR, ob->query("created_armor") );
		line += sprintf(HIY"┃                                                              ┃\n"NOR);
	    line += sprintf(HIY"┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n"NOR);
		line += sprintf(HIY"┃                                                              ┃"NOR);
        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
                parry_type = "parry";
        }       
        else
        {
                skill_type = "unarmed";
                parry_type = "parry";
        }

//by tiandi adjust

        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, parry_type, SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DODGE);
        damage_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DAMAGE);

        mattack_points = COMBAT_D->skill_power(ob, "magic", SKILL_USAGE_MATTACK);
        mparry_points = COMBAT_D->skill_power(ob, "magic", SKILL_USAGE_MDEFENSE);
        mdodge_points = COMBAT_D->skill_power(ob, "spells", SKILL_USAGE_MDODGE);
        mdamage_points = COMBAT_D->skill_power(ob, "magic", SKILL_USAGE_MDAMAGE);
        move_points = COMBAT_D->skill_power(ob, "move", SKILL_USAGE_MOVE);

       line += sprintf(HIY"\n┃"HIR" 物理命中： %-10d" HIG "\t 物理闪避： %-10d"HIY"          ┃\n" NOR,attack_points,dodge_points);
        line +=sprintf(HIY"┃"HIR" 物理伤害： %-10d" HIG "\t 物理防御： %-10d"HIY"          ┃\n" NOR,damage_points,parry_points);
       line += sprintf(HIY"┃"HIR" 法术命中： %-10d" HIG "\t 法术闪避： %-10d"HIY"          ┃\n" NOR,mattack_points,mdodge_points);
        line +=sprintf(HIY"┃"HIR" 法术伤害： %-10d" HIG "\t 法术防御： %-10d"HIY"          ┃\n" NOR,mdamage_points,mparry_points);
        line +=sprintf(HIY"┃"HIR" 灵巧速度： %-10d \t\t\t\t\t"HIY"┃\n" NOR,move_points);

		line += sprintf(HIY"┃                                                              ┃\n"NOR);
	    line += sprintf(HIY"┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n"NOR);
		line += sprintf(HIY"┃                                                              ┃"NOR);

		                line += sprintf(
                        "\n"HIY"┃"NOR" 才智(int)：%s\t 体质(con)：%-10s"HIY"         ┃  \n"
                        HIY"┃"NOR" 灵性(spi)：%s\t 魅力(per)：%s"HIY"         ┃  \n"
                        HIY"┃"NOR" 勇气(cor)：%s\t 力量(str)：%s"HIY"         ┃  \n"
                        HIY"┃"NOR" 耐力(dur)：%s\t 韧性(fle)：%s"HIY"         ┃  \n"
                        HIY"┃"NOR" 速度(agi)：%s\t 气量(tol)：%s"HIY"         ┃  \n"
                        HIY"┃"NOR" 运气(kar)：%s\t 定力(cps)：%s"HIY"         ┃  \n",
                        display_attr(my["int"], ob->query_int()),
                        display_attr(my["con"], ob->query_con()),
                        display_attr(my["spi"], ob->query_spi()),
                        display_attr(my["per"], ob->query_per()),
                        display_attr(my["cor"], ob->query_cor()),
                        display_attr(my["str"], ob->query_str()),
                        display_attr(my["dur"], ob->query_dur()),
                        display_attr(my["fle"], ob->query_fle()),
                        display_attr(my["agi"], ob->query_agi()),
                        display_attr(my["tol"], ob->query_tol()),
                        display_attr(my["kar"], ob->query_kar()),
                        display_attr(my["cps"], ob->query_cps()));


        line += sprintf(HIY"┃"BLU" 剩余参数点： %-10d     \t\t\t\t\t"HIY"┃  \n"HIY"┃\t\t\t\t\t\t\t\t┃"NOR"\n" , ob->query("gift_points") - 
                                                       ob->query("used_gift_points"));
if (me->query("pkname") !=  0 ){
           line += sprintf(HIY"┃"MAG" 你最后的仇人是%18s(%8s)。\t\t\t"HIY"┃\n┃\t\t\t\t\t\t\t\t┃\n" NOR, ob->query("pkname"),ob->query("pkid"));
}
        write(line);
				printf(HIY"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR);
        return 1;
}

string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( "%-5d"HIY" + %3d" NOR, gift,value-gift );
        else if( value < gift ) return sprintf("%-10d"HIR" - %3d" NOR, gift,gift-value );
        else return sprintf("%-10d ", gift);
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

┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                                                              ┃
┃ 朝廷四品官 风扇(Fengsh)                                      ┃
┃ 你是一位汉族十四岁的男性人类，甲午年十一月十四日卯时二刻生。 ┃
┃ 你总共杀了   98779个人，其中     14个玩家，被杀了      9次。 ┃
┃ 你到目前为止总共完成了       0个使命和         0个特殊使命。 ┃
┃ 你到目前为止叛师记录是  0次。 你的师父是            殷正廉。 ┃
┃ 你的伴侣是: 一二三四五一二三  (aaaaaaaab)                    ┃
┃ 自造物品：    0               自造房间：    0                ┃
┃                                                              ┃
┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨
┃                                                              ┃
┃ 物理命中： 37                 物理闪避： 153                 ┃
┃ 物理伤害： 27                 物理防御： 246                 ┃
┃ 法术命中： 21                 法术闪避： 2421                ┃
┃ 法术伤害： 21                 法术防御： 21                  ┃
┃ 灵巧速度： 171                                               ┃
┃                                                              ┃
┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨
┃                                                              ┃
┃ 才智(int)：7                  体质(con)：7                   ┃  
┃ 灵性(spi)：7                  魅力(per)：7                   ┃  
┃ 勇气(cor)：7          + 1     力量(str)：7                   ┃  
┃ 耐力(dur)：7                  韧性(fle)：7                   ┃  
┃ 速度(agi)：7                  气量(tol)：7                   ┃  
┃ 运气(kar)：7                  定力(cps)：7                   ┃  
┃ 剩余参数点： 125                                             ┃  
┃                                                              ┃
┃ 你最后的仇人是      我是乱杀人的(    pker)。                 ┃
┃                                                              ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛


see also : hp
HELP
    );
    return 1;
}
