inherit ROOM;
void create()
{
        set("short", "�����Ŀյ� ");
        set("long", @LONG
�յأ���ʯ���Ӳݣ����硣����ζ�����ˣ����˾��������ƺ��������Σ�
�ֿ���ɬ�������쳣�谵�������Լ���Ӱ�Ӷ�������������Ӳ��������
�Ķ���ɳɳ��Ť����ͣ��
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"lin1",
		  "east" : __DIR__"fchuan",
		]));         
		set("objects",([
        	__DIR__"npc/wei" : 1,
       	]) );
    set("outdoors", "bat");
    set("coor/x",1110);
	set("coor/y",-290);
	set("coor/z",-10);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
