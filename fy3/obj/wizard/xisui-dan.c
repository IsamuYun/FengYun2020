// xisui-dan.c - ϴ�赤

#include <ansi.h>

inherit PILL;

void create()
{
        set_name( HIC "ϴ�赤" NOR, ({ "xisui dan", "dan" }) );
        
        set("no_transfer", 1);

        if( clonep()) 
                set_default_object(__FILE__);
        else {  
                set("long", @TEXT
���ǿ����ڷ���use����$HIC$ϴ�赤$NOR$��������ֻ�����ɲ�ӵ�еĶ�����
������ʹ������л�������������
TEXT
                );
                
                set("unit", "Щ");
                set("base_unit", "��");
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
                tell_object(who, "������������ˣ�\n");
        }
        if( who->query("cor") <= 35 ) {
                who->add("cor", 1);
                tell_object(who, "������������ˣ�\n");
        }
        if( who->query("int") <= 35 ) {
                who->add("int", 1);
                tell_object(who, "��Ĳ��������ˣ�\n");
        }
        if( who->query("spi") <= 35 ) {
                who->add("spi", 1);
                tell_object(who, "������������ˣ�\n");
        }
        if( who->query("cps") <= 35 ) {
                who->add("cps", 1);
                tell_object(who, "��Ķ��������ˣ�\n");
        }
        if( who->query("per") <= 35 ) {
                who->add("per", 1);
                tell_object(who, "������������ˣ�\n");
        }
        if( who->query("con") <= 35 ) {
                who->add("con", 1);
                tell_object(who, "��ĸ��������ˣ�\n");
        }
        if( who->query("kar") <= 35 ) {
                who->add("kar", 1);
                tell_object(who, "��ĸ�Ե�����ˣ�\n");
        }
}
