inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ�������ĵ�������ս������ŵ�һ�ɴ̱ǵ�ҩ�ݵ�ζ����
��������ң��ƺ��ոձ��˷��������ָ�����ƿ�޶ѵĵ������ǡ�
��ǽ���Ÿ���ҩ��
LONG
        );
        set("exits", ([ 
		  "south" : __DIR__"zoulang1",		  
		]));         

//(3290,40,-30)
    set("coor/x",3290);
	set("coor/y",40);
	set("coor/z",-30);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
