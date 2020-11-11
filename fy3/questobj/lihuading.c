#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( HIW "�����滨��" NOR, ({ "needle box","box" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���ߴ糤����������ϻ�ӣ�����������Ӷ���\n");
                set("material", "silver");
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
	if (query("used")) return notify_fail(this_object()->name()+"ֻ����һ��\n");
	me=this_player();
    if( environment(me)->query("no_fight") ||
        environment(me)->query("no_magic") ||
        environment(me)->query("no_spells") 
	)
	return notify_fail("���ⲻ��͵Ϯ��\n");
    ob=present(arg,environment(me));
    if (!objectp(ob) || !living(ob)) return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ��\n");
                if(me->query("combat_exp")<1000000 &&userp(ob))
return notify_fail(this_object()->name()+"ֻ�ܶ�NPCʹ�ã�\n");
    if (!me->is_fighting(ob)) message_vision("$N��Цһ�����ӻ�������һ����������\n",me);
    message_vision("$N����$n���������е�"+this_object()->name()+"...\n",me,ob);
    message_vision(RED "��ϻ������������һƬ���⣮����...\n" NOR,me);
    message_vision("�������$N���ϣ�һ������ʧ�ˡ�\n",ob);
    ob->receive_damage("kee", 0, me);
    dp=COMBAT_D->skill_power(ob,"dodge",SKILL_USAGE_DEFENSE);
    damage=150000-dp;
    damage/=100;
    if (damage<0) damage=0;
    ob->receive_wound("kee",damage,me);    
    COMBAT_D->report_status(ob);                                         
    ob->kill_ob(me); 
    set("used",1);
    me->start_busy(3);
    ob->set("useding",me->query("id"));
    return 1;
}
