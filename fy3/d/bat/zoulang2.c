inherit ROOM;
void create()
{
        set("short", "�ڰ�����");
        set("long", @LONG
��������ƺ����Ӻڰ������䣬��͸��Ũ���Ѫ����ζ��
��Χ�Ŀ����ƺ����Ѿ����������������ص�����͸����������
LONG
        );
        set("exits", ([ 
		  "east" : __DIR__"zoulang1",
		  "west" : __DIR__"dating",
		]));         
//3280,30,-30
    set("coor/x",3280);
	set("coor/y",30);
	set("coor/z",-30);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
