// hu.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("������", ({ "hu tiehua","hu" }) );
	set("gender", "����" );
	set("age", 35);
	set("title",HIB"�޾�����"NOR);
	set("long",
		"���⣬������������Ҳҵĺ����ӣ�Ҳ�������������������Ц�ݣ�
һ˫�ֺ������Ĵ��۾�, �����ǳ�������õ����Ѻ����������������ӡ�\n");

	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("int",20);
	set("str",30);
	set("con",40);
	set("max_gin",500);	
	set("max_kee",500);	
	set("max_sen",500);	
	set_skill("move",50);

	setup();
	carry_object("/obj/cloth")->wear();
   

}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if(ob) 
        ob->set("marks/killed_hu",1);
        ::die();
}

