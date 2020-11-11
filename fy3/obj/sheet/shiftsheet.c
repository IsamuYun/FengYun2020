// yiru@hero
// cronus-shift sheet.c

inherit SHEET;

#include <ansi.h>
#include <login.h>

void create()
{
    set_name(YEL "�����" NOR, ({ "cronushift sheet", "sheet"}) );
    set_weight(5);
    set("unit", "��");
    set("value", 0);
    setup();
}

object find_env(object ob)
{
    while(ob)
    {
        if(ob->query("coor") ) return ob;
        else ob=environment(ob);
    }
    return ob;
}

int burn_function()
{
    object me = this_player();
    object env;

    if( me->is_fighting() )
        return notify_fail("ս���в���ʹ�ö������\n");

    env = me->query_temp("possheet");
    if(env)
        env = find_env(env);
    if(!env)
        return notify_fail("����ʹ�ö�λ��ȷ��ת�Ƶĵص㡣\n");

    me->start_busy(random(3));
    message_vision(
        HIC "$N����һ�Ŷ������\n\n"
        HIW "��Ȼ���ܷ���ѣĿ�Ĺ���������ʹ��Ŀ�����������\n\n"
        NOR, me);

    if( (!env->query("no_magic")) && (env != environment(me))){
        message("vision", 
            "��������" + me->name() + "��ʧ�ˡ�\n"
            , env, ({ me }));
        tell_object(me, HIC "������ʼ�����������㷢�����ѵ��ˡ���\n" NOR );
        me->move(env);
    }else{
        message("vision", 
            "��������ʲôҲû�з�����\n"
            , env, ({ me }));
        tell_object(me, HIC "������ʼ�����������㷢���㻹վ��ԭ�ء���\n" NOR );
    }

    destruct(this_object());

    return 1;
}
