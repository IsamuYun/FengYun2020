// yiru@hero 2000.8.5

// ��ʬ׷���

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "��ʬ׷���" NOR, ({ "haunting sheet", "sheet"}) );
    set_weight(5);
    set("unit", "��");
    set("value", 0);
    set("level", 5);
    setup();
}

int attach_function(object who)
{ 
    // string target;
    object dest, owner;

    if( !who->is_zombie() )
        return notify_fail( name() + "ֻ�����ڽ�ʬ���ϡ�\n");

    owner = who->query("possessed");
    if( objectp(owner) && owner!=this_player() )
        return notify_fail( "��������÷�����ס" + who->name() + 
                            "����ʹ���������\n");

    if( !objectp(query("targetname")) )
        return notify_fail( "�����������׷˭�Ļꣿ\n");

    // target = query("targetname");
    // dest = present(target, environment(who));
    // if( !dest ) dest = find_player(target);
    // if( !dest ) dest = find_living(target);
    
    dest = query("targetname");
    if( objectp(dest) ) {
        who->set("haunttar", dest);
        if( environment(dest)==environment(who) ) {
            who->kill_ob(dest);
                   message_vision("$N�۾���Ȼ�������૵�˵����" RED 
"ɱ....��....$n....\n" NOR,
            who, dest);
            who->set_leader(dest);
            dest->fight_ob(who);
        }
         else {
            who->set("haunt", 1);
           }
    } else {
       message_vision("$N�۾���Ȼ�������૵�˵����" RED 
"ɱ....ɱ....ɱ....\n" NOR,
            who);
        if( this_player() ) {
            who->kill_ob(this_player());
            who->set_leader(this_player());
            this_player()->fight_ob(who);
        }
    }
    this_object()->move(who);
    message_vision("$N��һ��"YEL"��ʬ׷���"NOR"����$n���ϡ�\n",this_player(),who);
    set("no_drop", 1);
    set("no_get", 1);
    set("equipped", "seal");
    return 1;
}
