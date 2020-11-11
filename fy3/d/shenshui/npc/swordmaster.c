// copy to /d/shenshui/npc/swordmaster.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("������", ({ "master bai", "master", "baisankong" }) );
        set("nickname", HIY"��ƽ����"NOR);
        set("gender", "����" );
        set("age", 54);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 20);
	set("attitude","peaceful");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 3);
        set("long",
"

\n"
	);
        create_family("��ƽɽׯ", 1, "ׯ��");

        set("combat_exp", 10000000);
        set("score", 200000);
        set("chat_chance", 10);
        set("chat_msg", ({
	"������ҡͷ̾��������ƽɽׯ������ϣ��˶�˥����������\n"	
        }) );

        set_skill("move", 100);
        set_skill("parry", 100);
        set_skill("dodge", 120);
        set_skill("force", 100);
	set_skill("unarmed", 80);
	set_skill("bai-quan",80);
        set_skill("literate", 100);
	set_skill("sword",130);
	set_skill("qingpingsword",150);
        set_skill("qingpingforce",120);
        set_skill("chaos-steps",120);
	map_skill("force", "qingpingforce");
	map_skill("parry","qingpingsword");
        map_skill("sword","qingpingsword");
        map_skill("dodge","chaos-steps");
        map_skill("move","chaos-steps"); 
     	map_skill("unarmed","bai-quan"); 
        set("inquiry", ([
"������": "�����˵��书��ͬѰ������ԭ����Ψ����ɫ���������п���ʤ����
��ϧ����������������������Ը�������һ���𣿣�answer��\n",
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/longsword")->wield();
carry_object(__DIR__"obj/kuzhi");
}
void init()
{
        object          me;
        add_action("do_answer","answer");
        ::init();
        if( interactive(me = this_player()) && !is_fighting() && !random(5)) {
                add_action("do_accept", "accept");
                call_out("greeting", 1, me);
        }

}
int greeting(object me)
{
if(me->query("gender") == "Ů��")
message_vision(HIY "\n$N��$n˵������Ը��������ҵ���Ů�𣿣�accept yes/no��\n" NOR,
this_object(), me);
else
message_vision(HIY "\n$N��$n˵������Ը��������ҵ������𣿣�accept yes/no��\n" NOR, 
this_object(), me);
        return 1;
}
/*
void attempt_apprentice(object me)
{
	command("smile");
        command("recruit " + me->query("id") );

}
*/
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","��ƽɽׯ��ͯ");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","��ƽɽׯ��ͯ");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","��ƽɽׯ����");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","��ƽɽׯ����");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","��ƽɽׯ��ʿ");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","��ƽɽׯ��ʿ");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","��ƽɽׯ��ʿ");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","��ƽɽׯ����");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","��ƽɽׯ����");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","��ƽɽׯ����");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","��ƽɽׯ����");
                return ;
        } else
                student->set("title","��ƽɽׯ����");
                return ;
}

int do_accept(string arg)
{
	string name;
        if( arg != "yes" &&  arg != "no") 
                return notify_fail("��Ҫ����ʲô��\n");
        if( arg == "yes") {
	name = (string) this_player()->query("name");
	name = "��"+name[2..];
	this_player()->set("name",name);
	this_player()->save();
        message_vision( HIY "$N˵�����ã����Ժ�ͽУ�"+this_player()->query("name")+"�������Ǿ���һ�����ˣ�\n" NOR, this_object());
        this_player()->set("marks/�׼���", 1);
        }
        else 
	command("sigh");
	return 1;
}
int do_answer(string arg)
{
        object shuzhi, me;
	me = this_player();  
        if(arg == "Ը��" ) {		
	if( shuzhi = present("kuzhi", this_object())) {     
        command("say �ã�����ɫ��\n");
        command("say ��ΰ��������µĿ�֦������ȥ�����ºһ�������ͻ������ˡ�\n");
        shuzhi->move(me);
        return 1;
        }
        say("������˵������λ" + RANK_D->query_respect(me) +
		",�Ѿ�����ȥ�ˣ��������ˡ�\n");
        return 1;
        }
        return 1;
}
