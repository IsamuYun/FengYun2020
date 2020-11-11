// ken 1999.12.7

#include <armor.h>
inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIR"金镂玉衣"NOR, ({ "jinyi" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件金丝与玉片做成的衣衫，看上去倒象是一件盔甲。但是年代久远，\n玉片剥落，要是谁能磨(mo)出些玉片就好了\n");
		set("material", "cloth");
		set("armor_prop/armor",80);		
	}
	setup();
}

void init()
{
  if(this_player()==environment())
  add_action("do_mo","mo");
}

int do_mo()
{
object me, *inv;
int i;
object cl,newtask;
me = this_player();
inv = all_inventory(me);
for(i=0; i<sizeof(inv); i++)
{
      if(inv[i]->query("name") == "玉石") 
  {     cl = inv[i];
	destruct(cl);
   message_vision("\n$N把玉石仔细的磨平，补在金镂玉衣上。\n",this_player());
        newtask = new(__DIR__"obj/jinyi2");
	newtask->move(me);
	destruct(this_object());
        return 1;
  }
}
        return 1;

}