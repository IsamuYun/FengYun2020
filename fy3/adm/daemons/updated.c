// updated.c

#define f_price "/obj/prize/f_p.c"
#define s_price "/obj/prize/s_p.c"
#define t_price "/obj/prize/t_p.c"
void checkrace(object ob);
void loadall(object me);
void create() { seteuid(getuid()); }
void check_user(object ob)
{
	mapping my;
	int lv;
	lv = ob->query("level");
//	checkrace(ob);
	if( !ob->query_temp("already_loaded"))
	{
	loadall(ob);
	}
	
	ob->delete("env/invisibility");
	my = ob->query_entire_dbase();
	if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
	if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
	if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];
	if( my["eff_gin"] > my["max_gin"] ) my["eff_gin"] = my["max_gin"];
	if( my["eff_kee"] > my["max_kee"] ) my["eff_kee"] = my["max_kee"];
	if( my["eff_sen"] > my["max_sen"] ) my["eff_sen"] = my["max_sen"];
	if( my["gin"] > my["eff_gin"] ) my["gin"] = my["eff_gin"];
	if( my["kee"] > my["eff_kee"] ) my["kee"] = my["eff_kee"];
	if( my["sen"] > my["eff_sen"] ) my["sen"] = my["eff_sen"];
//by tiandiȥ������ӵ�	
//	if( !( my["age"] % 5 ) && my["age"] <=55 ) my["gift_points"] = my["age"] - 5;
// by tiandi,Ǯׯ������ȼ��ҹ���1���ܴ�500�ƽ�
        if( my["deposit"] > lv * 5000000)	{
		write("Ǯׯ�������ޣ�ϵͳ�Զ��۳�������ʧ��"
		+ chinese_number(my["deposit"]- lv*5000000) +"��Ǯ��\n");
		my["deposit"] = lv* 5000000;
	}
}
void checkrace(object ob)
{
	object reward;
	int title_race;
	title_race = (int) ob->query("title_race");
	if (title_race == 1)
	{
		reward = new(f_price);
		reward->move(ob);
		ob->set("title_race", -1);
	}
        if (title_race == 2)
        {
                reward = new(s_price);
                reward->move(ob);
                ob->set("title_race", -2);
        }
        if (title_race == 3)
        {
                reward = new(t_price);
                reward->move(ob);
                ob->set("title_race", -3);
        }






return;
}

void loadall(object me)
{
	int MAX = 3;
	string name,id, *created;
	int j;
	object thing;
	id = me->query("id");
	created = get_dir(DATA_DIR + "login/" + id[0..0] + "/" + id + "/");
	write("\n\n");
	for(j=0; (j<sizeof(created) && j < (MAX+1) ); j++) 
	if( sscanf(created[j], "%s.c", name) == 1 )
		{
			thing = new( DATA_DIR + "login/" + id[0..0] + "/" + id + "/" + name + ".c");
			write( thing->name() + "\n");
			if(thing->move(me))  write("�ϣˣ�\n\n");
			thing->restore();
		}		
	me->set_temp("already_loaded",1);
}
