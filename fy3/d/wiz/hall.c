inherit ROOM;
void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
�����ǹ�����Ա��Ϣ���������۵ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jobroom"
]));
        set("valid_startroom", 1);
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
call_other( "/obj/board/fynews_b", "???" );
}

void init()
{
object room;
if(!wizardp(this_player()))
{
if(!room = find_object("/d/fy/church"))
room = load_object("/d/fy/church");
this_player()->move(room);
}
}
