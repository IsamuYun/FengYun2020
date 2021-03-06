// a skeleton for user rooms
#define X_COOR 0
#define Y_COOR 2020
#define Z_COOR 0
#define R_FLAG 29
#define OWNER "hfh"
#define CLASS "月形门"
inherit ROOM;
void create()
{
set("short", "冰雪仙境");
set("long", @LONG
四周树木葱翠，轻烟薄雾，出没于枝叶之间。良夜寂寂，足踏软草，竟连脚步
也是悄无声息。将到山顶，转了两个弯，一阵清风，四周全是花香。月色如霜
放眼望去，满坡尽是红色、白色、黄色的玫瑰。藤圆纪香从篮里抽出一支洞箫
轻柔道：我吹一首曲子给你听。轻轻吹了起来。胡斐但觉箫声缠绵，如怨如慕
一颗心似乎也随着婉转箫声飞扬，飘飘荡荡地，如在仙境，非复人间。。。

LONG
);
        set("exits", ([
"southeast" : "/p/residence/room3.c",
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
