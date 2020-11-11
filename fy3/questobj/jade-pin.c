
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC "êèÓñ·¢ô¢" NOR, ({ "jade-pin"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ö»");
		set("long", "Ò»¸ö´äÂÌÓûµÎµÄÓñ·¢ô¢£¬ÃÀÖĞ²»×ãµÄÊÇ±¾À´ÉÏÃæÏâÇ¶×ÅµÄÁ½¿Å´ó
±¦Ê¯È´²»Òí¶ø·ÉÁË,Äã¹À¼ÆÈç¹ûÕÒµ½ÁËÄÇÁ½¿é±¦Ê¯£¬»òĞí»¹¿ÉÒÔ
°ÑËü(install)¸´Ô­¡£\n");
		set("value", 1);
	}
}


void init()
{
  if(this_player()==environment())
  add_action("do_install","install");
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
			if(inv[i]->query("name") == "[1;32mÄı±Ì±¦Ê¯[2;37;0m") {hezhu = 1; zhu1 = inv[i];}
                        if(inv[i]->query("name") == "[1;31m»¯Ñª±¦Ê¯[2;37;0m") {baizhu = 1; zhu2 = inv[i];}

		}
if( hezhu && baizhu )
{
	destruct(zhu1);
        destruct(zhu2);
	jade = new("/questobj/obj/pin1");
	jade->move(me);
message_vision("$NĞ¡ĞÄÒíÒíµÄ°ÑÕÒµ½µÄÁ½¿é±¦Ê¯·ÅÔÚêèÓñ·¢ô¢ÉÏ£¬Ö»Ìı¡°¿¨À²¡±Ò»Éù£¬
Á½¿é±¦Ê¯×Ô¶¯µÄÏâÇ¶ÔÚêèÓñ·¢ô¢ÉÏÁË£¬Ò»Ö»¹â²Ê¶áÄ¿µÄêèÓñ·¢ô¢³ÊÏÖÔÚÄãµÄÃæÇ°¡£\n",this_player());
	destruct(this_object());

}
else 
message_vision("$NÕæÏë°ÑêèÓñ·¢ô¢¸´Ô­£¬µ«¿ÉÏ§µÄÊÇÊÖÖĞÃ»ÓĞ²ÄÁÏ¡£\n",this_player());

return 1;
}
