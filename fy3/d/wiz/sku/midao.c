//sku@00-11-19 
inherit ROOM;
void create ()
{
  set ("short", "ÃÜµÀ");
  set ("long", @LONG
ÕâÊÇ¿ìÀÖÎªÁËÍµÀÁ£¬×Ô¼ºĞŞµÄÃØÃÜÍ¨µÀ£º
     [45mÌì»ú A  ³ÁÏã B  ÈıÇå C  ´óÀí D  ¹ØÍâ E  »ÆÉ½ F[0m
     [42mÄ§½Ì G  ÍòÃ· H  Îäµ± I  ÉñË® J  ³£´º K  ÉÙÁÖ L[0m
     [43mÉñ½£ M  Çå·ç N  áÔÉ½ O  ĞË¹ú P  òùòğ Q  ÓÄÁé R[0m
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : "/d/fy/fysquare",
  "west" : __DIR__"workroom",
]));
  set("coor", ([ /* sizeof() == 3 */
  "z" : 1000000,
  "x" : 0,
  "y" : 0,
]));
  set("no_magic", 1);

  setup();
  replace_program(ROOM);
}
