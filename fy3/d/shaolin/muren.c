// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ľ����");
        set("long", @LONG
����ľ�����ˣ������ǳ����ֵĵ�һ�أ�����������ޣ��ܵ�
��ľ����Ķ��������־�Ӣ�������϶���һ�������ˡ��������һ
��խխ�Ĺ���������ȫ��ľ�ˣ��ɻ��ؿ��ƣ���ʹ������ʮ��������
���ּ��ء�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"banruo",
  "north" : __DIR__"muma",
]));
        set("outdoors", "shaolin");
	set("coor/x",-210);
	set("coor/y",390);
	set("coor/z",70);
	setup();
}
void init()
{
	delete("exits");
	if(userp(this_player()))
	{
	remove_call_out("attack");
	call_out("attack",1+random(2),this_player());
	}
}
int attack(object me)
{
object muren;
muren= new(__DIR__"npc/muren");
muren->set("combat_exp",50000*random(100));
muren->set_temp("apply/damage",100*random(10));
muren->move(this_object());
COMBAT_D->do_attack(muren,me);
if(present(me,this_object()) && random(9))
{
destruct(muren);
call_out("attack",1+random(2),me);
}
else
{
destruct(muren);
set("exits/north", __DIR__"muma");
}
}
