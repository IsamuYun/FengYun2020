// outdoor.c zip@hero 2000.1.27 ·¿×ÓÃÅ¿Ú
#include <ansi.h>
#define ID 301
inherit ROOM;
void create()
{	string *dir=({"¶«","Î÷"});
	set("short",HIG"·çÔÆ½Ö"+chinese_number(ID/100)+"ºÅ"+dir[ID%2]+NOR);
	set("long",@LONG
·çÔÆ½Ö£¬·çÔÆ³ÇÄÚ·çÔÆÈËÎï¾Ó×¡µÄµØ·½£¬ÄÜÔÚÕâÀïÓµÓĞÒ»¼ä·¿×ÓÊÇÎŞÊıÈËµÄ
ÃÎÏë¡£Ê¨×ÓµÄ[1;33mÑöÌì¸ó[2;37;0m¾ÍÔÚÕâÀï¡£ÓôÓô´Ğ´ĞµÄËÉÁÖ£¬ÄñÓï»¨Ïã¡£
Ì§Í·ÑöÌìÍû£¬Ğ¦¿´·çÔÆ¹ı¡£
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