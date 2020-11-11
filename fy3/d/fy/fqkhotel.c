inherit ROOM;

void create()
{
        set("short", "����˿�ջ");
        set("long", @LONG
ǰ������һ������˫�ɵľ޻������Ź��Ŷ�ԧ��������ϵ�ż���СС�Ļ�ͭ���塣
΢���ӹ������巢������ö��Ķ�����������������Ŷ���Ĵ��������ϸ�������
�֡������Ϻ���һ�������֡�����͸�����վ�����Ƴ���վ���������뿴�ơ�������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"swind1",
]));
        set("objects", ([
        __DIR__"npc/waiter" : 1,
		 __DIR__"npc/gmss" : 1,
                        ]) );
		set("item_desc", ([
                "sign": @TEXT

�����·��ʿ��С���Ƴ���վ���񣬵�Ȼ��Ҫ��ȡһ�������ѿ���
ȥ����(goguanwai)   ��ʮ������      
ȥ����(gochenxiang)   ʮ������

TEXT
        ]) );

        set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
     
}
void init()
{	
	add_action("go_guanwai","goguanwai");
	add_action("go_chenxiang","gochenxiang");
}
int go_guanwai()
{
	object me,gold;
	int lv;
	me = this_player();
	gold = present("silver_money", me);
	lv = me->query("level");
	if (lv>9 )
	{
		if (!gold)
			return notify_fail("ȥ������Ҫ֧����ʮ������!\n");
		if (gold->query_amount() < 20)
			return notify_fail("ȥ������Ҫ֧����ʮ������!\n");
		message_vision("$N�����˵�С����ʮ�����������������С�\nֻ����С�����ų���˵��:���⡣���������ͷ����$N�󺰣��͹������ˣ�\n����ʼ����������ˡ�\n......\n......\n......\n......\n���պ������ڵ��˹����ˡ����򺰵����͹٣������³��ˣ�\n",me);
		gold->add_amount(-20);
	}
	else 
	{
		message_vision("$N���������С�\nֻ����С�����ų���˵��:���⡣���������ͷ����$N�󺰣��͹������ˣ�\n����ʼ����������ˡ�\n......\n......\n......\n......\n���պ������ڵ��˹����ˡ����򺰵����͹٣������³��ˣ�\n",me);
	}
	me ->move("/u/guanwai/inn");
	return 1;
}
int go_chenxiang()
{
	object me,gold;
	int lv;
	me = this_player();
	gold = present("silver_money", me);
	lv = me->query("level");
	if (lv>9 )
	{
		if (!gold)
			return notify_fail("ȥ������Ҫ֧��ʮ������!\n");
		if (gold->query_amount() < 10)
			return notify_fail("ȥ������Ҫ֧��ʮ������!\n");
		message_vision("$N�����˵�С��ʮ�����������������С�\nֻ����С�����ų���˵��:���㡣���������ͷ����$N�󺰣��͹������ˣ�\n����ʼ����������ˡ�\n......\n......\n......\n......\n���պ������ڵ��˳����ˡ����򺰵����͹٣������³��ˣ�\n",me);
		gold->add_amount(-10);
	}
	else 
	{
		message_vision("$N���������С�\nֻ����С�����ų���˵��:���㡣���������ͷ����$N�󺰣��͹������ˣ�\n����ʼ����������ˡ�\n......\n......\n......\n......\n���պ������ڵ��˳����ˡ����򺰵����͹٣������³��ˣ�\n",me);
	}
	me ->move("/d/chenxiang/inn");
	return 1;
}