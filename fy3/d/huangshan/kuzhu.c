// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����Ϫ");
        set("long", @LONG
��;ʢ����������ϪˮҲ�е�����ɬζ��������ҩ��ڣ������
����ҩ����Ʒ����������֮����Ȼ������Ȫ�����ڽⷦ�����а�����
�������ص�����ȡ�����ҩ�����Ǳ���ɽ���ڴ˷�������
LONG
        );
        set("exits", ([ 
  "southup" : __DIR__"jiulong",
]));
        set("objects", ([
                __DIR__"npc/snake" : 2,
       ]) );
        set("item_desc", ([
               "mountain": "ɽ�䶸�����������֮�������ƺ�����������(climb)��ȥ��\n",
      		"ɽ": "ɽ�䶸�����������֮�������ƺ�����������(climb)��ȥ��\n",
      		"up": "ɽ�䶸�����������֮�������ƺ�����������(climb)��ȥ��\n"
]) );
        set("outdoors", "huangshan");
	set("coor/x",-540);
	set("coor/y",-480);
	set("coor/z",10);
	setup();
}
void init()
{
	add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "ɽ" || arg == "hill" || arg == "up")
        {
        me = this_player();
        message_vision("$N��������ɽ����ȥ��\n", me);
        me->move(__DIR__"huangshan.c");
        return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}

