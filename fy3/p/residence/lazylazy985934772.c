// a skeleton for user rooms
#define X_COOR 0
#define Y_COOR 2010
#define Z_COOR 10
#define R_FLAG 516
#define OWNER "lazylazy"
#define CLASS "�λóǡ�"
inherit ROOM;
void create()
{
set("short", "ů���");
set("long", @LONG
    ��������������ȫ���鼮���ɼ��˼����˰���֮����һ
�����񰸣�����һֻ����ƿ��ƿ����ż�֦�軨����ƿ����
�������㣬����Щ��ī��ʯ�����и�������񲧣�װ������
ˮ����������ϴ�ʵġ�
    һ��ò���ˣ����ż�ѩ�׵��·��������������ԣ���
��������������ƿ�в軨�����ĳ���ֻ������ͥ������ü
Ŀ�续��Ƥ����������ƿ�����ϼ��֣������޵Ĳ軨����һ
�ȣ�Ҳ����Ȼʧɫ��

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
