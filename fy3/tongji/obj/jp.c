// lady_dress.c
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{        string *order=({"��", "С", "��", "Բ","��","��","��","��","���","����"});
        set_name((order[random(10)]) + "ѫ��", ({ "xzhang"}) );

        set_weight(120);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "    ����Ϊ�˽���Э����ͨ͢��ʮ����˵��й�֮ʿ���ر����Ĵ�����,�����ƾ
��ѫ�����ղ���˴����ͣ������ʮ��ѫ�£�����ɱ��ʮ����ˣ��������װ(zuo)��һ
�ѳͶ����ƽ�������������֮�������ʲô����. . . . . .��ѫ������д�ţ�
                        ��   ��   ��   �ơ�\n");
                set("unit", "��");
                set("value", 1000000);
                set("material", "stone");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 10);
                set("armor_prop/intelligence",2);
        }
        setup();
}
