// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������������������������������ת��Ϊ�˵Ŀ��ܣ�������˶���ţ
һ�����ǿױ���������ţͷ������ǣ֮�������ߣ���ʱ��ͭ��������
���ô�ʹ��ʱ�̾��ѡ�������������һ��Ӹ�����
LONG
        );
        set("exits", ([
		"up" : __DIR__"xuechi",
		"down" : __DIR__"banggan",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-270);
	setup();
        replace_program(ROOM);
}
 
