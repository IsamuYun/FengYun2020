#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "���ӹʳ�");
        set("long", @LONG
�˳�λ���Ŷ����ι��У�ϵ��������ʮ��������ʦǰ������
�ʳǣ��óǽ����Ա����ϸ�ʮ���ɵĻ���̨���ϣ������޳�ǽ��
���±������� ��������Ȼ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"sichou2",
  "eastdown" : __DIR__"tulufan",
]));
        set("objects", ([
                __DIR__"npc/bird" :2,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1080);
	set("coor/y",1030);
	set("coor/z",0);
	setup();
}