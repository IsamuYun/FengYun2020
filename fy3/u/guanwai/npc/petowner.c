#include <ansi.h>
inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg);

void create()
{
        set_name("潇江", ({ "xiaojiang" }) );
        set("gender", "女性" );
        set("age", 22);
        set("long","潇江姓顾，后嫁给一小土财主，财主过世后就开使每天背一个小筐卖（ｙａｎｇ）宠物\n");
        set("combat_exp", 5);
        set("chat_chance", 15);
  //      set("chat_msg", ({
  //              (: random_move :)
   //     }) );
        set("attitude", "friendly");
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{	
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_yang", "yang");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "潇江说道：这位" + RANK_D->query_respect(ob)
                                + "，要买小猫小狗么？\n");
                        break;
                case 1:
                        say( "潇江说道：这位" + RANK_D->query_respect(ob)
                                + "，你太穷酸了，我不卖给你。\n");
                        break;
        }
}

int do_yang(string arg)
{
	string ctype, cname, ccolor, cid;
	object ob, me, gold;
	string id,filename;
	object newpet;
        me = this_player();
	id = me->query("id");
        if(!arg || sscanf(arg,"%s %s %s %s",ctype,ccolor,cname,cid ) != 4)
        return notify_fail("指令格式：yang <type> <color> <name> <english name>\n");
	if(me->is_busy())
	return notify_fail("你上一个动作还没有完成。\n");
	if(file_size( me->query_save_file() + ".pet.o") > 0)
	return notify_fail("你已经拥有你心爱的宠物了。\n");
	gold = present("gold_money", this_player());
    if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < 10000)
        return notify_fail("你身上没有那麽多金子。\n");
	if((int)me->query("score") < 10000)
	return notify_fail("你的评价不够。\n");
	if( !check_legal_name(cname))
	return notify_fail("");
        if( !check_legal_id(cid))
        return notify_fail("");

	if( ccolor != "$BLK$" && 
	    ccolor != "$NOR$" &&
            ccolor != "$RED$" &&
            ccolor != "$GRN$" &&
            ccolor != "$YEL$" &&
            ccolor != "$BLU$" &&
            ccolor != "$MAG$" &&
            ccolor != "$CYN$" &&
            ccolor != "$WHT$" &&
            ccolor != "$NOR$" &&
            ccolor != "$HIR$" &&
            ccolor != "$HIG$" &&
            ccolor != "$HIY$" &&
            ccolor != "$HIB$" &&
            ccolor != "$HIM$" &&
            ccolor != "$HIC$" &&
            ccolor != "$HIW$" 
	)
	return notify_fail("不知你要什么颜色．\n");
	cname = ccolor + cname;
        cname = replace_string(cname, "$BLK$", BLK);
        cname = replace_string(cname, "$RED$", RED);
        cname = replace_string(cname, "$GRN$", GRN);
        cname = replace_string(cname, "$YEL$", YEL);
        cname = replace_string(cname, "$BLU$", BLU);
        cname = replace_string(cname, "$MAG$", MAG);
        cname = replace_string(cname, "$CYN$", CYN);
        cname = replace_string(cname, "$WHT$", WHT);
        cname = replace_string(cname, "$HIR$", HIR);
        cname = replace_string(cname, "$HIG$", HIG);
        cname = replace_string(cname, "$HIY$", HIY);
        cname = replace_string(cname, "$HIB$", HIB);
        cname = replace_string(cname, "$HIM$", HIM);
        cname = replace_string(cname, "$HIC$", HIC);
        cname = replace_string(cname, "$HIW$", HIW);
        cname = replace_string(cname, "$NOR$", NOR);
        cname += NOR;
	seteuid(ROOT_UID);
	newpet = new("/obj/pet");
	newpet->set("is_pet",1);
	switch( ctype ) {
                case "tortoise":
			newpet->set("title","乌龟");
			newpet->set("dur",5+random(10));
			newpet->set("spi",1+random(5));
			newpet->set("str",1+random(5));
			newpet->set("agi",1+random(5));
			newpet->set("con",1+random(5));
			if (!random(10))
			newpet->set_skill("petfangyu",1);
			ctype = "一只乌龟";
                        break;
                case "cat":
		    newpet->set("title","猫咪");
			newpet->set("dur",1+random(5));
			newpet->set("spi",5+random(10));
			newpet->set("str",1+random(5));
			newpet->set("agi",1+random(5));
			newpet->set("con",1+random(5));
			if (!random(10))
			newpet->set_skill("petfire",1);
			ctype = "一只猫咪";
                        break;
                case "pig":
            newpet->set("title","肥猪");
			newpet->set("dur",1+random(5));
			newpet->set("spi",1+random(5));
			newpet->set("str",1+random(5));
			newpet->set("agi",1+random(5));
			newpet->set("con",5+random(10));
			if (!random(10))
			newpet->set_skill("petgedang",1);
			ctype = "一头肥猪";
                        break;
                case "bison":
            newpet->set("title","野牛");
			newpet->set("dur",1+random(5));
			newpet->set("spi",1+random(5));
			newpet->set("str",5+random(10));
			newpet->set("agi",1+random(5));
			newpet->set("con",1+random(5));
			if (!random(10))
			newpet->set_skill("petqiangji",1);
			ctype = "一头野牛";
                        break;
                case "monkey":
            newpet->set("title","猴子");
			newpet->set("dur",1+random(5));
			newpet->set("spi",1+random(5));
			newpet->set("str",1+random(5));
			newpet->set("agi",5+random(10));
			newpet->set("con",1+random(5));
			if (!random(10))
			newpet->set_skill("petbisha",1);
			ctype = "一只猴子";
                        break;
		default:
			return notify_fail("这里没有你要的东西．\n");
	}
	newpet->set("owner",me->query("id"));
	newpet->set("possessed",me);
	newpet->set("name",cname);
	newpet->set("shouming",9999);
	newpet->set("obedience",100);
	newpet->set("id",cid);
	newpet->set("level",1);
	newpet->set("chengzhang",random(20)+20);
	newpet->save();
	ctype = ctype + cname;
	destruct(newpet);
	gold->add_amount(-10000);
	me->add("score",-10000);
    me->start_busy(1);
	command("chat "+ me->query("name") +"从我这里领养了"+ctype+"，"+HIC"可要好好照顾它哦！");
	command("say 好了，你试着吹一声口哨（ｗｈｉｓｔｌｅ），你的小宝宝就会跑过来的！\n");
        seteuid(getuid());
	return 1;
}
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {
                write("对不起，中文名字必须是一到二十个中文字。\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("对不起，中文名字不能用控制字元。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("对不起，名字必需是中文。\n");
                        return 0;
                }
        }
        return 1;
}

int check_legal_id(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 3) || (strlen(name) > 20 ) ) {
                write("对不起，英文名字必须是三到二十个字。\n");
                return 0;
        }

	return 1;
}
