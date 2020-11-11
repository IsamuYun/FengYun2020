// hu.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("胡铁花", ({ "hu tiehua","hu" }) );
	set("gender", "男性" );
	set("age", 35);
	set("title",HIB"无拘无束"NOR);
	set("long",
		"阳光，照着他满脸青惨惨的胡茬子，也照着他脸上那懒洋洋的笑容，
一双又黑又亮的大眼睛, 他就是楚留香最好的朋友胡铁花，又名花疯子。\n");

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

