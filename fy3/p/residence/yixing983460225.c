// a skeleton for user rooms
#define X_COOR 10
#define Y_COOR 2070
#define Z_COOR 0
#define R_FLAG 2573
#define OWNER "yixing"
#define CLASS "大理"
inherit ROOM;
void create()
{
set("short", "红叶山庄正厅");
set("long", @LONG
红叶山庄正厅：
    这一间非常豪华宽敞的会客厅，客厅正北面放着两把红木雕花
椅，两边整齐的摆放着若干稍小的红木椅，北面墙上挂着一幅“笑看
风云”图。似乎有很大的玄机在里面，在图的上面是一块巨大的牌匾，上
书“雄霸天下”四个镏金大字。这是庄内举行重大会议和接待贵客
的地方，每当重要的日子，庄主和夫人就会在此和众人见面。

LONG
);
        set("exits", ([
"north" : __DIR__"ttab984275228",
"west" : __DIR__"yixing983464343",
"east" : __DIR__"ttab983460516",
"south" : "/p/residence/ttab983288506.c",
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
