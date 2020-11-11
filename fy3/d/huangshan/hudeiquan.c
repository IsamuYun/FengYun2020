
inherit ROOM;
#include <room.h>

void create()
{
        set("short", "����Ȫ");
        set("long", @LONG
���ﾰɫ����,��ľ�Դ�,�������,�����صľ������������ĺ���,��˫�ɶ�,������
��ǰ����,��ʱ�����治��ĸ�������һ��ԧ��˫��,�ƺ��ڱ�����Ĺ¶�.���������
��˵����ף�����ĺ�����Ȫ��,�������棬�װ׵�ˮ����������������,ʹ��û�������
�ж��,��˵��Ȫˮ��ȥ������,�����˵������ҩ,��֪�����Ǽ�,����������(pao)һ
��,�ܿ��ٻָ�ƣ��ȴ�ǲ�������ʵ.
LONG
        );
        set("exits", ([
                "north" : __DIR__"shanmen",
        ]));
        set("objects", ([
                __DIR__"npc/hudei": 4,
        ]) );
	set("no_magic", 1);
        set("outdoors", "huangshan");
	set("coor/x",-510);
	set("coor/y",-550);
	set("coor/z",0);
	setup();

}

void init()
{
	add_action("do_pao", "pao");

}

int do_pao()
{
	object me;
	int wait;
	me = this_player();
	wait = random( 20 - (int)(me->query("con"))) * 2;
	if ( wait <= 20) wait = 21;
	wait = 5;
	message_vision("$N����Ծ����Ȫ�У�\n",me);
	tell_object(me,"��е�����ľ���������������..��\n");
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

