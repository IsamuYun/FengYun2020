
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIR"·çÔÆÈºÓ¢Æ×"NOR, ({ "qunyingpu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "±¾");
            set("material", "paper");
            set("long", "Ò»±¾·çÔÆÈºÓ¢Æ×£¬¼ÇÔØ×Å¹Å½ñÓ¢ĞÛµÄÃû×Ö£¬µ«·­¿ªÒ»¿´£¬
ÀïÃæÒıÑÔµÄµØ·½¾¹È»ÊÇ¿ÕµÄ£¬Èç¹ûÓĞÖ§±Ê£¬ÔÙÕÒµ½Ä«Ö­µÄ»°£¬
ÄãÕæÏëĞ´(write)µãÊ²Ã´ÉÏÈ¥¡£\n");
          }
}


void init()
{
  if(this_player()==environment())
  add_action("do_install","write");
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
			if(inv[i]->query("name") == "¶ËÑâ") {hezhu = 1; zhu1 = inv[i];}
                        if(inv[i]->query("id") == "maobi") {baizhu = 1; zhu2 = inv[i];}

		}
if( hezhu && baizhu )
{
	destruct(zhu1);
	jade = new("/questobj/obj/qypu");
	jade->move(me);
message_vision("$NºÀĞË´ó·¢£¬ÄÃÆğÀÇºÁ±Ê£¬²İ²İ¼¸±Ê£¬½«$NÔÚ½­ºşÖĞµÄ´¦ÊÀĞÄµÃ
Ğ´ÔÚ¿Õ°×µÄµØ·½¡£\n",this_player());
	destruct(this_object());

}
else 
message_vision("$NÏëÔÚ[1;31m·çÔÆÈºÓ¢Æ×[2;37;0mÉÏĞ´Ğ©Ê²Ã´£¬¿ÉÏ§µÄÊÇÈ±ÉÙÊéĞ´µÄ¹¤¾ß¡£\n",this_player());

return 1;
}
