//sku@00-11-19 
inherit ROOM;
void create ()
{
  set ("short", "[45m¿ìÀÖµÄĞİÏ¢ÊÒ[0m");
  set ("long", @LONG
ÕâÊÇ¿ìÀÖµÄ¹¤×÷¼ä,Êé×ÀÉÏÒ»Ì¨[42m±¼ÌÚ760[0mÔÚ·É¿ìµÄ
ÔË×ª×Å¡£¿¿´°·Å×ÅÒ»ÕÅĞ¡´²£¬ÒşÒşÔ¼Ô¼ÄãÌıµ½·çÔÆ³Ç
ÀïµÄ»¶ÉùĞ¦Óï¡£Õâ¶¼ÊÇ¿ìÀÖĞÁÇÚÀÍ¶¯µÄ½á¹ûÑ½¡£ 
LONG);

  set("coor", ([ /* sizeof() == 3 */
  "z" : 1000000,
  "y" : 0,
  "x" : -10,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"midao.c",
]));
  set("valid_startroom", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/book" : 1,
]));
  set("no_magic", 1);

  setup();
  replace_program(ROOM);
}
