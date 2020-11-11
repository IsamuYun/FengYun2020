// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������", ({ "furen" }) );
	set("gender", "����" );
	set("title", HIR "����ʦ" NOR);
	set("age", 52);
		  set_temp("kf_tufei",66);
        set("pursuer", 1);
set("long",
		"�����˱������幬��һ���ϵ�ʿ���˵������������£�
��������˼�����\n");
	set("combat_exp", 50000);
	set("str",200);
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
	add_action("do_ji","ji");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
			say( "������Ц������λ" + RANK_D->query_respect(ob)
				+ "����ı��п���������ҪѪ��һ���ˡ�\n");
			break;
		case 1:
			say( "������˵������λ" + RANK_D->query_respect(ob)
				+ "����ı���ɱ�����㣬��Ѫ��һ�±��аɡ�\n");
			break;
	}
}

int  do_ji(string arg)
{
	object me, ob;
	object gold;
	int cost = 1;
	int i,j,base,current;
	string id,name ;	
	string file,newfile,filestring;
	me = this_player();
	id = me->query("id");
        if( !arg ) return notify_fail("��Ҫ��ʲ��������\n");
        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("������û�н��ӡ�\n");
        if( !objectp(ob = present(arg, me)) )
        return notify_fail("������û������������\n");
        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
        if( !ob->query("weapon_prop") )
        return notify_fail("��ֻ�ܼ��ɵ��������Ķ�����\n");
        if( ob->query("equipped") )
        return notify_fail("�㲻�ɼ�װ�����˵�������\n");
        if( !ob->query("owner") )
        return notify_fail("��ֻ�ɼ��Լ������������\n");
	base= (int)ob->query("base_damage");
	current = (int) ob->query("weapon_prop/damage");
	for(j=1;j<=100;j++)
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
	me->add("bellicosity",cost);
	seteuid(ROOT_UID);
// need to update 3 things: damage, rigidity, and weight
	ob->add("weapon_prop/damage",j);
	ob->set("weight",(int)ob->query("weight")+j*700);
	ob->add("rigidity",j*10);
	ob->save();
	ob->restore();
	if(ob->move(me))	
	message_vision("$N��"+ob->name()+"������һ�ڴ�Ѫ����ĭ��˵�������ˣ�\n",this_object());
        seteuid(getuid());
	return 1;
}
