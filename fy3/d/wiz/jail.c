// Room: /d/wiz/courthouse.c

#include <ansi.h>
void test_me(object me);
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����Ψһ��һ���������ܵ�����������һ����������ͷʹ�Ľ�ɫ��
����һ��������˵�ͷ�Ͳ�ʹ�ˣ����ͷӦ�ÿ�ʼʹ�˰ɣ�����
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jobroom"
]));
        set("watch_jianyu_room",1);
	set("no_fight", 1);
	set("no_magic", 1);
	set("no_spells", 1);
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",10);
	setup();
}
void init()
{
        if(!wizardp(this_player()))
	{
	"/cmds/std/look"->look_room(this_player(),this_object());
	this_player()->set("startroom", __FILE__);
        add_action("do_nothing", "");
        add_action("do_quit","quit");
        add_action("do_say","say");
	}
}	

int do_nothing()
{
write("������������డ����������\n");
return 1;
}

int do_quit()
{
"/cmds/usr/quit"->main(this_player(),"");
return 1;
}
int do_say()
{
"/cmds/std/say"->main(this_player(),"");
return 1;
}
