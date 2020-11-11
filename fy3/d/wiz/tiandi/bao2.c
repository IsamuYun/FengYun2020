// bao.c
// by xgchen@zzfy
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_me();
int ask_stop();

void create()
{
        set_name("����ƽ", ({ "lin zhongping", "lin" , "zhongping"}) );
        set("gender", "����" );
        set("age", 54);
        set("long",
                "����Ǵ����������̲����飬������˽���ϰ�����\n");
	 set("max_force", 50000);
        set("force", 50000);
        set("combat_exp", 40000000);
        set("attitude", "friendly");
        set("title", "��͢�̲�����");
        set("nickname", HIW"������˽"NOR);
        set_temp("apply/attack",300);
        set_temp("apply/damage",30000);
        set_skill("dodge", 500);
        set_skill("unarmed",500);
        set_skill("parry", 500);
        set_skill("force",500);
        set_skill("literate", 500);
        set("str", 500);

        setup();
        carry_object(__DIR__"obj/mangpao")->wear();
       add_money("gold",300);
	set("inquiry", ([
		"����": (: ask_me :),
		"����": (: ask_me :),
		"work": (: ask_me :),
		"Ч��": (: ask_me :),
		"quest": (: ask_me :),
		"����": (: ask_stop :),
		"stop": (: ask_stop :),
		]) );
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_answer", "answer");
}
int ask_me()
{
        object ob,me;
        me = this_player();
        if (!(int)me->query("kaifengfu")){
        command("say ��λ"+ RANK_D->query_respect(me)
               + "������Ϊ��͢Ч������������������ﱨ����\n");
        return 1;
         }
        command("say ����Ϊ��͢��Ա�����ܰ׳Թ���ٺ»�����Ŭ������(work)���ǰ���\nÿ�ΰ���������ʵ�򱾸��㱨(finish)��");
        return 1;
}
int ask_stop()
{
        object ob,me;
        me = this_player();
        if(me->query_condition("kf_stop") > 0)
        {
        	return notify_fail("ʲô��\n");
        }
        
        if (!(int)me->query("kf_working")){
        command("say ��λ"+ RANK_D->query_respect(me)
               + "����Ը��Ϊ��͢Ч��������Ҳ����ǿ��\n");
        return 1;
         }
        command("say �����û��ץ���ﷸ��(answer yes��answer no)");
        me->set_temp("kf_stop",1);
        return 1;

}
int do_answer(string arg)
{
        object ob,me;
        me = this_player();
        if (!me->query_temp("kf_stop") || me->query_condition("kf_stop") > 0)
             return notify_fail("ʲô��\n");
        if (!arg || (arg !="yes"&&arg !="no")){
        command("say ���������µ���˵ʲô����\n");
        return 1;
         }
        if (arg =="no")
        {                               //113
        command("say �ﷸ����ץ�����㻹Ҫ����ʲô��\n");
        return 1;
         }
        message_vision (BLU"����ƽ���ɴ�ŭ���İ�����\n"NOR,me);
        command("say �󵨣�����Ϊ��͢��Ա��ʳ����ٺ»�������˲������ݹֱ������顣");
        command("say ���������������ʮ��塣");
        message_vision (HIB"�������ʱӵ�����������ƻ������۽�"+me->query("name")+"�����ڵء�\n"NOR,me);
        me->delete_temp("kf_stop");
        me->add("combat_exp", -1000);
        me->apply_condition("kf_stop", 10+random(10));
        me->set("startroom", base_name(environment(me)));
        return 1;
}
