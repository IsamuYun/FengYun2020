// yiru@hero 2000.8.5

// ���ɷ�ħ��

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "���ɷ�ħ��" NOR, ({ "no-magic sheet", "sheet"}) );
    set_weight(5);
    set("unit", "��");
    set("value", 0);
    set("level", 5);
    setup();
}

int burn_function()
{
    object me = this_player();
    int bonus;

    bonus = me->query("atman_factor");
    if( bonus < 1 ){
        write("����ʹ�� enchant ����ָ����������������\n");
        return 1;
    }
    if( me->query("atman")<me->query("atman_factor") ){
        write("������������ˣ�\n");
        return 1;
    }
    if( !me->query_condition("drunk") ){
        write("�����ں���һ������Ҳû��Ү��\n");
        return 1;
    }

    me->add("atman", -me->query("atman_factor") );

    message_vision("\n$N����һ��"+name()+"��\n",me);

    bonus += query("level");
        if(me->query("family/family_name")!="��ɽ����")
        {
                bonus = bonus/5;
        }

    // ����ɹ��ʡ�
    if( random(bonus) > query("level") )
    {
        environment(me)->set("no_magic",1);
        environment(me)->set("magic_protect",1);
        message_vision(HIY"\n������$NԪ����ϣ�����Χ��ħ�������ˣ�\n"NOR,me);
        // ���ɷ�ħ��ҪԪ����ϣ��Ǻ�
        me->unconcious();
        me->be_full();
    }
    else
    {
        message_vision("\n����$Nʧ���ˣ�\n",me);
        }
        me->start_busy(1);
    destruct(this_object());

    return 1;
}

