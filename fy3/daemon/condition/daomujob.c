#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    object obj,ob2,place;
	int i;
	string arg;
	me = this_player();	
	arg = me->query("name")+"�ĵ�Ĺ��";
	place = environment(me);

	ob2 = present("daomu ren",place);
	me->apply_condition("daomujob", duration - 1);

	if (duration <1)
		return 0;

	if (ob2)
	{
		if (ob2->query("name") == me->query("name") +"�������õĵ�Ĺ��" )
				return 1;
	}
		if (duration %3 == 0)
		{

	 if (place->query("short") == "������" && me->query_temp("daomu") == 3)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/d/taishan/nantian");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"�������õĵ�Ĺ��");
		message_vision("��֪�����ִ���һ��Ĺ�ߡ�\n",obj);
		return 1;
	}
	 if (place->query("short") == "������" && me->query_temp("daomu") == 1)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/d/xj/zhenlong");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"�������õĵ�Ĺ��");
		message_vision("��֪�����ִ���һ��Ĺ�ߡ�\n",obj);
		return 1;
	}
	 if (place->query("short") == "�·����" && me->query_temp("daomu") == 2)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/d/bat/ren3");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"�������õĵ�Ĺ��");
		message_vision("��֪�����ִ���һ��Ĺ�ߡ�\n",obj);
		return 1;
	}
	if (place->query("short") == "ӭ÷��ջ" && me->query_temp("daomu") == 4)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/u/guanwai/inn");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"�������õĵ�Ĺ��");
		message_vision("��֪�����ִ���һ��Ĺ�ߡ�\n",obj);
		return 1;
	}
	 if (place->query("short") == "������" && me->query_temp("daomu") == 5)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/u/wudang/zhixiao");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"�������õĵ�Ĺ��");
		message_vision("��֪�����ִ���һ��Ĺ�ߡ�\n",obj);
		return 1;
	}
	 if (place->query("short") == "ɽׯ��Ժ" && me->query_temp("daomu") == 6)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/u/resort/back_yard");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"�������õĵ�Ĺ��");
		message_vision("��֪�����ִ���һ��Ĺ�ߡ�\n",obj);
		return 1;
	}
	 if (place->query("short") == "����" && me->query_temp("daomu") == 7)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/u/palace/dating");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"�������õĵ�Ĺ��");
		message_vision("��֪�����ִ���һ��Ĺ�ߡ�\n",obj);
		return 1;
	}
	 if (place->query("short") == "��ʯ" && me->query_temp("daomu") == 8)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/d/tieflag/rock0");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"�������õĵ�Ĺ��");
		message_vision("��֪�����ִ���һ��Ĺ�ߡ�\n",obj);
		return 1;
	}
	 if (place->query("short") == "����ɽׯ" && me->query_temp("daomu") == 9)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/d/shenshui/ruanhong");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"�������õĵ�Ĺ��");
		message_vision("��֪�����ִ���һ��Ĺ�ߡ�\n",obj);
		return 1;
	}
	 if (place->query("short") == "��԰" && me->query_temp("daomu") == 10)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/d/qingping/garden");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"�������õĵ�Ĺ��");
		message_vision("��֪�����ִ���һ��Ĺ�ߡ�\n",obj);
		return 1;
	}
		
		}
		return 1;
}

