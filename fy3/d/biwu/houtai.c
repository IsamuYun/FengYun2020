// ɽè(adx) by snow 2000-05-15

inherit ROOM;

void create ()
{
	set ("short", "��̨");
	set ("long", @LONG
���Ǳ��䳡�ĺ�̨�������ǹ��ϯ�������ֱ���ĵط���ֻ����ʦ��
�߹��������ȥ��
LONG);
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"up"   : __DIR__"caipan",
		"southeast"   : __DIR__"kantai3",
		"southwest"   : __DIR__"kantai1",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob, where;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if ( !wizardp(me) && dir=="up" ) {
		if(!me->query("snowzongshi"))
			return notify_fail("ֻ��Сѩ��ʦ���ܴ����������ϯ��\n");
	}
	return ::valid_leave(me, dir);
}
