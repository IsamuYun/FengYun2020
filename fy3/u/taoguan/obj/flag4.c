
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR "��ɫ���з�" NOR, ({ "red"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	   set("long","һ�����з��䡣�������������ȫ���Ա��(makehere)����ʹ�����Լ�ס�����ڵ�λ�á�\n");
	   set("value",500000);
        }
        setup();
}
void init()
{
        add_action("do_mark", "makehere");
        add_action("do_fly", "use");
}

int do_mark(string arg)
{
        object ob,me;
        string where;
        me = this_player();
        if (!arg) return notify_fail("��ʹ��makehere <����ID>��\n");

        ob = present(arg, me);
        if( !ob ) return notify_fail("������û�����ŷ��䡣\n");
        if(ob->query_temp("place")) 
		return notify_fail("���ŷ����Ѿ�������ˡ�\n");
        if(environment(me)->query("no_fight"))
		return notify_fail("���ﲻ�ʺ��±�ǡ�\n");
       if(me->query("class") != "sanqing")
		return notify_fail("ֻ�����幬�ĵ��Ӳſ��Ա�ǵص㡣\n");
       if(me->query("lifetili") < 50)
		return notify_fail("��Ļ���������ʮ�㡣\n");
        where = file_name(environment(me));
        ob->set_temp("place",where);
        ob->set_temp("times",20);
       me->add("lifetili",50);

        ob->set("long","һ���Ѿ�����ǹ��ķ��з�����ǵص�Ϊ"+environment(me)->query("short")+"��������ʹ��"+ob->query_temp("times")+"�Ρ�\n");
        message_vision("$Nȡ��������׼���õ�$n���ڵ��ϲ���һ�£�ֻ��һ�ɺ�â��͸���˵ص��¡�\n",me,ob);
        write("\n����"+ob->query("name")+"�ڡ�"+environment(me)->query("short")+"�����˱�ǣ��Ժ��������use <����ID>����Ļ������\n");
        return 1;
}
int do_fly(string arg)
{
        object ob,me,where;
        int i;
        me = this_player();
        if (!arg) return notify_fail("��ʹ��use <����ID>��\n");

        ob = present(arg, me);
        if( !ob ) return notify_fail("������û�����ŷ��䡣\n");
        if(!ob->query_temp("place")) 
		return notify_fail("���ŷ��仹δ����ǡ�\n");
        if( me->is_fighting() )
                return notify_fail("������ս���У����Ƚ���ս���ɣ�\n");
        me->move(ob->query_temp("place"));
        i = ob->query_temp("times");
        ob->set_temp("times",i - 1);
        me->start_busy(2);
        ob->set("long","һ���Ѿ�����ǹ��ķ��з�����ǵص�Ϊ"+environment(me)->query("short")+"��������ʹ��"+ob->query_temp("times")+"�Ρ�\n");
        message_vision("��Χ���һ����$N��Ȼ������"+environment(me)->query("short")+"��\n",me);
        if(ob->query_temp("times") < 1)
		destruct(ob);
        return 1;
}