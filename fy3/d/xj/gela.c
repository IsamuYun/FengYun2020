#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "�����ڳ�ɽ");
        set("long", @LONG
��ɽ֧�������ڳ�ɽ�����ѩ��ɽ�����˵�����֮��û�м���
��Ը��ð�մ���������ɽ��ȥѰ�Ҵ�˵�е���ɽѩ�����ഫ������
ֻ��һ���˻��Ŵ���ɽ�����˳������ҵ��������汦������ɽѩ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"bingchuan",
  "northeast" : __DIR__"tianshan",
  "southwest" : __DIR__"tianshan",
]));
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1130);
	set("coor/y",1000);
	set("coor/z",0);
	setup();
}
