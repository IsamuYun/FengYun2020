#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIR "��ʬ��" NOR);
        set("long", @LONG
������ɭ�ֲ������ϵ����ǲ�֫��ʬ���޴����ǰ���ɫ��Ѫ�Ρ�������
������������־��裬��֪��������ͻ�ܳ�һ����Ӱ��
LONG
        );
        set("exits", ([
                "east"  : __DIR__"turen5",
                "south" : __DIR__"turen8",
                "west"  : __DIR__"turen3",
                "north" : __DIR__"turen1",
        ]));
        set("no_magic",1);
        set("no_dazuo",1);
  set("pk_room", 1);
        setup();
        replace_program(ROOM);
}
