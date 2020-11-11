// /d/wiz/llx/obj/book.c

inherit ITEM;
void create()
#include <ansi.h>

{
        set_name(HIR"Mud编程工具书"NOR, ({ "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
HIW"int 才智    spi 灵性    cps 定力。\n"NOR
HIW"kar 运气    cor 勇气    str 力量。\n"NOR
HIW"tol 气量    fle 韧性    dur 耐力。\n"NOR
HIW"agi 速度    per 魅力    con 体质。\n"NOR

" BLK  - 黑色             NOR  - 恢复正常颜色\n"
" RED  - 红色             HIR  - 亮红色\n"
" GRN  - 绿色             HIG  - 亮绿色\n"
" YEL  - 土黄色           HIY  - 黄色\n"
" BLU  - 深蓝色           HIB  - 蓝色\n"
" MAG  - 浅紫色           HIM  - 粉红色\n"
" CYN  - 蓝绿色           HIC  - 天青色\n"
" WHT  - 浅灰色           HIW  - 白色\n");    
                set("value", 1);
                set("no_drop", 1);
                set("material", "paper");
                }
}
