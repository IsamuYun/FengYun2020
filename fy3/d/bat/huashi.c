inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ӳ��󣬲�֪�δ�����̴֧�㣬����һ���ѳ����׵���ζ��
�������ǽ����һ�����ӣ������ķ��ı���ȫ����������������
�ط�����ֵ��Ƕ�����ܾ�û�����ù���
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"shushi",
		  "east" : __DIR__"feng",
		]));         
		set("objects",([
			__DIR__"npc/tong4" : 1,
       	]) );

//(3300,30,-20)

    set("coor/x",3300);
	set("coor/y",30);
	set("coor/z",-20);
	set("no_magic",1);

	setup();
    replace_program(ROOM);

}
