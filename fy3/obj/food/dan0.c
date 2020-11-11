// writted by Tiandi
inherit ITEM;
void create()
{
        set_name("黑糊糊的东西", ({ "dan"}) );
        set_weight(1);
        if( clonep() )
           set_default_object(__FILE__);
        else {
           set("long","一堆黑糊糊的东西，好像是炼丹失败的产物。\n");
           set("unit", "堆");
           set("value", 0);
        }
        setup();
}
