
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name( HIR"�ײĶ���" NOR, ({ "dingdan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ����ϸ�Ķ����������Źײĵ�Ԥ�������
�ϵ�̴��ľ�ײ�һ�ڣ���������һ���ú��Ȧд�����ֺ�ֵ��ע�⣺
�Ϲ�Ǯׯ��������zuo)һˮ���ײģ�����ȱ�ٲ��ϣ�ˮ����̴��ľ�ϡ�\n");
	}
}


void init()
{
  if(this_player()==environment())
  add_action("do_install","zuo"); 
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
			if(inv[i]->query("name") == "̴��ľ��") {hezhu = 1; zhu1 = inv[i];}
                        if(inv[i]->query("name") == "[1;37mˮ��[2;37;0m") {baizhu = 1; zhu2 = inv[i];}

		}
if( hezhu && baizhu )
{
	destruct(zhu1);
        destruct(zhu2);
	jade = new("/questobj/obj/guancai1");
	jade->move(me);
message_vision("$Nƾ���Լ���������ͼ����һ��������ˮ���ײġ�$Næ�˰��죬
�۵���ͷ�󺹣��������˸�һ���ѿ��Ĺײġ�$N�����˷�����Щ
���ϣ����������ڹײ��õ��ײĵ껹���������ȡ�\n",this_player());
	destruct(this_object());

}
else 
message_vision("$Nһʱ�嶯���밴�ն����ϵĲ������ڹײģ�����ϧ����ȱ�ٲ��ϡ�\n",this_player());

return 1;
}
