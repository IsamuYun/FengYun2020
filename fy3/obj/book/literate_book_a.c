// literate_book_a.c

#include <ansi.h>

inherit BOOK;

void create()
{
        set_name("ǧ����", ({ "literate book", "book" }));
        set_weight(600);
        if( clonep() ) set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("value", 100);

                set("bcolor", BCYN);    // ���������ɫ
                set("lcolor", BLK);     // ���װ������ɫ
                set("fcolor", BBLU);    // ��ı������ɫ
                set("tcolor", WHT);     // ��ı�����ɫ

                set("skill", ([
                        "name"        : "literate",     // name of the skill
                        "exp_required": 0,              // minimum combat experience required to learn this skill.
                        "sen_cost"    : 30,             // sen cost every time study this
                        "difficulty"  : 30,             // the base int to learn this skill modify is sen_cost's (difficulty - int)*5%
                        "max_skill"   : 50,             // the maximum level you can learn from this object.
                ]) );
        }
}
