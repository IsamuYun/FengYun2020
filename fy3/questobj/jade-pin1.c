
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIY"½ğËãÅÌ"NOR, ({ "suanpan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "°Ñ");
            set("material", "gold");
            set("long", "Ò»°Ñ´¿½ğ´òÔìËãÅÌ¡£×ĞÏ¸Ò»¿´£¬·¢ÏÖºÃÏóÉÙÁËÁ½¸öÖé
Èç¹ûÄÜÕÒµ½ËüÃÇ£¬²¢×°£¨zhuang£©ÉÏÈ¥£¬ÄÇ¾ÍÍêÃÀÎŞÈ±ÁË¡£\n");
		set("value", 1);
	}
}


void init()
{
  if(this_player()==environment())
  add_action("do_zhuang","zhuang");
}

int do_zhuang()
{
int i,hezhu=0,baizhu=0;
object jade,me, *inv;
object zhu1,zhu2;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			if(inv[i]->query("name") == "[1;33mËãÅÌÖé[2;37;0m") {hezhu = 1; zhu1 = inv[i];}
			if(inv[i]->query("name") == "[1;33mËãÅÌÖé[2;37;0m") {baizhu = 1; zhu2 = inv[i];}

		}
if( hezhu && baizhu )
{
	destruct(zhu1);
        destruct(zhu2);
	jade = new("/questobj/obj/suanpans");
	jade->move(me);
message_vision("$NÂıÂıµØ°Ñ[1;33m½ğËãÅÌ[2;37;0m²ğ¿ª£¬Ğ¡ĞÄµØ½«[1;33mËãÅÌÖé[2;37;0m×°ÁËÉÏÈ¥¡£
\n",this_player());
	destruct(this_object());

}
else 
message_vision("$NÉíÉÏÃ»ÓĞ[1;33mËãÅÌÖé[2;37;0m¡£\n",this_player());

return 1;
}
