#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIR "���˳�" NOR);
        set("long", @LONG
������ɭ�ֲ������ϵ����ǲ�֫��ʬ���޴����ǰ���ɫ��Ѫ�Ρ�������
������������־��裬��֪��������ͻ�ܳ�һ����Ӱ��
LONG
        );
        set("exits", ([
                "south" : __DIR__"turen10",
                "west"  : __DIR__"turen5",
                "northwest" : __DIR__"turen2",
        ]));
        set("no_magic",1);
        set("no_dazuo",1);
  set("pk_room", 1);
        setup();
        replace_program(ROOM);
}
