// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�պ��", ({ "suhong" }) );
	set("gender", "Ů��" );
	set("age", 21);
	set("title", "�ϰ���");
	set("long",
		"��λ�ϰ�����б���ڹ�̨�ߣ�Ц����������㡣\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
		  set_temp("kf_tufei",21);
        set("pursuer", 1);
set("vendor_goods", ([
		__DIR__"obj/yxrs":12,
		__DIR__"obj/cddt":12,
	        __DIR__"obj/frsp":12,
                __DIR__"obj/ssqy":12,
                __DIR__"obj/ylzp":12,
                __DIR__"obj/pwym":12,
                __DIR__"obj/cwgp":12,
                __DIR__"obj/ychz":12,
                __DIR__"obj/jxyz":12,
                __DIR__"obj/zypg":12,
                __DIR__"obj/rxcy":12,
                __DIR__"obj/qcsh":12,
                __DIR__"obj/hyjp":12,
                __DIR__"obj/szpc":12,
                __DIR__"obj/glyc":12,
                __DIR__"obj/xcfs":12,
                __DIR__"obj/cpcy":12,
                __DIR__"obj/gzyq":12,
                __DIR__"obj/qcxr":12,
                __DIR__"obj/jymj":12,
                __DIR__"obj/glxj":12,
                __DIR__"obj/cpdx":12,
                __DIR__"obj/pxhy":12,
                __DIR__"obj/kzmt":12,
                __DIR__"obj/hhdq":12,

	]) );
	set_skill("unarmed",50);
	set_skill("tenderzhi",50);
	set_skill("dodge",50);
	set_skill("stormdance",50);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/pink_cloth")->wear();
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
message_vision("$N�۽Ǻ�Ц��������������$nһ�ۡ�\n",this_object(),ob);
			break;
		case 1:
message_vision("$N����΢�ڣ�¶����֬�����ۣ���$n�������֡�\n",this_object(),ob);
			break;
		case 2:
message_vision("$N����$nһ�ۣ�����������ӣ��С����Ц������\n",this_object(),ob);
			break;
	}
}
