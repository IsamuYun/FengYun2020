//xgchen@zzfy

inherit ROOM;
void create ()
{
        set ("short", "±ÈÎä¿´Ì¨");
        set ("long", @LONG
ÕâÊÇÖ£Öİ·çÔÆµÄ±ÈÎä³¡µÄ¿´Ì¨£¬¿´Ì¨ÉÏÓĞÒ»ÅÅÅÅµÄÄ¾ÖÆÌõµÊ¡£Äã×øÔÚ
ÕâÀïÒ»ÕÉ¸ßµÄ±ÈÎäÌ¨ÉÏÒ»ÇĞ±ÈÎä¹ıÕĞÄã¶¼ÄÜ¿´µÃ·Ç³£Çå³ş¡£ÕâÀï»¹Ìá¹©
Ãâ·ÑµÄÒûÊ³¡£

                [47m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù [0m
                [47m¡ù                              ¡ù [0m
                [47m¡ù [30m ´ò  ±é  Ìì  ÏÂ  ÎŞ  µĞ  ÊÖ[32m  ¡ù [0m
                [47m¡ù                              ¡ù [0m
                [47m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù [0m

        [47m¡ù¡ù¡ù¡ù¡ù [0m                               [47m¡ù¡ù¡ù¡ù¡ù [0m
        [47m¡ù      ¡ù [0m                               [47m¡ù      ¡ù [0m
        [47m¡ù  [30m½Å[32m  ¡ù [0m                               [47m¡ù  [30mÈ­ [32m ¡ù [0m
        [47m¡ù      ¡ù [0m                               [47m¡ù      ¡ù [0m
        [47m¡ù  [30mÌß[32m  ¡ù [0m  ÕâÀïÊÇÖ£Öİ·çÔÆµÄ±ÈÎä³¡¿´Ì¨¡£ [47m¡ù  [30m´ò [32m ¡ù [0m
        [47m¡ù      ¡ù [0m                               [47m¡ù      ¡ù [0m
        [47m¡ù  [30m±±[32m  ¡ù [0m  ÕâÀï¿ÉÒÔ¿´µ½ÉÏÃæµÄ±ÈÎäÀŞÌ¨¡£ [47m¡ù  [30mÄÏ [32m ¡ù [0m
        [47m¡ù      ¡ù [0m                               [47m¡ù      ¡ù [0m
        [47m¡ù  [30mº£[32m  ¡ù [0m  ÀŞÌ¨ÉÏÃæ¹Ò×ÅÒ»·ùºÜ´óµÄ¶ÔÁª¡£ [47m¡ù  [30mÉ½ [32m ¡ù [0m
        [47m¡ù      ¡ù [0m                               [47m¡ù      ¡ù [0m
        [47m¡ù  [30mòÔ[32m  ¡ù [0m                               [47m¡ù  [30mÃÍ [32m ¡ù [0m
        [47m¡ù      ¡ù [0m                               [47m¡ù      ¡ù [0m
        [47m¡ù  [30mÁú[32m  ¡ù [0m                               [47m¡ù  [30m»¢ [32m ¡ù [0m
        [47m¡ù      ¡ù [0m                               [47m¡ù      ¡ù [0m
        [47m¡ù¡ù¡ù¡ù¡ù [0m                               [47m¡ù¡ù¡ù¡ù¡ù [0m
[0m
LONG);
        set("no_fight",1);
        set("no_exert",1);
        set("no_magic",1);
        set("no_clean_up",1);
        set("watch_fight_room2",1);
        set("exits", ([
                "up"   : __DIR__"biwutai",
                "down"   : __DIR__"biwufang",
        ]));
        setup();
}

void init()
{
        add_action ("do_work","perform");
        add_action ("do_work","exert");
        add_action ("do_work","dazuo");
}

int do_work()
{
        write("ÕâÀï²»ÄÜÊ¹ÓÃÕâ¸öÖ¸Áî£¡\n");
        return 1;
}

int valid_leave(object me, string dir)
{
        object tai=load_object(__DIR__"biwutai");
        object *inv=all_inventory(tai);
        object ob, where;
        int i=sizeof(inv);


        if ( !wizardp(me) && dir=="up" ) {
                if(i>=3)
                        return notify_fail("±ÈÎäÌ¨ÉÏÒÑ¾­ÓĞÁ½ÃûÑ¡ÊÖ£¬ÄãÏÖÔÚ²»ÄÜÉÏÌ¨¡£\n");
        }
        return ::valid_leave(me, dir);
}
