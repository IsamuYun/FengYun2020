// /d/wiz/llx/obj/dangan.c

inherit ITEM;
void create()
#include <ansi.h>

{
        set_name(HIR"李熙真实资料（信不信由你）"NOR, ({ "dangan" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
WHT"李熙 ： 真名 徐先河 ， 77年7月1日出生，现居河南省平顶山市。
    电脑龄约10年有余，97年开始接触文字Mud，那时由于网费甚高，仅仅尝试了
一下但是Mud给人的无限的想象力却深深留在了我的脑海里，2000年河南省电信大
发慈悲，全省一片包月之声，廉价的上网费用引燃了我心中的Mud之火，随狂玩了
数月而欲罢不能。最后修炼Lpc大法走火入魔，盾入Wiz行列。
    本人除Mud外，酷爱Starcraft，经常在网上被菜而愈挫愈奋不能自拔。
    望与吾爱好相同者为友，共同堕落……
    本人联系方式
    E-mail : foxxh@371.net   Oicq : 157605\n"NOR  
);    
                set("value", 1);
                set("no_drop", 1);
                set("material", "paper");
                }
}
