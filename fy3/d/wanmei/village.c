inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "ÍòÃ·É½×¯");
        set("long", @LONG
ÔÚÄãÃæÇ°ÊÇÖ¦èâ½»²æµÄÃ·ÁÖ£¬Ã¿µ±°×Ñ©°¨°¨Ö®¶¬£¬±éÉ½Ã·»¨
¾¹Ïà¿ª·Å¡£±±·çÖ®ÖĞ£¬Ñ©»¨ÓëºìÃ·ÏàÓ³³É»Ô£¬ÃÀ²»Ê¤ÊÕ¡£Ã·Ö¦ÑÚ
Ó³Ö®ÖĞ£¬·çÁå¶£ßË£¬ºöÒşºöÏÖ¡£
Ò»¸öÃÅØÒ£¬ÉÏÃæĞ´×Å:

                  [37;41m©³©¥©¥©¥©¥©¥©¥©¥©¥©¥©·[0m
                  [37;41m©§[33m   Íò Ã· É½ ×¯ [37;41m   ©§[0m
                  [37;41m©»©¥©¥©¥©¥©¥©¥©¥©¥©¥©¿[0m

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road2",
  "east" : __DIR__"gate",
]));
        set("outdoors", "wanmei");
        set("coor/x",130);
	set("coor/y",-400);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
