#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"水浸天书"NOR, ({ "tianshus" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "stone");
            set("long", "这是一本传说没人能看懂的天书，但它的秘密好象已经被人发现了。
在水浸过的痕迹上隐约能辨认出一些文字。从模糊的文字上分析，
这是一本记载八识神通这门神奇功夫的书籍。\n");
            set("value", 20000);
            set("material", "paper");
                set("skill", ([
                        "name":                 "essencemagic", 
                        "exp_required": 0,                              
                        "sen_cost":             100,                            
                        "difficulty":   40,             
                        "max_skill":    40              
                ]) );
          }

    setup();
}