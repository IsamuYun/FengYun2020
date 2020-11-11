// Room: /d/oldpine/epath2.c

inherit ROOM;

void create()
{
        set("short", "Сʯ��");
        set("long", @LONG
��������վ��һ��������̦�Ĺ����ϣ�������һ��ɽ����������Ȫ
����ʯ֮����ɽ�±������ű��߲�Զ����һ���ٲ�����ɽ��������һ��
�����㴹���������ٲ����Ե�ʯ��ʮ�ֶ��ͣ��߶Ⱥ�ɽ���Ե��������
�˽�������ʮ�ɡ�
LONG
        );
        set("item_desc", ([
                "waterfall":
                        "����ٲ��������ɸߵ�ɽ���ϳ弤���£�����һ��ɽ���׵�Сˮ̶��\n"
                        "ˮ̶���ߵ�ʯ�ڴ�����������(vine)����ע�⵽�ٲ������ƺ�\n"
                        "��ʲ�ᶫ���ڷ����⡣\n",
                "vine":
                        "������һ������������ȽϽ������������ץס(hold)����������\n"
                        "�ܲ�����̩ɽһ������ȥ�������ٲ�������ʲ�᣿\n"
                        "���ˣ�������һ�㣬����ʯ�������Ǹ�Լ���ɵ�ɽ�����....��\n"
        ]) );
        set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/oldpine/epath1",
  "east" : "/d/oldpine/epath3",
]));
        set("outdoors", "oldpine");

        set("coor/x",-260);
	set("coor/y",-330);
	set("coor/z",100);
	setup();
}

void init()
{
        add_action("do_hold_vine", ({ "hold", "grab" }) );
}

int do_hold_vine(string arg)
{
        if( !arg || arg!= "vine" )
                return notify_fail("��Ҫץסʲ�᣿\n");
        message_vision("$N����ʯ�ŵĻ�������������Զ����һ������ץȥ....\n",
                this_player());
        if( random((int)this_player()->query_skill("dodge")) < 5 ) {
                message_vision("\nֻ����һ��ɱ���ĲҽУ�$N�Ѿ���ɽ����׹����ȥ��\n\n", this_player());
                tell_room(__DIR__"waterfall",
                        "���������˸������У�һ����Ӱ���Ϸ���������������ͨ��һ������̶�С�\n");
                this_player()->move(__DIR__"waterfall");
        } else {
                message_vision("$N�ֽ�������ʸ�������������������ɽ��....��\n",
                        this_player() );
                tell_room(__DIR__"passage",
                        "��Ȼһ����Ӱ���ϱߵ���Ļ���˳�����\n");
                this_player()->move(__DIR__"passage");
        }
        return 1;
}
