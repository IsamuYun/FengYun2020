inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�˴���Ϊ�տ����ıڿ���һ��������һ��ʯƺ��ƺ����һ��
����ʯ�̾͵����̣��̱߸���һ������С�У�������װ���ӵġ�ʯ
ƺ���Ҹ���һ����档
LONG
        );
        set("exits", ([ 
		  "east" : __DIR__"shushi",
		  "west" : __DIR__"qinshi",
		]));         
		set("objects",([
			__DIR__"npc/tong2" : 1,
       	]) );

// (3280,30,-20)

    set("coor/x",3280);
	set("coor/y",30);
	set("coor/z",-20);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
