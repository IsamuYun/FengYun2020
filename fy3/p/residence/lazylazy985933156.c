// a skeleton for user rooms
#define X_COOR 0
#define Y_COOR 2010
#define Z_COOR 0
#define R_FLAG 2060
#define OWNER "lazylazy"
#define CLASS "梦幻城　"
inherit ROOM;
void create()
{
set("short", "迎客厅");
set("long", @LONG
    大厅很宽敞，但绝不空旷。四壁悬满字画，隽秀洒脱，皆出
自此间女主人之手。屋里锦墩玉几，罗列珍饶。正中一个
紫金香炉，袅袅婷婷的缭绕，如兰似麝，另人心旷神怡，
却不燃的知是什么香。

LONG
);
        set("exits", ([
"up" : __DIR__"lazylazy985934772",
"north" : "/p/residence/lazylazy985687794.c",
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
