// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����Դ���춼��������壬Ȼ������¯���޺���������¾��۶��£�
һ��һ̶�����پ�̶����˵�����ÿ�����֮����ˮ�����������
�����ۣ��۶����ۣ�����ǧ����ڣ�����������裬��̬���
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"baizhang",
//  "up" : "/d/shenshui/midao1",
  "northdown" : __DIR__"kuzhu",
]));
        set("item_desc", ([
                "����": "������Ȼ�����ޱȣ���ʯ��ͻأ��ƽ����������Ŵ��⣨cliff������climb����ȥ��\n"
        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-540);
	set("coor/y",-490);
	set("coor/z",20);
	setup();
}
void init()
{
add_action("do_climb","climb");
}
int do_climb(string arg)
{
object me;
me= this_player();
if(!arg || arg != "cliff") return 0;
message_vision("$Nץס������ͻ����ʯ�飬����С����ȥ��\n", me);
me->start_busy(2);
call_out("arrive",2,me);
return 1;
}
int arrive(object me)
{
if(me)
{
message_vision("$Nһʧ�֣����������������\n",me);
me->receive_wound("kee",100);
}
return 1;
}
