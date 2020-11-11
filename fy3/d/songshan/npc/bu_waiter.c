// TIE@FY3
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("��ھ�", ({ "shen bijun","shen" }) );
	set("gender", "Ů��" );
	set("age", 22);
	set("long",
		"�޹�ɽׯ��ׯ���ˣ��򾲼�˼�������ܵ�����������С���⡣\n");
	set("combat_exp", 900000);
	set("attitude", "friendly");
	set("rank_info/respect", "�ϰ���");
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
			say( "��ھ����˸��򸣣�Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "��Ҫ���·���\n");
			break;
		case 1:
			say( "��ھ��ƺ��������������λ" + RANK_D->query_respect(ob)
				+ "�������û������������ʮһ�ɵ���Ϣ��\n");
			break;
		case 2:
			say( "��ھ������ʵ�����λ" + RANK_D->query_respect(ob)
				+ "���þ�û�л��޹�ɽׯ�ˣ���ʲô��Ϣ��\n");

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
        if( !arg ) return notify_fail("��Ҫ��ʲ�᣿\n");
        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("������û�н��ӡ�\n");
        if( !objectp(ob = present(arg, me)) )
        return notify_fail("������û������������\n");
        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
        if( ob->query("equipped") )
        return notify_fail("�㲻�ɲ����ŵ���Ʒ��\n");
        if( !ob->query("armor_prop") )
        return notify_fail("��ֻ�ܲ���������Ʒ��\n");

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
        return notify_fail("������û����" + sprintf("%d",cost)+ "�����ӡ�\n");
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
	message_vision("$N�ù�"+ob->name()+"����ķ첹����������һ��˵�������ˣ�\n",this_object());
        seteuid(getuid());
	return 1;
}

