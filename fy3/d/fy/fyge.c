// inn.c

#include <room.h>

inherit ROOM;


void create ()
{
  set ("short", "·çÔÆ¸ó");
  set ("long", @LONG
·çÔÆ¸óµÄÖ÷ÈË¾ÍÊÇµ±½ñÌìÏÂÏÀÃû¶¦¶¦µÄĞ¡Àî·Éµ¶¡£ÀîÌ½»¨³¤ÄêĞĞÏÀÔÚÍâ£¬µ«»¹ÊÇ
ÓĞºÜ¶à¿ÍÈËÄ½ÃûÀ´µ½´Ë¸ó£¬ÒÔÇóÒ»ÃæÖ®Ôµ¡£¸óÖĞ´óºì²¨Ë¹µØÌºÆÌµØ£¬¸»ÀöÌÃ»Í¡£Öìºì
µÄ´óÃÅÁ½²à¸÷¹ÒÒ»·ùÊ¯¿ÌµÄ¶ÔÁª¶ù£º
[33m
                	Ò»ÃÅÆß½øÊ¿£¬
                	¸¸×ÓÈıÌ½»¨¡£
[37m
LONG);

  set("valid_startroom", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fywaiter" : 1,
]));
  set("coor", ([ /* sizeof() == 3 */
  "y" : 10,
  "z" : 0,
  "x" : 10,
]));
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"nwind1",
  "up" : __DIR__"fyyage",
]));

  setup();
  replace_program(ROOM);
}
