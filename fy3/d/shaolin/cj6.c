// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ؾ�¥");
        set("long", @LONG
�����ӻҳ����ƺ����������������ݶ��Ǿ���������¥���вؾ�¥
������������������Ҳ�ѽ��룬����ǽ���Ͻ������ľ����ഫΪ����
��Զ��ʦ�������÷������ڡ�����ѧ֮�еĲ������š�
LONG
        );
        set("exits", ([ 
  "down": __DIR__"cj5",
  "up": __DIR__"cj7",
]));
        set("objects", ([
                __DIR__"obj/xisui" : 3,
            "/d/shaolin/npc/master_18c" : 1,
               __DIR__"obj/xuejing" : 1,
       ]) );
	set("coor/x",-210);
	set("coor/y",360);
	set("coor/z",120);
	setup();

}
int valid_leave(object me,string dir)
{
        object ob;
if(userp(me) && dir == "up" && !me->query("juexue") )
{
message_vision("$N��һ�����ε�絲ס�����㲻�ܶ�����\n",me);
return notify_fail("");
}
return 1;
}

