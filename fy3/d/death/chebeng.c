// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
ǡ��ս��ʱ��������ʬ��Ҳ�Ƴ��ѣ������֣�һ���ǽ��ﷸ��֫��
����������ԯ�ϣ�Ȼ���ڳ��������ۣ�һ������ǧ��ս����������
����������Ҳ��ֳ����Ρ��������˼����Էϳ����ã������ڵ���
����һ�������̿��ң������˼䷸�˵���ش󵽼��㡣����������һ
�෸���ˣ��ֵ�����أ�
LONG
        );
        set("exits", ([
		"up" : __DIR__"zhuidao",
		"down" : __DIR__"hanbing",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-190);
	setup();
        replace_program(ROOM);
}
 
