#include <room.h>
inherit ROOM;
int do_dash(string arg);
void create()
{
  set("short","��ľ��");
  set("long",@LONG
��ľ�ַǳ���������ʪ�����к���ζ�������������ô��һƬ
��ľ��(bush)�е��ǳ��Ծ��������ƺ�����û��·�����ܳ����˰�
�˸ߵ��Ӳݡ�
LONG
  );
  set("exits",([
            "west" :"/d/tieflag/searoad1",
               ]));
  set("item_desc", ([
            "bush": "��Ƭ��ľ��̫����,Ҫ���ȥ����ֻ��Ӳ��ǰ����dash���ˡ�\n",
            "��ľ��": "��Ƭ��ľ��̫����,Ҫ���ȥ����ֻ��Ӳ��ǰ����dash���ˡ�\n"

    ]) );

    set("outdoors", "bat");
	set("no_magic",1);

    set("coor/x",1100);
	set("coor/y",-290);
	set("coor/z",-10);

	setup();
//    replace_program(ROOM);
}

void init()
{

add_action("do_dash","dash");
}
int do_dash(string arg)
{
        object room;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ���Ķ��ꣿ\n");
                return 1;
        }
        if( arg == "bush" || arg == "��ľ��")
        {
         me = this_player();
		 if(me->query("force")>300)
		 {
          message_vision("$Nʹ������ľ����һ�������һ����ͷ���˽�ȥ��\n", me);
          room = load_object(__DIR__"lin2");
	      me->move(room);
		  me->set("force",0);
		  me->set("mana",0);
	      me->set("atman",0);
  
          return notify_fail("");
		 }
		 else
		 {
          message_vision("$N�۵�����������Ҳû�д�����·����
                        \n", me);		  
		  return 1;
		 }
        }
		else
		{
                write("��Ҫ���Ķ��ꣿ\n");
                return 1;
		
		}
        
}
