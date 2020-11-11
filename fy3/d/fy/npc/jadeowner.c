
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("������", ({ "seller", "jadeseller" }) );
        set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 20); 

        set("age", 49);
	set("title", "�����鱦");
        set("long", "����һλ�ʷ����ֵ��ƹ�\n");
        set("combat_exp", 700000);
	set("str", 300);
        set("attitude", "friendly");
        	  set_temp("kf_tufei",31);
        set("pursuer", 1);
set_skill("dodge", 100);
        set_skill("parry", 120);
        set("vendor_goods", ([
                __DIR__"obj/jade1":7,
                __DIR__"obj/jade2":7,
                __DIR__"obj/jade3":7,
                __DIR__"obj/jade4":7,
        ]) );

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
        add_action("do_vendor_list", "list");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( " ���ƹ�Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "�������� \n");
                        break;
                case 1:
                        say( " ���ƹ�Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "�����Ǽ���֮���һ��ɡ� \n");
                        break;

        }
}



