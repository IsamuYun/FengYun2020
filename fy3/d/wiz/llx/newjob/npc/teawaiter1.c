// tea_waiter.c

inherit NPC;
inherit F_VENDOR;
int do_gongzuo();
int do_lost();
#include <ansi.h>

void create()
{
        set("inquiry", ([
                "����" : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
                "lost" : (: do_lost :),
                "��Ҷ" : "�����ȥ���²��ˣ���������ȴ��������������"
        ]));
        set_name(HIW"Ʒ���ʿ" NOR , ({ "jushi" }) );
        set("gender", "����" );
        set("age", 40);
        set("long",
                "һλ�׷����׵����ߣ���Ʒ���ж���֮����\n");
        set("combat_exp", random(100000)+random(2000000));
        set("attitude", "friendly");
        set("rank_info/respect", "Ʒ���ʿ");
        set("vendor_goods", ([
                "/obj/example/teapot": 10,
                "/obj/example/dumpling": 10,
                "/obj/example/chicken_leg": 20,
        ]) );
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
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "Ʒ���ʿЦ�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "Ʒ���ʿ��ë��Ĩ��Ĩ���ŵ�һ�����ӣ�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
                case 2:
                        say( "Ʒ���ʿ˵������λ" + RANK_D->query_respect(ob)
                                + "�����������Ųɵ��²�Ҷ����! ���㰡!...\n");
                        break;
        }
}

int do_gongzuo()
{ 
    object ob,me;
        
    me = this_player();
    if((me->query("class")) == "dali")
    {
        message_vision("$N˵�����ۣ����Ǵ��������磬������������ĺ���˼�鷳��ѽ��\n",this_object(), me);
        return 1;
    }
    if(me->query("score")<100)
    {
        message_vision("$N������һ�ۣ�˵����ƾʲô���������㣿\n",this_object(), me);
        return 1;
    }
    if(me->query("combat_exp")>400000) 
    {
        message_vision("$N˵������~~  ��Ҫ���Ϸ���Ц�ˣ����������µģ����С�������ͷ�������\n",this_object(), me);
        return 1;
    }
    if(me->query("shou_xincha")==1)
    {
        message_vision("$N�ʵ�����λ" + RANK_D->query_respect(me) + "�Ƿ�������������δ��ɰɣ�\n",this_object(), me);
        return 1;
    }    
    if(me->query("shou_xincha")==2)
    {
        message_vision("$N˵�����Ҳ��Ǹ������Ʊ�����ѵ���������ˣ�\n",this_object(), me);
        return 1;
    }  
    if(me->query("shou_xincha")==0)
    {
        switch(random(6)) //���������������
        { 
        case 0: 
        ob = new(__DIR__"obj/cp1");
        message_vision("$N΢Ц�����ðɣ��������Ͻָ�����ũ����һ���²裬��ȥȡ������\n",this_object(), me);
        me->set("shou_xincha",2);
        ob->move(this_player());
        tell_object(me,"Ʒ���ʿ������һ�Ų�Ʊ��\n");
        break;

        case 1: 
        ob = new(__DIR__"obj/cp2");
        message_vision("$N΢Ц�����ðɣ�����֮�����и�����ũ����һ���²裬��ȥȡ������\n",this_object(), me);
        me->set("shou_xincha",2);
        ob->move(this_player());
        tell_object(me,"Ʒ���ʿ������һ�Ų�Ʊ��\n");
        break;
        
        case 2: 
        ob = new(__DIR__"obj/cp3");
        message_vision("$N΢Ц�����ðɣ��䵱ɽ���¸�����ũ����һ���²裬��ȥȡ������\n",this_object(), me);
        me->set("shou_xincha",2);
        ob->move(this_player());
        tell_object(me,"Ʒ���ʿ������һ�Ų�Ʊ��\n");
        break;

        case 3: 
        ob = new(__DIR__"obj/cp4");
        message_vision("$N΢Ц�����ðɣ������¸�����ũ����һ���²裬��ȥȡ������\n",this_object(), me);
        me->set("shou_xincha",2);
        ob->move(this_player());
        tell_object(me,"Ʒ���ʿ������һ�Ų�Ʊ��\n");
        break;

        case 4: 
        ob = new(__DIR__"obj/cp5");
        message_vision("$N΢Ц�����ðɣ���÷ɽׯ������ũ����һ���²裬��ȥȡ������\n",this_object(), me);
        me->set("shou_xincha",2);
        ob->move(this_player());
        tell_object(me,"Ʒ���ʿ������һ�Ų�Ʊ��\n");
        break;

        case 5: 
        ob = new(__DIR__"obj/cp6");
        message_vision("$N΢Ц�����ðɣ��������߸�����ũ����һ���²裬��ȥȡ������\n",this_object(), me);
        me->set("shou_xincha",2);
        ob->move(this_player());
        tell_object(me,"Ʒ���ʿ������һ�Ų�Ʊ��\n");
        break;
        } 
    }

} 

int accept_object(object me, object ob)
{
    int  exp, pot, score, money;
    object mon;

    me = this_player();
    if((string)ob->query("id")!="xincha")
    {
        return 1;
    }
    if(me->query("shou_xincha")==0)
    {
        message_vision("$N˵�����������������˵�����Ҹ�������ô������ô��\n",this_object(), me);
        return 0;
    }
    if(me->query("shou_xincha")!=2)
    {
        message_vision("$N˵���������Ҽǵú���û������ȥȡ�²裬�㿪ʲô��Ц��\n",this_object(), me);
        return 0;
    }
    if((string)ob->query("id")=="xincha")
    {
        command("say �ã����Ǹ���Ľ�����\n");
        call_out("destroying", 1, this_object(), ob); 
        exp = 100 + random(100);
        pot = exp / 2 + 1;
        score = random(10);
        money = exp / 3 + random(10);
        mon = new("/obj/money/silver");
        mon->set_amount(money);
        mon->move(me);
        me->add("potential", pot); 
        me->add("combat_exp", exp); 
        me->add("score",score);
        tell_object(me, HIY"�㱻�����ˣ�\n" NOR +
        chinese_number(exp) + HIG"��ʵս����\n" NOR +
        chinese_number(pot) + HIC"��Ǳ��\n" NOR +
        chinese_number(score) + HIM"���ۺ�����\n" NOR +
        chinese_number(money) + HIW"������\n" NOR);
        call_out("delete", 1);
        return 1;
    }    
}

int do_lost()
{
    object me;
    me = this_player();
    tell_object(me,"$N�ú��ɻ���������㡣\n");
    if(me->query("shou_xincha")==1)
    {
        message_vision("$N˵�����㶪ʲô������ô��֪����\n",this_object(), me);
        return 1;
    }
    if(me->query("shou_xincha")==2)
    {
        me->add("score", -10);
            if (present("chapiao",me)) destruct(present("chapiao",me));      
        call_out("delete",1);
        message_vision("$N˵�������С�¶��첻�ˣ�������\n",this_object(), me);
        return 1;
    }    
}

int delete()
{
        this_player()->delete("shou_xincha");
        return 1;
}