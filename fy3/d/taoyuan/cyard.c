inherit ROOM;
void create()
{
        set("short", "小院");
        set("long", @LONG
小小的院落，一方葡萄架遮住了半边，淡黄的阳光斜斜的照在上面，把嫩绿
的叶脉变得透明。院的中间是一口水井，咿咿呀呀的摇辘声犹如在耳；篱笆的另
一角堆着一些清扫用具。
LONG
        );
        set("exits", ([ 
	"east" : __DIR__"kitchen",
	"south" : __DIR__"anju",
	"north" : __DIR__"livingroom",
	"west" : __DIR__"cyard1",
	]) );

	set("objects", ([
	__DIR__"obj/corner": 1,
	]) );

	set("resource/water",1);
        set("outdoors","taoyuan");
        set("coor/x",210);
	set("coor/y",-20);
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
                                "name": "井水",
                                "remaining": 15,
                                "drunk_apply": 0,
                        ]) );
                        write("你从水井里装满了井水！ \n");
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


void reset()
{
	object *inv;
        object item1, corner;
        ::reset();
        corner = present("corner", this_object());
        inv = all_inventory(corner);
        if( !sizeof(inv)) {
        item1 = new(__DIR__"obj/saoba");
        item1->move(corner);
        }
}

