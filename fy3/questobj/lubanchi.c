// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(WHT"³���"NOR, ({ "lubanchi" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("jungle",1);
		set("material", "iron");
		set("long", "����һ��ľ���õ�³���\n");
		set("wield_msg", "$N���һ�Ѻ����͵�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n�������䡣\n");
	}
	init_blade(5);
	setup();
}
