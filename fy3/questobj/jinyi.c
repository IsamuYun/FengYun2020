// ken 1999.12.7

#include <armor.h>
inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIR"��������"NOR, ({ "jinyi" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����˿����Ƭ���ɵ�����������ȥ������һ�����ס����������Զ��\n��Ƭ���䣬Ҫ��˭��ĥ(mo)��Щ��Ƭ�ͺ���\n");
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
      if(inv[i]->query("name") == "��ʯ") 
  {     cl = inv[i];
	destruct(cl);
   message_vision("\n$N����ʯ��ϸ��ĥƽ�����ڽ��������ϡ�\n",this_player());
        newtask = new(__DIR__"obj/jinyi2");
	newtask->move(me);
	destruct(this_object());
        return 1;
  }
}
        return 1;

}