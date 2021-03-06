// longyan-guo.c - 龙涎果

#include <ansi.h>

inherit HERB;

void create()
{
        set_name( HIY "龙涎果" NOR, ({ "longyan guo", "guo" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
这是可以吃（eat）的$HIY$龙涎果$NOR$，它们是只有神仙才拥有的东西。
它可以使你的所有基本技能升级，并且获得五百点潜能和两千点经验。
TEXT
                );
                
                set("unit", "些");
                set("base_unit", "个");
                set("base_weight", 500);
                set("value", 0 );
        }

        set_amount(1);

        setup();
}

void get_effect( object who ) 
{
        mapping skills_map, all_skills;
        string *base_skills;
        int i;
        
        who->add("potential", 500);
        tell_object(who, "你的潜能增加了" + chinese_number( 500 ) + "点！\n");
        who->add("combat_exp", 2000);
        tell_object(who, "你的经验增加了" + chinese_number( 2000 ) + "点！\n");

        skills_map = who->query_skill_map();
        if( !mapp(skills_map) || !sizeof(skills_map) ) return;
        base_skills = keys(skills_map);

        all_skills = who->query_skills();
        for( i = 0; i < sizeof(base_skills); i ++ ) {
                all_skills[ base_skills[i] ] ++;
                tell_object(who, "你的“" + to_chinese( base_skills[i] ) + "”升级了！\n");
        }
}
