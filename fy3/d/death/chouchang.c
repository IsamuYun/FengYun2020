// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�鳦��");
        set("long", @LONG
�����ƺ�������ǲ�ͬ��û�д��̾ߣ����еĶ������Ǽ��ѹ��Ӻ�
���ѽ�ţ���������������õ��ʿ����ӣ�����һ��������һ���ҽУ�
������������ͷƤ������㷢���Ժ�����������ˣ���صĳ�������
ֻ��Ż�����������ֶ���һ������֮�ġ��������±�����һ���ˡ�
LONG
        );
        set("exits", ([
		"up" : __DIR__"tuoke",
		"down" : __DIR__"youguo",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-220);
	setup();
        replace_program(ROOM);
}
 
