inherit ROOM;
#include <ansi.h>
void create()
{
  set ("short", BLINK CYN"̸�ľ�"NOR NOR);
        set("long", @LONG
�����Ƿ����ȫ�ĵط�֮һ��Ҳ��һЩ���Ѿۻ�ĺõط���������
һ���ƹ�������������Ŀ�ĸ��ָ����ľƣ���һЩ�����������ھ�
��ʹ�������߻��м������ȵĴ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"yitea2",
]));

	set("no_fight",1);
		set("NONPC",1);
        set("no_sheet",1);
        set("no_beg",1);
        set("no_du",1);
        set("no_magic",1);
        set("no_dazuo",1);
        set("coor/x",10);
        set("coor/y",-30);
        set("coor/z",20);
	setup();
        replace_program(ROOM);
}
