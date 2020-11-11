// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	object con,item;
        set("short", "黄山剑庐");
        set("long", @LONG
好不容易过铁索，眼前一亮，居然有间茅屋，屋上居然也有牌匾
上书“黄山剑庐”，屋内陈设简单，一张红木桌上放着几册经卷，笔筒
中稀疏地插着几只狼毫，西墙一柄长剑，上书“苍穹”二字。
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
        con = present("西墙",this_object());
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

