#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "���ѹ�");
        set("long", @LONG
����ˮ���ݺᣬ���մ�������ɽѩˮ����������ɽ�������ݲ�����
������ȴ�����������Ѽܳ�Ƭ��������ˮ�������ݷ���һ���컷��
�������ѹ����������һ���������硣ֻ���ǽ�������ڰ�ֵ�������
���ڼ����ϣ������ߵ����Ͽգ�����ï�ܵ�Ҷ�Ӻͺ������Ĵ�������
���ֿɼ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "westup" : __DIR__"emin",
  "eastup" : __DIR__"huoyan",
]));
        set("objects", ([
                __DIR__"npc/waiter2" :1,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1050);
	set("coor/y",1030);
	set("coor/z",-10);
	setup();
}
