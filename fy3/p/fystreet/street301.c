// outdoor.c zip@hero 2000.1.27 �����ſ�
#include <ansi.h>
#define ID 301
inherit ROOM;
void create()
{	string *dir=({"��","��"});
	set("short",HIG"���ƽ�"+chinese_number(ID/100)+"��"+dir[ID%2]+NOR);
	set("long",@LONG
���ƽ֣����Ƴ��ڷ��������ס�ĵط�����������ӵ��һ�䷿���������˵�
���롣ʨ�ӵ�[1;33m�����[2;37;0m������������де����֣����ﻨ�㡣
̧ͷ��������Ц�����ƹ���
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","lion");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"