inherit ITEM;

void create()
{
        set_name("鱼骨头", ({ "fish bone" , "鱼骨头"}) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个被吃的干干净净的鱼骨头。 \n");
                set("value", 1);
        }
}


