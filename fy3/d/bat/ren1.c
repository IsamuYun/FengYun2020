//3290,0,10
inherit ROOM;
void create()
{
        set("short", "�˼�� ");
        set("long", @LONG
����һ����խ��ɽ�������ű���һ��ɽ����ȥ���˷���һ��������ֱ�̲�񷡣 
LONG      );
        set("exits", ([ 
		  "northup" : __DIR__"ren2",
		  "southdown" : __DIR__"ren",
		]));         
		set("objects",([
        	__DIR__"npc/wushi1" : 1,
       	]) );
    set("outdoors", "bat");
    set("coor/x",3290);
	set("coor/y",30);
	set("coor/z",40);
	set("no_magic",1);set("no_dazuo",1);

	setup();
   

}
int valid_leave(object me, string dir)
{
	object ob;
        if( dir == "northup" && ob=present("wu shi", this_object()))
        {
		return notify_fail("��������·��"+ob->name()+"��ס�� ��\n");
	}
		return 1;
}


