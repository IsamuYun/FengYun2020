// work.c
//#include "/feature/damage.c"

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ǡ�˲���ɽʢ�������ϵ�ʯ�ϡ����������������ܶ��˶���������Ͷ��š�
���Լ��ĺ�ˮȥ��ȡһЩ���롣ÿ�������﹤�����˶������õ�һ�ݺܹ�ƽ��
���ꡣ���������ææµµ�Ĺ����ţ��ſڹ���һ������(sign)��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"octo5",
]));

        set("item_desc", ([
                "sign": @TEXT
��������ȱ���֣������Ӷһ���̹����ɻ

work     ��ʼ������

TEXT
        ]) );
    set("no_fight", 1);
    set("no_magic", 1);
        set("coor/x",-1230);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",-1230);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_work", "work");
}

int do_work(string arg)
{
        object ob;
        object me;

        me = this_player();
if(me->is_busy()) return notify_fail("��Ķ�����û����ɣ����ܹ�����\n");
message_vision("$N����Ĺ������ڽ����ˣ�����Ҳ�۵�Ҫ��\n", 
me);
me->add("gin",-30);
me->add("sen",-30);
//receive_damage("gin",30,me);
//receive_damage("sen",30, me);
ob = new("/obj/money/silver");
ob->move(me);
message_vision("�ϰ��$N˵��������Ĺ�Ǯ��\n", me);
me->start_busy(1);
return 1;
}
