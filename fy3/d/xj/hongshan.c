#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "��ɽ");
        set("long", @LONG
��ɽ��ɽ�ʺ��ɫ������ɽ���Ǻܸߣ�Ҳ���Ǻ���ΰ�������Ǻ�������
ɽ����һ�����ơ�������������������Կ���Զ���ĳ��źͳ���Ĵ��̡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "up" : __DIR__"zhenlong",
  "southdown" : __DIR__"tulu",
]));
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
	set("coor/y",1130);
	set("coor/z",10);
	setup();
}