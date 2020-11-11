inherit ROOM;
#include <room.h>

void create()
{
        set("short", "温泉");
        set("long", @LONG
走过莽林，就能看见一个很大的温泉。由于这里火山的原因，这里的泉水常年温
热，白白的水气从温泉中升起，让人有一种温暖的感觉。听老一辈人说，这里的温泉
有着起死回生的功效，你真想一下跳（ｊｕｍｐ）进去，验证一下。
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
        message_vision("$N噗嗵一声跳进温泉。\n",me);
        tell_object(me,"温暖的泉水包围着你，让你感到全身无比的舒泰．．\n");
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
        message_vision("由于温泉水的神奇功效，$N的精气神全得到了恢复！！\n", me);
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
        }
return;
}
