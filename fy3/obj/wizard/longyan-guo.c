// longyan-guo.c - ���ѹ�

#include <ansi.h>

inherit HERB;

void create()
{
        set_name( HIY "���ѹ�" NOR, ({ "longyan guo", "guo" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
���ǿ��Գԣ�eat����$HIY$���ѹ�$NOR$��������ֻ�����ɲ�ӵ�еĶ�����
������ʹ������л����������������һ����ٵ�Ǳ�ܺ���ǧ�㾭�顣
TEXT
                );
                
                set("unit", "Щ");
                set("base_unit", "��");
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
        tell_object(who, "���Ǳ��������" + chinese_number( 500 ) + "�㣡\n");
        who->add("combat_exp", 2000);
        tell_object(who, "��ľ���������" + chinese_number( 2000 ) + "�㣡\n");

        skills_map = who->query_skill_map();
        if( !mapp(skills_map) || !sizeof(skills_map) ) return;
        base_skills = keys(skills_map);

        all_skills = who->query_skills();
        for( i = 0; i < sizeof(base_skills); i ++ ) {
                all_skills[ base_skills[i] ] ++;
                tell_object(who, "��ġ�" + to_chinese( base_skills[i] ) + "�������ˣ�\n");
        }
}
