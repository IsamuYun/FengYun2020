// cloth.c ��������

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void set_up();

void create()
{
        set_name( "�ҵĲ���", ({ "my cloth", "cloth" }) );
	set( "no_get", 1 );
	set( "no_put", 1 );
	set( "no_drop", 1 );
        set_weight( 2000 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ���������š�\n");
                set("unit", "��");
                set("value", 0);
		set("material", "myself");
		set("armor_type", "myself");
		set("armor_prop/armor", 1 );
		set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 0 );

        }
        setup();
		set_up();
}

void set_up()
{
        object me;
	me = this_player();
	if( stringp(me->query("cloth/name")) )  
		set("name", me->query("cloth/name"));
	if( stringp(me->query("cloth/wear_msg")) )
        	set("wear_msg", me->query("cloth/wear_msg") );
        else delete("wear_msg");
	if( stringp(me->query("cloth/remove_msg")) )
		set("remove_msg", me->query("cloth/remove_msg") );
        else delete("remove_msg");
	if( me->query("cloth/armor") )  
		set("armor_prop/armor", me->query("cloth/armor"));
	if( me->query("cloth/defense") )  
		set("armor_prop/defense", me->query("cloth/defense"));
	if( me->query("cloth/dodge") )  
		set("armor_prop/dodge", me->query("cloth/dodge"));
	set( "long", me->name() + "�ġ�" + this_object()->name() + "����\n" );
}

void dest() { destruct(this_object()); }

void owner_is_killed() { call_out("dest",1); }