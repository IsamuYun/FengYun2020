#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( CYN"�з�����" NOR, ({ "gsword" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѵ���������͵��з��������������ʿɲ�(cha)��ֻ�ܱ������䡣\n");
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
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
      if(inv[i]->query("name") == "�Ž���") 
  {     cl = inv[i];
	destruct(cl);
   message_vision("\n$NС�ĵؽ��з���������Ž��ʡ��ߴ羹Ȼ���ã�\n",this_player());
        newtask = new(__DIR__"obj/gsword2");
	newtask->move(me);
	destruct(this_object());
        return 1;
  }
}
        return 1;

}
