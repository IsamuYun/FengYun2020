inherit ROOM;
void create()
{
        set("short", "边陲小镇杂货铺");
        set("long", @LONG
门口一面幌子随风飘荡。这里本来是一个安静的地方,远离喧嚣的
内陆,最近这里可能发生了一些事情,江湖上的高手经常出现在这里，
本来狭小的空间显的有些拥挤了。老板也在忙不停的招呼客人。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"bazha1",
]));
        set("objects", ([
        __DIR__"npc/seller2" : 1,
                        ]) );

        set("coor/x",-1100);
	set("coor/y",-1080);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
