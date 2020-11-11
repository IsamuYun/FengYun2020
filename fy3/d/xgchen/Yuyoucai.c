#include <ansi.h>
inherit NPC;

string host_id;
void create()
{
	set("title",HIY"Ц�滢"NOR);
	set_name("���в�",({"yuyoucai","yu"}));
	set("gender","����");
	set("age",53);
	set("attitude","friendly");
	set("long","һ��Ц���Ե����ӣ�һ�����Ǹ������ˡ�\n");
	set("inquiry",([
		"jiuxi" : "�ţ�10�����Ӱ�һ�ξ�ϯ���޶��ۡ�",
		"��ϯ"  : "�ţ�10�����Ӱ�һ�ξ�ϯ���޶��ۡ�",
		]));
	setup();
    carry_object("/obj/cloth")->wear();

}
int accept_object(object who,object ob)
{
	object yu;
	string arg;
	int val;
	val=ob->value();
	yu=this_object();
	if ( ob->query("name") == HIR"���"NOR)
	{
		if (ob->query_temp("id_code") != host_id)
		{
			yu->ccommand("say ��������������⣬û�գ�\n");
			return 1;
		}
		else {
			yu->ccommand("say �õģ���ү�����롣\n");
			who->set_temp("guest",1);
			return 1;
		}
	}
	if ( !val)
		return 0;
	if (yu->query_temp("gold_recieved"))
	{
		write("���ϰ��ź���˵���Բ��������Ѿ����¶����ˡ�\n");
		return 0;
	}
	if (val >= 100000)
	{
		yu->ccommand("smile");
		yu->ccommand("say ��֪����үΪʲô�����ϯ����ϲ��������أ�\n");
		write("ָ����ϯ���order <����> gold because <��ϯԭ��>\n");
		who->set_temp("gold_given",1);
		yu->set_temp("gold_recieved",1);
		return 1;
	}
	else
	{	
		yu->ccommand("say ��ô��Ǯ����ʲô����\n");
		return 0;
	}
}
void init()
{
	add_action("do_order","order");
}
int do_order(string arg)
{
	int amount,i;
	object *ob;
	object invitation;
	string reason;
	object who,yu;
	who=this_player();	
	yu=this_object();
	if (who->query_temp("ordered"))
		return notify_fail("���Ѿ�������ϯ�ˡ�\n");
	if ( !(who->query_temp("gold_given")) )
		return notify_fail("ʲ�᣿\n");
	if ( !arg || sscanf(arg,"%d gold because %s",amount,reason) !=2)
		return notify_fail("ָ���ʽ��order <����> gold because <��ϯԭ��>\n");
	if ( amount <= 0)
		return notify_fail("ϲ����������......\n");
	who->set_temp("gold",amount);
	who->set_temp("reason",reason);
	who->set_temp("ordered",1);
	who->set_temp("host",1);
	ob=filter_array(users(),"filter_accept_qingjian",this_object());
	for (i=0;i<sizeof(ob);i++)
	{
		invitation=new("/d/fy/npc/obj/invitation");
		invitation->set("long",
"�𾴵�"+ob[i]->query("name")+":\n"
"    Ϊ����ף"+who->query_temp("reason")+",�����ڿ���־Ƽҿ����ϯ����ӭ����ʱ�μӣ�лл��\n"
"                                                         "+who->query("name")+"����\n"
         );
		invitation->set_temp("id_code",who->query("id"));
		host_id=who->query("id");
		invitation->move(ob[i]);
		tell_object(ob[i],"���յ�һ�����\n");
	}
	yu->ccommand("say ��ү����ϯ���Ͽ�ʼ���Ƚ������Ե�Ƭ�̡�\n");
	who->delete_temp("gold_given");
	yu->ccommand("chat Ϊ��ף"+who->query_temp("reason")+","+who->query("name")+"("+who->query("id")
		+")"+"�ڱ���¥�����ϯ��ϲ��"+chinese_number(who->query_temp("gold"))+"��,���ڿ�ʼ��\n");
	call_out("end_jiuxi",200,who);
	return 1;	 
}
int filter_accept_qingjian(object ppl)
{
	if (!(ppl->query_temp("host")))
	{
		return 1;
	}
	else {
		return 0;
	}
}
int end_jiuxi(object who)
{
	object yu;
	who->delete_temp("host");
	yu=this_object();
	yu->ccommand("chat Ϊ��ף"+who->query_temp("reason")+","+who->query("name")+"("+who->query("id")
		+")"+"�ڱ���¥����ľ�ϯ,���ڽ�������л��λ��������\n");
	yu->delete_temp("gold_recieved");
	who->delete_temp("ordered");
	return 1;
}