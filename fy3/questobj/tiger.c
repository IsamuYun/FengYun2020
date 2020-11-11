
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIW "°×ÓñÀÏ»¢" NOR, ({ "tiger"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ö»");
		set("long", "Ò»Ö»¾§Ó¨ÌŞÍ¸µÄ°×ÓñÀÏ»¢,·¢³öµ­µ­µÄ¹âÃ¢¡£
      ÔÚËüµÄµ×²¿ÓĞÒ»¸öĞ¡¿×£¬Äã¿ÉÒÔ°ÑÊ²Ã´¶«Î÷´ÓÕâ¸öĞ¡¿×Èû£¨sai£©½øÈ¥¡£\n");
		set("value", 1);
	}
}


void init()
{
  if(this_player()==environment())
  add_action("do_sai","sai");
}

int do_sai()
{
int i,hezhu=0,baizhu=0;
object jade,me, *inv;
object zhu1;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			if(inv[i]->query("name") == "[37mÀ¯·âÃÜº¯[2;37;0m") {hezhu = 1; zhu1 = inv[i];}
		}
if( hezhu )
{
	destruct(zhu1);
	jade = new("/questobj/obj/tiger1");
	jade->move(me);
message_vision("$N°Ñ[37mÀ¯·âÃÜº¯[2;37;0m´ò¿ª£¬°ÑÀïÃæµÄÒ»ÕÅĞ¡Ö½Æ¬¾í³ÉÒ»¸öĞ¡¾í£¬Ğ¡ĞÄµØ°ÑËü´Ó[1;37m°×ÓñÀÏ»¢[2;37;0mµ×
²¿µÄĞ¡¿×ÈûÁË½øÈ¥,²¢°ÑĞ¡¿×·âÉÏ¡£\n",this_player());
	destruct(this_object());

}
else 
message_vision("$NÏë°ÑÊ²Ã´¶«Î÷Èû½øÈ¥£¿\n",this_player());

return 1;
}
