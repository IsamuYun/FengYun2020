// farmer.c
inherit NPC;
#include <ansi.h>

void create()
{       
        set_name(HIG"��ũ"NOR, ({ "farmer" }) );
        set("gender", "����" );
        set("age", 33);
        set("long", "һλ�Ը��ֲ�ҶΪ����ũ�����ų��صĲ�������������ĺ�ˮ�Ӳ�԰�л�����\n");
        set("combat_exp", 20);
        set("attitude", "friendly");
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_msg_combat", ({
                "ũ��е���ɱ���ģ�ɱ���ģ�\n",
                "ũ��е����������ģ����컯���´���ģ�\n",
                (: command, "surrender" :),
        }) );
        setup();
/*      carry_object(__DIR__"obj/raincoat")->wear();
        carry_object(__DIR__"obj/sandals")->wear();*/
        add_money("coin", 20);
}
int accept_object(object me, object ob)
{
    me = this_player();
    if(me->query("shou_xincha")==0)
    {
        write("ũ��˵�����ⲻ�����Լ�Ҫ���Ĳ�Ʊ�ɣ���û���ˣ�\n");
        call_out("destroying", 1, this_object(), ob);
        return 1;
    }
    if((string)ob->query("name")==YEL"���߲�Ʊ" NOR)
    {
        if(me->query("shou_xincha")==1)
        {
            command("say �õģ����Ǹ����Ƴǲ販ʿ���²裡\n");
        call_out("destroying", 1, this_object(), ob); 
        ob = new(__DIR__"obj/xcf");
        ob->move(me);
        tell_object(me,"ũ�������һ����²衣\n");
        return 1;
        }
        else if(me->query("shou_xincha")==2)
        {
            command("say �õģ����Ǹ������Ʒ���ʿ���²裡\n");        
        call_out("destroying", 1, this_object(), ob); 
        ob = new(__DIR__"obj/xcf1");
        ob->move(me);
        tell_object(me,"ũ�������һ����²衣\n");
        return 1;
        }
    }
    command("say �������������Ĳ�Ʊ�ɣ�\n");
}
