// outdoor.c zip@hero 2000.1.27 �����ſ�
#include <ansi.h>
#define ID 109
inherit ROOM;
void create()
{	string *dir=({"��","��"});
	set("short",HIG"���ƽ�"+chinese_number(ID/100)+"��"+dir[ID%2]+NOR);
	set("long",@LONG
���ƽ֣����Ƴ��ڷ��������ס�ĵط�����������ӵ��һ�䷿���������˵�
���롣�������Խ����ݾ�����������де����֣����ﻨ�㡣
���й�Ȼ��һ�����ӣ�
LONG	);
	set("exits",([
	"west" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","owner_id");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"