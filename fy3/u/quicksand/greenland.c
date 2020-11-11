
inherit ROOM;

void create()
{
        set("short", "绿洲");
        set("long", @LONG
你脚下的流沙已经不见，一个小小的湖泊呈现在你的眼前。湖里的水虽然
只有二指厚，却很清澈。在酷热的风中，湖水仍是那么的清凉。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"desert9",
  "east" : __DIR__"desert8",
//"north" : "/d/bloomdoor/greenland",
]));
	set("resource/water",1);
        set("outdoors", "quicksand");

        set("coor/x",-1085);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-1085);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init()
{
	object ob;
	string outexit;
        if( interactive( ob = this_player()))
        {
        if(query("exits/east")) delete("exits/east");
        outexit = __DIR__"desert"+(string)( random(3)+6)+ ".c";
        set("exits/east", outexit);

        }
        add_action("do_fillwater", "fillwater");
}

int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return notify_fail("你要往什么东西里灌水？\n");
;

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
                                "name": "清水",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("你从井里装满了清水! \n");
			return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？\n");
        }
	return 1;
}
