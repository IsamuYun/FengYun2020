#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�������߳�������������ʹ��ʢ��������������¶�Ҳ�൱�ͣ�
һ�������紵��������ȫ����ʱ�䳤�ˣ�����е����䡣����һ��
���������ֵ����֮�⣬�������Ǿ�������ľ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"goudi",
  "east" : __DIR__"pubu",
]));
        set("objects", ([
                "/d/oldpine/npc/venomsnake" :2,
                "/d/oldpine/npc/bandit" :1,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1100);
	set("coor/y",1020);
	set("coor/z",-10);
	setup();
}
