// xgchen@zzfy
inherit ROOM;
void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
�����Ǳ���ѡ�ֵ���Ϣ�ң�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"biwukantai",
  "down" : __DIR__"poemp"
]));
        set("no_magic",1);
        set("no_exert",1);
        setup();
}

void init()
{
object room;
if(this_player()->query("gender")=="Ů��")
{
if(!room = find_object("/d/fy/biwufang2"))
room = load_object("/d/fy/biwufang2");
this_player()->move(room);
}
}
