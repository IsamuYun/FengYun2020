// lady_dress.c
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{        string *order=({"大", "小", "方", "圆","长","短","厚","薄","五角","六角"});
        set_name((order[random(10)]) + "勋章", ({ "xzhang"}) );

        set_weight(120);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "    这是为了奖励协助朝廷通缉十大恶人的有功之士而特别打造的纯金奖牌,你可以凭
此勋章在钦差大人处领赏，如果有十块勋章，而且杀了十大恶人，你可以组装(zuo)成一
把惩恶扬善剑（刀），除此之外好象还有什么功用. . . . . .。勋章上面写着：
                        惩   恶   扬   善。\n");
                set("unit", "个");
                set("value", 1000000);
                set("material", "stone");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 10);
                set("armor_prop/intelligence",2);
        }
        setup();
}
