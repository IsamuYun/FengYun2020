inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
	set_name(HIY "�������" NOR, ({ "master dadi", "master", "dadi" }) );
	set("reward_npc", 1);
	set("gender", "����");
	set("age", 99);
	set("long",
"������۸����ߣ���ò������֣���������һ�㡣\n");

	set("str", 160);
	set("cor", 30);
	set("int", 60);
	set("dur", 60);
	set("spi", 64);
set("dur", 200);
	set("cps", 130);
	set("force", 40000000);
	set("max_force", 80000);
	set("force_factor", 400);
	set("combat_exp", 10000000);
	set("score", 200000);
	set_skill("unarmed", 120);
	set_skill("force", 100);
	set_skill("iron-cloth", 100);
        set_skill("yiqiforce", 80);
        set_skill("literate",180);
        set_skill("incarnation",320);
	set_skill("dodge",100);
	set_temp("apply/attack",300);
	set_temp("apply/damage",3000);
	map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce");
	set("no_shown",1);
	create_family("������", 1, "��ʦ");
	setup();
	carry_object("/u/baimiao/npc/obj/shengzhu");
}
int accept_fight(object me)
{
        return 0;
}
/*
void attempt_apprentice(object me)
{
        command("recruit " + me->query("id") );
                return;
}
*/
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xianren");
}
void init()
{
add_action("do_look","look");
}

int do_look(string arg)
{

if (arg == "master dadi" || arg == "dadi" || arg =="master")
{
write("������۸����ߣ���ò������֣���������һ�㡣\n");
return 1;
}
return 0;
}


void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 320000 ) {
                student->set("title","����");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","����");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","����");
                return ;
        } else
                student->set("title","���޽���");
                return ;

}

