// boater.c

inherit NPC;

void create()
{
    set_name("������",({"old boater","boater"}));
    set("long","�����ݱ�������ʴ�����괵�򣬻�����ǧ�������ƣ��Ե���ô˥��
��һ˫�۾���ȴ���������磬����ֻҪһ���ƹ�ȥ���κ��˵����ܣ�ȴ��Ҳ������������\n");
    set("gender","Ů��");
    set("age",62);
    set("no_arrest",1);
    set("int",22);
    set("cor",20);
    set("per",10);
    set("con",20);
    set("cps",20);
    set("agi",20);
    set("gin",1000);
    set("max_gin",1000);
    set("eff_gin",1000);
    set("max_sen",1000);
    set("sen",1000);
    set("eff_sen",1000);
    set("combat_exp",111110);  
    set_skill("force",100);
    set_skill("nine-moon-force",150);
    set("force",1000);
    set("max_force",1000);
    set("force_factor",20);
    map_skill("force","nine-moon-force");
    set("attitude", "friendly");
	set("chat_chance",2);
	set("chat_msg",({
		"��������ѽ��ѽҡ���֡�\n",
    }) );
    setup();
    carry_object("obj/cloth")->wear(); 
    carry_object(__DIR__"obj/changgao")->wield();
    add_money("silver",30);
}

void unconcious()
{
::die();
}
