// /d/wiz/llx/obj/book.c

inherit ITEM;
void create()
#include <ansi.h>

{
        set_name(HIR"Mud��̹�����"NOR, ({ "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
HIW"int ����    spi ����    cps ������\n"NOR
HIW"kar ����    cor ����    str ������\n"NOR
HIW"tol ����    fle ����    dur ������\n"NOR
HIW"agi �ٶ�    per ����    con ���ʡ�\n"NOR

" BLK  - ��ɫ             NOR  - �ָ�������ɫ\n"
" RED  - ��ɫ             HIR  - ����ɫ\n"
" GRN  - ��ɫ             HIG  - ����ɫ\n"
" YEL  - ����ɫ           HIY  - ��ɫ\n"
" BLU  - ����ɫ           HIB  - ��ɫ\n"
" MAG  - ǳ��ɫ           HIM  - �ۺ�ɫ\n"
" CYN  - ����ɫ           HIC  - ����ɫ\n"
" WHT  - ǳ��ɫ           HIW  - ��ɫ\n");    
                set("value", 1);
                set("no_drop", 1);
                set("material", "paper");
                }
}
