#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���ݾ�ͷ");
        set("long", @LONG
�����������ţ�һ�ȣ�door1��ͨ�����棬�ǻ�·������һ�ȣ�door2��������
·��������ǿ������׵�����̽�ģ�ֻҪһ��̤�£�����ٲ����ˣ�û����֪����
�������ǻ�·��������Լ�ѡ��ȥ���ţ���ֻҪһ�����ţ��ͷ��߳�ȥ���ɡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"tianti3",
]));
        set("outdoors", "bat");
        set("coor/x",3310);
	set("coor/y",20);
	set("coor/z",20);
	set("no_magic",1);
        set("no_clean_up", 0);
        set("item_desc", ([
		"door1" : "�����ż�������ȫһģһ���ģ�û�����ܿ������Ĳ���������Ĳ��\n",
		"door2" : "�����ż�������ȫһģһ���ģ�û�����ܿ������Ĳ���������Ĳ��\n",
        ]) );
	setup();
        
}

void init()
{
        add_action("do_say", "say");
        add_action("do_open", "open");
}


int do_say(string arg)
{
        if( !arg || (arg!= "�������������������" && arg!="�Ҿ�����ڣ�" && arg!="I won't regret!" && arg!="����������ͨ�ˡ�" && arg!="����������㹻��") )
        
                return 0;
        else
        {
        	message_vision(HIY"$N�ƿ����ţ���ǰ�ֳ������ޱȵ�Ϧ��...\n"NOR,
                        this_player() );
                this_player()->move(__DIR__"anbian1");
                return 0;
	}
}

int do_open(string arg)
{
        if( !arg || (arg!= "door1" && arg!="door2") )
                return notify_fail("��Ҫ��ʲ�᣿\n");
        else
        {
        	message_vision(HIB"$N�ƿ����ţ�ʧ�������������Ԩ�����뿪��������
һɲ�Ǽ䣬�����ǰ�ָ��ֳ����İ����˵�Ц��...\n"NOR,
                        this_player() );
                this_player()->die();
                return 1;
	}
}