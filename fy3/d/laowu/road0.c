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
  "north" : __DIR__"road1",
"south":"/d/fy/ngate",
"west":"/d/xj/heimiao",
//"east":"/d/baihuagu/road1",
]));
        set("outdoors", "laowu");
        set("coor/x",0);
	set("coor/y",1000);
	set("coor/z",0);
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
