//3300,0,10
inherit ROOM;
void create()
{
        set("short", "�˼���� ");
        set("long", @LONG
ʯͷ������ɫ�ģ��䡢Ӳ��������ŭ���Ĵ��ź���������ǧ����Х�������ڡ�
�������ܽ�ʯ���У�����ÿһ�������д����Ĵ�ֻ������������һֻֻ�����޾�
��ҧס��С�á����۶����ɣ����̵Ĵ����������ܲ��Ϻ����������ɱ��    
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"kongdi",
		  "east" : __DIR__"dong",
		]));         
		set("objects",([
        	__DIR__"npc/xunluo" : 1,
			__DIR__"npc/dizi" : 2,
       	]) );
    set("outdoors", "bat");
    set("coor/x",3300);
	set("coor/y",0);
	set("coor/z",10);
	set("no_magic",1);
      set("no_dazuo",1);

	setup();
    replace_program(ROOM);

}
