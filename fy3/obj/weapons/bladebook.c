// by Tiandi 
inherit ITEM;
#include <ansi.h>
void create()
{
         set_name(HIY  "��������������ƪ" NOR, ({ "bladebook","duan book" }) );
         set_weight(10000);
         if( clonep() )
         set_default_object(__FILE__);
         else{
         set("unit", "��");
         set("long", "һ�������ŵ���Ķ��췽���Ĳ��ӡ�\n");
         set("value", 50000);
         set("rigidity",2000);
         set("material", "silk");
         set("mtype", "blade");
         set("for_create_weapon",1);
         }
         setup();
}
