// taolord.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name( "����Ϫ" , ({ "master yu", "master", "yu" }) );
    set("reward_npc", 1);
    set("difficulty", 20); 

        set("gender", "Ů��");
        set("age", 46);
        set("long",
                
"һ��С���۵����֣�\n");

        set("combat_exp", 10000000);
        set("score", 200000);

        set("class", "taoist");

        set("str", 40);
        set("int", 30);
        set("cor", 20);
        set("cps", 30);
        set("spi", 30);

        set("force", 2000);
        set("max_force", 1000);
        set("force_factor", 30);

        set("atman", 1400);
        set("max_atman", 1400);

        set("mana", 4000);
        set("max_mana", 2000);
        set("mana_factor", 5);

        set("apprentice_available", 3);
        create_family("�ɹ���", 1, "Ů����");

        set_skill("literate", 70);
        set_skill("force", 30);
        set_skill("spells", 200);
	set_skill("move", 40);
        set_skill("unarmed", 150);
	set_skill("tenderzhi",150);
        set_skill("sword", 100);
        set_skill("parry", 40);
        set_skill("dodge", 40);

        set_temp("apply/dodge", 200);
        set_temp("apply/armor", 20);

        setup();

        carry_object("obj/cloth")->wear();
}
/*
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say ƶ�������Ѿ������������ӣ���������ͽ�ˡ�");
        }
}

void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
                command("say ƶ���ǳ����ˣ���������ͽ�������ˡ�");
        else {
                command("say ��... �����ɹ��֣�Ҳ��....");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
        add("apprentice_availavble", -1);
}

 
void re_rank(object student)
{
	student->set("title","�ɹ����ֹ�");
                return ;

}
*/