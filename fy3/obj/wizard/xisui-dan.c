// xisui-dan.c - 洗髓丹

#include <ansi.h>

inherit PILL;

void create()
{
        set_name( HIC "洗髓丹" NOR, ({ "xisui dan", "dan" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
这是可以内服（use）的$HIC$洗髓丹$NOR$，它们是只有神仙才拥有的东西。
它可以使你的所有基本属性升级。
TEXT
                );
                
                set("unit", "些");
                set("base_unit", "粒");
                set("base_weight", 10);
                set("value", 0 );
        }

        set_amount(1);

        setup();
}

void get_effect( object who ) 
{
        if( who->query("str") <= 35 ) {
                who->add("str", 1);
                tell_object(who, "你的力量升级了！\n");
        }
        if( who->query("cor") <= 35 ) {
                who->add("cor", 1);
                tell_object(who, "你的勇气升级了！\n");
        }
        if( who->query("int") <= 35 ) {
                who->add("int", 1);
                tell_object(who, "你的才智升级了！\n");
        }
        if( who->query("spi") <= 35 ) {
                who->add("spi", 1);
                tell_object(who, "你的灵性升级了！\n");
        }
        if( who->query("cps") <= 35 ) {
                who->add("cps", 1);
                tell_object(who, "你的定力升级了！\n");
        }
        if( who->query("per") <= 35 ) {
                who->add("per", 1);
                tell_object(who, "你的魅力升级了！\n");
        }
        if( who->query("con") <= 35 ) {
                who->add("con", 1);
                tell_object(who, "你的根骨升级了！\n");
        }
        if( who->query("kar") <= 35 ) {
                who->add("kar", 1);
                tell_object(who, "你的福缘升级了！\n");
        }
}
