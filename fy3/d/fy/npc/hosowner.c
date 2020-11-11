// waiter.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("����", ({ "pusheng" }) );
	set("gender", "����" );
	set("age", 31);
	set("title", GRN "������" NOR);
	set("long",
		"��λ�������ϰ��书��ҽ����տ����������������\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
		  set_temp("kf_tufei",27);
        set("pursuer", 1);
set("per",30);
	set("vendor_goods", ([
                __DIR__"obj/sendrug":12,
                __DIR__"obj/keedrug":22,
                __DIR__"obj/gindrug":12,

	]) );
	set("inquiry", ([ 
			"����" : "ʮ�����±��˿����������(heal)��ʮ�����Ͼ���Ҫ�շ��ˡ�\n" 
	]));

	set_skill("unarmed",50);
	set_skill("dodge",150);
	set_skill("changquan",150);
	map_skill("unarmed", "changquan");
	setup();
	carry_object(__DIR__"obj/fycloth")->wear();
        carry_object("/d/qianjin/npc/obj/chungongtu");
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
	add_action("do_heal", "heal");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(20) ) {
		case 0:
message_vision("$N����$nһ�ۣ�����˵��������Ƽ��ݣ���ˮ���գ��Ƿ񣮣������ȣ�\n",this_object(),ob);
			break;
	}
}
int do_heal()
{
	object me,gold;
	int lv;
	me = this_player();
	lv = me->query("level");
	if (me->query("kee")>= me->query("max_kee")){
		write("��״���ܺã�����Ҫ�������ơ�\n");
		return 1;
	}
	gold = present("gold_money", me);
	if (lv< 10)
	{
	me->set("eff_kee",me->query("max_kee"));
	me->set("kee",me->query("max_kee"));
	me->set("eff_sen",me->query("max_sen"));
	me->set("sen",me->query("max_sen"));
	me->set("eff_gin",me->query("max_gin"));
	me->set("gin",me->query("max_gin"));
		write("�����������ˣ�\n");
		return 1;
	}
	if (!gold)
			return notify_fail("����ֻ�ս���!\n");
	if (gold->query_amount() < lv/10)
			return notify_fail("�����ϵĽ��Ӳ���"+lv/10+"��!\n");
	gold->add_amount(-lv/10);
	me->set("eff_kee",me->query("max_kee"));
	me->set("kee",me->query("max_kee"));
	me->set("eff_sen",me->query("max_sen"));
	me->set("sen",me->query("max_sen"));
	me->set("eff_gin",me->query("max_gin"));
	me->set("gin",me->query("max_gin"));
	write("�����������ˣ�\n");
	return 1;
}

