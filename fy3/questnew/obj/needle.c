// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <weapon.h>
inherit DAGGER;
void create()
{
//         string *order=({"��ɫ��", "��ɫ��", "��ɫ��", "��ɫ��","��ɫ��",});
        set_name("����", ({ "needle"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", "һ��ϸ�������룬ͷ���и�С�ס�\n");
                set("value", 50);
                set("material", "steel");
        }
        init_dagger(10);
        set("wield_msg", "$N�ӻ�������һ֧$n�������С�\n");
        set("unwield_msg", "$N�����е�$n���뻳�С�\n");
        setup();
}