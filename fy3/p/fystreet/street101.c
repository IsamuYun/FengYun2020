// outdoor.c zip@hero 2000.1.27 ·¿×ÓÃÅ¿Ú
#include <ansi.h>
#define ID 101
inherit ROOM;
void create()
{	string *dir=({"¶«","Î÷"});
	set("short",HIG"·çÔÆ½Ö"+chinese_number(ID/100)+"ºÅ"+dir[ID%2]+NOR);
	set("long",@LONG
·çÔÆ½Ö£¬·çÔÆ³ÇÄÚ·çÔÆÈËÎï¾Ó×¡µÄµØ·½£¬ÄÜÔÚÕâÀïÓµÓĞÒ»¼ä·¿×ÓÊÇÎŞÊıÈËµÄ
ÃÎÏë¡£¿ìÀÖµÄ¿ìÀÖ[2;37;0m¾ÍÔÚÕâÀï¡£ÓôÓô´Ğ´ĞµÄËÉÁÖ£¬ÄñÓï»¨Ïã¡£
o
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","sku");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"