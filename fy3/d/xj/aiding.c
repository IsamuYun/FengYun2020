#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����������Ϊ�¹��������󲿷��������粨�ĸɺԺ��ף�
��Ŀ�������׾�Ө���ΰͣ����������������⣬���ƺ�ҹ����
���¹⣬������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"tulufan",
  "westdown" : __DIR__"pubu",
]));
        set("objects", ([
                __DIR__"npc/saltboss" :1,
                        ]) );
        set("item_desc", ([
                "�ΰ�": "����һ���ΰ��̸����Ѿ��ɺԵĺ��ס�\n",
                "yanba": "����һ���ΰ��̸����Ѿ��ɺԵĺ��ס�\n",
                "salt rock": "����һ���ΰ��̸����Ѿ��ɺԵĺ��ס�\n",
        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1080);
	set("coor/y",1020);
	set("coor/z",0);
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
