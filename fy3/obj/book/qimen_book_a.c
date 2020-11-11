// qimen_book_a.c

#include <ansi.h>

inherit BOOK;

void create()
{
        set_name("奇门兵器入门", ({ "qimen book", "book" }));
        set_weight(600);
        if( clonep() ) set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
                set("value", 100);

                set("bcolor", BBLU);    // 书的整体颜色
                set("lcolor", WHT);     // 书的装订线颜色
                set("fcolor", BWHT);    // 书的标题框颜色
                set("tcolor", BLK);     // 书的标题颜色

                set("skill", ([
                        "name"        : "qimen",        // name of the skill
                        "exp_required": 0,              // minimum combat experience required to learn this skill.
                        "sen_cost"    : 30,             // sen cost every time study this
                        "difficulty"  : 30,             // the base int to learn this skill modify is sen_cost's (difficulty - int)*5%
                        "max_skill"   : 50,             // the maximum level you can learn from this object.
                ]) );
        }
}
