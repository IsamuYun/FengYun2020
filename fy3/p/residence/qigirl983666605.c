// a skeleton for user rooms
#define X_COOR 10
#define Y_COOR 2040
#define Z_COOR 20
#define R_FLAG 2071
#define OWNER "qigirl"
#define CLASS "������ҡ�"
inherit ROOM;
void create()
{
set("short", "��ʹ��");
set("long", @LONG
����ƾ����Ϫ����Ϫ֮ˮ����ɽ�������£�����������ɽ�ƶ����͵�С̶��
ˮ���䲻�ͼ���������ɫ��ѣ�������Ȼ�Ĺ�ͬ������Ϊһ�塣�Ա߻���
һ�ţ����������Ϫ���Ŷ���ˮ���˳ơ���ʹ�š���С��ʹ����������
�������ڴˣ�����ǧ�ž�����

LONG
);
        set("exits", ([
"southdown" : "/p/residence/qigirl983386013.c",
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
