
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIY"������"NOR, ({ "suanpan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "gold");
            set("long", "һ�Ѵ���������̡���ϸһ�������ֺ�������һ��������
������ҵ����ǣ���װ��zhuang����ȥ���Ǿ�������ȱ�ˡ�\n");
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
int i,hezhu=0;
object jade,me, *inv;
object zhu1;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("name") == "[1;33m������[2;37;0m") {hezhu = 1; zhu1 = inv[i];}
		

		}
if( hezhu )
{
	destruct(zhu1);
	jade = new("/questobj/obj/suanpan1");
	jade->move(me);
message_vision("$N�����ذ�[1;33m������[2;37;0m�𿪣���ȱ�ٵ�һ��[1;33m������[2;37;0mװ����ȥ��
\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N������,���Ǿ�����һ��[1;33m������[2;37;0m�滻ȱ�ٵĿ�λ�Ƚ��׵���\n",this_player());

return 1;
}
