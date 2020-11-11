// waiter.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�ӻ�����", ({ "trader" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ����һ�����Ǽ�թ�ƻ������ӡ�\n");
	set("combat_exp", 500000);
         set("attitude", "friendly");
	set("rank_info/respect", "�ϰ�");
	set("vendor_goods", ([
		"/d/wiz/fyup/obj/qh1" : 10,
		"/d/wiz/fyup/obj/sheet" : 30,
		"/obj/glass" : 50,          
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
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
                        say( "\n�ӻ�����Ц�����˵������λ" + RANK_D->query_respect(ob)
    + "�����˵����Ķ���һ������ֵ�����ŵػ��������ưɡ�\n");
			break;
		case 1:
			say( "\n�ӻ�����˵���������ʯȱ��������ô��źð���\n");
			break;
	}
}