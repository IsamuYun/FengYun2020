inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ʯ");
        set("long", @LONG
����һ��޴�İ�ɫɽʯ����Լ�����������߸��ˡ�ʯͷ�ı����쳣
ƽ�������˾������ʯ���ϵļ����ɫӡ�ۣ���֪����Ȼ���ɣ�������Ϊ
�ĺۼ��������������Կ��������ĺ�ˮ����������ֻ�������������ƣ���
֪���ж�߲Żᵽ����
LONG
        );
	set("outdoors","fengyun");
        set("coor/x",200);
	set("coor/y",-30);
	set("coor/z",30);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_step", "step");
}

int do_step(string arg)
{
	if(!arg || arg != "��ɫӡ��" )
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision(HIY "$Nһ�Ų���ʯ���ϵĺ�ɫӡ�ۣ�ֻ������֨ѽ��һ����\n�±����ѿ���һ���Ż���\n" NOR, this_player());
	set("exits/enter", __DIR__"holeopen2");
        if(!this_player()->query("m_success/��ʯ"))
        {
                this_player()->set("m_success/��ʯ",1);
                this_player()->add("score",50);
	message("system",HIC "\n�����ַ��ơ���������"+this_player()->query("name")+"�⿪��������⣬�����"HIY"���������²����š�"HIC"�ĳƺš�\n" NOR,users());

        }
	return 1;
}

int do_climb(string arg)
{
        object 	me;
	int	mlvl;

	if(!arg || (arg != "up" && arg != "down")) {
		write("��Ҫ���ϻ�������\n");
		return 1;
	}
	me = this_player();
	if( arg == "up") {
		message_vision(HIY "\n$NС�������������ȥ�������������������ڡ�\n" NOR, me);
		message_vision(HIR "\n$N����һ��ûץ�ȣ���Σ���ϵ�����ȥ��\n" NOR, me);
		me->move(__DIR__"yadi");
                me->receive_wound("kee", 50);
                me->receive_wound("sen", 50);
                me->receive_wound("gin", 50);
		message_vision(HIR "\n$N��Σ���ϵ������������ص�ˤ���˵��ϣ�\n" NOR, me);
		me->unconcious();
	}
	else {
		message_vision(HIY "$NС�������������ȥ�������������������ڡ�" NOR, me);
		me->move(__DIR__"yadi");
	}
	return 1;
}
