
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIR"����ȺӢ��"NOR, ({ "qunyingpu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ������ȺӢ�ף������ŹŽ�Ӣ�۵����֣�������һ����
�������Եĵط���Ȼ�ǿյģ������֧�ʣ����ҵ�ī֭�Ļ���
������д(write)��ʲô��ȥ��\n");
          }
}


void init()
{
  if(this_player()==environment())
  add_action("do_install","write");
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
			if(inv[i]->query("name") == "����") {hezhu = 1; zhu1 = inv[i];}
                        if(inv[i]->query("id") == "maobi") {baizhu = 1; zhu2 = inv[i];}

		}
if( hezhu && baizhu )
{
	destruct(zhu1);
	jade = new("/questobj/obj/qypu");
	jade->move(me);
message_vision("$N���˴󷢣������Ǻ��ʣ��ݲݼ��ʣ���$N�ڽ����еĴ����ĵ�
д�ڿհ׵ĵط���\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N����[1;31m����ȺӢ��[2;37;0m��дЩʲô����ϧ����ȱ����д�Ĺ��ߡ�\n",this_player());

return 1;
}
