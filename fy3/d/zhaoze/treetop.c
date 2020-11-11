inherit ROOM;
void create()
{
        set("short", "·üÁúÒş¸ó");
        set("long", @LONG
Äã¾ªÆæµÄ·¢ÏÖÒ»¸öÉè¼ÆµäÑÅµÄĞ¡Ä¾Îİ£¬Ä¾ÎİÇ°ÃæÓĞÄ¾×À£¬Ä¾ÒÎ¡£
Ä¾×ÀÉÏ·Å×ÅÒ»¹ÅÇÙ£¬Ò»¸öº×·¢ÀÏÕßÕıÔÚÂş²»¾­ĞÄµÄ²¦Åª×Å¡£
Ä¾ÎİÉÏµÄÁºÉÏĞü×ÅÒ»¿éØÒ¶î£¬ÉÏÃæÁú·É·ïÎèµÄĞ´×Å:


                  [37;39m©³©¥©¥©¥©¥©¥©¥©¥©¥©¥©·[0m
                  [37;39m©§[31m   ·ü Áú Òş ¸ó [37;39m   ©§[0m
                  [37;39m©»©¥©¥©¥©¥©¥©¥©¥©¥©¥©¿[0m


ÕâÀïËÄÖÜ±»ÌÙÌõÕÖ×¡£¬ÒªÊÇ²»Õ¾ÔÚÊ÷ÉÏ»¹ÕæÄÑ·¢ÏÖÕâÀï¡£²»¹ıÒªÏë
³öÈ¥Ò²Ö»ÄÜ·Ö¿ª(cut)ÌÙÌõ(tiao)ÁË¡£
LONG
        );
        set("objects", ([
         __DIR__"npc/rmaster": 1,
          ]) );
        set("coor/x",-10);
        set("coor/y",-610);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_open", "cut");
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("ÄãÒª·Ö¿ªÊ²Ã´£¿\n");
                return 1;
        }
        if( arg == "tiao" || arg == "ÌÙÌõ")
        {
        me = this_player();
        message_vision("$NÏòÇ°×ßÁËÁ½²½£¬·ÜÁ¦ÓÃË«ÊÖ·Ö¿ªÌÙÌõ£¬Ö»Ìı
£¢Ë¢£¢µØÒ»Éù£¬ÌÙÌõ±»·Ö¿ªÁËÒ»¸öÈ±¿Ú¡£\n", me);
        if( !query("exits/east") ) {
        set("exits/east", __DIR__"edge");
        if(!me->query("m_success/·üÁúÒş¸ó"))
        {
                me->set("m_success/·üÁúÒş¸ó",1);
                me->add("score",500);

        }
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("ÄãÉìÊÖ·Ö¿ªÁË"+arg+"¡£\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/east") ) return;
        message("vision",
"ÌÙÌõÎŞÉùÎŞÏ¢µÄÓÖºÏÉÏÁË£¬µ²×¡ÁË·¢ÏÖµÄµÀÂ·¡£\n",
                this_object() );
                delete("exits/east");
}

