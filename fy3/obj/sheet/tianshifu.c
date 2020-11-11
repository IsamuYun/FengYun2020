// yiru@hero 2000.8.5

// ��ʦ��

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "��ʦ��" NOR, ({ "tian-shi sheet", "sheet"}) );
    set_weight(5);
    set("unit", "��");
    set("value", 0);
    set("level", 5);
    setup();
}

int attach_function(object ob)
{
    object me = this_player();
    int damage, bonus;

    if( !me->is_fighting(ob) ){
        write(name()+"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        return 1;
    }

    bonus = me->query("atman_factor");
    if( bonus < 1 ){
        write("����ʹ�� enchant ����ָ����������������\n");
        return 1;
    }
    if( me->query("atman")<me->query("atman_factor") ){
        write("������������ˣ�\n");
        return 1;
    }
    me->add("atman", -me->query("atman_factor") );
    bonus = bonus * bonus / 40 ;

    message_vision(HIC"\n$N��$n��������һ����ʦ����\n"NOR,me,ob);
    message_vision(HIY"\n\n��ʦ��˲����$N�����ϱ�ը��������������\n\n"NOR,ob);

    if( me->query_skill("scratching")>150 )
        damage = 150 + query("level");
    else if( me->query_skill("scratching")>30 )
        damage = query("level");
    else
        damage = 0;
    damage += bonus;
    damage -= ob->query_spi();

    if( damage > 0 ){
                if(me->query("family/family_name")!="��ɽ����")
                {
               damage = damage/10;
                }

        damage = damage/2 + random(damage);
        ob->receive_damage("gin", damage, me);
        ob->receive_damage("kee", damage, me);
        ob->receive_damage("sen", damage, me);
    }

    // ��ʾ���״̬
    if( wizardp(me) ) tell_object(me, GRN "�Եз����"+damage+"���˺���\n" NOR);
    if( wizardp(ob) ) tell_object(ob, CYN "�������"+damage+"���˺���\n" NOR);
    COMBAT_D->report_status(ob, 0);

        if(userp(me))
        {
        me->start_busy(2);
    }
    else
    {
        me->start_busy(1);
    }


    destruct(this_object());

    return 1;
}
