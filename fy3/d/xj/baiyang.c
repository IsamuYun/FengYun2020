#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
���λ����ɽ֧�������ڳ�ɽ��´�е�ɽ���ɴ������й���������
�����ߴ�ͦ�ε�������������������˵�������ֵĹ�ľ���ʻ���������
�����£����ﻹ�������ޱȣ����˸е������泩��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"chairong",
  "south" : __DIR__"bingchuan",
  "east" : __DIR__"goudi",
]));
        set("item_desc", ([
                "��ľ": "һ�Ӳ�֪���Ĺ�ľ��������ï�ܡ�\n",
                "guanmu": "һ�Ӳ�֪���Ĺ�ľ��������ï�ܡ�\n",
                "����": "�Ұ�ɫ���������Ͻ�����һ�������۾��Ƶİ̺ۣ��е�����Ц����\n�����ڿޣ������е�һ����Ŀ���ƺ�������һ�Թ�ľ�ϡ�\n",
                "yangshu": "�Ұ�ɫ���������Ͻ�����һ�������۾��Ƶİ̺ۣ��е�����Ц����\n�����ڿޣ������е�һ����Ŀ���ƺ�������һ�Թ�ľ�ϡ�\n"
        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
	set("coor/y",1020);
	set("coor/z",-10);
	setup();
}

int dig_notify()
{
	object ob;
	if(!query("already"))
	{
	message_vision("�ϣ�����һ�����ٿ����ϵ��ΰ��Ա�$N����һС�顣\n",this_player());
	ob = new(__DIR__"obj/salt");
	ob->move(this_object());
	set("already",1);
	return 1;	
	}
	else
	return 0;

}

/*
do_look^Dlook^Omarks/foundjade^Hset_temp^Galready^Ckar^Equery^Hiron box-��������һ����$N�ĸ��ƺ�������һ���������ϡ�
:!��ͷһ����������¶����һ�����С�
:
^S/d/xinjiang/obj/box^Dmove7���ϳ�����һ�����ӣ����˸����֦Ҷ��$Nʲô��û�з��֡�
:
^Fcreate^Dinit^Gdo_look

:dig_notify
*/