
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ��������ʵ�����أ������ͱ���������ݲ����������м�ֻ����
�ӿ����ӹ�����������������ȫ��������
LONG
        );
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/redlama" : 1,
        ]) );

        set("coor/x",-1130);
	set("coor/y",-20);
	set("coor/z",-10);
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
        if( arg == "valley" || arg == "up" || arg == "����")
        {
        me = this_player();
        message_vision("$Nץ��ͻ����ʯ�ǣ�������˳�Źȱ�������ȥ��\n", me);
        me->start_busy(2);
        call_out("fliping",2,me);
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
        me->move(__DIR__"cliff");
        message_vision("$N˳�Źȱ�����������\n", me);
	}
        return 1;
}

