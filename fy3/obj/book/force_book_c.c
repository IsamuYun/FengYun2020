// force_book_c.c

#include <ansi.h>

inherit BOOK;

void create()
{
        set_name("�ڹ���Ҫ", ({ "force book", "book" }));
        set_weight(600);
        if( clonep() ) set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("value", 5000);

                set("bcolor", BRED);    // ���������ɫ
                set("lcolor", BLK);     // ���װ������ɫ
                set("fcolor", BWHT);    // ��ı������ɫ
                set("tcolor", BLK);     // ��ı�����ɫ

                set("skill", ([
                        "name"        : "force",        // name of the skill
                        "exp_required": 35000,          // minimum combat experience required to learn this skill.
                        "sen_cost"    : 40,             // sen cost every time study this
                        "difficulty"  : 40,             // the base int to learn this skill modify is sen_cost's (difficulty - int)*5%
                        "max_skill"   : 90,             // the maximum level you can learn from this object.
                ]) );
        }
}
