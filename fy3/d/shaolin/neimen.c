// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Ժ��");
        set("long", @LONG
�����沢���ߴ��ǽ���ŵô���֮��������ֺ�Ժ��
Ҳ����������ѧ�ķ�Դ��--������Ժ��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"neiyuan",
  "southup" : __DIR__"qianfe",
]));
        set("objects", ([
                __DIR__"npc/monk8" : 2,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-210);
	set("coor/y",290);
	set("coor/z",60);
	setup();
}
int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="north" && ob=present("shaolin monk", this_object()) &&
me->query("class") != "shaolin")
return notify_fail(
"����˵����ֻ�������µ��Ӳſ��Խ���������Ժ��\n");
return 1;
}
