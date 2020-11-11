// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "飞来石");
        set("long", @LONG
在平坦的山面之上，突然冒出一块石头，似乎除了飞来一说，别的实
在难以解释。石面光滑，上书三字“飞来石”，远看石头，上粗下细，好
象摇晃不止，实在令人匪夷所思。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"guangming",
  "west" : __DIR__"paiyun",
]));
        set("item_desc", ([
                "飞来石": "你可以试着推一推（push）\n",
                "stone": "你可以试着推一推（push）\n"
        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-600);
	set("coor/y",-530);
	set("coor/z",30);
	setup();
}
void init()
{ add_action("do_push","push");}
int do_push()
{
object me;
me=this_player();
me->receive_damage("kee",30);
message_vision("$N用尽全身力气，用力推了推飞来石，飞来石似乎晃了晃！\n",me);
return 1;
}
