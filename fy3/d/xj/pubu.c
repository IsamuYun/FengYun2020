#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "瀑布");
        set("long", @LONG
这里是沟的尽头，数十丈高的悬崖就象是被人一刀砍出来的。
一丈多宽的瀑布一泻而下，在阳光下就象是闪着银光的绸缎，颇为
壮观。瀑布以一泄千里之势击入湖中，隆隆之声不绝于耳。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"goudi2",
  "eastup" : __DIR__"aiding",
]));
        set("objects", ([
                "/d/oldpine/npc/serpent" :1,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("coor/x",-1090);
	set("coor/y",1020);
	set("coor/z",-10);
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
                                "name": "清凉的水",
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
                write("你要往什么东西里灌水？\n");
        }
        return 1;
}
