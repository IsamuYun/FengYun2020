inherit ITEM;

void create()
{
        set_name("工作台", ({ "table", "工作台",}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "张");
                set("long", "一张钛金制的桌子。上面放着一些有关Mud编程方面的书籍和资料\n");
                set("value", 1);
        }
}

int is_container()
{
return 1;
}
