// a skeleton for user rooms
#define X_COOR 0
#define Y_COOR 2020
#define Z_COOR 0
#define R_FLAG 2565
#define OWNER "lazylazy"
#define CLASS "梦幻城　"
inherit ROOM;
void create()
{
set("short", "昙香小筑");
set("long", @LONG
只见一带粉垣，里面数楹修舍，几丛翠竹遮映。进门便是曲折游廊，阶下石子漫成甬路，上面小小几间房舍。屋子两旁异草散漫，牵藤引蔓，垂帘绕柱，或如翠带飘飘，或如金绳蟠屈，味香气馥，非凡花可比。间有小桥流水，其水清清，曲折萦纡。池边两行垂柳，杂以桃杏，遮天蔽日，竟无一些尘土。度桥而去，可至后院，院内红枫白杨漫路，又是另一番景象。

LONG
);
        set("exits", ([
"south" : __DIR__"lazylazy985933156",
"east" : "/p/residence/room3.c",
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
