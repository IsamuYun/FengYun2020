// yu-ye.c - 玉液

#include <ansi.h>

inherit JULEP;

void create()
{
        set_name( HIC "玉液" NOR, ({ "yu ye", "ye" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
这是可以喝（drink）的$HIC$玉液$NOR$，它们是只有神仙才拥有的东西。
它可以使你最高的技能升级，并且获得五十点最大内力。
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
        int i, max;
        
        who->add("max_force", 50);
        tell_object(who, "你的内力增加了" + chinese_number( 50 ) + "点！\n");

        all_skills = who->query_skills();
        if(! sizeof( all_skills )) return;
        name_skills = keys( all_skills );
        
        max = 0;
        for( i = 1; i < sizeof(name_skills); i ++ ) 
                if( all_skills[ name_skills[max] ] < all_skills[ name_skills[i] ] )
                        max = i;
        all_skills[ name_skills[max] ] ++;
        tell_object(who, "你的“" + to_chinese( name_skills[max] ) + "”升级了！\n");
        
}
