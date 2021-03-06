#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "比赛准备室");
        set("long", @LONG
这里黑乎乎的，地上还有一些粘满了血迹的布条，偶然也看得到断
了的长剑、钢刀什么的。北面的门紧紧的锁着，里面散发出一阵阵血腥
的气味。这里有个兵器架(shelf),请你小心使用，十二个门已经打开的!.
LONG
        );
        set("exits", ([
                "1" : __DIR__"turen1",
                "2" : __DIR__"turen2",
                "3" : __DIR__"turen3",
                "4" : __DIR__"turen4",
                "5" : __DIR__"turen5",
                "6" : __DIR__"turen6",
                "7" : __DIR__"turen7",
                "8" : __DIR__"turen8",
                "9" : __DIR__"turen9",
               "10" : __DIR__"turen10",
               "11" : __DIR__"turen11",
               "12" : __DIR__"turen12",
        ]));
	set("item_desc", ([
                "shelf" : 
"\n
一个很有年头的兵器架，红漆都剥落得差不多了。
架上摆满了: 
                 钢刀(blade)    长剑(sword)
                 钢杖(staff)    长鞭(whip)
                 铁锤(hammer)   扳指(jiezi)
                 暗器(throwing) 短兵(dagger)
                 真丝宝甲(armor)

参加比赛可以按需要，随便拿取(take)使用。
                                郑州风云巫师组 敬启
\n"

]));
        set("objects", ([  "/d/pk/npc/wu1" : 1,   ]) );
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);
        setup();
}
int valid_leave(object me, string dir)
{
        if (me->query_temp("pkok")!=1)
                return notify_fail("比赛使者喝道：给我站住！没有杀人证，不能进去。\n");
        return ::valid_leave(me,dir);
}
void init()
{
        add_action("do_take","take");
}
int do_take(string arg)
{
        object obj,ob;
        ob = this_player();
        if( !arg || arg=="" )
        {
                message_vision("$N站在兵器架前，还没想好要什么兵器。\n", ob);
                return 1;
        }
        switch (arg)
        {
                case "sword":
                        obj = new("/obj/weapon/sword");
                        obj -> move(ob);
                        message_vision("$N从兵器架上取下一口长剑。\n",ob);
                        break;
                case "blade":
                        obj = new("/obj/weapon/blade");
                        obj -> move(ob);
                        message_vision("$N从兵器架上取下一口钢刀。\n",ob);
                        break;
                case "staff":
                        obj = new("/obj/weapon/staff");
                        obj -> move(ob);
                        message_vision("$N从兵器架上取下一杆钢杖。\n",ob);
                        break;
                case "whip":
                        obj = new("/obj/weapon/whip");
                        obj -> move(ob);
                        message_vision("$N从兵器架上取下一条长鞭。\n",ob);
                        break;
                        obj = new("/obj/weapon/hammer");
                        obj -> move(ob);
                        message_vision("$N从兵器架上取下一把铁锤。\n",ob);
                        break;
                case "throwing":
                        obj = new("/obj/weapon/dart");
                        obj -> move(ob);
                        message_vision("$N从兵器架上取下一把飞镖。\n",ob);
                        break;
                case "dagger":
                        obj = new("/obj/weapon/dagger");
                        obj -> move(ob);
                        message_vision("$N从兵器架上取下一把匕首。\n",ob);
                        break;
                case "armor":
                        obj = new("/obj/baojia");
                        obj -> move(ob);
                        message_vision("$N从兵器架上取下一副宝甲。\n",ob);
                        break;
                case "jiezi":
                        obj = new("/obj/weapon/glove");
                        obj -> move(ob);
                        message_vision("$N从兵器架上取下一个板指。\n",ob);
                        break;
                default:
                        message_vision("$N站在兵器架前，还没想好要什么兵器。\n", ob);
        }
        return 1;
}
