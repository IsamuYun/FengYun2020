//TIE@FY3
inherit NPC;
#include <ansi.h>;
inherit F_MASTER;
void create()
{
	set_name("����", ({ "master li", "master","li" }) );
    set("reward_npc", 1);
    set("difficulty", 150); 

	set("gender", "����" );
        set("title", "��ɽ������");
	set("age", 25);
	set("int", 30);
	set("per", 30);
        set("apprentice_available", 50);
        create_family("��ɽ��", 3, "����");
	set("long",
		"���������µ�һ���������֮�ӣ�����ӵ��ɽׯ����������Ϊ������Ϊ��ɽ������\n"
		);
        set("force_factor", 20);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_force", 3000);
        set("force", 3000);

        set("combat_exp", 9999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("blade", 150);
        set_skill("force", 100);
        set_skill("move", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("yunwu-strike", 100);
	set_skill("qiusheng-blade", 130);
	set_skill("xianjing", 150);
	set_skill("liuquan-steps", 100);

	map_skill("unarmed", "yunwu-strike");
        map_skill("blade", "qiusheng-blade");
        map_skill("force", "xianjing");
        map_skill("dodge", "liuquan-steps");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "blade.jingsheng" :),
        }) );

	setup();
	carry_object(__DIR__"obj/greencloth")->wear();
        carry_object(__DIR__"obj/yuhuan")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
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
                command("say �����Ž����Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "����" )
          {      command("say ��ֻ���е��ӣ��㻹��ȥ���ҵķ��˰ɣ�");
          }
        else {

                command("smile");
                command("say ��һ��Ҫ�������ɽ�ɵ��书��");
                command("smile");
                command("recruit " + ob->query("id") );
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huangshan");
        add("apprentice_availavble", -1);
}

int accept_fight(object me)
{
	return 0;
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","��ɽ�ɵ���");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","��ɽ��С��");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","��ɽ������");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","��ɽ�ɴ���");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","��ɽ������");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","��ɽ�ɳ���");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","��ɽ��Ԫ��");
                return ;
        } else
                student->set("title","��ɽ�ɸ�����");
                return ;
}
*/
void init()
{
	add_action("do_get","get");
}

int do_get(string arg)
{
string what,where;
if(!arg) return 0;
if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
if((strsrch(what, "cang qiong") != -1 || strsrch(what, "all") != -1) &&
 (strsrch(where, "xiqiang") != -1 || strsrch(where, "��ǽ") != -1 ||
strsrch(where, "west wall") != -1 || strsrch(where, "wall") != -1))
 {
 {message_vision("$N��$n���һ�����󵨣����Ҵ��ȸ���������⣡\n",this_object(),this_player());
 this_object()->kill_ob(this_player());
this_player()->start_busy(2);
return 1;
}
return 0;
}
}
