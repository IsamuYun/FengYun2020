inherit ROOM;
void create()
{
        set("short", "������ ");
        set("long", @LONG
��·������ɾ������������Ƿ����˼䣬��ϡ�Ǵ�˵��������Ӱ��ߣ�
һ��ѩ�׵�ʯͷ������һ�꾧Ө��͸��ҡҷ���˵�С�ݣ�ʯ�Ͽ������֣�����
����ʯ��
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"side",
		 
		]));         
		set("objects",([
			"/obj/paper_seal" : 3,
       	]) );



    set("coor/x",3320);
	set("coor/y",10);
	set("coor/z",10);
	

	setup();
    replace_program(ROOM);

}
