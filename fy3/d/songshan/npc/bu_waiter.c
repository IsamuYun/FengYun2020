// TIE@FY3
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("沈壁君", ({ "shen bijun","shen" }) );
	set("gender", "女性" );
	set("age", 22);
	set("long",
		"无垢山庄的庄夫人，因静极思动，就跑到这里来做点小生意。\n");
	set("combat_exp", 900000);
	set("attitude", "friendly");
	set("rank_info/respect", "老板娘");
	set("vendor_goods", ([
		__DIR__"obj/bu1" : 10,
		__DIR__"obj/bu2" : 30,
		__DIR__"obj/bu3" : 10,
		__DIR__"obj/bu4" : 5,
	]) );
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
       add_action("do_bu","bu");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "沈壁君道了个万福，笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，要补衣服吗？\n");
			break;
		case 1:
			say( "沈壁君似乎自言自语道：这位" + RANK_D->query_respect(ob)
				+ "，最近有没有听到关于萧十一郎的消息？\n");
			break;
		case 2:
			say( "沈壁君向你问道：这位" + RANK_D->query_respect(ob)
				+ "，好久没有回无垢山庄了，有什么消息吗？\n");

			break;
	}
}

int  do_bu(string arg)
{
	object me, ob;
	object gold;
	int cost = 1;
	int i,j,base,current;
	string id,name ;	
	string file,newfile,filestring;
	me = this_player();
	id = me->query("id");
        if( !arg ) return notify_fail("你要补什麽？\n");
        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("你身上没有金子。\n");
        if( !objectp(ob = present(arg, me)) )
        return notify_fail("你身上没有这样东西。\n");
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
        if( ob->query("equipped") )
        return notify_fail("你不可补穿着的物品。\n");
        if( !ob->query("armor_prop") )
        return notify_fail("你只能补穿着类物品。\n");

         base= (int)ob->query("base_damage");
	current = (int) ob->query("armor_prop/damage");
     
	for(j=1;j<=500;j++)
	{
		base = base + j;
		if(base >= current) break;
	}
	for(i=1; i<=j;i++)
			cost = cost * 2;
        if((int) gold->query_amount() < cost)
        return notify_fail("你身上没带够" + sprintf("%d",cost)+ "两金子。\n");
        gold->add_amount(-cost);
        me->start_busy(1);
	seteuid(ROOT_UID);
// need to update 3 things: damage, rigidity, and weight
	ob->add("armor_prop/damage",j);
       ob->add("armor_prop/armor",j);
	ob->set("weight",(int)ob->query("weight")+j*2);
	ob->add("rigidity",j*10);
	ob->save();
	ob->restore();
	if(ob->move(me))	
	message_vision("$N拿过"+ob->name()+"认真的缝补起来，过了一会说道：好了！\n",this_object());
        seteuid(getuid());
	return 1;
}

