//QCed and Modified by Tie
#include <ansi.h>
inherit NPC;  
inherit F_VENDOR;
int tell_test();

void create()
{
        set_name("С��", ({ "xiaofan" }) );
        set("gender", "����");
        set("age", 22);
	set("long",
		"��С���������Ÿ����ӣ��������Ÿ��ƺ�������ϵ��ͭ�壬��ס�������졣\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ([
		"/obj/example/wineskin":10,
		"/obj/example/dumpling":10,
		"/obj/example/chicken_leg":10,
	]) ); 
        set("inquiry", ([
                "����" : (: tell_test :),
		"beauty" : (: tell_test :),
		"leaf" : (: tell_test :),
		"��Ҷ" : (: tell_test :)
        ]) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "С��������˵���ղ���λ���˸���һƬ��Ҷ��˵Ҫ����ʮ�������ġ�\n"
        }) ); 
        setup(); 
	carry_object("/obj/cloth")->wear();
	
}

void init()
{
       ::init();
	if(interactive(this_player()) && !is_fighting()) {
		call_out("greeting", 1, this_player());
	}
	add_action("do_vendor_list", "list");
}      

int tell_test()
{
	object	me;

	me = this_player();
		
		command( "say ����������Ϊ���������������߹���");
		command( "say ����һλ����˵Ҫ�ҵ���·�ϣ�");
		command( "say �����Ƽ�����������·����û��һ�����ǰ�����߹�");
		command( "say �ҾͿ���Ƭ��Ҷ������������ʮ�����ӡ�");

	return 1;
}

int greeting(object me)
{

		message_vision(HIR "\nС����������:ţ�⣬���ơ�\n" NOR, this_object());

	
	return 1;
}

int accept_object(object me, object obj)
{
	object pai;
if( (int) obj->value() >= (500000) && me->query_temp("mark/����") )
	{
        command("smile");
	pai = new(__DIR__"obj/shuye");
	if(pai)
	pai->move(me);
        message_vision("$N�ó���Ҷ��$n��\n",this_object(),me);
        me->set_temp("mark/����", 0);
	return 1;	
	}

else
        {
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
"��С����������밲�ˡ�");
        return 1;
        }
}
