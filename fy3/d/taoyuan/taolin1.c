inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һƬï�ܵ������֣����з�����������Ӣ�ͷף�һ�㵭���ı�����
��������Ĳ��㣬�����ڿ���֮�С�ż����һ�����������������Գ��ľ�����
�����С·�ѱ��仨���������ѱ治���ۼ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"taolin2",
  "west" : __DIR__"taolin",
]));

	set("item_desc", ([
	    "����": "���Ʋ�ϼ����һ����������ֵؿ�����֦ͷ��\n",
	    "peach tree": "���Ʋ�ϼ����һ����������ֵؿ�����֦ͷ��\n",
	]) );

   	set("outdoors","taoyuan");
        set("coor/x",120);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

void init() 
{
   add_action("do_pick", "pick");
}

int do_pick(string arg)
{
   object me, zhi;

   me = this_player(); 
   if(!arg || arg != "taozhi" && arg != "��֦") return 0;	
   if(me->query_temp("marks/taozhi")){
      tell_object(me, "\n��ժ������ͺ��! \n");	
      return 1;
   }	
   zhi = new(__DIR__"obj/taozhi");
   zhi->move(me);
   me->set_temp("marks/taozhi", 1);
   message_vision("\n$N����ժ��һ֦�һ�������\n", me);
	
   return 1;	
}

