#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"���Ƴǵ����"NOR);
        set("long", @LONG
�����Ƿ��Ƴ��������գ�������ȥ�����Ƴǵľ���һ�����ţ�������ȴ�Ƿ���
�Ľ��ء������й�������������������֮�ˣ�������Զ���������
�˴�������翣������ɾ���ʵ�����˲�����ȥ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
          "west" : __DIR__"eroad3",

        "east" : __DIR__"eroad5",
]));
			
        set("outdoors", "fyup");
        set("objects", ([
               __DIR__"npc/star4" : 1,
       ]) );
        set("no_fight",1);
        set("no_magic",1);
        set("no_beg",1);
        set("no_du",1);
        set("no_sheet",1);
        set("no_dazuo",1);
        set("coor/x",0);
	set("coor/y",0);
        set("coor/z",10);
        setup();
}
