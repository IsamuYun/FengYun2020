inherit ROOM;
void create()
{
        set("short", "桃林");
        set("long", @LONG
这是一片茂密的桃树林，林中芳草鲜美，落英缤纷，一层淡淡的薄雾，混
合着青青的草香，弥漫在空气之中。偶尔的一两声鸟鸣，愈发地显出幽静来。
这里的小路已被落花铺满，早已辨不出痕迹来。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"taolin1",
  "south" : __DIR__"taolin",
  "north" : __DIR__"taolin",
  "east" : __DIR__"valley",
]));

	set("item_desc", ([
	    "桃树": "粉云彩霞般的桃花，热热闹闹地开满了枝头。\n",
	    "peach tree": "粉云彩霞般的桃花，热热闹闹地开满了枝头。\n",
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


