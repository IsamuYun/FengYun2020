inherit ROOM;
void create()
{
        set("short", "ũ��");
        set("long", @LONG
����һ���ܼ��ӵ�ũ�ң������ݳɵ�ǽ��ů������é�ݸǶ�����Ȼ��ªȴ
�����ڷ�Ƨ�ꡣ�ų����ţ����ڳ���ʮ�ּ򵥣����Ҿ����ĵģ����˺����ȥ
�����ˡ�ǽ�Ϲ���һЩ���õ�ũ�ߣ���ۻ������ʡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"east" : __DIR__"nongjia",
	]) );

   set("objects", ([
      __DIR__"obj/wall": 1,
   ]) );

   set("coor/x",180);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

void reset()
{
	object *inv;
        object item1, item2, item3, wall;
        ::reset();
        wall = present("wall", this_object());
        inv = all_inventory(wall);
        if( !sizeof(inv)) {
        item1 = new(__DIR__"obj/liandao");
        item1->move(wall);
        item2 = new(__DIR__"obj/hook");
        item2->move(wall);
        item3 = new(__DIR__"obj/raincoat");
        item3->move(wall);
        }
}

