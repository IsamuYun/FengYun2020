#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB"妙手空空" NOR, ({ "miaoshou" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张破破烂烂的纸，上面好象写着一些秘籍。\n");
          }
    setup();
}
