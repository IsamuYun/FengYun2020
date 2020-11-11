#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_launch", "��");
       add_action("do_stop", "ͣ");
}


void create()
{
       set_name(BLU"���"NOR, ({"shen deng", "deng", "light"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
       	       set("long", "һֻ��������ƣ��������������ѡ��ˣ������п��ԡ�ͣ����������ֻ�������Ρ�\n");
               set("value", 1000000000);
               set("unit", "ֻ");
       }
}

int do_launch(string arg)
{
       object target, where, npc, me;
       me = this_player();
  
       if(!arg) return notify_fail("������Ҫ��˭���������������� ( �� <id> ) \n");
       if(query("used") >= 3)
          return notify_fail("��ֻ����Ѿ��ù������ˣ������Ȼ��ɫ��\n");
          
       if( me->is_busy() || me->is_fighting())
          return notify_fail("����æ���ء�\n");

       if (objectp(target = LOGIN_D->find_body(arg))) 
            where = environment(target);
       else return notify_fail("û�������Ү������\n");
       
       if (!where) return notify_fail("�����������Ʈ��䣬�Ҳ�������\n");
       
       if (wizardp(target)) return notify_fail("�������ð��ֻ���飬���������һ��������͵�����Ǿ�������ʦ�ǣ���Ҫ������\n");

       if (target==me) return notify_fail("�������ð��ֻ���飬ָ���������Ц�������Ͼ�Ȼ����ô���ĵ���\n");

       if(objectp(npc = me->query_temp("shendeng_npc")))
          return notify_fail("������ʹ��������ء�\n");
          
       message_vision(HIY"\n$N����һ���Ʋ���������ϲ����������������л�һ������"+target->name()+HIY"�����֡�\n\n" NOR, me);
       npc = new("shendeng_npc");
       npc->do_setup(me, target);
       me->set_temp("shendeng_npc", npc);
       me->start_busy(1);
       me->add("used", 1);
       return 1;
}


int do_stop()
{
	object npc, me;
	me = this_player();
	
	if(!me->query_temp("shendeng_npc"))
          return notify_fail("����û��ʹ������ƣ�ͣʲôͣ��\n");

	npc = me->query_temp("shendeng_npc");
        if(objectp(npc))
           npc->do_remove();
	message_vision(HIC"\n$N������ƴ��˿������ø����ӽ��������ˡ�\n\n" NOR, me);
	me->delete_temp("shendeng_npc");
        me->start_busy(1);
	return 1;
}


