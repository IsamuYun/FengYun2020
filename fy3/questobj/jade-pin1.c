
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
            set("long", "һ�Ѵ���������̡���ϸһ�������ֺ�������������
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
int i,hezhu=0,baizhu=0;
object jade,me, *inv;
object zhu1,zhu2;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			if(inv[i]->query("name") == "[1;33m������[2;37;0m") {hezhu = 1; zhu1 = inv[i];}
			if(inv[i]->query("name") == "[1;33m������[2;37;0m") {baizhu = 1; zhu2 = inv[i];}

		}
if( hezhu && baizhu )
{
	destruct(zhu1);
        destruct(zhu2);
	jade = new("/questobj/obj/suanpans");
	jade->move(me);
message_vision("$N�����ذ�[1;33m������[2;37;0m�𿪣�С�ĵؽ�[1;33m������[2;37;0mװ����ȥ��
\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N����û��[1;33m������[2;37;0m��\n",this_player());

return 1;
}
