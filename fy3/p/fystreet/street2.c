#define ID 2
#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIG"���ƽ�"+chinese_number(ID)+"��"NOR);
	set("long",@LONG
���ƽ֣����Ƴ��ڷ��������ס�ĵط�����������ӵ��һ�䷿���������˵�
���롣һ�����Ĵ���������Ǵд������������ɡ�����ԼԼ����Щ���Ӵ�����
��¶��ͷ����
LONG	);
	set("exits",([
	"south": __DIR__"street"+(string)(ID-1), 
	"west" : __DIR__"street"+(string)ID+"01",
	"east" : __DIR__"street"+(string)ID+"00",
"north": __DIR__"street"+(string)(ID+1),
	]));
	set("coor/x",50);
	set("coor/y",20+ID*10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
