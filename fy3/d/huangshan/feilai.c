// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����ʯ");
        set("long", @LONG
��ƽ̹��ɽ��֮�ϣ�ͻȻð��һ��ʯͷ���ƺ����˷���һ˵�����ʵ
�����Խ��͡�ʯ��⻬���������֡�����ʯ����Զ��ʯͷ���ϴ���ϸ����
��ҡ�β�ֹ��ʵ�����˷�����˼��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"guangming",
  "west" : __DIR__"paiyun",
]));
        set("item_desc", ([
                "����ʯ": "�����������һ�ƣ�push��\n",
                "stone": "�����������һ�ƣ�push��\n"
        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-600);
	set("coor/y",-530);
	set("coor/z",30);
	setup();
}
void init()
{ add_action("do_push","push");}
int do_push()
{
object me;
me=this_player();
me->receive_damage("kee",30);
message_vision("$N�þ�ȫ�����������������Ʒ���ʯ������ʯ�ƺ����˻Σ�\n",me);
return 1;
}
