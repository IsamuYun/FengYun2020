// snake_skin.c

inherit COMBINED_ITEM;

void create()
{
        set_name("青蛇蜕皮", ({"snake skin", "skin"}));
        set("long",
                "这是一张完好的有着厉害毒性的蛇蜕，看上去是制作毒药的好材料。\n");
        set("unit", "叠");
        set("base_unit", "张");
        set("base_weight", 5);
        set("value", 1000);
        set_amount(1);
}

