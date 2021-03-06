// force_book_c.c

#include <ansi.h>

inherit BOOK;

void create()
{
        set_name("内功精要", ({ "force book", "book" }));
        set_weight(600);
        if( clonep() ) set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
                set("value", 5000);

                set("bcolor", BRED);    // 书的整体颜色
                set("lcolor", BLK);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色

                set("skill", ([
                        "name"        : "force",        // name of the skill
                        "exp_required": 35000,          // minimum combat experience required to learn this skill.
                        "sen_cost"    : 40,             // sen cost every time study this
                        "difficulty"  : 40,             // the base int to learn this skill modify is sen_cost's (difficulty - int)*5%
                        "max_skill"   : 90,             // the maximum level you can learn from this object.
                ]) );
        }
}
