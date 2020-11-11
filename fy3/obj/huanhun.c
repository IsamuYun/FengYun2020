#include <ansi.h>
inherit ITEM;

void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(HIR "���굤" NOR, ({ "huanhun dan" , "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ż��굤���ǻָ��������ҩ��\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                }
        setup();
}
int do_eat(string arg)
{
        object me = this_player();

        object *inv;
        mapping hp_status, skill_status;
        string *sname;
        int i;

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

        skill_status = me->query_skills();
        if (!skill_status)
        return notify_fail("���ò��ųԻ��굤��\n");

        sname  = keys(skill_status);
        for(i=0; i<sizeof(skill_status); i++) {
                me->set_skill(sname[i], skill_status[sname[i]]+7);
        }

        hp_status = me->query_entire_dbase();
        me->set("combat_exp",hp_status["combat_exp"]*50/49);
        me->set("potential",hp_status["potential"]*2-1);
        
        me->save();
        message_vision(HIR "$N����һ�Ż��굤��ֻ����һ���ʹ����ʱ�ֺ�ת������\n" NOR, me);
        destruct(this_object());
        return 1;
        
}
