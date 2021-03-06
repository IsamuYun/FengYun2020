// a skeleton for user rooms
#define X_COOR 20
#define Y_COOR 2020
#define Z_COOR 0
#define R_FLAG 29
#define OWNER "mochou"
#define CLASS "狂人帮"
inherit ROOM;
void create()
{
set("short", "听涛小筑");
set("long", @LONG
这里是个精致高雅的房间，地上铺着厚厚的波斯毯，壁上高悬着水晶灯，
散发出淡淡的光芒，给人无限华丽而又非常柔和的感觉。碧波蓝天成一色
的大海离此不远，阵阵涛声传来，如空谷回音。透过挂着湘妃竹帘的窗子，
可以看到远处银光闪闪的海面和沙鸥翔集的天空。海面一碧万倾，铺展开
的浪花愉快的跳跃着。天空几朵云儿漫漫地散开，形成两排挂在天空的字：
白衣一袭仗剑侠义走风云
莫问世事只为柔情亦无愁

LONG
);
        set("exits", ([
"up" : __DIR__"mochou985758436",
"south" : "/p/residence/baiyun982545370.c",
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
