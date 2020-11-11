inherit ROOM;
#include <room.h>

void create()
{
        set("short", "��Ȫ");
        set("long", @LONG
�߹�ç�֣����ܿ���һ���ܴ����Ȫ�����������ɽ��ԭ�������Ȫˮ������
�ȣ��װ׵�ˮ������Ȫ������������һ����ů�ĸо�������һ����˵���������Ȫ
�������������Ĺ�Ч��������һ�����������𣩽�ȥ����֤һ�¡�
LONG
        );
        set("exits", ([
                "west" : "/d/zhaoze/garden",
        ]));
        set("objects", ([
                __DIR__"npc/chanchu": 1,
          ]) );
        set("no_magic", 1);
        set("coor/x",15);
        set("coor/y",-610);
        set("coor/z",-20);
        set("coor/x",15);
        set("coor/y",-610);
        set("coor/z",-20);
        setup();

}

void init()
{
        add_action("do_jump", "jump");

}

int do_jump()
{
        object me;
        int wait;
        me = this_player();
        wait = random( 40 - (int)(me->query("con"))) * 2;
        if ( wait <= 20) wait = 21;
        message_vision("$N����һ��������Ȫ��\n",me);
        tell_object(me,"��ů��Ȫˮ��Χ���㣬����е�ȫ���ޱȵ���̩����\n");
        remove_call_out("curehimup");
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
        message_vision("������Ȫˮ�����湦Ч��$N�ľ�����ȫ�õ��˻ָ�����\n", me);
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
        }
return;
}
