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
  "west" : __DIR__"taolin1",
  "south" : __DIR__"taolin",
  "north" : __DIR__"taolin",
  "east" : __DIR__"valley",
]));

	set("item_desc", ([
	    "����": "���Ʋ�ϼ����һ����������ֵؿ�����֦ͷ��\n",
	    "peach tree": "���Ʋ�ϼ����һ����������ֵؿ�����֦ͷ��\n",
	]) );

 	set("objects", ([	
	"/u/wudang/npc/bird": 2,
	]) );

   	set("outdoors","taoyuan");
        set("coor/x",130);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}


