//3290,0,10
inherit ROOM;
void create()
{
        set("short", "�˼�� ");
        set("long", @LONG
   ɽ��Խ��Խ����,��ӥ����ͷ���ɹ������������ĺ�Х����
LONG      );
        set("exits", ([ 
		  "northup" : __DIR__"ren3",
		  "southdown" : __DIR__"ren1",
		]));         
		set("objects",([
        	__DIR__"npc/wushi2" : 1,
       	]) );
    set("outdoors", "bat");
    set("coor/x",3290);
	set("coor/y",40);
	set("coor/z",50);
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

