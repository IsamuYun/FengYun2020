inherit ROOM;
void create()
{
        set("short", "É½×¯´óÃÅ");
        set("long", @LONG
ÕâÀï±ãÊÇÇåÆ½É½×¯µÄ´óÃÅ£¬ºìÉ«µÃ´óÃÅ¿´ÉÏÈ¥ÆÕÆÕÍ¨Í¨£¬Ö»ÓĞÃÅ¶î
ÉÏµÄ"ÇåÆ½É½×¯"ËÄ×ÖÉõÊÇÈÇÈË×¢Ä¿£¬ÃÅ¿ÚÁ¢×Å¼¸Î»¾¢×°ÉÙÄê£¬ÕıÊÇÇåÆ½
ÃÅÏÂµÜ×Ó£¬ÃÅÇ°Ò»¿ÃÀÏ»±Ê÷£¬Ö¦Ò¶Ã¯ÃÜ£¬ËÆºõÌåÏÖ×Å×¯Ö÷µÄ¶ÀÌØ·ç¹Ç¡£

                  [37m   Çå Æ½ É½ ×¯ [37m   [0m

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"wuchang1",
  "west" : __DIR__"road",
]));
   set("objects", ([
      __DIR__"npc/lu": 1,
      __DIR__"npc/young": 2,
   ]) );

   	set("outdoors","qingping");
        set("coor/x",110);
	set("coor/y",2000);
	set("coor/z",0);
	set("coor/x",110);
	set("coor/y",2000);
	set("coor/z",0);
	setup();
	
	replace_program(ROOM);
}
