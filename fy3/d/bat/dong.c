//3310,0,10
inherit ROOM;
void create()
{
        set("short", "���� ");
        set("long", @LONG
һ�������Ƶ���ʯ������������������������(huache)�� 
����ͨ��һ���������ɽ���� 
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"anbian",
		]));         
  set("item_desc", ([
            "huache": "�ƺ�������(dash)��ȥ,������...\n",
            "����": "�ƺ�������(dash)��ȥ,������...\n"
    ]) );
    set("coor/x",3310);
	set("coor/y",0);
	set("coor/z",10);
	set("no_magic",1); set("no_dazuo",1);

	setup();

}
void init()
{
 add_action("do_dash","dash");
}
int do_dash(string arg)
{
        object room;
        object me;
        me = this_player();
        message_vision("$Nһ���Ӿ������˻�����
$NԽ׹Խ�죮������$N�ƺ�������һ���ҽУ�����ë���Ȼ��\n", me);
        room = load_object(__DIR__"dong1");
        me->move(room);
        me->start_busy(2);
        return notify_fail("");
       
}

