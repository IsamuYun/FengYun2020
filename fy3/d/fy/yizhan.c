inherit ROOM;
void create()
{
        set("short", "通商驿站");
        set("long", @LONG
这里是风云城的驿站，主要为的是通商的便利，如果你想去关外，又怕旅
途的劳累，在这里雇一辆马车，不失为一个好办法。后院里，你可以看到一辆
辆的装好了货物的马车整装待发。一个矮矮胖胖的驿站老板正在忙碌着。
LONG
        );
        set("exits", ([   "north" : "/d/fy/wgate", ]));
       set("objects",([    __DIR__"npc/boss1" : 1,   ]));
        set("coor/x",-60);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
void mabian_notify()
{
        object ob;

  message("vision","大喊道：“我要去大昭，马夫何在？”。\n" , this_object() );
                call_out("boat_come",5);
}
void boat_come()
{
        object boat;
        object woman;
        object *inv;
        object who, oob;
        int i;
        
        if (query("exits/up")) return;
        if (!objectp(boat=find_object(__DIR__"boat")))
                boat=load_object(__DIR__"boat");
        inv=all_inventory(boat);
        
        message("vision","半盏茶的功夫，一个白发苍苍的赶车老人，驾着一辆套好的马车缓缓而来。\n",this_object());
        message("vision","赶车老人说道：“客官，您是要去大昭寺吗？那就请上车吧”\n",this_object());
        boat->set("exits/down",__DIR__"yizhan");
        boat->set("no_fight",1);
        boat->set("no_magic",1);
        set("exits/up",__DIR__"boat");
        call_out("boat_leave",10,boat);
}
void boat_leave(object boat)
{
        if (query("exits/up")) delete("exits/up");
        if (boat->query("exits/down")) boat->delete("exits/down");
        message("vision","赶车老人马鞭一甩，马车咕噜噜的驶出驿站。\n",this_object()); 
        boat->set_temp("mark/dest","island");
        message("vision","赶车老人马鞭一甩，马车咕噜噜的驶出驿站。\n",boat);
        boat->boat_run(0);
}

