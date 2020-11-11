// a skeleton for user rooms
#define X_COOR 20
#define Y_COOR 2020
#define Z_COOR 10
#define R_FLAG 3083
#define OWNER "tyui"
#define CLASS "������"
inherit ROOM;
void create ()
{
  set ("short", "�쳤�ؾ���Զ��");
  set ("long", @LONG
����С�Ϻ�ңԶ�ļң����Ǹ����������С��쳤�ؾ���Զ��������İ���ܺ�
����ǳ��ɫ��ǽ���пð��㻨��ɢ����������������������̨��ʮ�Ĵ������ƽ
���ʵ磬�ϱ߰ڷ���һ�ŵ¹���Ƥɳ�����ǹ��������ġ�������עĿ�����컨
���ϵĶ�ʮ�ĿŲʵƣ�ÿ������С�Ϻ�ңԶ������ֵ����裬֪���쳤�ؾá���

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
  set("class", "������");
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
	write("������"+arg+"����ķ��䡣\n");
	return 1;
}

int do_setowner(string arg)
{
	string oldowner;
	oldowner = (string)query("owner");
	set("owner",arg);
	write("�㽫�����������ʱ��Ϊ"+arg+"��\n");
	call_out("set_back",60, oldowner);
	return 1;
}

int set_back(string oldowner)
{
	set("owner", oldowner);
	return 1;
}
