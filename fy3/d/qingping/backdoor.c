inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��԰�ı߽���һ��Сľ�ţ�ľ��������һ��С���ţ�һ����������ʯ��
С·���ѵش�ľ��ǰ��������ʧ�ڻ����С���Ϊ����ƽʱ���������ߣ�����
��ʯ���в�֪��ʱ����Щ��֪���Ļ��ݣ���������Ұ����ȴҲ���ķҷ�������
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
   "westup" : __DIR__"bridge",
   "northwest" : __DIR__"northpond.c",	
   "south" : __DIR__"southpond1.c",	
   ]));

   set("objects", ([
      __DIR__"obj/cao": 1,
   ]) );

   set("outdoors","qingping");
   set("coor/x",200);
	set("coor/y",2000);
	set("coor/z",0);
	setup();
	
}

void reset()
{
   object *inv;
   object item1, cao;
   ::reset();

   cao = present("cao", this_object());
   inv = all_inventory(cao);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/paper");
      item1->move(cao);
   }
}

