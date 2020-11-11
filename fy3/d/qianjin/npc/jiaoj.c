#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����", ({ "jiaojiao" }) );
	set("title", HIM "���ݾ���" NOR);
	set("gender", "Ů��" );
	set("age", 22);
	set("str", 10);
	set("int", 30);
	set("per", 30);
set("apprentice_available", 50);
        create_family("ǧ��¥", 3, "����");
        set("long",
                "������Ů������\n"
                );
        set("force_factor", 200);
        set("chat_chance", 5);
        set("chat_msg", ({
name()+"�ֹ������森���ҵ�С��������Ҫ����ע���ˣ�\n",
}) );
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

        set("combat_exp", 999999999);
        set_skill("unarmed", 500);
        set_skill("sword", 550);
        set_skill("force", 500);
        set_skill("move", 500);
        set_skill("literate", 500);
        set_skill("dodge", 500);
	  set_skill("perception", 100);
        set_skill("yunwu-strike", 100);
        set_skill("siqi-sword", 120);
        set_skill("xianjing", 150);
        set_skill("liuquan-steps", 100);
        map_skill("unarmed", "yunwu-strike");
        map_skill("sword", "siqi-sword");
        map_skill("force", "xianjing");
        map_skill("dodge", "liuquan-steps");
	set("long", @LONG
���������µ�һ��ˣ������������,��������Ȥ�Ļ����루����������
LONG
);
	set("combat_exp", 1000000);
	set("attitude", "friendly");

	setup();
	carry_object(__DIR__"obj/pink_cloth")->wear();
}

void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say ����������Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
          {      command("say ��ֻ��Ů���ӣ��㻹��ȥ���ҵķ���ɣ�");
          }
        else {

                command("smile");
                command("say ���պ��Ҫ���ǧ��¥Ӵ��");
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
	command("say СŮ��ϲ���ϴ���������,�����Ӯ��,�Ҿ�������...");
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
                student->set("title","ǧ��¥С��");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","ǧ��¥����");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","ǧ��¥����");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","ǧ��¥����");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","ǧ��¥����");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","ǧ��¥Ԫ��");
                return ;
        } else
                student->set("title","ǧ��¥������");
                return ;
}

int accept_object(object me, object obj)
{
        command("grin");
        command("say ��ð���..." + RANK_D->query_respect(me) +
"����һ�����������Ŀ��ĵģ�");
        return 1;
}

void init()
{
	add_action("do_enjoy","enjoy");
}

int do_enjoy()
{
object me;
object wo;
object *inv;
object silk;

int maxgin,maxkee, maxsen;
int i;
	me = this_player();
message_vision("$N��ƮƮ����$n�߹���������ĸ�Ū$n������,������һ�ȣ�����\n",this_object(),me);
	me->unconcious();
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			destruct(inv[i]);
		}
	maxgin = (int)me->query("max_gin");
        maxkee = (int)me->query("max_kee");
        maxsen = (int)me->query("max_sen");
	me->set("eff_gin", maxgin);
	me->set("gin", maxgin);
        me->set("eff_kee", maxkee);
        me->set("kee", maxkee);
        me->set("eff_sen", maxsen);
        me->set("sen", maxsen);
      silk = new("/questnew/obj/hongbao");
silk->move(this_object());
command("give full-hongbao to " + me->query("id"));
add("given",1);
wo = new(__DIR__"obj/wo");
        wo->move(me);
return 1;
}
