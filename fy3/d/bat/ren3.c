//3290,0,10
inherit ROOM;
void create()
{
        set("short", "�·����");
        set("long", @LONG
   ���羢�������¾����۵ף�������˼�ľ�����
ֻ�о�����ƥ�ĸ��ֲ��ܵ���������Ǹߴ���ʤ����
LONG      );
        set("exits", ([ 
		 
		  "southdown" : __DIR__"ren2",
		]));         
		set("objects",([
                __DIR__"npc/baiyiren" : 1,
       	]) );
    set("outdoors", "bat");
    set("coor/x",3290);
	set("coor/y",50);
	set("coor/z",60);
	set("no_magic",1);
	set("no_dazuo",1);

	setup();
}
