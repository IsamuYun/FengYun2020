//edit by tiandi 2008.6.11
#include <room.h>
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string getper(object me, object obj);
string tough_level(int power);
string gettof(object me, object obj);
string getdam(object me, object obj);
string *tough_level_desc = ({
BLU"����һ��"NOR,BLU"��������"NOR,BLU"��֪����"NOR,BLU"��ѧէ��"NOR,BLU"����ǿǿ"NOR,
BLU"�����ž�"NOR,BLU"����é®"NOR,BLU"��֪һ��"NOR,BLU"����ͨͨ"NOR,BLU"ƽƽ����"NOR,

HIB"ƽ������"NOR,HIB"��ͨƤë"NOR,HIB"��������"NOR,HIB"��������"NOR,HIB"����С��"NOR,
HIB"����С��"NOR,HIB"����Ѿ�"NOR,HIB"��������"NOR,HIB"��������"NOR,HIB"�ڻ��ͨ"NOR, 

CYN"�������"NOR,CYN"¯����"NOR,CYN"��Ȼ���"NOR,CYN"���д��"NOR,CYN"���д��"NOR,
CYN"��Ȼ��ͨ"NOR,CYN"�������"NOR,CYN"�޿�ƥ��"NOR,CYN"����Ⱥ��"NOR,CYN"����似"NOR,

HIC"�����뻯"NOR,HIC"��ͬ����"NOR,HIC"����Ⱥ��"NOR,HIC"�Ƿ��켫"NOR,HIC"�����ױ�"NOR,
HIC"��������"NOR,HIC"һ����ʦ"NOR,HIC"�������"NOR,HIC"�񹦸���"NOR,HIC"������˫"NOR,

HIR"��������"NOR,HIR"���춯��"NOR,HIR"������"NOR,HIR"������ʥ"NOR,HIR"�������"NOR,
HIR"��ǰ����"NOR,HIR"���˺�һ"NOR,HIR"��ز�¶"NOR,HIR"��ɨ����"NOR,HIR"��ɲ�"NOR,

HIY"�����ɵ�"NOR,HIY"��������"NOR,HIR"ǿ������"NOR,HIY"��������"NOR,HIR"ǰ�޹���"NOR,
HIY"��豹���"NOR,HIY"��������"NOR,HIY"���ž���"NOR,HIY"�����޵�"NOR,HIY"���µ�һ"NOR,
});
string *heavy_level_desc= ({
        "����",
        "����",
        "����",
        "����",
        "����",
        "����"  
});
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;

        if( !arg ) result = look_room(me, environment(me));
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
                if( obj->is_character() ) result = look_living(me, obj);
                else result = look_item(me, obj);
        } else result = look_room_item(me, arg);
        return result;
}

int look_room(object me, object env)
{
        int i;
        object *inv;
        mapping exits,quest;
        string str, *dirs;
        if( !env ) {
                write("������ܻ����ɵ�һƬ��ʲ��Ҳû�С�\n");
                return 1;
        }
        str ="\n";
        str += sprintf( "%s - %s\n    %s%s",
                env->query("short"),
                wizardp(me)? file_name(env)+sprintf(" - (%d,%d,%d)",env->query("coor/x"),
                env->query("coor/y"),env->query("coor/z")): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
	// add by tiandi for job	
	
	if (quest =  me->query("tiequest"))
	{
		if ((string)env->query("short") == quest["quest"])
		{
	 	 str +=HIG"    ��ͻȻ��������ķ羰��Ȼ�Ͱ���������һ�������Ǿ��������������͡�\n"NOR;
		   call_out("auto_perform", random(60), me); 
		}
	}
        if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
                if( sizeof(dirs)==0 )
                        str += "    ����û���κ����Եĳ�·��\n";
                else if( sizeof(dirs)==1 )
                        str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
                else
                        str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",
                                implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
        }
        else str += "    ����û���κ����Եĳ�·��\n";

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
               if( inv[i]->query("no_shown")) continue;
                if( !me->visible(inv[i]) ) continue;
	  if (inv[i]->query("inquiry"))
		  str +=HIY" ?"NOR;
	  else
		  str += "  ";

	  if (inv[i]->query_temp("in_trade"))
		str +=inv[i]->short() + HIB "<��̯��>" NOR"\n";
              else  if (inv[i]->is_busy() )
		str +=inv[i]->short() + HIY "<æµ��>" NOR"\n";
	  else  if (inv[i]->query("statusnow"))
		str +=inv[i]->short() + HIY "<"+ inv[i]->query("statusnow")+">" NOR"\n";
	else
		str +=	inv[i]->short() + "\n";


        }
        write(str);
        return 1;
}

int look_item(object me, object obj)
{
        mixed *inv;
        string prep,line;
		printf(HIY"������������������������������������������������������������������������������������\n"NOR);
		printf(HIY"   "NOR"%-60s",obj->long());

		if (obj->query("weapon_prop") || obj->query("armor_prop"))
		{
		printf(HIY"�ĩ���������������������������������������������������������������������������������\n"NOR);
		line = sprintf(HIY"��"HIR" �ɳ��̶�:%-10d ǿ���̶�:%-10d װ���;�:%-10d �ȼ�����:%-10d"HIY"��\n"NOR,
			obj->query("level"),obj->query("leveled"),
			obj->query("abradability"),obj->query("limited_lv"));
		line += sprintf(HIY"��"NOR" ��������:%-10d �����˺�:%-10d ��������:%-10d ��������:%-10d"HIY"��\n"NOR,
			obj->query("weapon_prop/attack")?obj->query("weapon_prop/attack"):obj->query("armor_prop/attack"),
			obj->query("weapon_prop/damage")?obj->query("weapon_prop/damage"):obj->query("armor_prop/damage"),
			obj->query("armor_prop/armor")?obj->query("armor_prop/armor"):obj->query("weapon_prop/armor"),
			obj->query("armor_prop/dodge")?obj->query("armor_prop/dodge"):obj->query("weapon_prop/armor"));
		line += sprintf(HIY"��"NOR" ��������:%-10d �����˺�:%-10d ��������:%-10d ��������:%-10d"HIY"��\n"NOR,
			obj->query("weapon_prop/mattack")?obj->query("weapon_prop/mattack"):obj->query("armor_prop/mattack"),
			obj->query("weapon_prop/mdamage")?obj->query("weapon_prop/mdamage"):obj->query("armor_prop/mdamage"),
			obj->query("armor_prop/marmor")?obj->query("armor_prop/marmor"):obj->query("weapon_prop/marmor"),
			obj->query("armor_prop/mdodge")?obj->query("armor_prop/mdodge"):obj->query("weapon_prop/mdodge"));
		line += sprintf(HIY"��"NOR" ��    ��:%-10d ��    ��:%-10d ��    ��:%-10d ��    ��:%-10d"HIY"��\n"NOR,
			obj->query("weapon_prop/strength")?obj->query("weapon_prop/strength"):obj->query("armor_prop/strength"),
			obj->query("weapon_prop/courage")?obj->query("weapon_prop/courage"):obj->query("armor_prop/courage"),
			obj->query("weapon_prop/intelligence")?obj->query("weapon_prop/intelligence"):obj->query("armor_prop/intelligence"),
			obj->query("weapon_prop/spirituality")?obj->query("weapon_prop/strength"):obj->query("armor_prop/spirituality"));
		line += sprintf(HIY"��"NOR" ��    ��:%-10d ��    ��:%-10d ��    ��:%-10d ��    ��:%-10d"HIY"��\n"NOR,
			obj->query("weapon_prop/composure")?obj->query("weapon_prop/composure"):obj->query("armor_prop/composure"),
			obj->query("weapon_prop/personality")?obj->query("weapon_prop/personality"):obj->query("armor_prop/personality"),
			obj->query("weapon_prop/constitution")?obj->query("weapon_prop/constitution"):obj->query("armor_prop/constitution"),
			obj->query("weapon_prop/karma")?obj->query("weapon_prop/karma"):obj->query("armor_prop/karma"));
		line += sprintf(HIY"��"NOR" ��    ��:%-10d ��    ��:%-10d ��    ��:%-10d ��    ��:%-10d"HIY"��\n"NOR,
			obj->query("weapon_prop/agility")?obj->query("weapon_prop/agility"):obj->query("armor_prop/agility"),
			obj->query("weapon_prop/durability")?obj->query("weapon_prop/durability"):obj->query("armor_prop/durability"),
			obj->query("weapon_prop/flexibility")?obj->query("weapon_prop/flexibility"):obj->query("armor_prop/flexibility"),
			obj->query("weapon_prop/tolerance")?obj->query("weapon_prop/tolerance"):obj->query("armor_prop/tolerance"));
		line += sprintf(HIY"��"HIM" ����:%-5d ����:%-5d �ڻ�:%-5d Ѫ��:%-5d ����:%-5d ����:%-5d ����:%-5d"HIY"   ��\n"NOR,
			obj->query("armor_prop/addkee"),obj->query("armor_prop/addmana"),
			obj->query("armor_prop/addforce"),obj->query("armor_prop/addeffkee"),
			obj->query("armor_prop/heavyhit"),obj->query("armor_prop/against"),obj->query("armor_prop/move"));

		write(line);
		printf(HIY"������������������������������������������������������������������������������������\n"NOR);
		}
		
	else
	printf(HIY"������������������������������������������������������������������������������������\n"NOR);
        inv = all_inventory(obj);
        if( !obj->is_closed() && sizeof(inv)) {
                switch( (string)obj->query("prep") ) {
                        case "on":
                                prep = "��";
                                break;
                        case "under":
                                prep = "��";
                                break;
                        case "behind":
                                prep = "��";
                                break;
                        case "inside":
                                prep = "��";
                                break;
                        default:
                                prep = "��";
                                break;
                        }
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("%s���У�\n  %s\n", prep,
                        implode(inv, "\n  ") ), me);
        }
        return 1;
}

string getper(object me, object obj)
{
        int per;
        int spi;
        int weight;
        string str;
        per = obj->query_per();
        spi = me->query_spi();
        if (spi>35) weight = 0;
        else weight = (int)(35 - spi)/4 ;
        if (random(10)>6) per = per - weight;
        else per = per + weight ;
                  if ((string) obj->query("gender") == "����" || (string) obj->query("gender") == "����")
        {
                   
                     if (per >=40) 
                        str =HIG"����һ���������ȣ��ɷ���ǣ���ֹ������\n"NOR;
                if (per <= 39 && (per > 38))
                        str =HIG"����������ˬ���Ǹ����棬�������ˡ�\n"NOR;
                if (per <= 38 && (per > 37))
                        str =HIG"���ڷ����ʣ��������������������ٷ硣\n"NOR;
                if (per <= 37 && (per > 36))
                        str =HIG"����Ʈ�ݳ������������ס�\n"NOR;
                if (per <= 36 && (per > 35))
                        str =HIG"�����������񣬷�ױ����������������\n"NOR;
                if (per <= 35 && (per > 34))
                        str =HIG"���ڷ�������Ŀ�����ǣ����˹�Ŀ������\n"NOR;
                if (per <= 34 && (per > 33))
                        str =HIY"���ڷ����촽�����˿��Σ���ֹ�������ޡ�\n"NOR;
                if (per <= 33 && (per > 32))
                        str =HIY"����˫Ŀ���ǣ�ü�Ҵ��飬�������޲�Ϊ֮�Ķ���\n"NOR;
                if (per <= 32 && (per > 31))
                        str =HIY"���ھٶ���������ˮ�����̷��飬������������Ŀ�⡣\n"NOR;
                if (per <= 31 && (per > 30))
                        str =HIY"����˫�۹⻪Ө��͸���������ǵĹ�â��\n"NOR;
                if (per <= 30 && (per > 29))
                        str =HIY"����Ӣ���������������Ρ�\n"NOR;
                if (per <= 29 && (per > 28))
                        str =MAG"����Ŀ�Ƶ��ᣬ�ߴ�ͦ���������Ķ���\n"NOR;
                if (per <= 28 && (per > 27))
                        str =MAG"�����������£�����˹�ģ���ֹ�ʶȡ�\n"NOR;
                if (per <= 27 && (per > 26))
                        str =MAG"���ý�ü��Ŀ��Ӣ�˲������Ǳ�������\n"NOR;
                if (per <= 26 && (per > 25))
                        str =MAG"��������Ũ�ף����۱��ǣ��������ݣ������㵹��\n"NOR;
                if (per <= 25 && (per > 24))
                        str =MAG"����ü��˫�����������ǣ�Ӣͦ���ڡ�\n"NOR;
                if (per <= 24 && (per > 23))
                        str =CYN"���û���������׳��������Ӣ�˲�����\n"NOR;
                if (per <= 23 && (per > 22))
                        str =CYN"���÷�ɫ��𪣬�촽ī����˹������\n"NOR;
                if (per <= 22 && (per > 21))
                        str =CYN"����Ũü���ۣ��ߴ�ͦ�Σ�����������\n"NOR;
                if (per <= 21 && (per > 20))
                        str =CYN"���ñ�ֱ�ڷ��������������Գ������Ը�\n"NOR;
                if (per <= 20 && (per > 19))
                        str =CYN"����üĿ���㣬�����󷽣�һ���˲š�\n"NOR;
                if (per <= 19 && (per > 18))
                        str =YEL"������Բ���������ڷ����Ǹ񲻷���\n"NOR;
                if (per <= 18 && (per > 17))
                        str =YEL"������òƽƽ�������������ʲôӡ�ࡣ\n"NOR;
                if (per <= 17 && (per > 16))
                        str =YEL"���ð����Բ���������⣬���ζ��ࡣ\n"NOR;
                if (per <= 16 && (per > 15))
                        str =YEL"�����ͷ���룬����һ���Ͳ����øС�\n"NOR;
                if (per <= 15 && (per > 14))
                        str =YEL"����������ݣ�����ݹǣ�����Ҫ�����Ρ�\n"NOR;
                if (per <= 14 && (per > 13))
                        str =RED"���÷�ͷ�������Բ��ģ��ֽŶ̴֣����˷�Ц��\n"NOR;
                if (per <= 13 && (per > 12))
                        str =RED"������ü���ۣ��������ߣ�������״��\n"NOR;
                if (per <= 12 && (per > 11))
                        str =RED"���������Ƥ��ͷ�����������˲����ٿ��ڶ��ۡ�\n"NOR;
                if (per <= 11 && (per > 10))
                        str =RED"�����������죬������ף�����ޱȡ�\n"NOR;
                if (per <= 10)
                        str =RED"����ü����б����ͷѢ�ţ�����������\n"NOR;
        }
        else
        {
            if ((string) obj->query("gender") == "Ů��")
            {
                if (per >=40) 
                        str =HIW"�������������ܣ������ƻã��Ѳ����Ƿ�������\n"NOR;
                if (per <= 39 && (per > 38))
                        str =HIG"�����������ɣ���մһ˿�̳���\n"NOR;
                if (per <= 38 && (per > 37))
                        str = HIG"���ڲ�����ϼ���������񣬻����������ӡ�\n"NOR;
                if (per <= 37 && (per > 36))
                        str =HIG"�����������������Ż���ɽ�����˼�֮���ס�\n"NOR;
                if (per <= 36 && (per > 35))
                        str =HIG"���ڷ����۰ף�Ӥ��С�ڣ�üĿ���飬�·�̫�����١�\n"NOR;
                if (per <= 35 && (per > 34))
                        str =HIG"�����������ģ����ȷ�����������Σ��۹�֬�ޡ�\n"NOR;
                if (per <= 34 && (per > 33))
                        str =HIY"�����������ã�ü��ī���������Ұ꣬Ŀ���ﲨ��\n"NOR;
                if (per <= 33 && (per > 32))
                        str =HIY"���ڷ�����ü�����溬�����������ݣ�ת�ζ��顣\n"NOR;
                if (per <= 32 && (per > 31))
                        str =HIY"����üĿ�续������ʤѩ�����ν�����߻���\n"NOR;
                if (per <= 31 && (per > 30))
                        str =HIY"���ڽ����������������£�����ܳ������㡣��\n"NOR;
                if (per <= 30 && (per > 29))
                        str =HIY"�����о���毻���ˮ���ж����������磬��̬��ǧ��\n"NOR;
                if (per <= 29 && (per > 28))
                        str =MAG"���ý�С���磬��������������������ˡ�\n"NOR;
                if (per <= 28 && (per > 27))
                        str =MAG"����Ѽ��������������ü���ڷ����٣��������֡�\n"NOR;
                if (per <= 27 && (per > 26))
                        str =MAG"��������ϸ�����������������Ķ��ˣ�������ɡ�\n"NOR;
                if (per <= 26 && (per > 25))
                        str =MAG"���÷���ϸ������欶��ˣ�����һ�����������ѡ�\n"NOR;
                if (per <= 25 && (per > 24))
                        str =MAG"���÷��۰���������ҩ���̣����￴����\n"NOR;
                if (per <= 24 && (per > 23))
                        str =CYN"������������Ŀ����ˮ��ǧ�����ġ�\n"NOR;
                if (per <= 23 && (per > 22))
                        str =CYN"�����������ģ�����Ө͸��������˼��\n"NOR;
                if (per <= 22 && (per > 21))
                        str =CYN"������Ц��Ȼ����Լ���ˡ�\n"NOR;
                if (per <= 21 && (per > 20))
                        str =CYN"�������滨��¶������������\n"NOR;
                if (per <= 20 && (per > 19))
                        str =CYN"���÷��˳������������ˡ�\n"NOR;
                if (per <= 19 && (per > 18))
                        str =YEL"���ü���΢�ᣬ�ŵ��������¿��ˡ�\n"NOR;
                if (per <= 18 && (per > 17))
                        str =YEL"�����䲻���£���Ҳ�׾�����Щ����֮����\n"NOR;
                if (per <= 17 && (per > 16))
                        str =YEL"����������С�������޹⣬��������\n"NOR;
                if (per <= 16 && (per > 15))
                        str = YEL"���øɻƿ��ݣ���ɫ���ƣ�����Ů��ζ��\n"NOR;
                if (per <= 15 && (per > 14))
                        str =YEL"������������Ƥɫ�ֺڣ���ª������\n"NOR;
                if (per <= 14 && (per > 13))
                        str =RED"����һ�����������һ����û�øС�\n"NOR;
                if (per <= 13 && (per > 12))
                        str =RED"������С�綹��üëϡ�裬�����צ������������\n"NOR;
                if (per <= 12 && (per > 11))
                        str =RED"���ð���ü�������ۣ���Ƥ�Ʒ�������һ�������¡�\n"NOR;
                if (per <= 11 && (per > 10))
                        str =RED"�������б�ۣ���ɫ�Ұܣ�ֱ�����һ�㡣\n"NOR;
                 if (per <=10) 
                        str =RED"���ó������Σ�״��ҹ�棬Ů�˳������������������硣\n"NOR;
         }
    }
        if( !str) str="";
        return str;
}
string gettof(object me, object ob)
{
        object weapon;
        string skill_type,parry_type;
        int attack_points;
		/*����Ϊ�ȼ� by tiandi
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
		*/
        return  tough_level(ob->query("level"));
}
int look_living(object me, object obj)
{
        string str, limb_status, pro;
        mixed *inv;
        mapping my_fam, fam;

        if( me!=obj )
                message("vision", me->name() + "�������㿴����֪����Щʲ�����⡣\n", obj);
        str ="\n"; 
        str += obj->long();
        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
        if( (string)obj->query("race")=="����"
        &&      intp(obj->query("age")) )
                if(userp(obj))
                str +=  sprintf("%s��������%s�����%s�ˡ�\n", pro, chinese_number(obj->query("age") / 10 * 10),
                                obj->query("national"));
                else
                str += sprintf("%s������Լ%s���ꡣ\n", pro, chinese_number(obj->query("age") / 10 * 10));
                str+=getper(me,obj);
                str +=sprintf("�书����������");
                str+=gettof(me,obj);
                str += sprintf("��");
                str +=sprintf("�����ƺ�");
                str +=getdam(me,obj);
                str += sprintf("��\n");
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      mapp(my_fam = me->query("family")) 
        &&      fam["family_name"] == my_fam["family_name"] ) {
        
                if( fam["generation"]==my_fam["generation"] ) {
                        if( (string)obj->query("gender") == "����" )
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                        else
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += pro + "�����ʦ����\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "�����ͬ�ų�����\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += pro + "�����ʦ����\n";
                        else
                                str += pro + "�����ʦ�塣\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "�����ͬ��������\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "����ĵ��ӡ�\n";
                        else
                                str += pro + "�����ʦֶ��\n";
                }
        }
        if(obj->query("prick") )
{
                                str += pro + RED"���Ϻ������һ֦Ѫ����\n"NOR;
}
        if(obj->query("id")==me->query("marry") )
        {
              if( (string)me->query("gender")=="Ů��" )
              {
                    str += sprintf("%s������ɷ�\n", pro);
              }
              else{
                    str += sprintf("%s��������ӡ�\n", pro);
              }
        }
        if (me->query("jiebai"))
        if (strsrch(me->query("jiebai"), obj->query("id")+">") >= 0)
        {
              if( obj->query("gender")=="Ů��" )
              {
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s�������㡣\n", pro);
                    else
                        str += sprintf("%s����Ľ������ӡ�\n", pro);
              }
              else{
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s����Ľ����ֳ���\n", pro);
                    else
                        str += sprintf("%s�������ܡ�\n", pro);
              }
        }

        if( obj->query("max_kee") )
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 / (int)obj->query("max_kee")) + "\n";

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "%s���ϴ�����\n%s\n",
                                pro, implode(inv, "\n") );
        }

        message("vision", str, me);

        if( obj!=me 
        &&      living(obj)
        &&      random((int)obj->query("bellicosity")/10) > (int)me->query_per() ) {
                write( obj->name() + HIR"ͻȻת��ͷ������һ�ۡ�\n"NOR);
                COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;

        str = obj->short();
        if( obj->query("equipped") )
                str = HIC "  ��" NOR + str;
        else if( !flag )
                str = "    " + str;
        else
                return 0;

        return str;
}

int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("����ֻ�л����ɵ�һƬ��ʲ��Ҳû�С�\n");

        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));
                        
                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("��Ҫ��ʲ�᣿\n");
}
string tough_level(int power)
{

        int lvl;
		power -= 1;
        if(power<1) power=0;
        lvl = to_int(power/2);
                        if( lvl >= sizeof(tough_level_desc) )
                                lvl = sizeof(tough_level_desc)-1;
                        return tough_level_desc[((int)lvl)];
}
string getdam(object me, object obj)
{

        int level;
        level = obj->query_temp("apply/damage");
        level = level / 50;
                        if( level >= sizeof(heavy_level_desc) )
                                level = sizeof(heavy_level_desc)-1;
                        return heavy_level_desc[((int)level)];
}
void auto_perform(object me) 
{ 
	object env,gift,gold;
	int reb,exp,ti,pot,score,doubletime,doubletype;
	mapping quest;
         env = environment(me);
	
	quest =  me->query("tiequest");
	//write("start"+env->query("short")+"\n"+quest["quest"]+"\n");
	if (quest && (string)env->query("short") == quest["quest"])
	{
	 	message_vision("\n\n���"+(string)env->query("short") +"�ľ�ɫ�����۵ף������ʱ�泩��������\n",me);
		if ((int) me->query("tiequest_time") < time() )
    		       {
          			 tell_object(me,"�ܿ�ϧ����δ�ܼ�ʱ�������\n");
			return;
    		       }
      		    else
    		      {
 	        tell_object(me,"��ϲ�㣡���������һ����������\n");
	reb = me->query("reborned");
    exp = me->query("level");
	doubletime = me->query("doubletime");
	doubletype = (int)me->query("doubletype");
	ti = me->query_temp("tiejobtemp");
	exp = 100*exp;
	exp = exp + exp/10*ti;
	exp = exp + exp/5*reb;
	//write(exp+"/20000*"+ti);
	if (doubletime - time() > 0)
		exp = exp*(doubletype+1);
	exp = exp / 2;
	pot = exp / 7 * 4;
	score = reb+1;  

	me->add("combat_exp",exp);
	me->add("potential",pot);
    me->add("score",score);
  	tell_object(me,HIW"�㱻�����ˣ�\n" +
	chinese_number(exp) + "��ʵս����\n"+
	chinese_number(pot) + "��Ǳ��\n"+
	chinese_number(score)+"������\n" NOR);
	if (ti==10)
		{
		if ( me->query("level")>89)
				gift=new("/d/wiz/fyup/obj/hongbao5");
		else if ( me->query("level")>79)
				gift=new("/d/wiz/fyup/obj/hongbao4");
		else if ( me->query("level")>69)
				gift=new("/d/wiz/fyup/obj/hongbao3");
		else if ( me->query("level")>59)
				gift=new("/d/wiz/fyup/obj/hongbao2");
		else if ( me->query("level")>49)
				gift=new("/d/wiz/fyup/obj/hongbao1");	
		else gift=new("/d/wiz/fyup/obj/hongbao");
		gift->move(me);
		score = 60 + random(40);
		score = score + score/5*reb;
		gold=new("/obj/money/gold");
	    gold->set_amount(exp/100);
	    gold->move(me);
		me->add("score",score);
		me->add("combat_exp",exp);
		me->add("potential",pot);
  		tell_object(me,HIY"�㱻���⽱���ˣ�\n" +
		chinese_number(exp) + "��ʵս����\n"+
		chinese_number(pot) + "��Ǳ��\n"+
		chinese_number(exp/100) + "���ƽ�\n"+
		chinese_number(score)+"������\n" NOR);
		tell_object(me,HIY"��İ�����������һ�㡣\n"NOR);
		}
	ti ++;
	if (!ti) ti = 1;
	if (ti >10) ti = 1;
	me->set_temp("tiejobtemp", ti );
          me->add("tiejob", 1 );
	me->set("tiequest",0);
		}

	}
	return;
} 
int help (object me)
{
        write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
 
HELP
);
        return 1;
}

