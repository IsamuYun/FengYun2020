// a skeleton for user rooms
#define X_COOR 10
#define Y_COOR 2020
#define Z_COOR 10
#define R_FLAG 3703
#define OWNER "bll"
#define CLASS "地狱阿修罗　"
inherit ROOM;
void create()
{
set("short", "掌门人华英雄之家");
set("long", @LONG
             英雄是天下第一地武林高手，他是个好人也是个杀手
岩溪汇池，壮若大盆，分三叠，水清石丽，翠碧交加，故俗称清碧溪。溪前满坡茶
园，清翠碧绿，清香扑鼻。感通茶，在南诏时代就有种植。举首看苍山，峰峦挺
秀，绵延十二三里。
                                这是英雄剑划地。

LONG
);
        set("exits", ([
"up" : __DIR__"bll951517371",
"down" : "/p/residence/room3.c",
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
