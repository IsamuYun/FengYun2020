// toxinbook.c

inherit ITEM;

void create()
{
        set_name("端砚", ({ "duanyan" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "方");
                set("long",
                        "这是一块研好了墨汁的名贵砚台。\n");
                set("value", 200);
                set("material", "paper");
        }
}
