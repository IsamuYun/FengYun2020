
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC "������" NOR, ({ "jade-pin"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "һ���������ε����������в�����Ǳ���������Ƕ�ŵ����Ŵ�
��ʯȴ���������,���������ҵ��������鱦ʯ����������
����(install)��ԭ��\n");
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
			if(inv[i]->query("name") == "[1;32m���̱�ʯ[2;37;0m") {hezhu = 1; zhu1 = inv[i];}
                        if(inv[i]->query("name") == "[1;31m��Ѫ��ʯ[2;37;0m") {baizhu = 1; zhu2 = inv[i];}

		}
if( hezhu && baizhu )
{
	destruct(zhu1);
        destruct(zhu2);
	jade = new("/questobj/obj/pin1");
	jade->move(me);
message_vision("$NС������İ��ҵ������鱦ʯ�����������ϣ�ֻ����������һ����
���鱦ʯ�Զ�����Ƕ�����������ˣ�һֻ��ʶ�Ŀ�������������������ǰ��\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N�������������ԭ������ϧ��������û�в��ϡ�\n",this_player());

return 1;
}
