// by Tiandi 
inherit ITEM;
#include <ansi.h>
void create()
{
         set_name(HIY  "�·���������֮��" NOR, ({ "clothbook","duan book" }) );
         set_weight(10000);
         if( clonep() )
         set_default_object(__FILE__);
         else{
         set("unit", "��");
         set("long", "һ���������·���Ķ��췽���Ĳ��ӡ�\n");
         set("value", 50000);
         set("rigidity",2000);
         set("material", "silk");
         set("mtype", "cloth");
         set("for_create_armor",3);
         }
         setup();
}