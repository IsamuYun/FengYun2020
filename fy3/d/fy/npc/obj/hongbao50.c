#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "��鳬�����" NOR, ({ "hongbao50" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
                set("value", 500000);
            set("unit", "��");
            set("material", "cloth");
            set("long", "һ��СС�Ľ�������������ţ���ż��ɣ���ͷ����\n");
          }
    setup();
}
void init()
{

if(environment()==this_player())
add_action("do_open","open");
}
int do_open(string arg)
{
object gold;
if(arg != "hongbao" && arg != "���") return 0;
if(query("opened"))
return notify_fail("���С������������ǿյģ�\n");
gold = new("/obj/money/gold");
gold->set_amount(50);
gold->move(this_player());
set("opened",1);
set("value",0);
return notify_fail("��򿪽�������������ó�һЩ�ƽ�\n");
}