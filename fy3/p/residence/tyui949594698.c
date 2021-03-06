// a skeleton for user rooms
#define X_COOR 20
#define Y_COOR 2020
#define Z_COOR 10
#define R_FLAG 3083
#define OWNER "tyui"
#define CLASS "锦衣卫"
inherit ROOM;
void create ()
{
  set ("short", "天长地久紫远阁");
  set ("long", @LONG
这是小紫和遥远的家，他们给这里起名叫「天长地久紫远阁」屋子里的摆设很豪
华，浅紫色的墙边有棵百香花正散发着阵阵香气，靠北边有台三十四寸的索尼平
面大彩电，南边摆放着一排德国真皮沙发，是供客人做的。最引人注目的是天花
板上的二十四颗彩灯，每天晚上小紫和遥远都会快乐的跳舞，知道天长地久……

LONG);

  set("objects", ([ /* sizeof() == 3 */
  "/mlb/obj/vcd" : 1,
  "/zki/bed" : 1,
  "/zki/gui" : 1,
]));
  set("owner", "tyui");
  set("room_flag", 3083);
  set("valid_startroom", 1);
  set("NONPC", 1);
  set("class", "锦衣卫");
  set("no_magic", 1);
  set("coor", ([ /* sizeof() == 3 */
  "z" : 10,
  "y" : 2020,
  "x" : 20,
]));
  set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"room3.c",
]));

  setup();
  replace_program(ROOM);
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
