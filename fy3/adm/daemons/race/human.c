// human.c

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;

mapping *combat_action = ({
	([	"action":		"$N»ÓÈ­¹¥»÷$nµÄ$l",
		"damage_type":	"ðöÉË",
	]),
	([	"action":		"$NÍù$nµÄ$lÒ»×¥",
		"damage_type":	"×¥ÉË",
	]),
	([	"action":		"$NÍù$nµÄ$lºÝºÝµØÌßÁËÒ»½Å",
		"damage_type":	"ðöÉË",
	]),
	([	"action":		"$NÌáÆðÈ­Í·Íù$nµÄ$l´·È¥",
		"damage_type":	"ðöÉË",
	]),
	([	"action":		"$N¶Ô×¼$nµÄ$lÓÃÁ¦»Ó³öÒ»È­",
		"damage_type":	"ðöÉË",
	]),
});

void create()
{
	seteuid(getuid());
	set("unit", "Î»");
	set("gender", "ÄÐÐÔ");
	set("can_speak", 1);
	set("attitude", "peaceful");
	set("limbs", ({
		"Í·²¿",	"¾±²¿",	"ÐØ¿Ú",	"ááÐÄ",	"×ó¼ç",	"ÓÒ¼ç",	"×ó±Û",
		"ÓÒ±Û",	"×óÊÖ",	"ÓÒÊÖ",	"Ñü¼ä",	"Ð¡¸¹",	"×óÍÈ",	"ÓÒÍÈ",
		"×ó½Å",	"ÓÒ½Å", "×óÀß", "ÓÒÀß", "Ç°ÐØ", "ºó±³", "Ã¼ÐÄ",
                "ºóÑü", "ºó¾±", "×ó¿è", "ÓÒ¿è", "ºóÄÔ", "×óÑÛ", "ÓÒÑÛ",
		"×ó¼Õ", "ÓÒ¼Õ"
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

        if( undefinedp(my["national"]) ) my["national"] = "ºº×å";

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
		if (my["national"] == "ºº×å") my["max_gin"] = 200 + my["spi"]*13 ;
		else if (my["national"] == "Ãç×å") my["max_gin"] = 200 + my["spi"]*15 ;
		else if (my["national"] == "Âú×å") my["max_gin"] = 200 + my["spi"]*10 ;
		else if (my["national"] == "ÃÉ¹Å×å") my["max_gin"] = 200 + my["spi"]*6 ;
		else if (my["national"] == "°××å") my["max_gin"] = 200 + my["spi"]*12 ;
		else if (my["national"] == "²Ø×å") my["max_gin"] = 200 + my["spi"]*12 ;
		else my["max_gin"] = 70  + my["spi"]*10;
		if( my["max_atman"] > 0 ) my["max_gin"] += my["max_atman"] ;
//by tiandi cut dur
//		my["max_gin"] += my["dur"]*my["dur"];
	}
	if( userp(ob) || undefinedp(my["max_kee"]) ) {
		if (my["national"] == "ºº×å") my["max_kee"] = 200 + my["con"]*14 ;
		else if (my["national"] == "Ãç×å") my["max_kee"] = 200 + my["con"]*6 ;
		else if (my["national"] == "Âú×å") my["max_kee"] = 200 + my["con"]*15 ;
		else if (my["national"] =="ÃÉ¹Å×å") my["max_kee"] = 200 + my["con"]*10 ;
		else if (my["national"] == "°××å") my["max_kee"] = 200 + my["con"]*11 ;
		else if (my["national"] == "²Ø×å") my["max_kee"] = 200 + my["con"]*11 ;
		if( my["max_force"] > 0 ) my["max_kee"] += my["max_force"] ;
//		my["max_kee"] += my["dur"]*my["dur"];
	}
	if( userp(ob) || undefinedp(my["max_sen"]) ) {
		if (my["national"] == "ºº×å") my["max_sen"] = 200 + my["int"]*11 ;
		else if (my["national"] == "Ãç×å") my["max_sen"] = 200 + my["int"]*10 ;
		else if (my["national"] == "Âú×å") my["max_sen"] = 200 + my["int"]*12 ;
		else if (my["national"] == "ÃÉ¹Å×å") my["max_sen"] = 200 + my["int"]*8 ;
		else if (my["national"] == "°××å") my["max_sen"] = 200 + my["int"]*11;
		else if (my["national"] == "²Ø×å") my["max_sen"] = 200 + my["int"]*15 ;
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
