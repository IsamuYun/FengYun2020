inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
��ǰ�Ǽ�����Ϊ��ͨ�Ĵ��ᣬ����С������������׷����֣���ֻ�ʷʵ�
��׶죬�����������쳤�˲��Ӹ¸µĽУ��ƺ�������Ȼ�ҵ����������
ÿ��Ϧ�����µ�ʱ�򣬺���é��ձ�ɵ��ݶ���ᱻ�����Ĵ�����ס��������
��������һ�����˵��׷�����ζ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
   "south" : __DIR__"road1",
   "west" : __DIR__"farm1",
   "east" : __DIR__"farm2",
   "north" : __DIR__"farm",
   ]));

   set("objects", ([
      __DIR__"npc/kid": 2,
   ]) );

   	set("outdoors","taoyuan");
        set("coor/x",190);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}

