
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIW "�����ϻ�" NOR, ({ "tiger"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "һֻ��Ө��͸�İ����ϻ�,���������Ĺ�â��
      �����ĵײ���һ��С�ף�����԰�ʲô���������С������sai����ȥ��\n");
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
			if(inv[i]->query("name") == "[37m�����ܺ�[2;37;0m") {hezhu = 1; zhu1 = inv[i];}
		}
if( hezhu )
{
	destruct(zhu1);
	jade = new("/questobj/obj/tiger1");
	jade->move(me);
message_vision("$N��[37m�����ܺ�[2;37;0m�򿪣��������һ��СֽƬ���һ��С��С�ĵذ�����[1;37m�����ϻ�[2;37;0m��
����С�����˽�ȥ,����С�׷��ϡ�\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N���ʲô��������ȥ��\n",this_player());

return 1;
}
