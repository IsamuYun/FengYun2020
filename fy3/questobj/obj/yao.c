inherit ITEM;
void create()
{
    set_name("圣药", ({ "yao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "丸");
             set("value", 100000); 
            set("material", "paper");
            set("long", "一丸圣药，功可活死人，肉白骨。正是江湖人士梦寐以求的灵丹。\n");
          }

    setup();
}