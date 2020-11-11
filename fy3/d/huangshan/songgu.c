// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ËÉ¹ÈâÖ");
        set("long", @LONG
³¤³¤µÄÊ¯½×£¬ÑØÍ¾¾¡ÊÇÃ¯ÁÖĞŞÖñ£¬Ê÷Ö¦ÉÏ¹Ò×ÅÔÆÎí²İ£¬Ô½·¢Ôö¼ÓÁË
ÇåÁ¹ÓÄ¾²µÄ¸Ğ¾õ£¬ºÍÇ°ÃæµÄÏÕ¾ş½ØÈ»²»Í¬¡£×ßÍêÊ¯½×±ãÊÇËÉ¹ÈâÖ£¬ÕâÊÇ
Ò»×ùÃ÷´úµÄµÀ¹Û£¬âÖÇ°´äÖñÈçº££¬ÖîÌ¶»·²¼£¬¾°É«ÇåÓÄÖÁ¼«¡£ºóÃæ±ãÊÇ
ÎåÁúÌ¶ºÍôä´ä³Ø¡£

                  [42;41m©³©¥©¥©¥©¥©¥©¥©¥©¥©¥©·[0m
                  [42;41m©§[33m   ËÉ ¹È ÓÄ ¾² [42;41m   ©§[0m
                  [42;41m©»©¥©¥©¥©¥©¥©¥©¥©¥©¥©¿[0m
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"feicui",
  "northup" : __DIR__"caishi",
  "east" : __DIR__"diezhang",
]));
        set("objects", ([
        __DIR__"npc/master" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-650);
	set("coor/y",-540);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
