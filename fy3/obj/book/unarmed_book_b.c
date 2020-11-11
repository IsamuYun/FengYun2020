// unarmed_book_b.c

#include <ansi.h>

inherit BOOK;

void create()
{
        set_name("ȭ�Ž���", ({ "unarmed book", "book" }));
        set_weight(600);
        if( clonep() ) set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("value", 1000);

                set("bcolor", BCYN);    // ���������ɫ
                set("lcolor", BLK);     // ���װ������ɫ
                set("fcolor", BWHT);    // ��ı������ɫ
                set("tcolor", BLK);     // ��ı�����ɫ

                set("skill", ([
                        "name"        : "unarmed",      // name of the skill
                        "exp_required": 15000,          // minimum combat experience required to learn this skill.
                        "sen_cost"    : 35,             // sen cost every time study this
                        "difficulty"  : 35,             // the base int to learn this skill modify is sen_cost's (difficulty - int)*5%
                        "max_skill"   : 70,             // the maximum level you can learn from this object.
                ]) );
        }
}
