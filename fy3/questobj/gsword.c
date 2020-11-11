#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( CYN"尚方宝剑" NOR, ({ "gsword" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把当今皇上御赐的尚方宝剑。可是无鞘可插(cha)，只能别在腰间。\n");
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间。\n");
	}
	init_sword(45);
	setup();
}
void init()
{
  if(this_player()==environment())
  add_action("do_cha","cha");
}

int do_cha()
{
object me, *inv;
int i;
object cl,newtask;
me = this_player();
inv = all_inventory(me);
for(i=0; i<sizeof(inv); i++)
{
      if(inv[i]->query("name") == "古剑鞘") 
  {     cl = inv[i];
	destruct(cl);
   message_vision("\n$N小心地将尚方宝剑插入古剑鞘。尺寸竟然正好！\n",this_player());
        newtask = new(__DIR__"obj/gsword2");
	newtask->move(me);
	destruct(this_object());
        return 1;
  }
}
        return 1;

}
