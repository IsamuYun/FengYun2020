// waiter.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("��С��", ({ "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 5);
		  set_temp("kf_tufei",64);
        set("pursuer", 1);
set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ([
		"/obj/example/wineskin" : 10,
		"/obj/example/dumpling" : 30,
      	"/obj/example/chicken_leg" : 40
		]) );
	set("inquiry", ([ 
			"go" : "С�����ں͸�����վ�������¿���վ����ʮ���������ʹ�á�\n" 
		]));
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
	switch( random(3) ) {
		case 0:
                        say( "\n��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
    + "����ӭ������������ϣ��������Ŀ��ġ�\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                  + "������Ҫ��ʲô��\n");
			break;
		case 2:
			say( "��С��˵������λ" + RANK_D->query_respect(ob)
        + "������ûʲô����Ϣ����\n");
			break;
	}
}
