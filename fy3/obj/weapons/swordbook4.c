// by Tiandi 
inherit ITEM;
#include <ansi.h>
void create()
{
         set_name(HIY  "����������֮��" NOR, ({ "swordbook","duan book" }) );
         set_weight(10000);
         if( clonep() )
         set_default_object(__FILE__);
         else{
         set("unit", "��");
         set("long", "һ�������Ž���Ķ��췽���Ĳ��ӡ�\n");
         set("value", 50000);
         set("rigidity",2000);
         set("material", "silk");
         set("mtype", "sword");
         set("for_create_weapon",4);
         }
         setup();
}
