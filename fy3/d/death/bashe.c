// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�Թ��������֮ͽ����Т֮�˶మ��Ū�Ƿǣ�������ģ������������
���ߴ糤�鹴ȥ��ͷ��ʹ֮�ڲ����ԣ���Ḵ���������ٰΣ�����
ѭ����ֱ�������ĵ���ɥ������Ϊ�ˣ��㲻���ٷ���ҵ�������±���
��Ƥ����
LONG
        );
        set("exits", ([
		"up" : __DIR__"yandu",
		"down" : __DIR__"bopi",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-150);
	setup();
        replace_program(ROOM);
}
 
