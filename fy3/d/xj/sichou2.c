#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
һ���������ܲ����۵���·��������ǧ�����ʷ�У�������ʳ��
�����˵������������ǵİ׹����ڵ�·���ԡ�������������ô�Ĳ���
�ۣ��ƺ�һ������ĺ��Ӷ����Խ�����ڽ��¡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"sichou",
  "southeast" : __DIR__"sichou3",
]));
        set("objects", ([
                __DIR__"npc/trader2" :2,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1090);
	set("coor/y",1040);
	set("coor/z",0);
	setup();
}