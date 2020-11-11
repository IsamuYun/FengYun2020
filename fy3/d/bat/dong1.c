#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����Լ���������˷�ŭ�ľ������������̴ܶ٣�Ȼ��һ���ֹ���ƽ���� 
��ƽ����������ȫ���ڰ�����Ȼ������Ǳ����Σ�գ� �㷢���ұ���һ��
�ţ�rightdoor������Ц�����ź󷢳����ģ�Ц��ͻȻ�����������������
�������������Ķ��ջ󣬼�ֱ�����޷��ܾ������������ƶ�����������һ��
�ţ�leftdoor���������ź�û��������
LONG
  );
  set("item_desc", ([
            "leftdoor": "���ź��ұ�����һģһ����\n",
            "rightdoor": "����ȻʲôҲ���������������Ѿ��ӿ���...\n"

    ]) );
	set("no_magic",1); set("no_dazuo",1);

    set("objects",([
        	__DIR__"npc/bianfu" : 1,			
       	]) );
//(3310,0,-30)
    set("coor/x",3310);
	set("coor/y",0);
	set("coor/z",-30);
	setup();
}
void init()
{

add_action("do_open","open");
}
int do_open(string arg)
{
        object room;
        object me;
		int urkee;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "rightdoor")
        {
         me = this_player();
         message_vision(HIR"$N��һ�ƿ��ţ�����һ����Ͷ����Ļ������������˹�ȥ��\n"NOR, me);
         room = load_object(__DIR__"room1");
	     me->move(room);
         return notify_fail("");
	    }
        if( arg == "leftdoor")
        {
         me = this_player();
		 urkee=me->query("eff_kee");
         message_vision(HIR"$N��һ�ƿ��ţ�һ������Կ�ò����ٿ���ٶ����˳�����\n"NOR, me);
         message_vision("("+RED"$N������Ѫ���Ѿ�������в�����ʱ�����ܶ�����"+NOR+")\n", me);
         me->receive_wound("kee",urkee+1000);
//	     me->die();
         return notify_fail("");
	    }
       return 1;
        
}


