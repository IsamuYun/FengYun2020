
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������Ϲ�ͺͺ�ģ�����һ���ľ�ʯʲôҲû�С��������ɫ�ƺ�
Ҳ�ر𰵵���������ʹ�˸е������ĻҰ�����������һ���޵ף��������ɵ�
���ȡ�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"mroad2",
]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/poslave" : 2,
        ]) );
        set("item_desc", ([
                "����": "�ȱڲ����ܹ⻬�����ƺ���һ��ϣ��������(climb)��ȥ��\n"
        ]) );


        set("coor/x",-1130);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-1130);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}
void init()
{
        add_action("climbing", "climb");
}

int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "valley" || arg == "down" || arg == "����")
        {
        me = this_player();
        message_vision("$Nץ��ͻ����ʯ�ǣ�������˳�Źȱ�������ȥ��\n", me);
        me->start_busy(7);
        call_out("fliping",7,me);
        me->stop_busy();
        return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}
int fliping(object me)
{
	if( !me->is_ghost()) {
        me->move(__DIR__"valley");
        message_vision("$N˳�Źȱ�����������\n", me);
	}
        return 1;
}

