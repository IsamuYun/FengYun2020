inherit ITEM;
void create()
{
    set_name("细棉线", ({ "mianxian" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "根");
             set("value", 100); 
            set("material", "paper");
            set("long", "一根长长的细棉线。\n");
          }

    setup();
}

