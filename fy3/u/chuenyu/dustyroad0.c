// Room: /d/chuenyu/dustyroad.c

inherit ROOM;

void create()
{
        set("short", "���С·");
        set("long", @LONG
����һ����С��ͨ�����Ļ���С·��������С��Ľ��⣬���ƺ���
����������С����������������������һ���޼ʵ�ƽԭ��һ��������
��ɽ��������������֡�
LONG
        );
        set("exits", ([ 
  "southwest" : "/u/palace/palace_path1",
  "north" : __DIR__"dustyroad.c",
]));
        set("outdoors", "chuenyu");

        set("coor/x",100);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",100);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_go","go");

}

int do_go()
{
if(random(2)){
this_player()->move(this_object());
return 1;
}
}
