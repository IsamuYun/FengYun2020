// songshu-meat.c ������
// �޸ģ���ɽ��ѧ  �����ᣨMicro��----Micro_Liang@Hotmail.Com

#include <weapon.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("������", ({ "songshu meat", "meat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�������⡣\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 4);
                set("food_supply", 100);
        }
        setup();
}

