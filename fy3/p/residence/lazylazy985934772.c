// a skeleton for user rooms
#define X_COOR 0
#define Y_COOR 2010
#define Z_COOR 10
#define R_FLAG 516
#define OWNER "lazylazy"
#define CLASS "梦幻城　"
inherit ROOM;
void create()
{
set("short", "暖书阁");
set("long", @LONG
    屋子里罗罗列列全是书籍，可见此间主人爱书之甚。一
张青玉案，案上一只白玉瓶，瓶里插着几枝茶花。玉瓶旁铺
着张索笺，放着些笔墨砚石，还有个斗大的玉钵，装满了清
水，想是用来洗笔的。
    一美貌妇人，穿着件雪白的衣服，正坐在青玉案旁，手
托着香腮，瞧着瓶中茶花呆呆的出神。只见她天庭开阔，眉
目如画，皮肤更比那玉瓶还白上几分，那鲜艳的茶花与她一
比，也是黯然失色。

LONG
);
        set("exits", ([
"down" : "/p/residence/lazylazy985933156.c",
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
