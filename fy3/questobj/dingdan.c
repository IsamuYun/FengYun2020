
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name( HIR"¹×²Ä¶¨µ¥" NOR, ({ "dingdan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ÕÅ");
            set("material", "paper");
            set("long", "Ò»ÕÅÏêÏ¸µÄ¶¨µ¥£¬¼ÇÔØ×Å¹×²ÄµÄÔ¤¶¨Çé¿ö£º
ÉÏµÈÌ´ÏãÄ¾¹×²ÄÒ»¿Ú£®£®ÏÂÃæÓĞÒ»ĞĞÓÃºì±ÊÈ¦Ğ´µÄÎÄ×ÖºÜÖµµÃ×¢Òâ£º
ÄÏ¹¬Ç®×¯Óû¶¨×ö£¨zuo)Ò»Ë®¾§¹×²Ä£¬ÏÖÔÚÈ±ÉÙ²ÄÁÏ£ºË®¾§¡¢Ì´ÏãÄ¾ÁÏ¡£\n");
	}
}


void init()
{
  if(this_player()==environment())
  add_action("do_install","zuo"); 
}

int do_install()
{
int i,hezhu=0,baizhu=0;
object jade,me, *inv;
object zhu1,zhu2;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			if(inv[i]->query("name") == "Ì´ÏãÄ¾ÁÏ") {hezhu = 1; zhu1 = inv[i];}
                        if(inv[i]->query("name") == "[1;37mË®¾§[2;37;0m") {baizhu = 1; zhu2 = inv[i];}

		}
if( hezhu && baizhu )
{
	destruct(zhu1);
        destruct(zhu2);
	jade = new("/questobj/obj/guancai1");
	jade->move(me);
message_vision("$NÆ¾×Å×Ô¼ºµÄÏëÏó£¬ÊÔÍ¼×ö³öÒ»¸öÍêÃÀµÄË®¾§¹×²Ä¡£$NÃ¦ÁË°ëÌì£¬
ÀÛµÃÂúÍ·´óº¹£¬²Å×ö³öÁË¸öÒ»¿ÚÄÑ¿´µÄ¹×²Ä¡£$NÕæºó»ÚÀË·ÑÁËÕâĞ©
²ÄÁÏ£¬µ«»òĞí°ÑÕâ¿Ú¹×²ÄÄÃµ½¹×²Äµê»¹ÄÜÓĞËù²¹¾È¡£\n",this_player());
	destruct(this_object());

}
else 
message_vision("$NÒ»Ê±³å¶¯£¬Ïë°´ÕÕ¶¨µ¥ÉÏµÄ²ÄÁÏ×ö¿Ú¹×²Ä£¬µ«¿ÉÏ§µÄÊÇÈ±ÉÙ²ÄÁÏ¡£\n",this_player());

return 1;
}
