inherit NPC;
int do_liwu();
#include <ansi.h>

void create()
{
        set("inquiry", ([
                "liwu" : (: do_liwu :),
                ]));
        set_name(HIC"��"HIY"��"HIG"ʹ"HIM"��"NOR, ({ "olympic" }));
        set("long", 
              "����ר�̴ӹ��ʰ�ί�����Ϊ��ҷ�����ģ�\n"
              );
        set("gender", "Ů��" );
        set("age", 60);
        set("con",100); 
        set("dex",100);
        set("max_kee",10000000);
        set("eff_kee",10000000);
        set("kee",10000000);
        set("max_gin",10000000);
        set("eff_gin",10000000);
        set("gin",10000000);
        set("max_sen",10000000);
        set("eff_sen",10000000);
        set("sen",10000000);

        set("per",100);
        set("int",100);
        set("str",2000);
        set("fle",2000);
        set("combat_exp", 2100000000);
        set("attitude", "friendly");
        setup();
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
        switch( random(2) ) {
                case 0:
                        say(HIC"��"HIY"��"HIG"ʹ"HIM"��"NOR"�����˵������λ" + RANK_D->query_respect(ob)
                                + "��ף�ر�����³ɹ���������������ֻ�������һ�ܡ�\n"NOR);
                        break;
        }
}

int do_liwu()
{ 
        object ob,me;
        me = this_player();

        if(me->query("mud_age")<=43200)
        {
        message_vision(HIM"$N˵����������ʱ�仹����ʮ��Сʱ����ȥ���������ɣ�\n"NOR,this_object(), me);
        return 1;
        }
        if(me->query("olympic")==1)
        {
        message_vision(HIM"$N˵�������Ѿ��ù�����˰ɣ���ռ����ѽ��\n"NOR,this_object(), me);
        return 1;
        }
        ob = new("d/wiz/xgchen/bao");
        message_vision(HIR"$N΢Ц����������ף�������2008���������Ȩ�ɹ�!!\n"NOR,this_object(), me);
        me->set("olympic",1);
        ob->move(this_player());
        tell_object(me,HIR"��õ���һ����" + ob->query("name") +"\n"NOR);
       return 1;
} 


