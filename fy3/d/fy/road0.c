inherit ROOM;
void create()
{
        set("short", "�ϱ����");
        set("long", @LONG
���Ƿ��Ƴǵ�һ����Ҫ��������ϴ���ɽ��ˮ��ֱ���ɻ������½ӷ��ƾ�����
��ͨ���Ϻ��ڡ��������������ò�����һ���������Ϸ��ͱ�����չ��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"sgate",
  "south" : __DIR__"sroad1",
]));
        set("outdoors", "laowu");
        set("coor/x",10);
	set("coor/y",-420);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-420);
	set("coor/z",10);
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
