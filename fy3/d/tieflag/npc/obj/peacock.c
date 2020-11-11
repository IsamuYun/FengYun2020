#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( GRN "��ȸ��" NOR, ({ "peacock tail","peacock" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ����Ƶ�ԲͲ����������ƽ�������������������صİ�����\n"
);
                set("material", "gold");
                
        }

        setup();

}
void init()
{
	add_action("do_shoot","shoot");
}
int do_shoot(string arg)
{
	object ob;
	object me;
	int dp;
	int damage;
	if (!arg) return notify_fail("��Ҫ��˭��\n");
	if (!query_temp("unused")) return notify_fail(this_object()->name()+"ֻ����һ��\n");
	me=this_player();
    if( environment(me)->query("no_fight") ||
        environment(me)->query("no_magic") ||
        environment(me)->query("no_spells") 
	)
	return notify_fail("���ⲻ��͵Ϯ��\n");
    ob=present(arg,environment(me));
    if (!objectp(ob) || !living(ob)) return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ��\n");
    if (!me->is_fighting(ob)) message_vision("$N��Цһ�����ӻ�������һ����������\n",me);
    message_vision("$N����$n���������е�"+this_object()->name()+"...\n",me,ob);
    message_vision(RED "��ԲͲ�зų�һƬ��â���ԻͲ��ã������������Ŀ�ȸ��ë...\n" NOR,me);
    message_vision("��â����$N���ϣ�һ������ʧ�ˡ�\n",ob);
    ob->receive_damage("kee", 0, me);
    dp=COMBAT_D->skill_power(ob,"dodge",SKILL_USAGE_DEFENSE);
    damage=100000-dp;
    damage/=100;
    if (damage<0) damage=0;
    ob->receive_wound("kee",damage,me);    
    COMBAT_D->report_status(ob);                                         
    ob->kill_ob(me); 
    delete_temp("unused");
    me->start_busy(3);
    ob->set("useling",me->query("id"));
    return 1;
}
