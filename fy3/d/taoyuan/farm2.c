inherit ROOM;
void create()
{
        set("short", "农家");
        set("long", @LONG
这是一户很简朴的农家，门敞开着，屋内陈设十分简单，而且静悄悄的，
主人好象出去做活了。屋内竹床上铺着简单的被褥，上面摆了一个已经很旧了
的针线篮。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"west" : __DIR__"nongjia",
	]) );

   set("objects", ([
      __DIR__"obj/basket": 1,
   ]) );

   set("coor/x",200);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

void reset()
{
	object *inv;
        object item1, item2, item3, basket;
        ::reset();
        basket = present("basket", this_object());
        inv = all_inventory(basket);
        if( !sizeof(inv)) {
        item1 = new(__DIR__"obj/string.c");
        item1->move(basket);
        }
}

