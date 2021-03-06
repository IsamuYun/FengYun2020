#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "天池");
        set("long", @LONG
天池背靠博格达峰，为天山第二高峰，山峰终年积雪。即使是盛夏天气，
湖水的温度也相当低。湖的面积并不算大，形状是狭长形，池水清澄，
碧蓝碧蓝的，看了就叫人感到喜欢。天池四周的山腰上，有许多云杉林，
云杉形如宝塔，挺拔、整齐，很有气势。清澈湖水，皑皑雪峰和葱茏挺
拔的云松林，构成了天池的迷人的景色。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"tianshan",
]));
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("coor/x",-1150);
	set("coor/y",1000);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_fillwater", "fillwater");
}

int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "冰凉的湖水",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("你从天池里装满了冰凉的湖水！\n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？\n");
        }
        return 1;
}
