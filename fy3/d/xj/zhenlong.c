#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����λ�ں�ɽɽ��������߹�ʮ�ɣ�������������ɫ��Ƭ����������
ʮ��ҫ�ۡ�������Χ�Ǻ�ש�أ��Ѿ��ܾ��ˣ��������Ѻۡ�����ܾ�����
��һЩ��������������������֮�⣬�ƺ�û�����������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"hongshan",
]));
	set("no_death_penalty",1);
	set("outdoors", "xinjiang");
        set("coor/x",-1120);
	set("coor/y",1130);
	set("coor/z",20);
	setup();
}
