// taoism_book_c.c

#include <ansi.h>

inherit BOOK;

void create()
{
        set_name("����", ({ "taoism book", "book" }));
        set_weight(600);
        if( clonep() ) set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("value", 5000);

                set("bcolor", BWHT);    // ���������ɫ
                set("lcolor", GRN);     // ���װ������ɫ
                set("fcolor", BMAG);    // ��ı������ɫ
                set("tcolor", WHT);     // ��ı�����ɫ

                set("skill", ([
                        "name"        : "taoism",       // name of the skill
                        "exp_required": 35000,          // minimum combat experience required to learn this skill.
                        "sen_cost"    : 40,             // sen cost every time study this
                        "difficulty"  : 40,             // the base int to learn this skill modify is sen_cost's (difficulty - int)*5%
                        "max_skill"   : 90,             // the maximum level you can learn from this object.
                ]) );
        }
}
