inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
δ��˷����ƺ����������������Ķ��ö��������������������
�������ܣ��������ޣ��ƶ������������������롣����ɱ�����ص���
Ҳ��һ�ְ����ĸо���
LONG
        );
        set("exits", ([ 
		  "east" : __DIR__"qishi",
		  "down" : __DIR__"dating",
		]));         
		set("objects",([
			__DIR__"npc/tong1" : 1,
       	]) );

//(3270,30,-20)
    set("coor/x",3270);
	set("coor/y",30);
	set("coor/z",-20);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
