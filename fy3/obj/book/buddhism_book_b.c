// buddhism_book_b.c

#include <ansi.h>

inherit BOOK;

void create()
{
        set_name("椤枷经", ({ "buddhism book", "book" }));
        set_weight(600);
        if( clonep() ) set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
                set("value", 1000);

                set("bcolor", BWHT);    // 书的整体颜色
                set("lcolor", GRN);     // 书的装订线颜色
                set("fcolor", BCYN);    // 书的标题框颜色
                set("tcolor", WHT);     // 书的标题颜色

                set("skill", ([
                        "name"        : "buddhism",     // name of the skill
                        "exp_required": 15000,          // minimum combat experience required to learn this skill.
                        "sen_cost"    : 35,             // sen cost every time study this
                        "difficulty"  : 35,             // the base int to learn this skill modify is sen_cost's (difficulty - int)*5%
                        "max_skill"   : 70,             // the maximum level you can learn from this object.
                ]) );
        }
}
