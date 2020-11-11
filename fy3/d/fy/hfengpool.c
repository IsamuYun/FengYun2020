
inherit ROOM;
#include <room.h>

void create()
{
        set("short", "��ҶȪ");
        set("long", @LONG
���Ƴ��еķ�ҶȪ�Ƿ�Բ�������������һ����Ȫ��ˮ�����У�Ȫˮ�ʵ���,
�ʶ�������Ҷ����������ȥ����������Ч����˵�����������ٵ����á����ֵ�һ
�������ɶ�ÿ�춼�Դ�Ȫˮ��棨�����裩�����������绨�������ò��
LONG
        );
        set("exits", ([
                "west" : __DIR__"hfenglang3",
        ]));
        set("objects", ([
                __DIR__"npc/xianu": 2,
        ]) );
        set("outdoors", "fengyun");
	set("no_magic", 1);
        set("coor/x",45);
	set("coor/y",45);
	set("coor/z",0);
	setup();
        create_door("west", "̴ľ��", "east", DOOR_CLOSED);

}

void init()
{
	add_action("do_jump", "wash");

}

int do_jump()
{
	object me;
	int wait;
	me = this_player();
	wait = random( 40 - (int)me->query("con")) * 2;
	if ( wait <= 20) wait = 6;
	message_vision("$N��������Ȫˮ�У�\n",me);
	tell_object(me,"��е�ȫ���ޱȵ���̩����\n");
//	remove_call_out("curehimup");
	call_out("curehimup", wait, me);
return 1;
}

void curehimup(object me)
{
        int gin,kee,sen;
        if(!me) return;
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
if( me && environment(me) == this_object())
	{
	message_vision("$N�ľ�����ȫ�ָ��ˣ���\n", me);
	me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
	me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
	}
return;
}

