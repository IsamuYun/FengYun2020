// a skeleton for user rooms
#define X_COOR 0
#define Y_COOR 2070
#define Z_COOR 0
#define R_FLAG 2569
#define OWNER "yixing"
#define CLASS "大理"
inherit ROOM;
void create()
{
set("short", "红叶山庄花园");
set("long", @LONG
      花园依山而建，清澈的山泉水，从几丈高的地方冲
到下面的池塘里，荡起片片水雾。透过淡淡的水雾，隐
约可见瀑布后的石壁上刻着几个字：“剑在手，问天下
谁是英雄”，字体菱角分明，仿佛是用利器刻上去的。
池塘周围种满了奇花异草。不知什么原因，这里四季如，
春，终年百花齐放，彩蝶飞舞。

LONG
);
        set("exits", ([
"northwest" : __DIR__"biza1199083313",
"east" : "/p/residence/yixing983460225.c",
]));
set("objects", ([
       ]) );
	set("coor/x",X_COOR);
	set("coor/y",Y_COOR);
	set("coor/z",Z_COOR);
	set("room_flag",R_FLAG);
	set("owner", OWNER);
	set("class", CLASS);
	setup();
}
void init()
{
	int flag;
	flag = (int) query("room_flag");
	if(flag & 1) set("valid_startroom",1);
	if(flag & 2) set("NONPC",1);
	if(flag & 4) set("no_fight",1);
        if(flag & 8) set("no_magic",1);
	if(flag & 16) set("outdoors","residence");
	add_action("do_invite","invite");
	add_action("do_setowner","setowner");
}
int valid_enter(object me)
{
	int flag;
// always let owner go in:
	if((string)me->query("id") != (string)query("owner"))
	return 0;
	if(flag & 512)
	if((string)me->query("id") != (string)query("owner"))
	return 1;
	if(flag & 1024)
        if((string)me->query("class") != (string)query("class"))
        return 1;
	if(flag & 2048)	
	if((string)query("invite") != (string)me->query("id"))
	return 1;	
	return 0;
}
int do_invite(string arg)
{
	object me;
	me= this_player();
	if((string)me->query("id") != (string)query("owner"))
	return 0;
	set("invite",arg);
	write("你邀请"+arg+"来你的房间。\n");
	return 1;
}

int do_setowner(string arg)
{
	string oldowner;
	oldowner = (string)query("owner");
	set("owner",arg);
	write("你将房间的主人暂时设为"+arg+"。\n");
	call_out("set_back",60, oldowner);
	return 1;
}

int set_back(string oldowner)
{
	set("owner", oldowner);
	return 1;
}
