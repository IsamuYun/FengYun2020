//by tiandi 2008.5.9
//edit by xgchen@fy 2002-2-9

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#define LOWER_LIMIT 200000
inherit F_DBASE;

string *guard_msg = ({
    CYN "$Nע����$n���ж�����ͼѰ�һ���һ���ɹ���\n" NOR,
        CYN "$N������$n��һ��һ������ʱ׼���������ơ�\n" NOR,
        CYN "$N����Ϊ������Ҫ�ҳ�$n��������\n" NOR,
        CYN "$N�������ƶ��ŽŲ����ȴ�����ѵĳ��з�λ��\n" NOR,
        CYN "$N�۾�գҲ��գ�ض���$n���Ż����֡�\n" NOR,
});

string *catch_hunt_msg = ({
        HIW "$N��$n������������ۺ죬���̴���������\n" NOR,
        HIW "$N����$n��ȣ����ɶ������㣡��\n" NOR,
        HIW "$N��$nһ���棬������˵�ʹ���������\n" NOR,
        HIW "$Nһ��Ƴ��$n�����һ�����˹�����\n" NOR,
        HIW "$Nһ����$n�����һ㶣���У����������㣡��\n" NOR,
        HIW "$N�ȵ�����$n�����ǵ��ʻ�û���꣬���У���\n" NOR,
        HIW "$N�ȵ�����$n�����У���\n" NOR,});

string *winner_msg = ({
        CYN "\n$N������Ц��˵���������ˣ�\n\n" NOR,
        CYN "\n$N˫��һ����Ц��˵�������ã�\n\n" NOR,
        CYN "\n$Nʤ�����У�����Ծ�����ߣ�Ц�������ã�\n\n" NOR,
        CYN "\n$n��ɫ΢�䣬˵��������������\n\n" NOR,
        CYN "\n$n�������˼�����˵�����ⳡ�����������ˣ�����������\n\n" NOR,
        CYN "\n$n����һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR,
});

void create()
{
        seteuid(getuid());
        set("name", "ս������");
        set("id", "combatd");
}

string damage_msg(int damage, string type)
{
        string str;

        if (this_player()->query("env/report")) return "������ " + damage + " ��" + type + "��\n";

        if( damage == 0 ) return "���û������κ��˺���\n";

        switch( type ) {
		case "����":
				if( damage < 50 ) return "��ֻ�������������$p��Ƥ�⡣\n";
				else if( damage < 200 ) return "����$p���˿ڴ�ɢ����ŨŨ����ζ��\n";
				else if( damage < 500 ) return "���$p�յô�����������������ƺ����أ�\n";
				else return "����$p������������ص����ˣ�$p����һ��Ƥ���Ѿ��ս�����\n";
                break;
        case "����":
        case "����":
                if( damage < 50 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
                else if( damage < 100 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
                else if( damage < 200 ) return "������͡���һ������һ���˿ڣ�\n";
                else if( damage < 400 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
                else if( damage < 800 ) return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
                else return "���ֻ����$nһ���Һ���$w����$p$l����һ������ǵĿ����˿ڣ���\n";
                break;
        case "����":
    //            if( damage < 240 ) return HIM"$n����������$N��ҡɽ���ֵľ���ȫ����$N������ȥ��\n"+HIR+"$N���ۡ���һ���³�һ����Ѫ��\n"NOR;
     //           else return HIM"$n����������$N��ҡɽ�����ľ���ȫ����$N������ȥ��\n"+HIR+"$N���׽΢������ľ����𵽽�����λ��������\n"NOR;
      //          break;  //�޸Ĺ淶һ�� xgchen 2002-2-9
                if( damage < 100 ) return HIM"$n����������$N��ҡɽ�����ľ���ȫ����$N������ȥ��\n"+HIR+"$N�е��������ܣ��������˿˿Ѫ����\n"NOR;
                else if( damage < 200 ) return HIM"$n����������$N��ҡɽ�����ľ���ȫ����$N������ȥ��\n"+HIR+"$N����һ���ػ���\n"NOR;
                else if( damage < 400 ) return HIM"$n����������$N��ҡɽ�����ľ���ȫ����$N������ȥ��\n"+HIR+"$N�Ļ��ڴ�ʹ�������Ӳ�������\n"NOR;
                else if( damage < 800 ) return HIM"$n����������$N��ҡɽ�����ľ���ȫ����$N������ȥ��\n"+HIR+"$N���ۡ���һ���³�һ�����Ѫ��\n"NOR;
                else if( damage < 1600 ) HIM"$n����������$N��ҡɽ�����ľ���ȫ����$N������ȥ��\n"+HIR+"$N���׽΢������ľ����𵽽�����λ��\n"NOR;
                else return HIM"$n�����ϵ��׽�����ھ�����$N�ǿ������ص�������$N������ȥ��\n"+HIR+"$N�·��Ѿ����Թ�ȥ�ˡ�\n"NOR;
                break;
        case "�ػ���":
      //      �޸��ƻ���ľ�Ļػ���  xgchen 2002-2-9
                if( damage < 100 ) return HIY"$Nһ�л���$n���ϣ�ȴ��$n�����ƻ���ľ�������������ػ���$N�����ϡ�\n"+HIR+"$N�е��������ܣ��������˿˿Ѫ����\n"NOR;
                else if( damage < 200 ) return HIY"$Nһ�л���$n���ϣ�ȴ��$n�����ƻ���ľ�������������ػ���$N�����ϡ�\n"+HIR+"$N����һ���ػ���\n"NOR;
                else if( damage < 400 ) return HIY"$Nһ�л���$n���ϣ�ȴ��$n�����ƻ���ľ�������������ػ���$N�����ϡ�\n"+HIR+"$N�Ļ��ڴ�ʹ�������Ӳ�������\n"NOR;
                else if( damage < 800 ) return HIY"$Nһ�л���$n���ϣ�ȴ��$n�����ƻ���ľ�������������ػ���$N�����ϡ�\n"+HIR+"$N���ۡ���һ���³�һ�����Ѫ��\n"NOR;
                else if( damage < 1600) return HIY"$Nһ�л���$n���ϣ�ȴ��$n�����ƻ���ľ�������������ػ���$N�����ϡ�\n"+HIR+"$N���׽΢������ľ����𵽽�����λ��\n"NOR;
                else return HIY"$n���ƻ���ľ�񹦣���$N�ǿ������ص�������$N������ȥ��\n"+HIR+"$N�·��Ѿ����Թ�ȥ�ˡ�\n"NOR;
                break;
                      case "����":
                if( damage < 50 ) return "���ֻ������ش���$p��Ƥ�⡣\n";
                else if( damage < 100 ) return "�����$p$l�̳�һ�����ڡ�\n";
                else if( damage < 200 ) return "������ۡ���һ��������$n$l������\n";
                else if( damage < 400 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
                else if( damage < 800 ) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ��ģ����Ѫ������\n";
                else return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ���\n";
                break;
        case "����":
                if( damage < 50 ) return  "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
                else if( damage < 100 ) return "�����$p��$l���һ�����ࡣ\n";
                else if( damage < 200 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
                else if( damage < 400 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
                else if( damage < 600 ) return "������项��һ����$n����������\n";
                else if( damage < 800 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��	��\n";
                else if( damage < 1200 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
                else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
                break;
        case "ץ��":
                if( damage < 50 ) return "���ֻ�������ץ������ץ����΢���˵㡣\n";
                else if( damage < 100 ) return "�����$p��$lץ������Ѫ�ۡ�\n";
                else if( damage < 200 ) return "���һץ���У�$n��$l��ץ����Ѫ�ɽ���\n";
                else if( damage < 400 ) return "������͡���һ����$l��ץ����ɼ��ǣ���\n";
                else if( damage < 600 ) return "���һץ���У�$n��$l��ץ��Ѫ���ɣ�����\n";
                else if( damage < 800 ) return "�����һ�¡��͡���һ��ץ��$n���κü��£���һ��ˤ����\n";
                else if( damage < 1200 ) return "���$n����һ����$l��ץ�ý�Ϲ��ۣ���\n";
                else return "���ֻ����$nһ���Һ���$l��ץ�����Ѫ��������Ѫ�������أ���\n";
                break;
        case "������":
                if( damage < 25 ) return "$N�ܵ�$n$z�ķ����ƺ�һ����\n";
                else if( damage < 50 ) return  "$N��$n��$z�����Ѫ���ڣ���ʧɫ��\n";
                else if( damage < 100 ) return "$N��$n��$z���վ�����ȣ�ҡҡ�λΡ�\n";
                else if( damage < 200 ) return "$N��$n��$z���𣬡��١���һ������������\n";
                else if( damage < 400 ) return "$N��$n��$z����������������ð������顣\n";
                else if( damage < 600 ) return "$N��$n��$z������һ���ؿ������ܵ�һ���ػ�����������������\n";
                else if( damage < 800 ) return "$N��$n��$zһ����ǰһ�ڣ���������ɳ���������\n";
                else return "$N��$n��$zһ����ǰһ�ڣ�������Ѫ������������ߵķ��������ȥ����\n";
                break;
        default:
                if( !type ) type = "�˺�";
                if( damage < 50 ) str =  "���ֻ����ǿ���һ����΢";
                else if( damage < 100 ) str = "��������΢��";
                else if( damage < 200 ) str = "������һ��";
                else if( damage < 250 ) str = "������һ������";
                else if( damage < 400 ) str = "��������Ϊ���ص�";
                else if( damage < 600 ) str = "�������൱���ص�";
                else if( damage < 850 ) str = "������ʮ�����ص�";
                else if( damage < 1150 ) str = "�����ɼ������ص�";
                else str =  "�����ɷǳ����µ�����";
                return str + type + "��\n";
        }
}

string eff_status_msg(int ratio)
{
        if( ratio==100 ) return HIG "���������������۷�״̬��" NOR;
        if( ratio > 95 ) return HIG "�ƺ�ֻ���˵����ˣ������˴��塣" NOR;
        if( ratio > 90 ) return HIY "�������������˼���Ƥ���ˡ�" NOR;
        if( ratio > 80 ) return HIY "���˼������ˣ������ƺ��������¡�" NOR;
        if( ratio > 60 ) return HIY "���˲��ᣬ��������Ѫ��" NOR;
        if( ratio > 40 ) return HIR "��Ϣ���أ�����ɢ�ң��Ѿ���������·�ˡ�" NOR;
        if( ratio > 30 ) return HIR "�Ѿ�����ɢ�ң���������֧����������ȥ��" NOR;
        if( ratio > 20 ) return HIR "�������ˣ�ֻʣ�����һ�����ˡ�" NOR;
        if( ratio > 10 ) return RED "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�" NOR;
        if( ratio > 5  ) return RED "ͫ�շŴ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
        return RED "������Ѫ���Ѿ�������в�����ʱ�����ܶ�����" NOR;
}

string status_msg(int ratio)
{
        if( ratio==100 ) return HIG "���������������������۷�״̬��" NOR;
        if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
        if( ratio > 90 ) return HIY "������������Щ���á�" NOR;
        if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
        if( ratio > 60 ) return HIY "�������꣬��ɫ�Ұס�" NOR;
        if( ratio > 40 ) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
        if( ratio > 30 ) return HIR "�Ѿ�һ��ͷ�ؽ����ģ������������֧����������ȥ��" NOR;
        if( ratio > 20 ) return HIR "�������Ѿ����������ˡ�" NOR;
        if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
        return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}

int  bounce = 0;
int absorb_vic;

void netscape_report_status(object player)
{
        string status;
        string fstatus="";
        object weapon,ob;
        string skill_type,parry_type;
        int tmp,attack_points,parry_points,dodge_points;
        mapping my;
        ob = player;
        my = player->query_entire_dbase();
        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
                parry_type = "parry";
        }
        else
        {
                skill_type = "unarmed";
                parry_type = "unarmed";
        }

        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, parry_type, SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
status = "";
if((int) my["gin"] != (int)ob->query_temp("ns/gin")){
        status +=sprintf("0:%d;",my["gin"]);
        ob->set_temp("ns/gin",my["gin"]);       }
if((int) my["eff_gin"] != (int)ob->query_temp("ns/eff_gin")){
        status +=sprintf("1:%d;",my["eff_gin"]);
        ob->set_temp("ns/eff_gin",my["eff_gin"]);       }
if((int) my["max_gin"] != (int)ob->query_temp("ns/max_gin")){
        status +=sprintf("2:%d;",my["max_gin"]);
        ob->set_temp("ns/max_gin",my["max_gin"]);       }
if((int) my["kee"] != (int)ob->query_temp("ns/kee")){
        status +=sprintf("3:%d;",my["kee"]);
        ob->set_temp("ns/kee",my["kee"]);       }
if((int) my["eff_kee"] != (int)ob->query_temp("ns/eff_kee")){
        status +=sprintf("4:%d;",my["eff_kee"]);
        ob->set_temp("ns/eff_kee",my["eff_kee"]);       }
if((int) my["max_kee"] != (int)ob->query_temp("ns/max_kee")){
        status +=sprintf("5:%d;",my["max_kee"]);
        ob->set_temp("ns/max_kee",my["max_kee"]);       }
if((int) my["sen"] != (int)ob->query_temp("ns/sen")){
        status +=sprintf("6:%d;",my["sen"]);
        ob->set_temp("ns/sen",my["sen"]);       }
if((int) my["eff_sen"] != (int)ob->query_temp("ns/eff_sen")){
        status +=sprintf("7:%d;",my["eff_sen"]);
        ob->set_temp("ns/eff_sen",my["eff_sen"]);       }
if((int) my["max_sen"] != (int)ob->query_temp("ns/max_sen")){
        status +=sprintf("8:%d;",my["max_sen"]);
        ob->set_temp("ns/max_sen",my["max_sen"]);       }
        if( status != "") fstatus = status +"\n";
        status = "";
if((int) my["atman"] != (int)ob->query_temp("ns/atman")){
        status +=sprintf("13:%d;",my["atman"]);
        ob->set_temp("ns/atman",my["atman"]);       }
if((int) my["max_atman"] != (int)ob->query_temp("ns/max_atman")){
        status +=sprintf("14:%d;",my["max_atman"]);
        ob->set_temp("ns/max_atman",my["max_atman"]);       }
if((int) my["force"] != (int)ob->query_temp("ns/force")){
        status +=sprintf("15:%d;",my["force"]);
        ob->set_temp("ns/force",my["force"]);       }
if((int) my["max_force"] != (int)ob->query_temp("ns/max_force")){
        status +=sprintf("16:%d;",my["max_force"]);
        ob->set_temp("ns/max_force",my["max_force"]);       }
if((int) my["mana"] != (int)ob->query_temp("ns/mana")){
        status +=sprintf("17:%d;",my["mana"]);
        ob->set_temp("ns/mana",my["mana"]);       }
if((int) my["max_mana"] != (int)ob->query_temp("ns/max_mana")){
        status +=sprintf("18:%d;",my["max_mana"]);
        ob->set_temp("ns/max_mana",my["max_mana"]);       }
        if( status != "" ) fstatus += status + "\n";
        status = "";
tmp = my["food"]* 100/player->max_food_capacity();
if((int) tmp != (int)ob->query_temp("ns/food")){
        status +=sprintf("19:%d;",tmp);
        ob->set_temp("ns/food",tmp);       }
tmp =my["water"] * 100/player->max_water_capacity();
if((int) tmp != (int)ob->query_temp("ns/water")){
        status +=sprintf("20:%d;",tmp);
        ob->set_temp("ns/water",tmp);       }
tmp = attack_points + 1;
if((int) tmp != (int)ob->query_temp("ns/offense")){
        status +=sprintf("9:%d;",tmp);
        ob->set_temp("ns/offense",tmp);       }
tmp = ob->query_temp("apply/damage");
if((int) tmp != (int)ob->query_temp("ns/damage")){
        status +=sprintf("10:%d;",tmp);
        ob->set_temp("ns/damage",tmp);       }
tmp = (dodge_points/2 + (weapon? parry_points: (parry_points/2)));
if((int) tmp != (int)ob->query_temp("ns/defense")){
        status +=sprintf("11:%d;",tmp);
        ob->set_temp("ns/defense",tmp);       }
tmp = ob->query_temp("apply/armor");
if((int) tmp != (int)ob->query_temp("ns/armor")){
        status +=sprintf("12:%d;",tmp);
        ob->set_temp("ns/armor",tmp);       }
if((int) my["combat_exp"] != (int)ob->query_temp("ns/combat_exp")){
        status +=sprintf("21:%d;",my["combat_exp"]);
        ob->set_temp("ns/combat_exp",my["combat_exp"]);       }
if((int) my["bellicosity"] != (int)ob->query_temp("ns/bellicosity")){
        status +=sprintf("22:%d;",my["bellicosity"]);
        ob->set_temp("ns/bellicosity",my["bellicosity"]);       }
        if( status != "") 
                fstatus += status + "\n";
if(fstatus)
tell_object(player,fstatus);
}

varargs void report_status(object ob, int effective)
{
        if(ob->query_temp("using_netscape"))
                        netscape_report_status(ob);
        if( effective ) 
                message_vision( "( $N" + eff_status_msg(
                        (int)ob->query("eff_kee") * 100 / 
(int)ob->query("max_kee") ) 
                        + " )\n", ob);
        else
                message_vision( "( $N" + status_msg(
                        (int)ob->query("kee") * 100 / 
(int)ob->query("max_kee") ) 
                        + " )\n", ob);
}
// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
        int status, level, power;
        int enc, max;
        if( !living(ob) ) return 0;
        if(ob->query_temp("is_unconcious")) return 0;
        max = (int) ob->query_max_encumbrance();
        enc = (max  + max/10 - 1 - (int) ob->query_encumbrance() ) * 10 / max;
// npcs does not have this restrication
        if(!userp(ob)) enc = 10;
        level = ob->query_skill(skill);
//by tiandi ����һЩ�����������˼��㷽ʽ
        switch(usage) {
                case SKILL_USAGE_ATTACK:
						level = level*3;
                        level += ob->query_temp("apply/attack");      	
						level += ob->query_str()*2;
						level += ob->query_cor();
						if(ob->query("is_pet")&& ob->query("title")=="Ұţ")  level=level*ob->query("chengzhang")/10;
						break;
                case SKILL_USAGE_DEFENSE:
                        level += ob->query_temp("apply/defense");
                        level += ob->query_temp("apply/armor");
						level += ob->query_fle()*2;
						level += ob->query_dur();
						if(ob->query("is_pet")&& ob->query("title")=="�ڹ�")  level=level*5;
                        break;
                case SKILL_USAGE_DODGE:
             			level = level*3;
                        level += ob->query_temp("apply/dodge");
						level += ob->query_agi()*2;
						level += ob->query_fle();
						if(ob->query("is_pet")&& ob->query("title")=="����")  level=level*ob->query("chengzhang")/10;
                        break;
                case SKILL_USAGE_MOVE:
             			level = level*3;
                        level += ob->query_temp("apply/move");
						level += ob->query_agi()*2;
						level += ob->query_cps();
						if(ob->query("is_pet")&& ob->query("title")=="����")  level=level*ob->query("chengzhang")/10;
                        break;
                case SKILL_USAGE_DAMAGE:
						level = level/2;
             			level = level*3;
                        level += ob->query_temp("apply/damage");
						level += ob->query_str()*2;
						level += ob->query_kar();
						if(ob->query("is_pet")&& ob->query("title")=="Ұţ")  level=level*ob->query("chengzhang")/10;
                        break;
				case SKILL_USAGE_MATTACK:
						level = level*3;
                        level += ob->query_temp("apply/mattack");
						level += ob->query_spi()*2;
						level += ob->query_per();
						if(ob->query("is_pet")&& ob->query("title")=="è��") level=level*ob->query("chengzhang")/10;
                        break;
                case SKILL_USAGE_MDEFENSE:
                        level += ob->query_temp("apply/mdefense");
                        level += ob->query_temp("apply/marmor");
						level += ob->query_spi();
						level += ob->query_con();
						if(ob->query("is_pet")&& ob->query("title")=="è��")  level=level*ob->query("chengzhang")/10;
                        break;
                case SKILL_USAGE_MDODGE:
             			level = level*3;
                        level += ob->query_temp("apply/mdodge");
						level += ob->query_kar();
						if(ob->query("is_pet")&& ob->query("title")=="è��")  level=level*ob->query("chengzhang")/10;
                        break;
                case SKILL_USAGE_MDAMAGE:
						level = level/2;
             			level = level*3;
                        level += ob->query_temp("apply/mdamage");
						level += ob->query_spi()*2;
						level += ob->query_int();
						if(ob->query("is_pet")&& ob->query("title")=="è��") level=level*ob->query("chengzhang")/10;
                        break;

        }
	return level;
}
void fight_reward(object winner, object loser)
{
        object owner;

        if(owner=winner->query("possessed"))  winner = owner;
        winner->win_enemy(loser);
}
void fight_penalty(object winner, object loser)
{
        object owner;

        if(owner=loser->query("possessed"))  loser = owner;
        loser->lose_enemy(winner);
}
// do_protect()
// a function that checks to see if there is anything/anyone protects our victim

int do_protect(object me, object weapon,int ap, object victim)
{
        object *pros;
        string output;
        int pp;
        string parry_skill;
        int i;
        pros = victim->query_temp("protectors");
        i = random(sizeof(pros));
        if(!pros[i]) { 
        pros -= ({ pros[i] });
        if(!sizeof(pros)) victim->delete_temp("protectors");
        return 0;     }
        
        if(environment(pros[i]) != environment(victim)) return 0;
        if(pros[i]->is_character())
        {
                //      Check if the pros[i] can parry this attack for the victim.
                if( pros[i]->query_temp("weapon") ) {
                        pp = skill_power(pros[i], "parry", 
SKILL_USAGE_DEFENSE);
                        if( !weapon ) pp *= 2;
                } else {
                        if( weapon ) pp = skill_power(pros[i], "unarmed",SKILL_USAGE_DEFENSE)/2;
                        else pp = skill_power(pros[i], "unarmed", 
SKILL_USAGE_DEFENSE);
                }
                if( pros[i]->is_busy() ) pp /= 3;
                if( pros[i]->query("statusnow") == "�κ���")  pp /= 5;
                if( pp < 1 ) pp = 1;
                if( random(ap + pp)< pp ) {
                if(pros[i]->query_temp("weapon")){
                parry_skill = pros[i]->query_skill_mapped("parry");
                if( !parry_skill)  parry_skill = "parry";
                }
                else
                {
                parry_skill = pros[i]->query_skill_mapped("unarmed");
                if(!parry_skill) parry_skill = "unarmed";
                }
                output = SKILL_D(parry_skill)->query_parry_msg(weapon);
                if( pros[i]->query_temp("weapon"))
                output = replace_string( output, "$v", (pros[i]->query_temp("weapon"))->name());
                output = replace_string( output, "$n", pros[i]->name()); 
                output = replace_string( output, "$p", pros[i]->name()); 
                victim->set_temp("protectors_msg", output);
                return 1;
                }
                else
                        return 0;
        }
        else {
        victim->set_temp("protectors_msg",pros[i]->protection_msg());
        return pros[i]->protection();
        }

}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int 
attack_type, string attack_msg, string damtype)
{
        mapping my, your, action;
        string limb, *limbs, result;
        string attack_skill, force_skill, martial_skill, dodge_skill, 
parry_skill, absorb_skill;
        mixed foo;
        object armor,env,cloth,head,boots,finger,shield,wrists,waist,neck,pet;
      int ap, dp, pp;
        int damage, damage_bonus,tempdamage,mattack_points,mdodge_points,mdamage_points,mparry_points;
//        int wounded = 0;
//        int absorb_vic;
//      int  bounce = 0;
        // (0.5) First see if we are capable of attack
        if(me->query_temp("is_unconcious")) return 1;
//by tiandi ����PK��������ҵ�PK����
        if(me->query("env/no_pk")&&userp(victim))
	{
		write("��������PK����������unset no_pk������Ĵ˿��ء�\n");
	 return 1;
	}
        if(victim->query("env/no_pk")&&(userp(me)))
	{
		write("���Ķ���������PK������\n");
	 return 1;
	}

			
        my = me->query_entire_dbase();
        your = victim->query_entire_dbase();

        //
        // (1) Find out what action the offenser will take.
        //
        action = me->query("actions");
        if( !mapp(action) ) {
                me->reset_action();
                action = me->query("action");
                if( !mapp(action) ) {
                        CHANNEL_D->do_channel( this_object(), "sys",
                                sprintf("%s(%s): bad action = %O",
                                        me->name(1), me->query("id"), 
me->query("actions", 1)));
                        return 0;
                }
        }
        result = "\n" + action["action"] + "��\n";
        if(stringp(attack_msg)) result = "\n" + attack_msg + "\n";
        //
        // (2) Prepare AP, DP for checking if hit.
        //
        if( objectp(weapon) )   attack_skill = weapon->query("skill_type");
        else                                    attack_skill = "unarmed";

        limbs = victim->query("limbs");
        limb = limbs[random(sizeof(limbs))];

//����AP�ǹ�����������
        ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
        if( ap < 1) ap = 1;

//����DP�ǵз���������
        dp = skill_power(victim, "dodge", SKILL_USAGE_DODGE)/5;

//�ҷ���������DODGE����
        if( action["dodge"])
                dp -= dp * action["dodge"] / 1000 ;
        if( dp < 1 ) dp = 1;
        if( victim->is_busy() ) dp /= 3;
        if( victim->query("statusnow") == "�κ���")  dp /= 5;

        //      (2.5)   if player is enforced, let him/her relase the force even without hit others
        if( userp(me))
        {
                        if( my["force_factor"] && (my["force"] >=  my["force_factor"]) ) 
			{
                                        my["force"] -= my["force_factor"];
			    damage += my["force_factor"];
			}
                        else
                                        my["force_factor"] = 0; 
        }
        // (2.5) Let's see what/who can protect our victim, $N, $n,...all applies
   if(sizeof(victim->query_temp("protectors")) && do_protect(me,weapon,ap,victim)) 
   {
                result += victim->query_temp("protectors_msg");
                damage = RESULT_PROTECT;        
   }
   else
   {
        //
        // (3) Fight!
        //     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
        //     AP and DP are greater than zero, so we always have chance to hit
        //     or be hit.
        // 
//by tiandi ����ɽ���ʣ���ò��������ܣ�ʹ�õ͵ȼ�Ҳ���Դ��иߵȼ���
        if( random(ap) < dp ) {       // Does the victim dodge this hit?

                dodge_skill = victim->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";

// by tiandi �������limb����ûʲô�ã�skill�����������û�б�����
      result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

//by tiandi�ڲ�������Ҷ�ս���з������˹���������������AP����DP������£�����������������з�DODGE+1,������EXP+1
                if( dp < ap && (!userp(victim) || !userp(me)) 
                &&      random(your["gin"]*100/your["max_gin"] + your["int"]) 
> 50 && your["combat_exp"] < 3000000) {
                        your["combat_exp"] +=1;

                        victim->improve_skill("dodge", 1);
                }
//by tiandi NPC�ĳɳ�����ʱ������
    // This is for NPC only. NPC have chance to get exp when fail to hit.
                     if( (ap < dp) && !userp(me) ) {
                        if( random(my["int"]) > 15 ) my["combat_exp"] += 1;
                        me->improve_skill(attack_skill, random(my["int"]));
                }
                damage = RESULT_DODGE;

        } else {

                //
                //      (4) Check if the victim can parry this attack.
                //
                if( victim->query_temp("weapon") ) {
                        pp = skill_power(victim, "parry", 
SKILL_USAGE_DEFENSE);
                        if( !weapon ) pp *= 2;
                } else {
                        if( weapon ) pp = skill_power(victim, "unarmed",SKILL_USAGE_DEFENSE)/2;
                        else pp = skill_power(victim, "unarmed", 
SKILL_USAGE_DEFENSE);
                }
        if( action["parry"])
                pp -= pp * action["parry"] / 1000 ;

                if( victim->is_busy() ) pp /= 3;
                if( pp < 1 ) pp = 1;

                if( random(ap)< pp/3 ) {

        if(victim->query_temp("weapon")){
                parry_skill = victim->query_skill_mapped("parry");
                if( !parry_skill)  parry_skill = "parry";
        }
        else
        {
                parry_skill = victim->query_skill_mapped("unarmed");
                if(!parry_skill) parry_skill = "unarmed";       
        }
                result += SKILL_D(parry_skill)->query_parry_msg(weapon);
         if((string)victim->query_skill_mapped("parry") == "yijinjing"&&random((int)victim->query_skill("yijinjing", 1)) > 151 )
           {
//by tiandi �������㷽ʽ�˺���������10%
                        damage = skill_power(victim, "parry",SKILL_USAGE_DEFENSE)/2+2;
                        damage = (damage -damage/10+ random(damage/5)) ;
                       me->receive_damage("kee", damage);
                      result += damage_msg(damage, "����");
           }
      if((string)victim->query_skill_mapped("parry") == "yihua-jiemu"&&(string)victim->query_skill_mapped("dodge") == "yihua-jiemu"&&random((int)victim->query_skill("yihua-jiemu", 1)) > 151 )
           {
//by tiandi �������㷽ʽ
                        damage = skill_power(victim, "parry",SKILL_USAGE_DEFENSE)/2+2;
                           damage = (damage -damage/10+ random(damage/5)) ;
                       me->receive_damage("kee", damage);
                      result += damage_msg(damage, "�ػ���");
           }
              if( pp < ap && (!userp(victim) || !userp(me)) 
                        &&      random(your["gin"]*100/your["max_gin"] + 
your["int"]) > 50 && your["combat_exp"] < 3000000) {
                                your["combat_exp"] +=1;
                                victim->improve_skill("parry", 1);
                        }
                        damage = RESULT_PARRY;
                } else {

                        //
                 //      (5) We hit the victim and the victim failed to parry
                        //by tiandi �����˺����㹫ʽΪ��������������
					
		   if( objectp(weapon = me->query_temp("weapon")) )
      		  {
              		  attack_skill = weapon->query("skill_type");
  		      }       
   		     else
   		     {
             		   attack_skill = "unarmed";
   		     }
                        damage =  skill_power(me, attack_skill,SKILL_USAGE_DAMAGE) - skill_power(victim, "parry",SKILL_USAGE_DEFENSE)+10;
                       damage = (damage -damage/10+ random(damage/5)) ;
                        if( action["damage"] )
                                damage += action["damage"] ;


//by tiandi ��СSTR���˺�
                        damage_bonus = me->query_str();
// if use weapon, effectiveness only 1/3
                        if(weapon) damage_bonus = damage_bonus/3;

                        // Let force skill take effect.
                        if( my["force_factor"] && (my["force"] > 
my["force_factor"]) ) {
                                if( force_skill = 
me->query_skill_mapped("force") ) {
                                        foo = 
SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["force_factor"]);
                                        if( stringp(foo) ) result += foo;
                                        else if( intp(foo) ) damage_bonus += 
foo;
                                }
                        }

                        if( action["force"] )
                                damage_bonus += action["force"] * 
damage_bonus / 1000;

                        if( martial_skill = 
me->query_skill_mapped(attack_skill) ) {
                                foo = SKILL_D(martial_skill)->hit_ob(me, 
victim, damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo;
                        }

//by tiandi ���ӱ���
		 if( random( (int)me->query_agi()-(int)victim->query_agi()) > ((int)victim->query_agi())) {
			if(random(100) < (int)me->query_temp("apply/heavyhit")) {
			  message_vision(YEL"\n"YEL"��Ȼ��$N��Ϥ��$n��������ʽ���ҵ�������֮����$N����$n���Ƿ���һ����\n"NOR, me,victim);
			  damage = damage*3;
			}
		}
//by tiandi ���＼�ܱ�ɱ��
		 if (me->query_skill("petbisha",1) && me->query("is_pet")==1)
		 {
			 if (random(100)< 5)
			 {
				 message_vision(YEL"\n$N"YEL"˫�۷��������Ĺ�â���������ϣ�����$n���Ǳ�ɱһ����\n"NOR, me,victim);
				 damage = (damage+ me->query_skill("petbisha",1))*3;
			 }
		 }
//by tiandi ���＼��ǿ����
		 if (me->query_skill("petqiangji",1) && me->query("is_pet")==1)
		 {
			 if (random(100)< 50)
			 {
				 message_vision(YEL"\n$N"YEL"����һ�������Ľ���������$n����ȥ���Ʋ��ɵֵ���\n"NOR, me,victim);
				 if (damage/1000 <0)
				 {
					 tempdamage = 1;
				 }
				 else {
					tempdamage = damage/1000;
				 }
				 damage = damage + tempdamage*me->query_skill("petqiangji",1);
			 }
		 }

//by tiandi ���＼���ݻ���
		 if (me->query_skill("petfire",1) && me->query("is_pet")==1)
		 {
				 message_vision(YEL"\n$N"RED"��˫צ�м�����˿˿���磬����$n��ȥ��$n��ʧɫ��\n"NOR, me,victim);
		mattack_points = COMBAT_D->skill_power(me, "magic", SKILL_USAGE_MATTACK);
        mparry_points = COMBAT_D->skill_power(victim, "magic", SKILL_USAGE_MDEFENSE);
        mdodge_points = COMBAT_D->skill_power(victim, "spells", SKILL_USAGE_MDODGE);
        mdamage_points = COMBAT_D->skill_power(me, "magic", SKILL_USAGE_MDAMAGE);
				if (mattack_points > mdodge_points)
						tempdamage = mdamage_points - mparry_points;
				if (tempdamage > 0)
			 {
						tempdamage = victim->receive_damage("kee", tempdamage, me ); 
					    result += damage_msg(tempdamage, "����");
				}
		 }
//by tiandi ��ȡ��������damage,Ϊ����ֵ���ֵ
		tempdamage = damage;

                        // Let weapon or monster have their special damage.
                        if( weapon ) {
                                foo = weapon->hit_ob(me, victim, 
damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo;
                        } else {
                                foo = me->hit_ob(me, victim, damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo;
                        }

                        if( damage_bonus > 0 )
                                damage += (damage_bonus + 
random(damage_bonus))/2;
                        if( damage < 0 ) damage = 0;

/* ȥ������Ӱ�칥��
                        // Let combat exp take effect
                                bounce = your["combat_exp"];
                        while( random(bounce) > my["combat_exp"] ) {
                                damage -= damage / 5;
                                bounce/= 2;
                        }
                                bounce = 0;

*/

                        // (5.4) see how much damage our flexibility can absorb
                                damage -=  ((int)victim->query_fle());
                                damage -=  (int)victim->query_temp("apply/extra_fle");
                        if( damage < 0 ) damage = 0;


      //      (5.5) Check if victim can absorb the damage
                        //
                                absorb_vic = victim->query_skill("iron-cloth") *2 + victim->query_temp("apply/iron-cloth") * 2  ;
		//	message_vision("=="+absorb_vic+"==\n", me, victim );

                                absorb_vic = absorb_vic* (1+victim->query("reborned"))  ; 
                                if( victim->query_skill("iron-cloth"))
                         	 {
            			        absorb_skill = victim->query_skill_mapped("iron-cloth");
       				         if( !absorb_skill ) absorb_skill = "iron-cloth";
					
        				        result += SKILL_D(absorb_skill)->query_absorb_msg();
                                }
                                damage_bonus = me->query_skill("iron-cloth");
                                if( (damage - absorb_vic) < 0 )
                                {
			//		message_vision("=="+damage+"=="+absorb_vic+"\n", me, victim );

					
                                			absorb_skill = victim->query_skill_mapped("iron-cloth");
                               			 if( absorb_skill)
                              				  bounce = 0 - ((SKILL_D(absorb_skill)->bounce_ratio()) * (damage - absorb_vic) / 10);
                              			  else
                              				  bounce = 0;
                              			  absorb_skill = me ->query_skill_mapped("iron-cloth");
                            			   if( absorb_skill)
                             				   bounce -= (SKILL_D(absorb_skill)->bounce_ratio()) * damage_bonus / 10;
                              			  else
                             				   bounce -= 0;
                             			   if ( bounce < 0 ) 
							bounce = 0;
                				   me->receive_damage("kee", bounce, victim );
                     				   result += damage_msg(bounce, "������");
                                }
                                else
                                {

		//	message_vision("/////////"+damage+"///////"+absorb_vic+"\n", me, victim );

			bounce = 0;
                        //
                        //      (6) Inflict the damage.
                        //
	//by tiandi add be hited 
						 if( armor = victim->query_temp("armor/shield") ) {
                                foo = armor->be_hited(me, victim, damage);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage -= foo;
                        } 
//by tiandi ���＼��������
		 if (victim->query_skill("petfangyu",1) && victim->query("is_pet")==1)
		 {
			 if (random(100)< 50)
			 {
				 message_vision(YEL"\n$N"YEL"ȫ���������˹���У�һ��������\n"NOR, victim);
//				  message_vision("\n��ͨ�˺�"+chinese_number(damage)+"\n",victim);
//by tiandi ע�������һ������²���
				 damage = (damage * (1000 - victim->query_skill("petfangyu",1))/1000);
				 if (damage<0) damage = 0;
//				 message_vision("\n�˺�"+chinese_number(damage)+"\n",victim);
			 }
		 }
//by tiandi ���＼�ܸ���
		if (victim->query_temp("petalready") )
		{
			pet = victim->query_temp("petalready");
			if (environment(pet) == environment(victim))
			{
				if (pet->query_skill("petgedang",1) && pet->query("is_pet")==1)
				{
					if (random(100)< 50)
					{
						damage = tempdamage - skill_power(pet, "parry", SKILL_USAGE_DEFENSE);
						if (damage<0) damage = 0;
						tempdamage = damage /1000;
						if(tempdamage<0) 
							tempdamage = pet->query_skill("petgedang",1);
						else
							tempdamage = tempdamage*pet->query_skill("petgedang",1);
						damage = damage - tempdamage;
						tempdamage = pet->receive_damage("kee", tempdamage, me ); 
						message_vision(YEL"\n$N"BLU"�¸ҵ�վ����$n����ǰ����$n�����˴˴ε��˵�"+chinese_number(tempdamage)+"���˺���\n"NOR, pet,victim);

					}
				 }
			}
		}
//by tiandi ���ӷ���Ч��
		if (victim->query_temp("guarding",1))
		 {
				 damage = damage /2;
				 if (damage<0) damage = 0;
		 }

                        damage = victim->receive_damage("kee", damage, me ); 
		
	//	message_vision("me$Nvictim$n.\n", me, victim );

//by tiandi �����ܿ���
                        if( (me->is_killing(victim) || weapon) && random(damage) > (int)victim->query_temp("apply/armor") ) {
    // We are sure that damage is greater than victim's armor here.
                                victim->receive_wound("kee",
                                        damage - (int)victim->query_temp("apply/armor"), me);
           //                    wounded = 1;
                      }
                if(stringp(damtype)) 
                result += damage_msg(damage, damtype);
                else
                result += damage_msg(damage, action["damage_type"]);

//by tiandi ��������ĥ��,�趨���ƣ��촸����Ϊ1/2,����ʱ�ж�
		seteuid(ROOT_UID);
	if (me->query("class") != "baiyun" && me->query("class") != "tianchui" )
	{
		if(weapon && !random(10))
			if (weapon->query("selfmaking"))
		{
			weapon->set("abradability",weapon->query("abradability")-1);
			weapon->save();
			if (weapon->query("abradability")< 1)
				{
	//				write (weapon->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					weapon->unequip();
					
				}
		}
	}
	else if(weapon && !random(20))
	{
		if (weapon->query("selfmaking"))
		{
		weapon->set("abradability",weapon->query("abradability")-1);
		weapon->save();
		if (weapon->query("abradability")< 1)
			{
//				write (weapon->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
				weapon->unequip();
			
			}
		}
	}

	cloth = victim->query_temp("armor/cloth");
	head = victim->query_temp("armor/head");
	finger = victim->query_temp("armor/finger");
	boots = victim->query_temp("armor/boots");
	shield = victim->query_temp("armor/shield");
	wrists = victim->query_temp("armor/wrists");
	waist = victim->query_temp("armor/waist");
	neck = victim->query_temp("armor/neck");

//by tiandi ����װ��ĥ��,�趨���ѣ���Ѫ������Ϊ1/2,������ʱ�ж�
	if (victim->query("class") != "dazhao" && victim->query("class") != "tiexue")
	{
		if(!random(10))
		{
			if(cloth)
				if(cloth->query("selfmaking"))
			{
				cloth->set("abradability",cloth->query("abradability")-1);
				cloth->save();
				if (cloth->query("abradability")< 1)
				{
	//				write (cloth->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					cloth->unequip();

				}
			}
			if(head)
				if (head->query("selfmaking"))
			{
				head->set("abradability",head->query("abradability")-1);
				head->save();
				if (head->query("abradability")< 1)
				{
//					write (head->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					head->unequip();
					
				}
			}
			if(finger)
				if(finger->query("selfmaking"))
			{
				finger->set("abradability",finger->query("abradability")-1);
				finger->save();
				if (finger->query("abradability")< 1)
				{
	//				write (finger->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					finger->unequip();
					
				}
			}
			if(boots)
				if(boots->query("selfmaking"))
			{
				boots->set("abradability",boots->query("abradability")-1);
				boots->save();
				if (boots->query("abradability")< 1)
				{
	//				write (boots->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					boots->unequip();
					
				}
			}
			if(shield)
				if(shield->query("selfmaking"))
			{
				shield->set("abradability",shield->query("abradability")-1);
				shield->save();
				if (shield->query("abradability")< 1)
				{
//					write (shield->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					shield->unequip();
					
				}
			}
			if(wrists)
				if(wrists->query("selfmaking"))
			{
				wrists->set("abradability",wrists->query("abradability")-1);
				wrists->save();
				if (wrists->query("abradability")< 1)
				{
//					write (wrists->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					wrists->unequip();
					
				}
			}
			if(waist)
				if(waist->query("selfmaking"))
			{
				waist->set("abradability",waist->query("abradability")-1);
				waist->save();
				if (waist->query("abradability")< 1)
				{
	//				write (waist->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					waist->unequip();
					
				}
			}
			if(neck)
				if(neck->query("selfmaking"))
			{
				neck->set("abradability",neck->query("abradability")-1);
				neck->save();
				if (neck->query("abradability")< 1)
				{
	//				write (neck->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					neck->unequip();
					
				}
			}

		}
	}
	else if(!random(20))
		{
			if(cloth)
				if(cloth->query("selfmaking"))
			{
				cloth->set("abradability",cloth->query("abradability")-1);
				cloth->save();
				if (cloth->query("abradability")< 1)
				{
//					write (cloth->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					cloth->unequip();
					
				}
			}
			if(head)
				if (head->query("selfmaking"))
			{
				head->set("abradability",head->query("abradability")-1);
				head->save();
				if (head->query("abradability")< 1)
				{
//					write (head->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					head->unequip();
					
				}
			}
			if(finger)
				if(finger->query("selfmaking"))
			{
				finger->set("abradability",finger->query("abradability")-1);
				finger->save();
				if (finger->query("abradability")< 1)
				{
//					write (finger->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					finger->unequip();
				}
			}
			if(boots)
				if(boots->query("selfmaking"))
			{
				boots->set("abradability",boots->query("abradability")-1);
				boots->save();
				if (boots->query("abradability")< 1)
				{
//					write (boots->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					boots->unequip();
					
				}
			}
			if(shield)
				if(shield->query("selfmaking"))
			{
				shield->set("abradability",shield->query("abradability")-1);
				shield->save();
				if (shield->query("abradability")< 1)
				{
//					write (shield->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					shield->unequip();
					
				}
			}
			if(wrists)
				if(wrists->query("selfmaking"))
			{
				wrists->set("abradability",wrists->query("abradability")-1);
				wrists->save();
				if (wrists->query("abradability")< 1)
				{
	//				write (wrists->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					wrists->unequip();
					
				}
			}
			if(waist)
				if(waist->query("selfmaking"))
			{
				waist->set("abradability",waist->query("abradability")-1);
				waist->save();
				if (waist->query("abradability")< 1)
				{
//					write (waist->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					waist->unequip();
					
				}
			}
			if(neck)
				if(neck->query("selfmaking"))
			{
				neck->set("abradability",neck->query("abradability")-1);
				neck->save();
				if (neck->query("abradability")< 1)
				{
	//				write (neck->query("name")+"�;�Ϊ�㣬�Զ�ж�¡�\n");
					neck->unequip();
					
				}
			}

		}
						
	seteuid(getuid());




                                }
                        //
                        //      (7) Give experience
                        //

     if(( !userp(me) || !userp(victim) )&& your["combat_exp"] < 3000000) {
                                if( (ap < dp)
                                &&      (random(my["sen"]*100/my["max_sen"] ) 
> 50) ) {
                                        if(!random(4)) my["combat_exp"] +=1;
                                        me->improve_skill(attack_skill, 1);
                                }
                                if( random(your["max_kee"] + your["kee"]) < 
damage ) {
                                                your["combat_exp"] += 1;
                                }
                        }
                }
        } 
   } //protector
        result = replace_string( result, "$l", limb );
        if( victim->query_temp("weapon"))
        result = replace_string( result, "$v", (victim->query_temp("weapon"))->name());
        if( victim->query_skill_mapped("iron-cloth"))
        result = replace_string( result, "$z",  to_chinese(victim->query_skill_mapped("iron-cloth")));
        if( objectp(weapon) )
                result = replace_string( result, "$w", weapon->name() );
        else if( stringp(action["weapon"]) )
                result = replace_string( result, "$w", action["weapon"] );

        message_vision(result, me, victim );
        if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
                if( damage > 0 )
                        tell_object(me, sprintf( GRN 
"AP��%d��DP��%d��PP��%d���˺�����%d\n" NOR,
                                ap, dp, pp, damage));
                else
                        tell_object(me, sprintf( GRN 
"AP��%d��DP��%d��PP��%d\n" NOR,
                                ap, dp, pp));
        }

        if(  damage > 0  ) {
                if ( bounce > 0) report_status(me, 0);
                else
                //report_status(victim, wounded);
		report_status(victim, 0);
                                env = environment(victim);
        if( victim->is_busy() ) victim->interrupt_me(me);

                if( (!me->is_killing(your["id"])) && 
(!victim->is_killing(my["id"])) &&
((victim->query("biwu_fighter")!= 1 ) ||
(me->query("biwu_fighter") != 1) )&&
((victim->query("kee")*2 <= victim->query("max_kee")) ||
(me->query("kee")*2 <= me->query("max_kee")) )) {
                        me->remove_enemy(victim);
                        victim->remove_enemy(me);
			fight_reward(me, victim);
			fight_penalty(me, victim);			
                        message_vision( 
winner_msg[random(sizeof(winner_msg))], me, victim);
                }
                 if( (!me->is_killing(your["id"])) && 
(!victim->is_killing(my["id"])) &&
//env->query("biwuchang")&&
((victim->query("biwu_fighter")== 1 ) ||
(me->query("biwu_fighter") == 1) )&&
((victim->query("kee")*5 <= victim->query("max_kee")) ||
(me->query("kee")*5 <= me->query("max_kee")) )) {
                        me->remove_enemy(victim);
                        victim->remove_enemy(me);
			fight_reward(me, victim);
			fight_penalty(me, victim);			
message("channel:gab",HIY"�����䳡��"+
                me->query("family/family_name")+"��"+me->query("name")+"�ڱ���̨����"+
                victim->query("family/family_name")+"��"+victim->query("name")+"�������ʸ�������̨!\n\n"NOR,users());
        me->set("eff_kee", me->query("max_kee"));
        me->set("kee", me->query("max_kee"));
        me->set("gin", me->query("max_gin"));
        me->set("eff_gin", me->query("max_gin"));
        me->set("sen", me->query("max_sen"));
        me->set("eff_sen", me->query("max_sen"));
        me->set("force", me->query("max_force"));
      victim->set("eff_kee", victim->query("max_kee"));
        victim->set("kee", victim->query("max_kee"));
        victim->set("gin", victim->query("max_gin"));
        victim->set("eff_gin", victim->query("max_gin"));
        victim->set("sen", victim->query("max_sen"));
        victim->set("eff_sen", victim->query("max_sen"));
        victim->set("force", victim->query("max_force"));
        victim->delete("biwu_fighter");
        me->delete("biwu_fighter");
        victim->move("/d/fy/biwufang");

   }
       }
//������������xgchen

        if( functionp(action["post_action"]) )
                evaluate( action["post_action"], me, victim, weapon, damage);
        WEAPON_D->wear_off(me,victim,weapon,damage);
// See if the attack is fast enough to make another attack!
//      if( random( (int)me->query_agi()+(int)victim->query_agi()) < ((int) me->query_agi())/2)
//               do_attack(me, victim,me->query_temp("weapon"),TYPE_REGULAR);
        // See if the victim can make a riposte.
//        if( attack_type==TYPE_REGULAR
//        &&      damage < 1
//        &&      victim->query_temp("guarding") ) {
//                victim->set_temp("guarding", 0);
//                if( random(my["cps"]) < 2 ) {
//                        message_vision("$Nһ�����У�¶����������\n", me);
//                        do_attack(victim, me,victim->query_temp("weapon"), 
//TYPE_QUICK);
//                } else {
//                        message_vision("$N��$n����ʧ�󣬳û�����������\n", 
//victim, me);
//                        do_attack(victim, me, victim->query_temp("weapon"), 
//TYPE_RIPOSTE);
//                }
//        }
}

//      fight()
//
//This is called in the attack() defined in F_ATTACK, which handles fighting
//      in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
        object ob;
	int a,b,lv,lv2;
	lv = me->query("level");
	lv2 = victim->query("level");
//	a = random((int)me->query_agi());
//	b = random((int)victim->query_agi());
	a = random(skill_power(me, "move",SKILL_USAGE_MOVE));
	b = random(skill_power(victim, "move",SKILL_USAGE_MOVE));
	//write ("A:"+a+"VS B:"+b+"\n");
        if( !living(me) ) return;
// as long as we are in a fight, we are nervous, our ���� drops
        me->add("sen",-1);

//by tiandi ���������λ
        if( !me->visible(victim)
        && ( (int)me->query_skill("perception") < (int)victim->query("level")*5) )
                return;

// If victim is busy or unconcious, always take the chance to makeanattack.
        if( victim->is_busy() || !living(victim) ) {
                me->set_temp("guarding", 0);
                if( !victim->is_fighting(me) ) victim->fight_ob(me);
                do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

        // Else, see if we are brave enough to make an aggressive action.
      	  }
	 else if( random(a+lv*10)>random(b+lv2*10))
               {
      //by tiandi�������������ж�  		if( 5*(int)me->query_cor() > random((int)victim->query_cps())){
				if (!me->query_temp("guarding"))
				{
					   if( !victim->is_fighting(me) ) victim->fight_ob(me);
             		   do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
				}
            	 else 
			{
               	message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
              		  return;
			}
              	}
	else
		 return;
}

//      auto_fight()
//
//      This function is to start an automatically fight. Currently this is
//      used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
        // Don't let NPC autofight NPC.
        if( !userp(me) && !userp(obj) ) return;

 // Because most of the cases that we cannot start a fight cannot be checked
// before we really call the kill_ob(), so we just make sure we have no 
        // aggressive callout wating here.
        if( me->query_temp("looking_for_trouble") ) return;
        me->set_temp("looking_for_trouble", 1);

        // This call_out gives victim a chance to slip trough the fierce guys.
        call_out( "start_" + type, 0, me, obj);
}
void auto_follow(object follower, object leader)
{
        int fexp, lexp;
        fexp = follower->query("combat_exp");
        lexp = leader->query("combat_exp");
        if( fexp <=0 ) fexp =0;
        if( lexp <=0 ) lexp =0;
        if( random(lexp) > fexp/10 )    
        follower->set_leader(leader);
        else
        follower->set_leader(0);
}
void start_berserk(object me, object obj)
{
        int bellicosity;

        if( !me || !obj ) return;                               
// Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            
// Are we busy fighting?
        ||      
!living(me)                                                     
// Are we capable for a fight?
        ||      environment(me)!=environment(obj)       
// Are we still in the same room?
        ||      environment(me)->query("no_fight")      
// Are we in a peace room?
        )       return;

        bellicosity = (int)me->query("bellicosity");
        message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);

        if(     ((int)me->query("force") + (int)me->query_tol() * 10)> (random(bellicosity) + 
bellicosity)/2 ) return;
        if( userp(obj) &&
                (int) obj->query("combat_exp") < LOWER_LIMIT 
          )     return;

        if( bellicosity > (int)me->query("score") 
        &&      !wizardp(obj) ) {
                message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me)
                        + "����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n", me, obj);
                me->kill_ob(obj);
        } else {
                message_vision("$N����$n�ȵ���ι��" + RANK_D->query_rude(obj)
                        + "��" + RANK_D->query_self_rude(me) + 
"�������˴�ܣ����������ְɣ�\n",
                        me, obj);
                me->fight_ob(obj);
        }
}

void start_hatred(object me, object obj)
{
        if( !me || !obj ) return;                               
// Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            
// Are we busy fighting?         
        ||      
!living(me)                                                     
// Are we capable for a fight?
        ||      environment(me)!=environment(obj)       
// Are we still in the same room?
        ||      environment(me)->query("no_fight")      
// Are we in a peace room?
        )       return;

        // We found our hatred! Charge!
        message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, 
obj);
        me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
        if( !me || !obj ) return;                               
// Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            
// Are we busy fighting?
        ||      
!living(me)                                                     
// Are we capable for a fight?
        ||      environment(me)!=environment(obj)       
// Are we still in the same room?
        ||      environment(me)->query("no_fight")      
// Are we in a peace room?
        )       return;

        // We found our vendetta opponent! Charge!
        me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
        if( !me || !obj ) return;                               
// Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            
// Are we busy fighting?
        ||      
!living(me)                                                     
// Are we capable for a fight?
        ||      environment(me)!=environment(obj)       
// Are we still in the same room?
        ||      environment(me)->query("no_fight")      
// Are we in a peace room?
        )       return;

        // We got a nice victim! Kill him/her/it!!!
        me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
        switch(event) {
                case "dead":
                        message_vision("\n$N���ˡ�\n\n", ob);
                        break;
                case "unconcious":
                        
message_vision("\n$N����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n", ob);
                        break;
                case "revive":
                        message_vision("\n$N���������۾��������˹�����\n\n", 
ob);
                        break;
        }
}

void winner_reward(object killer, object victim)
{
        object owner;

        if(owner=killer->query("possessed")) killer = owner;
        killer->defeated_enemy(victim);
}
void loser_penalty(object killer, object victim)
{
        object owner;

        if(owner=victim->query("possessed")) victim = owner;
        victim->defeated_by_enemy(killer);
}

void killer_reward(object killer, object victim)
{
        int bls,oldtop,newtop,extra;
        string vmark;
        string ski, skill_type, parry_type;
        int i,msize,exp, pot, score, reb;
        object owner,weapon;
        object env,gift;
        object *mem;
                object objnew;
              object realkiller;

        // Call the mudlib killer apply.
        if(owner=killer->query("possessed")) killer = owner;
        realkiller = killer;
reb =  killer->query("reborned");

env = environment(victim);
        killer->killed_enemy(victim);
 //�����˱�����������ϵͳ xgchen@zzfy 2002-2-9
                    oldtop = killer->query("biqi_top");
      newtop = victim->query("biqi_top");
        if (!oldtop) oldtop=1000;
        if (!newtop) newtop=1000;
          if( objectp(weapon = killer->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
        }       
        else
        {
                skill_type = "unarmed";
              }
                 ski=killer->query_skill_mapped(skill_type);
	if (!ski)  ski="���ؾ�ѧ";
             if (newtop<oldtop&&userp(victim)&&userp(killer)) {
                                  killer->set("biqi_top",newtop);
            victim->set("biqi_top",oldtop);

       // ���� xgchen@zzfy 
      if(victim->query("biqi_top")<10&&victim->query("biqi_top")>0){
               message("channel:chat",HIR"�����ƹ��桿    "+
                killer->query("name")+"��"+environment(victim)->query("short")+
                "��"+CHINESE_D->chinese(ski)+"����"+victim->query("name")+"��\n\t\t"+killer->query("name")+
                           "��"+killer->query("biqi_top")+"����"BLINK+HIM"������"+NOR+HIR"������"+chinese_number(killer->query("biqi_top"))+"λ��\n\n"NOR,users());
          }
}
            killer->set("skname",CHINESE_D->chinese(ski));  
if(objectp(env))
        if ( env->query("no_death_penalty"))
        {
        victim->set_temp("no_death_penalty",1);
        return;
        }
        if( userp(victim) && userp (killer)) {
    killer->set("last_good_kill",(int)killer->query("mud_age")); 
                killer->add("PKS", 1);
                             killer->add("OPK",1);
                victim->set("pkname", killer->query("name"));
                victim->set("pkid", killer->query("id"));
                bls = 10;
        } else {
                killer->add("MKS", 1);
                bls = 1;
        }
       killer->add("bellicosity", bls * (userp(killer)? 1: 2));

//by tiandi PK���˽�����
               if(killer->query("OPK") > 2)
            {          
             killer->set("qiushi/howlong",9999999);
             killer->move("/d/wiz/qiushi");
            killer->set("startroom","/d/wiz/qiushi");
                    }  
                if(!interactive(victim))
        if( stringp(vmark = victim->query("vendetta_mark")) )
       if (killer->query("vendetta_mark")!=vmark) killer->add("vendetta/" + vmark, 1);

//by tiandi for little boss
		if (victim->query("issmallboss"))
		{
			mem = killer->query_team();
			msize = sizeof(mem);
			if(msize < 1) msize =1;
			if( msize <= 1) 
			{
			killer->add("smallboss",1);
			killer->add("combat_exp",victim->query("level")*300);
			tell_object(killer,HIY"��ɹ��ص�����ɱ�˶���ˣ���˱������ˣ�\n" +chinese_number(victim->query("level")*300) + "��ʵս���顣\n\n" +NOR);
			if (killer->query("smallboss")%20==0 )
				{
				gift=new("/d/wiz/fyup/obj/bbao");	
				gift->move(killer);
				tell_object(killer,NOR"����������ɶ�ʮ�����������˽�����"+ gift->query("name") + "�Ķ��⽱����\n\n" +NOR);
				}
			}
			else
			{
			    for(i=0;i<sizeof(mem);i++)
				{
                if((environment(killer) == environment(mem[i]))&& (killer->query("level") - 10) < mem[i]->query("level"))
					{
					 mem[i]->add("smallboss",1);
					 mem[i]->add("combat_exp",victim->query("level")*200);
					 tell_object(mem[i],HIY"��ɹ��ػ�ɱ�˶���ˣ���˱������ˣ�\n" + chinese_number(victim->query("level")*200) + "��ʵս���顣\n"NOR);
					 if (mem[i] == killer)
						{
						 tell_object(mem[i],HIY"�㱻���⽱���ˣ�\n" + chinese_number(victim->query("level")*100) + "��ʵս���顣\n"NOR);
						 mem[i]->add("combat_exp",victim->query("level")*100);
						}
				if (killer->query("smallboss")%10==0 )
				{
				gift=new("/d/wiz/fyup/obj/bbao");	
				gift->move(killer);
				tell_object(killer,NOR"�����������ʮ�����������˽�����"+ gift->query("name") + "�Ķ��⽱����\n\n" +NOR);
				}
						}
					else
						 tell_object(mem[i],"���ź������ڵȼ����̫��������Ѿ��������ֳ��������û���õ�������\n" +NOR);
				}
			}	 
		}
         if(mapp(killer->query("quest")))
        {
        mapping quest;
        if( interactive(killer) && (quest = killer->query("quest"))
                && ( (int)killer->query("task_time") >= time())
                && (victim->name() == quest["quest"])
                && !userp(victim))
        {
        exp = (quest["exp_bonus"] + random(quest["exp_bonus"]/2))*(1+reb/5);
		
// put a limit on max exp we can get from a quest
        if( exp > 1000) exp = 1000;
		tell_object(killer,"exp="+exp+"\n");
		tell_object(killer,"num="+killer->query_temp("quest_number")+"\n");
        exp = exp * (int) killer->query_temp("quest_number")*killer->query("level");
        if( exp > 1500) exp = 1500;
        pot = exp/ 10 + 1;
//      for weekly race, each quest worth same, 20
//        score = quest["score"]/2 + random(quest["score"]/2);
//        score = -1;
        mem = killer->query_team();
        msize = sizeof(mem);
        if(msize < 1) msize =1;
        if( msize <= 1) 
        {
        killer->add("combat_exp", exp);
        killer->add("potential", pot);
 //       killer->add("score", score);
        tell_object(killer,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n" +NOR);
        }
        else
        {
        exp = exp;
        pot = pot ;
        for(i=0;i<sizeof(mem);i++)
        {
                if(mem[i])
                if( (mem[i]->query_temp("ttarget") == victim->query("id"))
                || mem[i] == killer)
                if(environment(killer) == environment(mem[i])){
        mem[i]->add("combat_exp", exp);
        mem[i]->add("potential", pot);
        tell_object(mem[i],HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n" NOR);
                          }
        }
        }
        killer->set("quest", 0 );
        }
        }
        else
        {
        string quest;
        if( interactive(killer) && (quest = killer->query("quest"))
                && ( (int)killer->query("task_time") >= time())
                && (victim->name() == quest)
                && !userp(victim))
        {
        exp = random(100)+10;
// put a limit on max exp we can get from a quest
        exp = extra*exp * (int) killer->query_temp("quest_number")/5;
        if( exp > 1500) exp = 1500;
        exp += 1;       
        pot = exp/ 10 + 1;
//      for weekly race, each quest worth same, 20
//        score = quest["score"]/2 + random(quest["score"]/2);
//      score = 1;
        mem = killer->query_team();
        msize = sizeof(mem);    
        if(msize < 1) msize =1;
        if( msize <= 1) {       
        killer->add("combat_exp", exp);
        killer->add("potential", pot);
        killer->add("score", -score);
        killer->add("QUEST",1);
        tell_object(killer,HIY"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n" NOR);
//        chinese_number(score)+"���ۺ�����\n"NOR);
        }
        else{
        exp = exp ;
        pot = pot ;
        score = 1;
        for(i=0;i<sizeof(mem);i++)
        {
                if(mem[i])
                if( (mem[i]->query_temp("ttarget") == victim->query("id"))
                || mem[i] == killer)
                if(environment(killer) == environment(mem[i])){
        mem[i]->add("combat_exp", exp);
        mem[i]->add("potential", pot);
        mem[i]->add("score", -score);
        mem[i]->add("QUEST",1);
        tell_object(mem[i],HIY"�㱻����������ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n" NOR);
//        chinese_number(score)+"���ۺ�����\n"NOR);
                          }     
        }       
        }
        killer->set("quest", 0 );
        }
        }
// let's add the hired killer things here
        if( ! userp(realkiller) && realkiller->query("hired_killer")
        && (string)victim->query("id") == (string)realkiller->query("haunttar"))
                {
                message_vision("$Nһ���֣��Ҳ���ʹ����������ڣ�\n",realkiller);
                destruct(realkiller);
                }
	if(userp(killer)&&!userp(victim)){
        if(killer->query("job/sxy") >= 1 && victim->query("sxy-name") == killer->query("id") )
        {
           tell_object(killer,RED"��ɱ����һ�����ڿ�ͽ�ˣ�\n"NOR);
           killer->add("job/gong",1);   
        }
	}

}
 
void victim_penalty(object victim, object killer)
{
        string msg="Ī���������"+environment(victim)->query("short")+"���ˡ�";
        mapping actions;
        object env;
        if( userp(victim)){
                victim->add("KILLED",1);
        if(objectp(killer))
        {
                msg="��"+killer->query("name")+"("+killer->query("id")+")��"+environment(victim)->query("short");
                actions = killer->query("actions");
                switch(actions["damage_type"]) {
                case "����":
                case "����":
                        msg+="�����ˡ�";
                        break;
                case "����":
                        msg+="�����ˡ�";
                        break;
                case "����":
                        msg+="�����ˡ�";
                        break;
                case "ץ��":
                        msg+="ץ���ˡ�";
                        break;
                case "������":
                        msg+="�����ˡ�";
                        break;
                default:
                        msg+="ɱ���ˡ�";
                }
        }       
                CHANNEL_D->do_channel(this_object(), "rumor",
                        sprintf("%s"+msg, victim->name(1)));
        env = environment(victim);
        if(objectp(env))
        if ( env->query("no_death_penalty")) 
        {
        victim->set_temp("no_death_penalty",1);
        return;
        }
                                victim->clear_condition();
                // Give the death penalty to the dying user.
           victim->set("bellicosity", 0);
                victim->add("combat_exp", -(int)victim->query("combat_exp") /50);
                victim->delete("vendetta");
                if( victim->query("thief") )
                        victim->set("thief", (int)victim->query("thief") / 2);
                if( (int)victim->query("potential") >
(int)victim->query("learned_points"))
                        victim->add("potential",
                                ((int)victim->query("learned_points") -
(int)victim->query("potential"))/2 );
if (victim->query("combat_exp")<0){victim->set("combat_exp",0);}
// �������֣�10�����µ�����������۳�skill
if(victim->query("level")>10)
                victim->skill_death_penalty();
 
   }
}
