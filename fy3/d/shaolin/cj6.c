// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "藏经楼");
        set("long", @LONG
满屋子灰尘，似乎久已无人上来，屋顶是精钢所铸，楼下有藏经楼
首座护卫，便是蝼蚁也难进入，四周墙壁上皆是梵文经卷，相传为当年
觉远大师梦游天竺佛祖亲授。是武学之中的不二法门。
LONG
        );
        set("exits", ([ 
  "down": __DIR__"cj5",
  "up": __DIR__"cj7",
]));
        set("objects", ([
                __DIR__"obj/xisui" : 3,
            "/d/shaolin/npc/master_18c" : 1,
               __DIR__"obj/xuejing" : 1,
       ]) );
	set("coor/x",-210);
	set("coor/y",360);
	set("coor/z",120);
	setup();

}
int valid_leave(object me,string dir)
{
        object ob;
if(userp(me) && dir == "up" && !me->query("juexue") )
{
message_vision("$N被一股无形的罡风挡住，令你不能动弹！\n",me);
return notify_fail("");
}
return 1;
}

