#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name( HIY "������ָ" NOR, ({ "rongyu ring", "ring" }) );
        set_weight(0);

        set("no_get",1);
       set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long",
                        HIW"����֣�ݷ����͸�������ҵĽ�ָ��\n"NOR);
                set("armor_type", "finger");
                set("wear_msg", "$N��$n�ó���С�ĵش�����ָ�ϡ�\n");
                set("remove_msg", "$N��$nС�ĵش���ָ��ժ�����źá�\n");
        }
        setup();
}
void init()
{
        add_action("do_full","full");
        add_action("do_goto","gotoo");
}
int do_full(string arg)
{
        int m_kee;
        int m_sen;
        int m_gin;
        int m_force;
       if (this_player()->query("rongyu") < 1){
              message_vision(HIR"$N����������ң��벻Ҫ���á�\n"NOR,this_player());
                return 1;
        }
    if (( arg == "me")){
                m_kee = this_player()->query("max_kee");
        m_sen = this_player()->query("max_sen");
        m_gin = this_player()->query("max_gin");
        m_force = this_player()->query("max_force");
              message_vision(HIR"$N��������ָ��һ�������������\n"NOR,this_player());
        this_player()->set("eff_kee",m_kee);
        this_player()->set("kee",m_kee);
        this_player()->set("env/immortal",1);
        this_player()->set("eff_gin",m_gin);
        this_player()->set("gin",m_gin);
        this_player()->set("eff_sen",m_sen);
        this_player()->set("sen",m_sen);
        this_player()->set("force",m_force);
        this_player()->set("title",HIR"֣�ݷ����������"NOR);
                this_player()->set("max_mana", 2000);
                this_player()->set("max_atman", 2000);
                this_player()->set("atman", 2000);
                this_player()->set("mana", 2000);
                this_player()->set_skill("iron-cloth", 100);
        return 1;
     }
     return 0; 
}
int do_goto(object me, object target)
{
        if(this_player()->query("rongyu") < 1 )
                return notify_fail("�㲻��������Ҳ���ʹ��������ָ��\n");
        write(HIC"��Ҫȥ�ĸ�����ߣ�"NOR);
        input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
}

void select_target(object me, string name)
{
        object ob;

        if( !name || name=="" ) {
                write(HIC"ֹͣ�ƶ���\n");
                return;
        }
              me = this_player();
        ob = find_player(name);
        if( !ob || !me->visible(ob) || wizardp(ob) )
                ob = find_living(name);
        if( !ob || !me->visible(ob) || !environment(ob)) {
                write(HIB"���޷��ƶ�������˵���� ....\n"NOR);
                write(HIC"��Ҫȥ�ĸ�����ߣ�"NOR);
                input_to( (: call_other, __FILE__, "select_target", me :));
                return;
        }
      
        message_vision( HIR "\n$N�߾�������ָ��������ʦ������ƶ�Ȩ��....\n" NOR, me);
        me->move(environment(ob));
        message( "vision", HIG "\n�����߳�����һ���ˣ�����ȥ�������"+me->name()+"��\n\n" NOR,
                environment(ob), ({ me }) );
}
void owner_is_killed()
{
       destruct(this_object());
}
int query_autoload()
{
       return 1;
}

