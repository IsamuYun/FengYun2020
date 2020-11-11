// ɽè(adx) by snow 2000-05-15

inherit ROOM;

void create ()
{
	set ("short", "�ҿ�̨");
	set ("long", @LONG
����Сѩ������䳡����̨����̨����һ���ŵ�ľ�����ʡ�������
����һ�ɸߵı���̨��һ�б�������㶼�ܿ��÷ǳ���������ﻹ�ṩ��
�ѵ���ʳ��
LONG);
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"up"   : __DIR__"biwutai",
		"northwest"   : __DIR__"houtai",
		"southwest"   : __DIR__"kantai2",
		"south"   : __DIR__"zoulang",
	]));
	setup();
}

void init()
{
	add_action ("do_work","ansuan");
}

int do_work()
{
	write("���ﲻ��ʹ�����ָ�\n");
	return 1;
}

int valid_leave(object me, string dir)
{
        object tai=load_object(__DIR__"biwutai");
        object *inv=all_inventory(tai);
	object ob, where;
        int i=sizeof(inv);

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if ( !wizardp(me) && dir=="up" ) {
		if( ob->query("start/start") && !me->query("biwu_fighter") )
			return notify_fail("�����Ѿ���ʼ�ˣ��㲻��ѡ�ֲ�����̨��\n");
		if(i>=2)
			return notify_fail("����̨���Ѿ�������ѡ�֣������ڲ�����̨��\n");
	}
        return ::valid_leave(me, dir);
}
