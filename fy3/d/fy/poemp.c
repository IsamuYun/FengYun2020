inherit ROOM;
void create ()
{
  set ("short", "Ì½»¨Ê«Ì¨");
  set ("long", @LONG
·çÔÆÖĞµÄÀÏÀÏÉÙÉÙ´ó¶¼ÓĞÒ÷Ê«¶Ô´ÊµÄÑÅºÃ¡£Ö»ÒªÉÔÓĞÁé¸Ğ£¬¾Í»á´ø×Å±ÊÄ«µ½ÕâÀïÀ´
ÔÍÄğ£¬µÈµ½Áé¹âÕ§ÏÖÄÇö®ÄÇ£¬·Ü±Ê¼±Êé£¬ÒÔÇóÇ§¹ÅÃû¾ä¡£Ê«Ì¨ÕıÖĞÖì±ÊÈëÄ¾¿ñ²İ£º
[33m
                       ½ñÈÕÓĞ¾Æ½ñ³¯×í£¬
                       ÄÄ¹ÜËüÈÕ½£¸îÍ·£¡
                                       °¢Ìú¿ñÎèÓÚ¾ÆºóÊ§ÒâÊ±¡£

[37m
LONG);

        set("jianyu_room",1);
  set("no_death_penalty", 1);
  set("objects", ([ /* sizeof() == 3 */
    __DIR__"npc/referee" : 1,
  __DIR__"npc/prince" : 1,
  __DIR__"npc/yaren" : 1,
"/d/wiz/fyup/npc/xiaoqiang" :1,
]));
  set("coor", ([ /* sizeof() == 3 */
  "y" : 1,
  "z" : 0,
  "x" : -10,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wcloud1",
  "up" : __DIR__"wenroom",
]));
        call_other( "/obj/board/fyyh_b", "???" );
  setup();
//  replace_program(ROOM);
}
void init()
{
        add_action("do_work", "2002");

}
int do_work(string arg)
{
        object ob;
        object me;
        me = this_player();
if(me->is_busy()) return notify_fail("ÄãĞèÒªĞİÏ¢Ò»»á¡£\n");
if(me->query("2002")== 1) return notify_fail("ÄãÒÑ¾­À´½±ÀøÁË£¬²»ÄÜÔÙ½±ÀøÁË¡£\n");
message_vision("Ï£Íû$NÔÚĞÂµÄÒ»Äê¼ÌĞøÖ§³ÖÎÒÃÇ!\n",me);
ob = new("/questobj/obj/2002hongbao");
ob->move(me);
me->start_busy(1);
me->set("2002",1);
return 1;
}

