#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "土路");
        set("long", @LONG
荒原上的一段蜿蜒曲折的土路，伴随一条默默的溪流（ＲＩＶＥＲ），
清澈的溪水，使人感到一股清新气息。周围群山起伏，碧水蜿蜒，风光秀丽。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"beimen",
  "northup" : __DIR__"hongshan",
]));
        set("objects", ([
                __DIR__"npc/baiyi" :1,
                        ]) );
        set("item_desc", ([
                "river": "好清澈的溪流，里面还有小鱼（ｃａｔｃｈ）耶！！\n",
                "溪流": "好清澈的溪流，里面还有小鱼（ｃａｔｃｈ）耶！！\n"
        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("resource/water",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
	set("coor/y",1120);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_fillwater", "fillwater");
        add_action("do_catch", "catch");
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
                                "name": "清澈的溪水",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("你从溪流里装满了清水！! \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？");
        }
        return 1;
}

int do_catch()
{
	write("你一伸手，抓住一条小活鱼抛入口中．．．．\n啊－－－味道不错，如果再有点瓦萨比就好喽．．．\n");
//你伸出手试着抓了抓，结果什么也没抓到！
//combat_exp^Qmax_food_capacity^Dfood^CaddX你一伸手，抓住一条小活鱼抛入
        return 1;
}
