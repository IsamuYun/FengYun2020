#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "ÄÏ¹¬Ç®×¯");
        set("long", @LONG
ÖĞÔ­ÄÏ¹¬ÊÀ¼Ò£¬¼Ò²ÆÍò¹á£¬²úÒµ²»¿ÉÊ¤Êı¡£´Ë¼äÇ®×¯ºÚØÒºì×Ö£¬ÕıÊÇÄÏ¹¬²úÒµÖ®
Ò»¡£ÄÏ¹¬Ç®×¯µÄÒøÆ±ĞÅÓş¼«ºÃ£¬´ó½­ÄÏ±±¶¼¿É¶ÒÏÖ¡£¾ÍÊÇ¸»¿ÉµĞ¹úµÄ½ğÇ®°ï£¬Ò²ÄÑÍû
ÆäÏî±³¡£Ç®×¯ÖĞÑëÓĞÒ»ºìÄ¾¹ñÌ¨£¬°ëÈË¶à¸ß£¬ÉÏÓĞÅÆ£¨£ó£é£ç£î£©Ò»¿é¡£
[31m
                        ÄÏ¹¬Ç®×¯
[37m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"bazha",
  "east" : __DIR__"bazha1",
  "southeast" : __DIR__"bazha3",
]));
        set("item_desc", ([
                "sign": @TEXT
ÕâÀïÊÇÇ®×¯£¬Ä¿Ç°ÎÒÃÇÌá¹©µÄ·şÎñÓĞ£º

convert     ¶Ò»»Ç®±Ò¡£
withdraw    ÌáÈ¡´æ¿î¡£
deposit     ´æÈëÇ®±Ò¡£
balance     ²ìÑ°´æ¿î¡£
loan        ÏòÇ®×¯½èÇ®¡£

TEXT
        ]) );
        set("objects", ([
                __DIR__"npc/bankowner" :1,
                __DIR__"npc/swaiter7" :1,
                __DIR__"npc/swaiter8" :1,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1130);
	set("coor/y",1080);
	set("coor/z",0);
	setup();
}
