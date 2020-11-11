//3310,0,10
inherit ROOM;
void create()
{
        set("short", "洞口 ");
        set("long", @LONG
一块屏风似的岩石后，悬着条钢索，吊着辆滑车(huache)。 
钢索通向一个黑黝黝的山洞。 
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"anbian",
		]));         
  set("item_desc", ([
            "huache": "似乎可以跳(dash)进去,但里面...\n",
            "滑车": "似乎可以跳(dash)进去,但里面...\n"
    ]) );
    set("coor/x",3310);
	set("coor/y",0);
	set("coor/z",10);
	set("no_magic",1); set("no_dazuo",1);

	setup();

}
void init()
{
 add_action("do_dash","dash");
}
int do_dash(string arg)
{
        object room;
        object me;
        me = this_player();
        message_vision("$N一下子就跳进了滑车！
$N越坠越快．．．．$N似乎听见了一声惨叫，不禁毛骨悚然。\n", me);
        room = load_object(__DIR__"dong1");
        me->move(room);
        me->start_busy(2);
        return notify_fail("");
       
}

