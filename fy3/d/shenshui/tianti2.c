// TIE@FY3 ALL RIGHTS RESERVED
//XXDER
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
һ·��������ϸ�۲죬���߲ݴ�֮�о�Ȼ�����ɭɭ�׹ǣ����ж��в�
������Ȼ����Щ�������ˣ�ֻ��Ϊ�ε���������˷�����˼��һ�����ɵ�
��ʯ���ź��·�ϣ�������飢һ����ţ�����Ϊ�ˣ������������Ե�ʮ��
���죬�㲻�ɵ��ľ�������
LONG
        );
   set("exits", ([ 
      "east" : __DIR__"valley",
      "southdown" : __DIR__"tianti1",
   ]));
   set("objects", ([
      __DIR__"obj/grass": 1,
   ]) );
	set("outdoors","shenshui");
	set("coor/x",160);
	set("coor/y",12230);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}

void reset()
{
   object *inv;
   object item, grass;
   ::reset();

   grass = present("grass", this_object());
   inv = all_inventory(grass);
   if( !sizeof(inv)) {
      item = new(__DIR__"obj/sword");
      item->move(grass);
   }
}


