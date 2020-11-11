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
                if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
        } else
                return notify_fail("��ֻ���Բ쿴�Լ���״̬��\n");

        my = ob->query_entire_dbase();
		printf(HIY"������������������������������������������������������������������\n"NOR);
        line = sprintf(HIY"��                                                              ��"NOR"\n"HIY"��"NOR" %-60s "HIY"��\n", ob->short(1) );
	if (!ob->query("group")) 
		groupname = "��";
	else
		groupname = ob->query("group") + "\t���ŵȼ���" + chinese_number(ob->query("grouplv"));
	if (!ob->query("city"))
		cityname = "��";
	else
		cityname = ob->query("city")+ "\t���еȼ���" + chinese_number(ob->query("citylv"));
;
	if(ob->query("groupname")||ob->query("cityname")) line += sprintf("\n"HIY"��"NOR" ���ţ� %20s        \n ���У� %20s\n\n",groupname,cityname);
            if(ob->query("biqi_top")<50&&ob->query("biqi_top")>0)  line += sprintf(" %s�����±�����������%s�� \n"NOR,
                           ob==me?"��":ob->name(1),
                           chinese_number(ob->query("biqi_top")));
        line += sprintf(HIY"��"NOR" ����һ%2s%6s%6s���%s%s��                          "HIY" ��\n"HIY"�� "NOR"%-30s����"HIY"\t\t\t        ��\n",
                ob->query("unit"),
                ob->query("national"),
                chinese_number(ob->query("age")), 
                ob->query("gender"),
                ob->query("race"),
                CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
        line += sprintf(HIY"��"NOR" ���ܹ�ɱ��%8d���ˣ�����%7d����ң���ɱ��%7d�Ρ�"HIY" ��\n",
                my["MKS"] + my["PKS"], my["PKS"],my["KILLED"]);
        line += sprintf(HIY"��"NOR" �㵽ĿǰΪֹ�ܹ������%8d��ʹ����%10d������ʹ����"HIY" ��\n",
                my["TASK"],ob->query("bigtasks")); 
         line += sprintf(HIY"��"NOR" �㵽ĿǰΪֹ��ʦ��¼��%3d�Ρ�",ob->query("betrayer")); 
        if( !my["family"] )
				 line = sprintf("%s ��Ŀǰû��ʦ����\t       "HIY" ��\n",line);
          else
				 line = sprintf("%s ���ʦ����%18s��"HIY" ��\n",line, my["family"]["master_name"] );
         if (ob->query("marry") != 0) 
               { 
                               line += sprintf(HIY"��"NOR" ��İ�����: "YEL"%-18s(%8s)"HIY"                    ��"NOR,ob->query("marryname"),ob->query("marry"));
                   }
               else
                         {
                     line += sprintf(HIY"��"NOR" ��Ļ���״����δ��                                "HIY"           ��");
                          }
        line += sprintf(HIY"\n��"NOR" ���������� " HIR "%4d\t" NOR, ob->query("created_weapon") );
        line += sprintf("\t ������ߣ� " HIR "%4d                "HIY"��\n" NOR, ob->query("created_armor") );
		line += sprintf(HIY"��                                                              ��\n"NOR);
	    line += sprintf(HIY"�ĩ���������������������������������������������������������������\n"NOR);
		line += sprintf(HIY"��                                                              ��"NOR);
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

       line += sprintf(HIY"\n��"HIR" �������У� %-10d" HIG "\t �������ܣ� %-10d"HIY"          ��\n" NOR,attack_points,dodge_points);
        line +=sprintf(HIY"��"HIR" �����˺��� %-10d" HIG "\t ��������� %-10d"HIY"          ��\n" NOR,damage_points,parry_points);
       line += sprintf(HIY"��"HIR" �������У� %-10d" HIG "\t �������ܣ� %-10d"HIY"          ��\n" NOR,mattack_points,mdodge_points);
        line +=sprintf(HIY"��"HIR" �����˺��� %-10d" HIG "\t ���������� %-10d"HIY"          ��\n" NOR,mdamage_points,mparry_points);
        line +=sprintf(HIY"��"HIR" �����ٶȣ� %-10d \t\t\t\t\t"HIY"��\n" NOR,move_points);

		line += sprintf(HIY"��                                                              ��\n"NOR);
	    line += sprintf(HIY"�ĩ���������������������������������������������������������������\n"NOR);
		line += sprintf(HIY"��                                                              ��"NOR);

		                line += sprintf(
                        "\n"HIY"��"NOR" ����(int)��%s\t ����(con)��%-10s"HIY"         ��  \n"
                        HIY"��"NOR" ����(spi)��%s\t ����(per)��%s"HIY"         ��  \n"
                        HIY"��"NOR" ����(cor)��%s\t ����(str)��%s"HIY"         ��  \n"
                        HIY"��"NOR" ����(dur)��%s\t ����(fle)��%s"HIY"         ��  \n"
                        HIY"��"NOR" �ٶ�(agi)��%s\t ����(tol)��%s"HIY"         ��  \n"
                        HIY"��"NOR" ����(kar)��%s\t ����(cps)��%s"HIY"         ��  \n",
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


        line += sprintf(HIY"��"BLU" ʣ������㣺 %-10d     \t\t\t\t\t"HIY"��  \n"HIY"��\t\t\t\t\t\t\t\t��"NOR"\n" , ob->query("gift_points") - 
                                                       ob->query("used_gift_points"));
if (me->query("pkname") !=  0 ){
           line += sprintf(HIY"��"MAG" �����ĳ�����%18s(%8s)��\t\t\t"HIY"��\n��\t\t\t\t\t\t\t\t��\n" NOR, ob->query("pkname"),ob->query("pkid"));
}
        write(line);
				printf(HIY"������������������������������������������������������������������\n"NOR);
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
ָ���ʽ : score
           

���ָ�������ʾ��Ļ������ϣ�

������������������������������������������������������������������
��                                                              ��
�� ��͢��Ʒ�� ����(Fengsh)                                      ��
�� ����һλ����ʮ������������࣬������ʮһ��ʮ����îʱ�������� ��
�� ���ܹ�ɱ��   98779���ˣ�����     14����ң���ɱ��      9�Ρ� ��
�� �㵽ĿǰΪֹ�ܹ������       0��ʹ����         0������ʹ���� ��
�� �㵽ĿǰΪֹ��ʦ��¼��  0�Ρ� ���ʦ����            �������� ��
�� ��İ�����: һ��������һ����  (aaaaaaaab)                    ��
�� ������Ʒ��    0               ���췿�䣺    0                ��
��                                                              ��
�ĩ���������������������������������������������������������������
��                                                              ��
�� �������У� 37                 �������ܣ� 153                 ��
�� �����˺��� 27                 ��������� 246                 ��
�� �������У� 21                 �������ܣ� 2421                ��
�� �����˺��� 21                 ���������� 21                  ��
�� �����ٶȣ� 171                                               ��
��                                                              ��
�ĩ���������������������������������������������������������������
��                                                              ��
�� ����(int)��7                  ����(con)��7                   ��  
�� ����(spi)��7                  ����(per)��7                   ��  
�� ����(cor)��7          + 1     ����(str)��7                   ��  
�� ����(dur)��7                  ����(fle)��7                   ��  
�� �ٶ�(agi)��7                  ����(tol)��7                   ��  
�� ����(kar)��7                  ����(cps)��7                   ��  
�� ʣ������㣺 125                                             ��  
��                                                              ��
�� �����ĳ�����      ������ɱ�˵�(    pker)��                 ��
��                                                              ��
������������������������������������������������������������������


see also : hp
HELP
    );
    return 1;
}
