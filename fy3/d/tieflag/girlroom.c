// Room: girl


inherit ROOM;
#include <room.h>

void create()
{
        set("short", "����");
        set("long", @LONG
���ڶ����˸�����������ʱ�ʵ�ˮ������������ɼ������
���鱦�������������������ϣ��ƺ�б����һ������Ů�ӡ�
LONG
        );
        set("objects", ([
                __DIR__"npc/shui": 1,
        ]) );
       

        set("coor/x",70);
	set("coor/y",0);
	set("coor/z",-20);
	setup();
	replace_program(ROOM);      
}
