// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ؾ�¥");
        set("long", @LONG
���޹��ӣ�Ҳ�����鼮��ֻ��һ����ɮ������ȥ��������������ɮ
����ɫ��Ӧ�ñ��ǲؾ�¥����--һ�����ഫ��ɮƢ���Ź֣���ʮ����δ
�²ؾ�¥һ����
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"cj6",
  "down": __DIR__"cj4",
]));
        set("objects", ([
                __DIR__"npc/master_18a" : 1,
       ]) );
	set("coor/x",-210);
	set("coor/y",360);
	set("coor/z",110);
	set("no_fight",1);
	setup();
}
int valid_leave(object me,string dir)
{
        object ob;
if(userp(me) && dir == "up" && ob=present("master yi",this_object()))
{
message_vision("$N��$n��������ô������¥�أ�\n",ob,me);
return notify_fail("");
}
return 1;
}

