//xgchen@zzfy

inherit ROOM;
void create ()
{
        set ("short", "比武看台");
        set ("long", @LONG
这是郑州风云的比武场的看台，看台上有一排排的木制条凳。你坐在
这里一丈高的比武台上一切比武过招你都能看得非常清楚。这里还提供
免费的饮食。

                [47m※※※※※※※※※※※※※※※※※ [0m
                [47m※                              ※ [0m
                [47m※ [30m 打  遍  天  下  无  敌  手[32m  ※ [0m
                [47m※                              ※ [0m
                [47m※※※※※※※※※※※※※※※※※ [0m

        [47m※※※※※ [0m                               [47m※※※※※ [0m
        [47m※      ※ [0m                               [47m※      ※ [0m
        [47m※  [30m脚[32m  ※ [0m                               [47m※  [30m拳 [32m ※ [0m
        [47m※      ※ [0m                               [47m※      ※ [0m
        [47m※  [30m踢[32m  ※ [0m  这里是郑州风云的比武场看台。 [47m※  [30m打 [32m ※ [0m
        [47m※      ※ [0m                               [47m※      ※ [0m
        [47m※  [30m北[32m  ※ [0m  这里可以看到上面的比武擂台。 [47m※  [30m南 [32m ※ [0m
        [47m※      ※ [0m                               [47m※      ※ [0m
        [47m※  [30m海[32m  ※ [0m  擂台上面挂着一幅很大的对联。 [47m※  [30m山 [32m ※ [0m
        [47m※      ※ [0m                               [47m※      ※ [0m
        [47m※  [30m蛟[32m  ※ [0m                               [47m※  [30m猛 [32m ※ [0m
        [47m※      ※ [0m                               [47m※      ※ [0m
        [47m※  [30m龙[32m  ※ [0m                               [47m※  [30m虎 [32m ※ [0m
        [47m※      ※ [0m                               [47m※      ※ [0m
        [47m※※※※※ [0m                               [47m※※※※※ [0m
[0m
LONG);
        set("no_fight",1);
        set("no_exert",1);
        set("no_magic",1);
        set("no_clean_up",1);
        set("watch_fight_room",1);
        set("exits", ([
                "up"   : __DIR__"biwutai",
                "down"   : __DIR__"biwufang",
        ]));
        setup();
}

void init()
{
        add_action ("do_work","perform");
        add_action ("do_work","exert");
        add_action ("do_work","dazuo");
}

int do_work()
{
        write("这里不能使用这个指令！\n");
        return 1;
}

int valid_leave(object me, string dir)
{
        object tai=load_object(__DIR__"biwutai");
        object *inv=all_inventory(tai);
        object ob, where;
        int i=sizeof(inv);


        if ( !wizardp(me) && dir=="up" ) {
//                if( !me->query("biwu_fighter"))
//                        return notify_fail("你不是比武选手不能上去。\n");^M
                if(i>=3)
                        return notify_fail("比武台上已经有两名选手，你现在不能上台。\n");
        }
        return ::valid_leave(me, dir);
}
