// human.c

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;

mapping *combat_action = ({
	([	"action":		"$N��ȭ����$n��$l",
		"damage_type":	"����",
	]),
	([	"action":		"$N��$n��$lһץ",
		"damage_type":	"ץ��",
	]),
	([	"action":		"$N��$n��$l�ݺݵ�����һ��",
		"damage_type":	"����",
	]),
	([	"action":		"$N����ȭͷ��$n��$l��ȥ",
		"damage_type":	"����",
	]),
	([	"action":		"$N��׼$n��$l�����ӳ�һȭ",
		"damage_type":	"����",
	]),
});

void create()
{
	seteuid(getuid());
	set("unit", "λ");
	set("gender", "����");
	set("can_speak", 1);
	set("attitude", "peaceful");
	set("limbs", ({
		"ͷ��",	"����",	"�ؿ�",	"����",	"���",	"�Ҽ�",	"���",
		"�ұ�",	"����",	"����",	"����",	"С��",	"����",	"����",
		"���",	"�ҽ�", "����", "����", "ǰ��", "��", "ü��",
                "����", "��", "���", "�ҿ�", "����", "����", "����",
		"���", "�Ҽ�"
	}) );
}

void setup_human(object ob)
{
	mapping my;
	int j,exp,i;
	j = 2000;
	exp = ob->query("combat_exp");


	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));

        if( undefinedp(my["national"]) ) my["national"] = "����";

//by tiandi add level to NPC
	if (!ob->query("level"))
		{
		for(i=0;exp>j;i++)
			{
			j=j+j/9;
			exp-= j;
			}
		if (i <1) i =1;
		ob->set("level",i);
		}


	if( undefinedp(my["age"]) ) my["age"] = random(30) + 10;
	if( undefinedp(my["str"]) ) my["str"] = random(20)  + 6*i;
	if( undefinedp(my["cor"]) ) my["cor"] = random(20) + 6*i;
	if( undefinedp(my["int"]) ) my["int"] = random(20) + 6*i;
	if( undefinedp(my["spi"]) ) my["spi"] = random(20) + 6*i;
	if( undefinedp(my["cps"]) ) my["cps"] = random(20)  + 6*i;
	if( undefinedp(my["per"]) ) my["per"] = random(20) + 6*i;
	if( undefinedp(my["con"]) ) my["con"] = random(20) + 6*i;
	if( undefinedp(my["kar"]) ) my["kar"] = random(20) + 6*i;
        if( undefinedp(my["agi"]) ) my["agi"] = random(20) + 6*i;
        if( undefinedp(my["dur"]) ) my["dur"] = random(20)  + 6*i;
        if( undefinedp(my["fle"]) ) my["fle"] = random(20)  + 6*i;
        if( undefinedp(my["tol"]) ) my["tol"] = random(20)  + 6*i;


	if( userp(ob) || undefinedp(my["max_gin"]) ) {
		if (my["national"] == "����") my["max_gin"] = 200 + my["spi"]*13 ;
		else if (my["national"] == "����") my["max_gin"] = 200 + my["spi"]*15 ;
		else if (my["national"] == "����") my["max_gin"] = 200 + my["spi"]*10 ;
		else if (my["national"] == "�ɹ���") my["max_gin"] = 200 + my["spi"]*6 ;
		else if (my["national"] == "����") my["max_gin"] = 200 + my["spi"]*12 ;
		else if (my["national"] == "����") my["max_gin"] = 200 + my["spi"]*12 ;
		else my["max_gin"] = 70  + my["spi"]*10;
		if( my["max_atman"] > 0 ) my["max_gin"] += my["max_atman"] ;
//by tiandi cut dur
//		my["max_gin"] += my["dur"]*my["dur"];
	}
	if( userp(ob) || undefinedp(my["max_kee"]) ) {
		if (my["national"] == "����") my["max_kee"] = 200 + my["con"]*14 ;
		else if (my["national"] == "����") my["max_kee"] = 200 + my["con"]*6 ;
		else if (my["national"] == "����") my["max_kee"] = 200 + my["con"]*15 ;
		else if (my["national"] =="�ɹ���") my["max_kee"] = 200 + my["con"]*10 ;
		else if (my["national"] == "����") my["max_kee"] = 200 + my["con"]*11 ;
		else if (my["national"] == "����") my["max_kee"] = 200 + my["con"]*11 ;
		if( my["max_force"] > 0 ) my["max_kee"] += my["max_force"] ;
//		my["max_kee"] += my["dur"]*my["dur"];
	}
	if( userp(ob) || undefinedp(my["max_sen"]) ) {
		if (my["national"] == "����") my["max_sen"] = 200 + my["int"]*11 ;
		else if (my["national"] == "����") my["max_sen"] = 200 + my["int"]*10 ;
		else if (my["national"] == "����") my["max_sen"] = 200 + my["int"]*12 ;
		else if (my["national"] == "�ɹ���") my["max_sen"] = 200 + my["int"]*8 ;
		else if (my["national"] == "����") my["max_sen"] = 200 + my["int"]*11;
		else if (my["national"] == "����") my["max_sen"] = 200 + my["int"]*15 ;
		if( my["max_mana"] > 0 ) my["max_sen"] += my["max_mana"] ;
//		my["max_sen"] += my["dur"]*my["dur"];
	}

//update by tiandi for reborned player
	if (ob->query("rebb"))
		{
		my["max_gin"] += my["max_gin"]*(2*ob->query("reborned")-1);
		my["max_kee"] += my["max_kee"]*(2*ob->query("reborned")-1);
		my["max_sen"] += my["max_sen"]*(2*ob->query("reborned")-1);
		}
	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 200);
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
