#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���ݾ�ͷ ");
        set("long", @LONG
�����������ţ�һ�ȣ�door1��ͨ�����棬�ǻ�·������һ�ȣ�door2��������
·��������ǿ������׵�����̽�ģ�ֻҪһ��̤�£�����ٲ����ˣ�û����֪����
�������ǻ�·��������Լ�ѡ��ȥ���ţ���ֻҪһ�����ţ��ͷ��߳�ȥ���ɡ�
LONG        );
        set("exits", ([ 
  "down" : __DIR__"tt3",
]));       
  set("item_desc", ([
            "door1": "���ź��ұ�����һģһ����\n",
            "door2": "����ȻʲôҲ���������������Ѿ��ӿ���...\n"
    ]) );
        set("coor/x",3300);
        set("coor/y",20);
        set("coor/z",20);
        set("no_magic",1);
        setup();
}
void init()
{
add_action("do_open","open");
add_action("do_say","say");
}
int do_open(string arg)
{
               object me;
                int urkee;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
if( arg == "door1")
        {
         me = this_player();
                 urkee=me->query("eff_kee");
         message_vision(HIR"$N��һ�ƿ��ţ�ͻȻ�е�һ��ãȻ���Ĵ�һƬ�ž���\n"NOR, me);
         message_vision("("+RED"$N������Ѫ���Ѿ�������в�����ʱ�����ܶ�����"+NOR+")\n", me);
         me->receive_wound("kee",urkee+1000);
                    } else
        if( arg == "door2")
        {
         me = this_player();
                 urkee=me->query("eff_kee");
         message_vision(HIR"$N��һ�ƿ��ţ�һ������Կ�ò����ٿ���ٶ����˳�����\n"NOR, me);
         message_vision("("+RED"$N������Ѫ���Ѿ�������в�����ʱ�����ܶ�����"+NOR+")\n", me);
         me->receive_wound("kee",urkee+1000);
            }
       return 1;
}

int do_say(string arg)
{
object me;
object room;
me=this_player();
 if(arg == "�������������������")
{message_vision(HIY "\n$N�ƿ����ţ���ǰ�ֳ������ޱȵ�Ϧ��... \n"NOR,this_player());
room = load_object(__DIR__"side");
             me->move(room);
return 1;
}
}