#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "����ɽ");
        set("long", @LONG
����ɽ��ʮ���ɽͷ�������ٺ�ɫ�������յ���ҫ�£�����ȼ����
�����ܴ�𣬹�������ɽ�����ڴ�ɽ���γ��и����ϵĴ�˵����ʱ��
��ɽ��һ������������ͯ��ͯŮ��һλ�й�����׿��������Ľ���������
����ִ�������������ս������ҹ��������ն�˶��������Ѷ���ն��ʮ
��ء��������ٲ��������һ����ɽ����ն��������˻���ɽ�е�Ͽ�ȡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "westdown" : __DIR__"butao",
  "southeast" : __DIR__"sichou4",
  "east" : __DIR__"qianfo",
]));
        set("objects", ([
                __DIR__"npc/huwaiter" :1,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1040);
	set("coor/y",1030);
	set("coor/z",0);
	setup();
}