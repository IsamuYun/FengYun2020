
inherit ROOM;

void create()
{
        set("short", "��Ұ");
        set("long", @LONG
����һ���ޱߵ�ɳ���أ�ɽ�Ƶ�������ͻȻ������Ӱ���١����������
���綼��ů�ġ����ϵ�ʯ������һ�ְ������ɫ�������Ǳ���ѪȾ���һ����
һ���������۵Ĺٵ��������Ͷ�����չ��
LONG
        );
        set("exits", ([
 //  "north" : "/d/huashan/road1", 
  "northwest" : "/u/quicksand/desert2",
  "southeast" : __DIR__"road",
]));
        set("outdoors", "chenxiang");

        set("coor/x",-510);
	set("coor/y",-430);
	set("coor/z",-10);
	set("coor/x",-510);
	set("coor/y",-430);
	set("coor/z",-10);
	setup();
}
void init()
{
        add_action("do_go","go");

}

int do_go()
{
if(random(3)){
this_player()->move(this_object());
return 1;
}
}


