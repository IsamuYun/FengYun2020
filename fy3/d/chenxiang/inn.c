inherit ROOM;

void create()
{
        set("short", "��������ջ");
        set("long", @LONG
������ض������˿�ջ����վ���������񣬳���Ҳ��������ҿ�ջ��
ר��������ʿʹ�ã������뿴�ơ�������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxe1",
]));
        set("objects", ([
        __DIR__"npc/waiter" : 1,
                        ]) );
		set("item_desc", ([
                "sign": @TEXT

�����·��ʿ��С���Ƴ���վ���񣬵�Ȼ��Ҫ��ȡһ�������ѿ���
ȥ����(goguanwai)   ʮ������      
ȥ���Ƴ�(gofengyun)   ʮ������

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
	add_action("go_fy","gofengyun");
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
			return notify_fail("ȥ������Ҫ֧��ʮ������!\n");
		if (gold->query_amount() < 10)
			return notify_fail("ȥ������Ҫ֧��ʮ������!\n");
		message_vision("$N�����˵�С��ʮ�������������������С�\nֻ����С�����ų���˵��:���⡣���������ͷ����$N�󺰣��͹������ˣ�\n������ʼ����������ˡ�\n......\n......\n......\n......\n���պ��������ڵ��˹����ˡ����򺰵����͹٣������³��ˣ�\n",me);
		gold->add_amount(-10);
	}
	else 
	{
		message_vision("$N�����������С�\nֻ����С�����ų���˵��:���⡣���������ͷ����$N�󺰣��͹������ˣ�\n������ʼ����������ˡ�\n......\n......\n......\n......\n���պ��������ڵ��˹����ˡ����򺰵����͹٣������³��ˣ�\n",me);
	}
	me ->move("/u/guanwai/inn");
	return 1;
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
			return notify_fail("ȥ������Ҫ֧��ʮ������!\n");
		if (gold->query_amount() < 10)
			return notify_fail("ȥ������Ҫ֧��ʮ������!\n");
		message_vision("$N�����˵�С��ʮ�������������������С�\nֻ����С�����ų���˵��:���Ƴǡ����������ͷ����$N�󺰣��͹������ˣ�\n������ʼ�����Ƴǳ����ˡ�\n......\n......\n......\n......\n���պ��������ڵ��˷��Ƴ��ˡ����򺰵����͹٣������³��ˣ�\n",me);
		gold->add_amount(-10);
	}
	else 
	{
		message_vision("$N�����������С�\nֻ����С�����ų���˵��:���Ƴǡ����������ͷ����$N�󺰣��͹������ˣ�\n������ʼ�����Ƴǳ����ˡ�\n......\n......\n......\n......\n���պ��������ڵ��˷��Ƴ��ˡ����򺰵����͹٣������³��ˣ�\n",me);
	}
	me ->move("/d/fy/fqkhotel");
	return 1;
}