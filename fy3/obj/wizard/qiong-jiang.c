// qiong-jiang.c - 琼浆

#include <ansi.h>

inherit JULEP;

void create()
{
        set_name( HIC "琼浆" NOR, ({ "qiong jiang", "jiang" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
这是可以喝（drink）的$HIC$琼浆$NOR$，它们是只有神仙才拥有的东西。
它可以使你所有技能升级，并且将最大灵力、内力和法力均增加五十点。
TEXT
                );
                
                set("unit", "些");
                set("base_unit", "瓶");
                set("base_weight", 200);
                set("value", 0 );
        }

        set_amount(1);

        setup();
}

void get_effect( object who ) 
{
        mapping all_skills;
        string *name_skills;
        int i;
        
        who->add("max_atman", 50);
        tell_object(who, "你的灵力增加了" + chinese_number( 50 ) + "点！\n");
        who->add("max_force", 50);
        tell_object(who, "你的内力增加了" + chinese_number( 50 ) + "点！\n");
        who->add("max_mana", 50);
        tell_object(who, "你的法力增加了" + chinese_number( 50 ) + "点！\n");

        all_skills = who->query_skills();
        if(! sizeof( all_skills )) return;
        name_skills = keys( all_skills );
        
        for( i = 0; i < sizeof(name_skills); i ++ ) {
                all_skills[ name_skills[i] ] ++;
                tell_object(who, "你的“" + to_chinese( name_skills[i] ) + "”升级了！\n");
        }
}
