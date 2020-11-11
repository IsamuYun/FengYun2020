// a skeleton for user rooms
#define X_COOR 10
#define Y_COOR 2030
#define Z_COOR 10
#define R_FLAG 2071
#define OWNER "qigirl"
#define CLASS "关外胡家　"
inherit ROOM;
void create()
{
set("short", "百花谷");
set("long", @LONG
一月兰花， 二月桃花媚， 三月蔷薇展红艳， 
四月牡丹是尊贵， 五月石榴鲜欲醉，
六月鸡冠傲独帜， 七月荷花俏绝尘， 
芬芳桂花八月香， 九月菊花淡悠悠， 
十月芦苇扇秋凉， 海棠迎冬十一颤，
十二梅花独坐寒枝， 笑迎春又来。
这里四季如春，风景如画，是阳光普照和小天使定情的地方。。。

LONG
);
        set("exits", ([
"northup" : __DIR__"qigirl983666605",
"southdown" : "/p/residence/room3.c",
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
