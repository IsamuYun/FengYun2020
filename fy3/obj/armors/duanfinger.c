#include <ansi.h>
#include <armor.h>
inherit FINGER;   
void create()
{
	set_name( "自制的" , ({ "order" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("selfmaking",1);
		set("timestamp","STAMP");
		set("fuct",1);
		set("weight",1);
		set("rigidity",1);
		set("armor_prop/armor", 1 );
		set("enchant",0);
		set("base_damage",1);
		set("armor_type", "finger");
		set("value",1);
		set("owner","fengyun");
		set("rigidity",400);
		set("material", "iron");
		set("long", "描述");
		set("wear_msg", "$N戴上了一枚$n。\n");
		set("unequip_msg", "$N脱下了手指上的$n。\n");
		}
	setup();
}

string query_save_file()
{
        string id;
        id = query("owner");
        if( !stringp(id) ) return 0;
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
		set("armor_prop/armor",query("base_armor"));
		assure_file(file+ __SAVE_EXTENSION__);
		result = save_object(file,1);
		set("equipped",equipped);
	return result;
	}
return 0;
}
int restore()
{
	string file;
	if( stringp(file = this_object()->query_save_file()) )
		if(restore_object(file))
		{
		set_weight(query("weight"));
		return 1;
		}
return 0;
}
int query_autoload() { return 1; }