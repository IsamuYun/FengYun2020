#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("���»���", ({ "huapen" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("long", "һ���ǳ����µľ�̩�����裬��������������\n");
                set("weapon_prop/karma",1);
        }
        init_hammer(5);
        setup();
}
void init()
{
        if(environment(this_object())==this_player())
        if (!wizardp(this_player())) {
        set("no_get"," ���ǲ�Ҫ�Ҷ�����Ķ���Ϊ��! \n");
        set("no_drop","����Ķ�����ô������Ҷ���! \n");
        set("no_give","����Ķ�����ô���������أ�\n");
       }
//      add_action("do_read","wa");
//      add_action("do_go","go");
}