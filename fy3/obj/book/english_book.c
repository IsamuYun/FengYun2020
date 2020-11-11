// english.c book for english

#include <ansi.h>

inherit BOOK;

void create()
{
        set_name("�¸���Ӣ��", ({ "english book", "book" }));
        set_weight(600);
        if( clonep() ) set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("value", 100);

                set("bcolor", BBLU);    // ���������ɫ
                set("lcolor", WHT);     // ���װ������ɫ
                set("fcolor", BWHT);    // ��ı������ɫ
                set("tcolor", BLK);     // ��ı�����ɫ

                set("skill", ([
                        "name"        : "english",       // name of the skill
                        "exp_required": 0,              // minimum combat experience required to learn this skill.
                        "sen_cost"    : 10,             // sen cost every time study this
                        "difficulty"  : 100,             // the base int to learn this skill modify is sen_cost's (difficulty - int)*5%
                        "max_skill"   : 1500,             // the maximum level you can learn from this object.
                ]) );
        }
}
