// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
�ഫ��Ů洲�ʯ������ȡ����ɽʯ�о�Ӣ���ڣ�ɽɫ���ɽ���죬
��������ɫ��ɽ����ľҲ����ï�ܣ�ɽ�����ƣ��������˵��ɹ��ֺ��
�����ߣ���֮����ɽ�ٻ��ƣ��������ߣ������������˵��ˡ�ԶԶ����
��ԯ�壬ȴ��������ȥ��
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"songgu",
  "north" : __DIR__"xuanyuan",
]));
        set("outdoors", "huangshan");
	set("coor/x",-650);
	set("coor/y",-530);
	set("coor/z",40);
	setup();
}
void init()
{
add_action("do_chop","chop");
}

int do_chop(string arg)
{

        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ����ʲô��\n");
                return 1;
        }
        if( arg == "vine" || arg == "ɽ��")
	{
        me = this_player();
        obj = me->query_temp("weapon");
        if( !obj )
        {
        write("������֣���ô����\n");
        return 1;
        }
        if( obj->query("jungle"))
        {
        if( !query("exits/north") ) {
        set("exits/north", __DIR__"xuanyuan");
        message_vision(sprintf("$N�����е�%s����һ���򱱵�·��\n",obj->name()),
                me);
        me->start_busy(1);
        }
        else
        message_vision(sprintf("$N�����е�%s�����Ƶ�ɽ�٣�\n",obj->name()),
                me);
        }
        else
        message_vision(sprintf("$N�����е�%s�����Ƶ�ɽ��һ���ҿ���\n",obj->name()),
                me);
        }
        else
         write("��Ҫ����ʲô��\n");
                return 1;
}

void reset()
{
::reset();
delete("exits/north");
}
