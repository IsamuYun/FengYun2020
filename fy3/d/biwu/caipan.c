// ɽè(adx) by snow 2000-05-15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���䳡���ϯ");
	set("long", @LONG
�����Ǳ��䳡�Ĺ��ϯ��������̴̫ʦ���ų�һ�У�ÿ��̫ʦ������
������һ�Ż�Ƥ��ֻ��Сѩ�������ʦ��������ʦ�����ʸ��������
LONG);
	set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"biwutai",
		"down" : __DIR__"houtai",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        object tai=load_object(__DIR__"biwutai");
        object *inv=all_inventory(tai);
	object ob, where;
        int i=sizeof(inv);

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if ( !wizardp(me) && dir=="south" ) {
		if( ob->query("start/start") && !me->query("biwu_fighter") )
			return notify_fail("�����Ѿ���ʼ�ˣ��㲻��ѡ�ֲ�����̨��\n");
		if(i>=2)
			return notify_fail("����̨���Ѿ�������ѡ�֣������ڲ�����̨��\n");
	}
        return ::valid_leave(me, dir);
}

void init()
{
//	add_action ("do_start","start");
	add_action ("do_urged","urged");
	add_action ("do_check","check");
	add_action ("do_next","next");
	add_action ("do_xsave","xsave");
	add_action ("do_work","quit");
}

int do_urged()
{
	object where, ob, ob1, ob2;
	string id1, id2;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if(!ob->query("start"))
		return notify_fail("������δ��ʼ����\n");

	id1=ob->query("start/biwu_fighter1");
	id2=ob->query("start/biwu_fighter2");

	if(id1) ob1=find_player(id1);
	if(id2) ob2=find_player(id2);

	if(!ob1) ob->keep_biwu(id2);
	if(!ob2) ob->keep_biwu(id1);

	message_vision(CYN"$N��"+ob1->query("name")+"��"+
		ob2->query("name")+"һ�����ϱ���̨��\n"NOR, this_player());
	if(environment(ob1)->query("short")!="����̨") {
		message_vision (CYN"��ƽ��һ�Ű�"+ob1->query("name")+
		"���ϱ���̨����������ţ���ô���������ģ�\n"NOR, ob1);
		ob1->move(__DIR__"biwutai");
	}
	if(environment(ob2)->query("short")!="����̨") {
		message_vision (CYN"��ƽ��һ�Ű�"+ob2->query("name")+
			"���ϱ���̨����������ţ���ô���������ģ�\n"NOR, ob2);
		ob2->move(__DIR__"biwutai");
	}
	return 1;
}

int do_start(string arg)
{
	object where, ob;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	if(!arg)
		return notify_fail("��Ҫ��ʼʲô������\n");
	ob->do_start(arg);
	return 1;
}

int do_check()
{
	object where, ob;
	object me=this_player();
	int i, j, k, a, b, c;
	string arg, id, msg, *str, *menpai;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	i=ob->query("biwudahui");
	j=ob->query("start/lunxu");
	k=(ob->query("start/huihe")-1);
	arg=ob->query("start/start");
	menpai=ob->query("fenzu");

	if(!arg)
		return notify_fail("Ŀǰ��û�п�ʼ���䣡\n");

	if(arg=="xunhuan") {
		message_vision(WHT"��"+CHINESE_D->chinese_number(i)+"������ᣡ\n"NOR, me);
	} else {
		message_vision(WHT"���ڽ���"MAG+arg+WHT"���Ŵ����ѡ�α��䣡\n"NOR, me);
	}

	message_vision (WHT"��"+CHINESE_D->chinese_number(j)+"�֣�\n"NOR, me);

	for(a=1; a<(sizeof(menpai)+1); a++) {
		msg=WHT"��"+CHINESE_D->chinese_number(a)+"�飺";
		str=ob->query("fenzu/"+a+"/");
		for(b=1; b<(sizeof(str)+1); b++) {
			id=ob->query("fenzu/"+a+"/"+b+"");
			c=ob->query("jifen/"+id);
			msg+="("+id+") ����=="+c+"\t";
		}
		message_vision (WHT""+msg+"\n"NOR, me);
	}
	message_vision (WHT"\n���ڽ��е���"+CHINESE_D->chinese_number(k)+"�غϣ�\n"NOR, me);
	return 1;
}

int do_xsave()
{
	object where, ob, me;
	me=this_player();
	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	message_vision (CYN"������ȴ�����ϣ�\n"NOR, me);
	ob->save();
	return 1;
}

int do_next(string arg)
{
	object where, ob, me;
	me=this_player();
	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	message_vision (CYN"����������һ�ֱ��䣡\n"NOR, me);
	if(!arg) {
		ob->keep_biwu("adx");
	}
		ob->keep_biwu(arg);
	return 1;
}

int do_work()
{
	write("���ﲻ��ʹ�����ָ�\n");
	return 1;
}
