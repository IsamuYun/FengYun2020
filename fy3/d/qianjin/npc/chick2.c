#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���", ({ "girl" }) );
	set("title", HIM "��������" NOR);
	set("gender", "Ů��" );
	set("age", 22);
	set("str", 10);
	set("per", 30);
	set("long", @LONG
����Ƿ��Ƴǵ����ˣ���������Ȥ�Ļ����루����������
LONG
);
	set("combat_exp", 10);
	set("attitude", "friendly");

	setup();
	carry_object(__DIR__"obj/pink_cloth")->wear();
}

int accept_fight(object me)
{
	command("say СŮ�����������Ķ��֣�");
	return 0;
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
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
int maxgin,maxkee, maxsen;
int i;
	me = this_player();
message_vision("$N��ƮƮ����$n�߹���������ĸ�Ū$n�ĺڷ�������\n",this_object(),me);
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
        wo = new(__DIR__"obj/wo");
        wo->move(me);
	return 1;
}
