#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(BLU"���ǵ���"NOR, ({ "daoqiao" }) );
        set_weight(8000);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("for_bandit2",1);
                set("long", "һ������ɽ��ǧ�꺮�����ɵĵ��ʡ�\n");
        }
}

int is_container() { return 1; }

void init()
{
  if(this_player()==environment())
  add_action("do_combine","kan_qiao");
}

int do_combine()
{
int i,bk=0,sp=0,il=0;
object commcase,me, *inv;
object wandao,daoqiao,unarmed;
me = this_player();
inv = all_inventory(me);
i=0;
while(i<sizeof(inv))
                {
                        if(base_name(inv[i]) == "/questobj/wandao") {bk = 1; wandao = inv[i];}
                        if(base_name(inv[i]) == "/questobj/daoqiao") {sp = 1; daoqiao = inv[i];}
                        i++;
		}
                        if(me->query("str")>=11) {il = 1;}
if( bk && sp && il )
{
           wandao->move(environment(me));destruct(wandao);
	message_vision("$N�ݶ����������е�Բ���䵶�����ǵ��ʿ�ȥ,���ǵ������̶��ѡ�\n\n��Բ���䵶Ҳ��˻���һ����Ƭ��\n",me);
	commcase = new(__DIR__"duanqiao");
	commcase->move(me);
        daoqiao->move(environment(me));destruct(daoqiao);
}
else 
message_vision("$N���˿�����,������ôҲ���ܰ�Բ���䵶���ȥ!\n",this_player());

return 1;
}
