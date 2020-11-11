// waiter.c

inherit NPC;
int give_him();
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("����ʯ", ({ "batianshi" }) );
        set("gender", "����" );
        set("age", 81);
        set("title", HIY "����˾��" NOR);
        set("long",
                "���Ǹ����꺺�ӣ�Ŀ���ڴ����λ��˾�ա���\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",30);
        set_skill("unarmed",50);
        set_skill("dodge",50);
        set("inquiry", ([
                "��ҩ" : (: give_him :),
                "wayao" : (: give_him :),
        ]));
        setup();
        //carry_object("/obj/cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N˵���������������ȱ��һЩҩ�ģ�������\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N����$nһ�ۣ��ʵ��������ҩ����Ȥ�𣿣�����\n",this_object(),ob);
                        break;
        }
}
int give_him()
{
        object me , obj;
        me = this_player();
        if( !query("given")) {
        obj = new("/questnew/yaochu");
        message_vision("$N˵������Ȼ�����ҩ����Ȥ���ҾͰ�������Ҫ�Ĺ������������ˣ�
����ʯ����$nһ��ҩ����\n",this_object(), me);
        obj->move(me);
        set("given",1);
        return 1;
        }
        return 0;
}


int accept_object(object who, object ob)
{
  int  exp, pot, gong, score;
        exp = random(200)+100;
        pot = exp / 10 + 1;
        gong = exp / 50 + 2;
        score = exp / 50 +5;
        if(!(who->query("class") == "dali") )
        {
                write("����ʯ˵��:�㲻�Ǵ�����ӣ��������������Ķ����Ҳ�Ҫ��\n");
                return 1;
        }
if(ob->query("name") == "ǧ���˲�")
        {
command("say ��Ϊ���������˹��ף�����Ӧ�õõ�������\n");
        who->add("combat_exp",exp);
        who->add("potential",pot);
        who->add("score",score);
        who->add("gongxian",gong);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
        chinese_number(gong) + "��Դ�����Ĺ��׵�\n"+
        chinese_number(score) + "���ۺ����ۡ�\n" NOR);
        return 1;
        }
if(ob->query("name") == "���ͻ�ɽ")
        {
command("say ��Ϊ���������˹��ף�����Ӧ�õõ�������\n");
        who->add("combat_exp",exp);
        who->add("potential",pot);
        who->add("score",score);
        who->add("gongxian",gong);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
        chinese_number(gong) + "��Դ�����Ĺ��׵�\n"+
        chinese_number(score) + "���ۺ����ۡ�\n" NOR);
        return 1;
        }
if(ob->query("name") == "�����ھ�")
        {
command("say ��Ϊ���������˹��ף�����Ӧ�õõ�������\n");
        who->add("combat_exp",exp);
        who->add("potential",pot);
        who->add("score",score);
        who->add("gongxian",gong);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
        chinese_number(gong) + "��Դ�����Ĺ��׵�\n"+
        chinese_number(score) + "���ۺ����ۡ�\n" NOR);
        return 1;
        }
if(ob->query("name") == "�����")
        {
command("say ��Ϊ���������˹��ף�����Ӧ�õõ�������\n");
        who->add("combat_exp",exp);
        who->add("potential",pot);
        who->add("score",score);
        who->add("gongxian",gong);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
        chinese_number(gong) + "��Դ�����Ĺ��׵�\n"+
        chinese_number(score) + "���ۺ����ۡ�\n" NOR);
        return 1;
        }
        tell_object(who,"����ʯ˵��������������Ҫ���ֿ�֦�ò���\n");
        return 0;
}