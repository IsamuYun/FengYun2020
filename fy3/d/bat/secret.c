//3300,0,10
inherit ROOM;
void create()
{
        set("short", "���� ");
        set("long", @LONG
����һ��ǳ����صķ��䣬û�д�����ֻ����һ������
�������������һ�㰵ҹ��Ĺ��
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"feng",
		  "up" : __DIR__"tt1",
		]));         
		set("objects",([
			__DIR__"npc/kumei" : 1,
       	]) );

   set("coor/x",3300);
	set("coor/y",20);
	set("coor/z",-20);
	set("no_magic",1);
      set("no_dazuo",1);

	setup();
    replace_program(ROOM);

}
