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
  "east" : __DIR__"taolin1",
  "west" : "/u/wudang/xiaozhen",
]));

	set("item_desc", ([
	    "����": "���Ʋ�ϼ����һ����������ֵؿ�����֦ͷ��\n",
	    "peach tree": "���Ʋ�ϼ����һ����������ֵؿ�����֦ͷ��\n",
	]) );

 	set("objects", ([	
	__DIR__"obj/grass": 1,
	]) );

   	set("outdoors","taoyuan");
        set("coor/x",110);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}


void reset()
{
   object *inv;
   object item1, item2, grass;
   ::reset();

   grass = present("grass", this_object());
   inv = all_inventory(grass);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/petal");
      item2 = new(__DIR__"obj/mushroom");
      item1->move(grass);
      item2->move(grass);
   }
}

