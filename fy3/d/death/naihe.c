// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ڤ�����");
        set("long", @LONG
���Ʋҵ�֮��һƬ���������������಻�����˼䣬��˵������
�ڴ�·��������֮�ˣ����ǵظ��а����ؼ������񣬵ظ����ɭ��
�����˼䣬ʮ�˲�����ܾ����¶��ˣ����Դ�·����̫ƽ��������
˳·ǰ�б����ֹ���

LONG
        );
        set("exits", ([
                "north" : "/d/death/gate",
		"south" : "/d/death/naihe2",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-10);
	set("coor/z",-100);
	setup();
        replace_program(ROOM);
}
 
