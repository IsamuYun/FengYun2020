// ɽè(adx) by snow 2000-05-15

inherit ROOM;

void create ()
{
	set ("short", "���䳡����");
	set ("long", @LONG
����Сѩ������䳡�Ĵ��ţ�һ���߸ߵ�ľ���Ʒ������顺���䳡��
�����ֽ���֡����ﾭ���ٰ�������͵ı����ᡣ���е��˶��л����
�ӡ�
LONG);
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"north"   : __DIR__"zoulang",
		"south"   : "/d/bianliang/guangming",
	]));
	set("objects", ([
		__DIR__"npc/gongping" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob, where;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if ( !wizardp(me) && dir=="north" ) {
		if(me->query("snowzongshi"))
			return ::valid_leave(me, dir);
		if( ob->query("fangshi")!="������" && !ob->query("start/start"))
			return notify_fail("����û���κα��䣬�㲻�ܽ�ȥ��\n");
	}
	return ::valid_leave(me, dir);
}
