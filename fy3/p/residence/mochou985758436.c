// a skeleton for user rooms
#define X_COOR 20
#define Y_COOR 2020
#define Z_COOR 10
#define R_FLAG 29
#define OWNER "mochou"
#define CLASS "狂人帮"
inherit ROOM;
void create()
{
set("short", "观星台");
set("long", @LONG
透过深蓝色的天幕可以看到点点繁星放射着令人注目的光辉，它们围绕在
海港周围，从半空倒映在湛蓝的海面上，随着波浪，晃动着，闪烁着，像
一串流动着的珍珠。而月亮高高的挂在天幕。那么皎洁，那么明亮。像一
面光辉四射的银盘似的，从那平静的大海里涌了出来。给大海带来一片鱼
鳞似的银波。
在这幽美的夜色中，夜风轻飘飘地吹拂，白云轻拥着莫愁在低声私语……

LONG
);
        set("exits", ([
"down" : "/p/residence/mochou985756134.c",
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
