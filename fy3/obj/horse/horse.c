// horse.c

inherit ITEM;

#define MAX_LIFE        20

void create()
{
        set_name("����", ({ "horse" }) );
        set("horse_prop/max_life", MAX_LIFE);
        set("horse_prop/life", MAX_LIFE);
        set_max_encumbrance(100000);
        set("no_put", 1);
        set("prep", "on");
        set_weight( 0 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ƥ");
                set("long", @LONG 
����һƥ�����������Կ��ٵ�ʹ�㵽��ĳ���ط������һ����԰����˶�����
LONG
                );

                set("value", 100000);
    };
}

int is_container() { return 1; }