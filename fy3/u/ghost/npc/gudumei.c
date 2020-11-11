#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�¶���", ({ "gu du mei", "gu du" }) );
        set("nickname", "���ײ���");
        set("title", "���д��");
        set("gender", "����");
        set("age", 56);
        set("no_arrest",1);
        set("long",
		"һ�����ް߰׵��ˣ�˥�ϡ��㲡�ƣ�롢���˶��־塣\n"
	);
        setup();
	carry_object(__DIR__"obj/sword")->wield();
}

void init()
{
        object          me;

        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, me);
		add_action("do_agree", "agree");
		add_action("do_go", "go");
        }
}

void greeting(object ob)
{
	object		leader, room;
	string		*dirc = ({ "��", "��", "��", "��" });
	string		*dirg = ({ "east", "south", "west", "north" });
	string		*dire = ({ "exits/east", "exits/south", "exits/west", "exits/north" });
	string		*rooms = ({ "/u/ghost/forest4", "/u/ghost/forest1", "/u/ghost/forest2", "/u/ghost/forest3", "/u/ghost/forest8", "/u/ghost/forest5", "/u/ghost/forest6", "/u/ghost/forest7", "/u/ghost/forest9" });
	string		leave, sleave, oldroom;
	int		i;

	if( !ob || environment(ob) != environment() ) return;
	i = (int)this_object()->query_temp("marks/·");
	if(objectp(room = (object)this_object()->query_temp("marks/room"))) {
		if(oldroom = (string)this_object()->query_temp("marks/lastroom")) {
			room->set(dire[i], oldroom);
		}
	}
	room = environment();
	this_object()->set_temp("marks/room", room);
	if( leader = this_object()->query_leader()) {
		sleave = (string)dirg[i];
		leave = (string)this_object()->query_temp("marks/��");
		if(environment(leader) == room) {
			if( sleave != leave) {
				tell_object(leader, HIR "�¶�����������˵����Ϊ��ô�����һ��������������߲����ģ�\n" NOR);
				this_object()->set("exits", 0);
			}
			if( (int)this_object()->query("exits") == 8 ) {
				tell_object(leader, HIY "�¶���˵�������ˡ�\n" NOR);
		                leader->set_temp("marks/okleave", 0);
				this_object()->set_leader();
			}
			else {
				i = random(4);
				this_object()->set_temp("marks/·", i);
				this_object()->add("exits", 1);
				oldroom = room->query(dire[i]);
				this_object()->set_temp("marks/lastroom", oldroom);
				room->set(dire[i], rooms[this_object()->query("exits")]);
				tell_object(leader, HIY "�¶���˵������" + dirc[i] + "�ߡ�\n" NOR);
			}
		}
		else {
			this_object()->set("exits", 0);
			this_object()->set_leader();
		}
	}
	else {
		this_object()->set_leader();
		this_object()->set("exits", 0);
		say(HIY "�¶����ĺ�����¹����ţ������˿־������¶����һ˿ϣ������Ϣ�ŵ���\n" NOR);
		say(HIY "�㣮������˭�����ң�û���ң����߲����ģ�(agree to help)\n" NOR);
	}
	return;
}

int do_agree(string arg)
{
	object		me;

	if(arg == "to help") {
		me = this_player();
		me->set_temp("marks/okleave", 0);
		say("�¶��������˿־������¶����һ˿Ц�⣬��Ϣ�Ŷ�"+ me->name() +"����лл�㡣\n");
		this_object()->set_leader(me);
		tell_object(me, "�¶���˵�������ߡ�\n" NOR);
		this_object()->set_temp("marks/·", 0);
		return 1;
	}
	else
		return 0;
}

int do_go(string arg)
{
	this_object()->set_temp("marks/��", arg);
	return 0;
}
