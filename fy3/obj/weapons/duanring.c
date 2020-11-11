#include <ansi.h>
#include <weapon.h>
inherit RING;
void create()
{
set_name( "���Ƶ�" , ({ "order" }) );
set_weight(3000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "˫");
set("selfmaking",1);
set("timestamp","STAMP");
set("fuct",0);
set("weight",1);
set("weapon_prop/damage",1);
set("enchant",0);
set("base_damage",1);
set("value",1);
set("owner","fengyun");
set("rigidity",400);
set("material", "iron");
set("long", "����");
set("wield_msg", "$N�ó�$n�������ϡ�\n");
set("unwield_msg", "$Nж�������ϵ�$n��\n");
}
init_ring(30);
setup();
}

string query_save_file()
{
        string id;
        id = query("owner");
        if( !stringp(id) ) return 0;
     //   return sprintf(DATA_DIR+ "self/"+query("timestamp")+".c");
		return sprintf(DATA_DIR+"user/" + id[0..0] + "/" + id + "/" +query("timestamp") + ".c");
}

int save()
{
	string file;
	string equipped;
	int result;
	if( stringp(file = this_object()->query_save_file()) ) {
		equipped = (string)query("equipped");
		delete("equipped");
		set("weapon_prop/damage",query("base_damage"));
		assure_file(file+ __SAVE_EXTENSION__);
		result = save_object(file,1);
		set("equipped",equipped);
		return result;
	}
return 0;
}
int restore(){
	string file;
	if( stringp(file = this_object()->query_save_file()) )
	if(restore_object(file))
	 {
		set_weight(query("weight"));
		init_ring(query("base_damage"));
	return 1;
}
return 0;
}
mixed hit_ob(object me,object victim, int damage_bonus)
{
	int dam,fuct;
	string name;
	name = this_object()->query("name");
	fuct= this_object()->query("fuct");
	switch( fuct ) {
	case 93:
		dam = (int) me->query("force");
		victim->receive_damage("kee",dam/8);
		return name + HIC"����������������$n����Ӱ����$n������Ѫ����������\n" NOR;
		break;
	case 92:
		dam = (int) me->query("force");
		victim->receive_damage("gin",dam/8);
		return name +RED"�����ĺ�Х���ŵ�$n�����ɢ������\n" NOR;
		break; 
	case 91:
		dam = (int) me->query("force");
		victim->receive_damage("sen",dam/8);
		return name +HIG"�����ĺ�Х���ŵ�$n������������\n" NOR;
		break; 
	default:
	break;
	}
}

int query_autoload() { return 1; }
