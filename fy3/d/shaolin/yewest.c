// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "Ҵ��");
        set("long", @LONG
��ɽ�����Ҵ��һ����Ӳɽǽ�������Ͱ���ǽ������������Ȼ����
�ߴ�ȴҲ�������£�����������ֱͨɽ�ţ���������ֱ���˵أ�����
����Ҫ��������Ʒ��Ӵ˴����롣    
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"gulou",
  "southeast" : __DIR__"yonglu",
]));
        set("objects", ([
                __DIR__"obj/mache" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-220);
	set("coor/y",190);
	set("coor/z",40);
	setup();
}
void reset()
{
object ob1,ob2, con;
::reset();
ob1 = new("/d/wanmei/obj/vege");
ob2 = new ("d/wanmei/obj/drywoods");
con = present("mache",this_object());
if(con && ob1 && ob2)
{
	ob2->set_amount(random(5)+1);
	ob1->move(con); ob2->move(con);
}
}