// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	object con,item;
        set("short", "��ɽ��®");
        set("long", @LONG
�ò����׹���������ǰһ������Ȼ�м�é�ݣ����Ͼ�ȻҲ������
���顰��ɽ��®�������ڳ���򵥣�һ�ź�ľ���Ϸ��ż��ᾭ����Ͳ
��ϡ��ز��ż�ֻ�Ǻ�����ǽһ�����������顰��񷡱���֡�
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"kuzhu",
]));
        set("objects", ([
        __DIR__"npc/mas1" : 1,
        __DIR__"npc/mas2" : 1,
	__DIR__"obj/cq" : 1,
	__DIR__"obj/xi" : 1,
       	]) );
        set("valid_startroom", 1);
	set("coor/x",-650);
	set("coor/y",-500);
	set("coor/z",40);
	setup();
        con = present("��ǽ",this_object());
        item= present("cang qiong", this_object());
        item->move(con);

}
void reset()
{
object me,me2;
:: reset();
me2=present("master li",this_object());
me=present("master liu",this_object());
if(me) me->dismiss_team();
if(me2) me2->dismiss_team();
if(me && me2) me->add_team_member(me2);
}

