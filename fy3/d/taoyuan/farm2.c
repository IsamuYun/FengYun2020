inherit ROOM;
void create()
{
        set("short", "ũ��");
        set("long", @LONG
����һ���ܼ��ӵ�ũ�ң��ų����ţ����ڳ���ʮ�ּ򵥣����Ҿ����ĵģ�
���˺����ȥ�����ˡ������������ż򵥵ı��죬�������һ���Ѿ��ܾ���
����������
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

