// yu-ye.c - ��Һ

#include <ansi.h>

inherit JULEP;

void create()
{
        set_name( HIC "��Һ" NOR, ({ "yu ye", "ye" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
���ǿ��Ժȣ�drink����$HIC$��Һ$NOR$��������ֻ�����ɲ�ӵ�еĶ�����
������ʹ����ߵļ������������һ����ʮ�����������
TEXT
                );
                
                set("unit", "Щ");
                set("base_unit", "ƿ");
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
        tell_object(who, "�������������" + chinese_number( 50 ) + "�㣡\n");

        all_skills = who->query_skills();
        if(! sizeof( all_skills )) return;
        name_skills = keys( all_skills );
        
        max = 0;
        for( i = 1; i < sizeof(name_skills); i ++ ) 
                if( all_skills[ name_skills[max] ] < all_skills[ name_skills[i] ] )
                        max = i;
        all_skills[ name_skills[max] ] ++;
        tell_object(who, "��ġ�" + to_chinese( name_skills[max] ) + "�������ˣ�\n");
        
}
