// qiong-jiang.c - ��

#include <ansi.h>

inherit JULEP;

void create()
{
        set_name( HIC "��" NOR, ({ "qiong jiang", "jiang" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
���ǿ��Ժȣ�drink����$HIC$��$NOR$��������ֻ�����ɲ�ӵ�еĶ�����
������ʹ�����м������������ҽ���������������ͷ�����������ʮ�㡣
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
        int i;
        
        who->add("max_atman", 50);
        tell_object(who, "�������������" + chinese_number( 50 ) + "�㣡\n");
        who->add("max_force", 50);
        tell_object(who, "�������������" + chinese_number( 50 ) + "�㣡\n");
        who->add("max_mana", 50);
        tell_object(who, "��ķ���������" + chinese_number( 50 ) + "�㣡\n");

        all_skills = who->query_skills();
        if(! sizeof( all_skills )) return;
        name_skills = keys( all_skills );
        
        for( i = 0; i < sizeof(name_skills); i ++ ) {
                all_skills[ name_skills[i] ] ++;
                tell_object(who, "��ġ�" + to_chinese( name_skills[i] ) + "�������ˣ�\n");
        }
}
