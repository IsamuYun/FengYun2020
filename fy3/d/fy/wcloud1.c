inherit ROOM;
void create ()
{
  set ("short", "���ƴ�·");
  set ("long", @LONG
���ƹ㳡�ڶ���֪�����������������Ƿ��Ƴ��з�ɧ���˴Ծ�֮�ء���˵����
�պ�������С��̽�������������е���š��ϱߵĿ���ÿ�궼����һ��ѡ�ο��ԣ�
ǰ�������뾩�����ԡ���������̽��ʫ̨���Ƿ�ɧ�������������ǵ���֮���ĵ�
����
         {///||||\\\}_____ 
         {/||||||||\}  |��|
          |^^^^^^^^|   |ʫ|
          |̽��ʫ̨|   ~~~~
          ||_|_|_|_|
  | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ 
  _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |
  | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ 
  _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |
         {///||||\\\}_____ 
         {/||||||||\}  |��|
          |^^^^^^^^|   |��|
          |���ƿ���|   ~~~~
          ||_|_|_|_|

LONG);

  set("outdoors", "fengyun");
        set("objects", ([

  __DIR__"npc/xiwei" : 4,
  __DIR__"npc/song" : 1,
]));
  set("coor", ([ /* sizeof() == 3 */
  "y" : 0,
  "z" : 0,
  "x" : -10,
]));
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"poemp",
  "south" : __DIR__"examp",
  "east" : __DIR__"fysquare",
  "west" : __DIR__"wcloud2",
]));

  setup();
}

int valid_leave(object me, string dir)
{
        object ob,room;
        int i;
        if( userp(me) && dir == "north")
	{
        room = load_object("/d/qianjin/qianjin");
	if(room && !room->query("enter_permission"))
	if(objectp(ob = present("qinwei",this_object())))
		return notify_fail(ob->name()+"����ȵ������ʹ�������֮���������˵Ȳ������ڣ�\n");	
//        if( sizeof(me->query_all_condition()) != 0 )
//        return notify_fail("̽��ʫ̨������ķس���\n");
	}	
	return 1;
}
