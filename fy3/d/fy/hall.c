inherit ROOM;
void create()
{
        set("short", "�����콾��");
        set("long", @LONG
����һ�����϶���ʥ�Ĵ���ʯ�ţ���Լ���ڰ���ǰ�����ϰ߰ߵ�㣬
�绯��������˵������ʴ���ٷ��ѽ����¶�ŮӢ�۵ĵط������Ǳ���
����Ӣ�۶���Ϊ����֮����
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"ecloud5",
]));
        set("objects", ([
  	__DIR__"obj/depositbox" :1,
       ]) );
        set("coor/x",50);
        set("coor/y",10);
        set("coor/z",0);
        set("coor/x",50);
	set("coor/y",10);
	set("coor/z",0);
	set("no_clean_up", 1);
	set("keep",1);
	setup();
}
void init(){
	add_action("do_in", "put");
	add_action("do_out", "get");
}
int do_in(string arg)
{
	return 1;
}
int do_out(string arg)
{
	return 1;
}