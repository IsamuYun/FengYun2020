// seaside.c
inherit ROOM;
void create()
{
        set("short", "�������ɿ�");
        set("long", @LONG
��������Ҭ�ָ��ʣ����¼�ľ���ף���Ȼ����Ϊ����֮������̲�����ǽ�׵�
ϸɳ��һ�Ų��ϣ������ϸɳ�ӽ�ֺ�������������������ϣ��ͺ�������޻���һ
����������������⣬һ�����꣬������ȴ���˼����ɱ����֮�¡�һ��С·����
���ۣ�����ɽ�塣�����ǳ������Ŀ������ƹݣ����潸ʯ�ܲ���������Ϊ�վ���
���ﲻ֪����ʲôʱ��ʼ��һ��С��վ�������뿴�ơ���������
LONG
        );
        set("exits", ([ 
		  "north" : __DIR__"cloudinn",
          "south" : __DIR__"rock0",
          "east"  : __DIR__"uproad0",
		]));
        set("objects", ([
        __DIR__"npc/waiter" : 1,
		"/u/ghost/npc/obj/pipe" :1,
                        ]) );
		set("item_desc", ([
                "sign": @TEXT

�����·��ʿ��С���Ƴ���վ���񣬵�Ȼ��Ҫ��ȡһ�������ѿ���
ȥ���Ƴ�(gofengyun)   ��ʮ������      


TEXT
        ]) );
	     set("outdoors", "tieflag");
        set("coor/x",2000);
	set("coor/y",-200);
	set("coor/z",10);
	setup();
}
void init()
{	
	add_action("go_fy","gofengyun");
}

void pipe_notify()
{
        object ob;

        message("vision","һ������������԰��ߣ���������ؼ�ľ��ţ����ﵽԶ����\n" , this_object() );
		call_out("boat_come",5);
}
void boat_come()
{
	object boat;
	object woman;
	object *inv;
	object who, oob;
	int i;
	
	if (query("exits/down")) return;
	if (!objectp(boat=find_object(__DIR__"boat")))
		boat=load_object(__DIR__"boat");
	inv=all_inventory(boat);
	if (!(oob=present("old boater",boat)) || boat->query("exits/up")|| !living(oob))
	{              
			message("vision","�����ã�������ʲôҲû�г��֡�\n",this_object());
			return;
	}
	for (i=0;i<sizeof(inv);i++)
	    if (userp(inv[i]))
		{
			message("vision","�����ã�������ʲôҲû�г��֡�\n",this_object());
			return;
		}
	message("vision","���˰��Σ�һ���洬�����е���������׿����һ���׷��ԲԵ��ϸ��ˣ����ҡ�֡�\n",this_object());
	message("vision","������˵�������ϴ��ɣ���\n",this_object());
	boat->set("exits/up",__DIR__"island");
	boat->set("no_fight",1);
	boat->set("no_magic",1);
	set("exits/down",__DIR__"boat");
	call_out("boat_leave",10,boat);
}
void boat_leave(object boat)
{
	if (query("exits/down")) delete("exits/down");
	if (boat->query("exits/up")) boat->delete("exits/up");
	message("vision","�����ӳ���һ�㣬���۾��뿪�˺�����\n",this_object()); 
	boat->set_temp("mark/dest","mainland");
	message("vision","�����ӳ���һ�㣬���۾��뿪�˺�����\n",boat);
	boat->delete("no_fight");
	boat->delete("no_magic");
	boat->boat_run(0);
}
int go_fy()
{
	object me,gold;
	int lv;
	me = this_player();
	gold = present("silver_money", me);
	lv = me->query("level");
	if (lv>9 )
	{
		if (!gold)
			return notify_fail("ȥ���Ƴ���Ҫ֧����ʮ������!\n");
		if (gold->query_amount() < 20)
			return notify_fail("ȥ���Ƴ���Ҫ֧����ʮ������!\n");
		message_vision("$N�����˵�С����ʮ�����������������С�\nֻ����С�����ų���˵��:���Ƴǡ����������ͷ����$N�󺰣��͹������ˣ�\n����ʼ�����Ƴǳ����ˡ�\n......\n......\n......\n......\n���պ������ڵ��˷��Ƴ��ˡ����򺰵����͹٣������³��ˣ�\n",me);
		gold->add_amount(-20);
	}
	else 
	{
		message_vision("$N���������С�\nֻ����С�����ų���˵��:���Ƴǡ����������ͷ����$N�󺰣��͹������ˣ�\n����ʼ�����Ƴǳ����ˡ�\n......\n......\n......\n......\n���պ������ڵ��˷��Ƴ��ˡ����򺰵����͹٣������³��ˣ�\n",me);
	}
	me ->move("/d/fy/fqkhotel");
	return 1;
}
