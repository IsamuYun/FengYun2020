// ɽè(adx) by snow 2000-05-15

#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "����̨");
	set ("long", @LONG
������Ǳ��䳡�Ĵ����̨��һ�����ߵı���̨�������ɺ�ɫ�ĵ�̺
����̨���ߵı������ϰڷ�������ʮ�˰������Ϊװ�Ρ�����̨������һ
�����ϯ��ֻ����ʦ��Сѩ�����������ʦ�����������
LONG);
	set("info_sends",1);
	set("biwutai",1);
	set("exits", ([
		"north"   : __DIR__"caipan",
		"down"   : __DIR__"kantai2",
	]));
        set("item_desc", ([
                "dui lian" : @TEXT
        $BWHT$$GRN$����������������������������������$NOR$
        $BWHT$$GRN$��                              ��$NOR$
        $BWHT$$GRN$��  $BLK$��  ��  ��  ��  ��  ��  ��$GRN$  ��$NOR$
        $BWHT$$GRN$��                              ��$NOR$
        $BWHT$$GRN$����������������������������������$NOR$

        $BWHT$$GRN$����������$NOR$              $BWHT$$GRN$����������$NOR$
        $BWHT$$GRN$��      ��$NOR$              $BWHT$$GRN$��      ��$NOR$
        $BWHT$$GRN$��  $BLK$��$GRN$  ��$NOR$              $BWHT$$GRN$��  $BLK$ȭ$GRN$  ��$NOR$
        $BWHT$$GRN$��      ��$NOR$              $BWHT$$GRN$��      ��$NOR$
        $BWHT$$GRN$��  $BLK$��$GRN$  ��$NOR$              $BWHT$$GRN$��  $BLK$��$GRN$  ��$NOR$
        $BWHT$$GRN$��      ��$NOR$              $BWHT$$GRN$��      ��$NOR$
        $BWHT$$GRN$��  $BLK$��$GRN$  ��$NOR$              $BWHT$$GRN$��  $BLK$��$GRN$  ��$NOR$
        $BWHT$$GRN$��      ��$NOR$              $BWHT$$GRN$��      ��$NOR$
        $BWHT$$GRN$��  $BLK$��$GRN$  ��$NOR$              $BWHT$$GRN$��  $BLK$ɽ$GRN$  ��$NOR$
        $BWHT$$GRN$��      ��$NOR$              $BWHT$$GRN$��      ��$NOR$
        $BWHT$$GRN$��  $BLK$��$GRN$  ��$NOR$              $BWHT$$GRN$��  $BLK$��$GRN$  ��$NOR$
        $BWHT$$GRN$��      ��$NOR$              $BWHT$$GRN$��      ��$NOR$
        $BWHT$$GRN$��  $BLK$��$GRN$  ��$NOR$              $BWHT$$GRN$��  $BLK$��$GRN$  ��$NOR$
        $BWHT$$GRN$��      ��$NOR$              $BWHT$$GRN$��      ��$NOR$
        $BWHT$$GRN$����������$NOR$              $BWHT$$GRN$����������$NOR$
$NOR$
TEXT
        ]) );
	setup();
}

void init()
{
	add_action ("do_fight","fight");
	add_action ("do_fight","kill");
	add_action ("do_fight","hit");
	add_action ("do_work","quit");
	add_action ("do_work","halt");
}

int do_fight(string arg)
{
	object me=this_player();
	object *inv=all_inventory(environment(me));
	object ob;
	object who;
	int i;

	if(!arg) { 
		write("��Ҫͬ˭���䣿\n");
		return 1;
	}
	ob=present(arg, environment(me));
	if(!ob) {
		write("����û������ˣ�\n");
		return 1;
	}
	if(ob==me) {
		write("��Ҫͬ�Լ����䣿����\n");
		return 1;
	}
	if(!interactive(ob)) {
		write("�������޷�ͬ����䣡\n");
		return 1;
	}
	if(!userp(me) || !userp(ob)) {
		write("�������޷�ͬ����䣡\n");
		return 1;
	}

	for(i=0; i<sizeof(inv); i++) {
		who=inv[i];
		if(who->is_fighting()) {
			write("̨��"+who->query("name")+"�����ڱ��䣬���Ժ\n");
			return 1;
		}
	}

	message("channel:chat",HIW"�����䳡��"+
		me->query("family/family_name")+"��"+me->query("name")+"��"+
		ob->query("family/family_name")+"��"+ob->query("name")+
		"�ڱ���̨�Ͻ����ߵͣ�\n\n"NOR,users());

	me->set("biwu_fighter",1);
	ob->set("biwu_fighter",1);

	me->kill_ob(ob);
	ob->kill_ob(me);
	return 1;
}

void info_sends(string str)
{
	tell_room(__DIR__"kantai1", str);
	tell_room(__DIR__"kantai2", str);
	tell_room(__DIR__"kantai3", str);
}

int no_die(object me)
{
	object ob = me->query_temp("last_opponent");
	object obj, where;
	string id=ob->query("id");
	string id1=me->query("id");

	me->delete_temp("last_opponent");
	ob->delete_temp("last_opponent");
	me->delete_temp("last_damage_from");
	ob->delete_temp("last_damage_from");
	me->remove_all_killer();
	ob->remove_all_killer();

	me->set("eff_qi", me->query("max_qi"));
	me->set("qi", me->query("max_qi"));
	me->set("eff_jingli", me->query("max_jingli"));
	me->set("jingli", me->query("max_jingli"));
	me->set("eff_douzhi", me->query("max_douzhi"));
	me->set("douzhi", me->query("max_douzhi"));
	me->set("shenzhi", me->query("max_shenzhi"));
	me->set("neili", me->query("max_neili"));

	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("qi", ob->query("max_qi"));
	ob->set("eff_jingli", ob->query("max_jingli"));
	ob->set("jingli", ob->query("max_jingli"));
	ob->set("eff_douzhi", ob->query("max_douzhi"));
	ob->set("douzhi", ob->query("max_douzhi"));
	ob->set("shenzhi", ob->query("max_shenzhi"));
	ob->set("neili", ob->query("max_neili"));

	message("channel:chat",HIW"�����䳡��"+
		ob->query("family/family_name")+"��"+ob->query("name")+"�ڱ���̨����"+
		me->query("family/family_name")+"��"+me->query("name")+"��\n\n"NOR,users());

	message_vision (CYN"$N���ص�ˤ�ڵ��ϣ�\n"NOR,me);
	message_vision (CYN"\n$N�����ӵ���������������׳���������±���̨��\n"NOR,me);
	me->move(__DIR__"kantai1");
	message_vision (CYN"$N��׳�������������˹�����\n"NOR,me);
	message_vision (CYN"����׳�������Ŵ�ӵ��$N���±���̨��\n"NOR,ob);
	ob->move(__DIR__"kantai3");
	message_vision (CYN"$N������׳����ӵ�����˹�����\n"NOR,ob);

	me->delete("biwu_fighter");
	ob->delete("biwu_fighter");

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	obj=present("gongping zi", where);
	if(obj->query("fangshi")!="������") {
		if(obj->query("start/juesai"))
			obj->jieshu_biwu(id, id1);
			obj->keep_biwu(id);
	}
	return 1;
}

int do_work()
{
	write("���ﲻ��ʹ�����ָ�\n");
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( !wizardp(me) && dir=="north" ) {
		return notify_fail("�㼴����Сѩ�������ʦҲ����������ʦ���ܵ����ϯ��\n");
	}

	if ( !wizardp(me) && dir=="down" ) {
		if( me->query("biwu_fighter") )
			return notify_fail("������Ҫ�����ˣ���Ҫ�������ܡ�\n");
	}

	me->delete_temp("last_opponent");
	me->delete_temp("last_damage_from");
	me->remove_all_killer();

	return ::valid_leave(me, dir);
}

