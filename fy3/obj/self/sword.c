// sword.c ���ų���

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void set_up();

void create()
{
        set_name("�ҵĳ���", ({ "my sword", "sword" }));
	set( "no_get", 1 );
	set( "no_put", 1 );
	set( "no_drop", 1 );
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ű�����\n");
                set("unit", "��");
                set("value", 0);
                set("material", "myself");
        }
        init_sword(1);
        setup();
		set_up();
}

void set_up()
{
        object me;
	me = this_player();
//	if( stringp(me->query("weapon/name")) )
	if( me->query("weapon/name"))
		set("name", me->query("weapon/name"));
//	if( stringp(me->query("weapon/wield_msg")) )
	if( me->query("weapon/wield_msg"))
		set("wield_msg", me->query("weapon/wield_msg") );
        else delete("wield_msg");
//	if( stringp(me->query("weapon/unwield_msg")) )
	if( me->query("weapon/unwield_msg"))
		set("unwield_msg", me->query("weapon/unwield_msg") );
        else delete("unwield_msg");
	if( me->query("weapon/damage") )  
		set("weapon_prop/damage", me->query("weapon/damage"));
	set( "long", me->name() + "�ġ�" + this_object()->name() + "����\n" );
}

void dest() { destruct(this_object()); }

void owner_is_killed() { call_out("dest",1); }
