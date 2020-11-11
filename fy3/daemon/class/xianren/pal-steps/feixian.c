// yiru@hero
// feixian.c

#include <ansi.h>

inherit SSERVER;
void flyto(object me);


int conjure(object me, object target)
{
    object ob;

    if( me->query_temp("nofly") || me->query("job/sxy") )
        return notify_fail("������Ҫ�����������������ܣ�\n");

    if(me->query("class")!="xianren")
    {
        if( (me->query("score") < 3000) && (me->query("score") > -3000) )
            return notify_fail("����ۺ����۲������޷�����[������]\n");
        if( me->query("PKS") > 300 )
            return notify_fail("�������̫���ˣ��Ѿ��޷�����[������]\n");
        if( me->query("bellicosity") > 3000 )
            return notify_fail("���ɱ��̫���ˣ��޷�����[������]\n");

    }

    if( !(ob = me->query_temp("weapon"))
      ||      (string)ob->query("skill_type") != "sword" )
        return notify_fail("���ý�����ô�ܹ��������У�\n");

    if( me->is_fighting() )
    {
         return notify_fail("ս�����޷�ʹ���������У�\n");
    } 

    if(stringp(me->query_temp("fly_dest")))
        return notify_fail("���Ѿ�׼�����������ˣ�\n");

    if( me->query_spi() < 24 )
        return notify_fail("�������̫�ͣ��޷�ʹ����������\n");
    if( me->query("gin") < 90 )
        return notify_fail("��ľ����޷���Ч�ļ��У�\n");
    if( me->is_ghost())
        return notify_fail("����޷�ʹ�÷�������\n");

    if((int) me->query_skill("incarnation") < 190)
        return notify_fail("��������������\n");
    if((int) me->query_skill("windcloud-move",1) < 100)
        return notify_fail("����ɷ��������������죡\n");
    if((int) me->query_skill("imperialsword",1) < 100)
        return notify_fail("���������δ��Ҳ̫���˰ɣ�\n");

    write(HIY"�������ʲô�ط��أ�"NOR);
    input_to( (: call_other, __FILE__, "select_target", me :));
    return 1;
}

/* yiru removed, this is a bug.
int perform(object me, object target)
{
    return notify_fail("[������]��һ�ŷ�����\n");
}
*/

void select_target(object me, string name)
{
    object ob, wp;
    int cost;

    cost=120-me->query_spi();
    if(cost<10) cost=10;

    if( !(wp = me->query_temp("weapon")) ){
        write("û�н�����ô�ܹ��������У�\n");
        return;
    }

    if( !name || name=="" ) {
        write("�����������˰ɡ�\n");
        return;
    }

    ob = find_player(name);
    if( !ob || !me->visible(ob) || wizardp(ob) )
        ob = find_living(name);

    if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob)) {
        write(HIC"���޷����ܵ�����˵����� ....\n"NOR);
        write(HIY"�������ʲô�ط��أ�"NOR);
        input_to( (: call_other, __FILE__, "select_target", me :));
        return;
    }
    
    if( random(ob->query("spi")) < 3 || ob->query_temp("spi_protect") )
    {
        write(HIG"����ܵ�����˵����ԣ�������ǿ�� ....\n\n"NOR);
        return;
    }

    if( me->query("atman") < cost ) {
        write("�������������\n");
        return;
    }

    if(environment(ob)->query("no_magic"))
    {
        write("�����Ǹ��ط�����ʲô�����ܲ�����\n");
        return;
    }
    me->add("atman", -cost);

    if( random(240) > ( me->query_skill("incarnation") ) 
        || random(me->query_skill("windcloud-move",1)+me->query_skill("imperialsword",1)) < 10 )
    {
        message_vision(HIB"$N�߸����˵���$n"HIB"��һ����\n"
          HIY"���һ�����ȣ����˴���������������ž�͡�һ��ˤ�˸�����ࡣ\n"NOR, me, wp);
        if(!(wp->query("owner")) && !(wp->query("no_drop")) )
            wp->move(environment(me));
        else
            message_vision( HIW "����$N����Ѹ�٣�����һ���Ͱ�$n"HIW"���ȵ��������С�\n" NOR, me, wp);
        me->start_busy(1);
        return;
    }

    printf(HIW "�㿪ʼ��Ӧ"+ob->query("name")+HIW"�����ڡ���\n" NOR);

    me->set_temp("fly_dest",environment(ob));
    me->set("no_see",1);

    message( "vision", HIB "\nһ�������ӹ���"
      + me->name() + "�������У�ֻһ�����ʧ����Ӱ���٣�\n" NOR,
      environment(me), ({ me }) );

    flyto(me);
    return;
}

void flyto(object me)
{
    object ob=me->query_temp("fly_dest"), wp;

    me->delete("no_see");
    if( !(wp = me->query_temp("weapon")) ){
        write("û�н�����ô�ܹ��������У�\n");
        return;
    }

    if(ob){
        printf(HIB "������������%s"HIB"��һ�������ȵط���%s��\n"NOR,
          wp->name(),ob->query("short"));
        me->move(ob);
    } else {
        printf("��֪��Ϊʲô���������в���ʧ���ˡ�\n");
        return;
    }

    message( "vision", HIW "\nһ���׹��ӹ�������ǰͻȻ����һ���������ж�����\n" NOR,
      ob, ({ me }) );

    me->delete_temp("fly_dest");
    return;
}

