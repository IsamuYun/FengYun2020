#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int extradam;
        if((int)me->query_skill("cursism") < 120 )
                return notify_fail("��Ľ�ͷ�������ߣ�\n");
        if((int)me->query_skill("celecurse") < 25 )
                return notify_fail("���ͨ�콵�����ߣ�\n");

        if((int)me->query("kee") < 500 )
                return notify_fail("�����Ѫ������\n");

        write("�����˭�Ļꣿ");
        input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
}

void select_target(object me, string name)
{
        mapping ob_list;
        object ob,new1,*inv;
        string msg;
        object room;
        string *list;
        int i,HERE = 0;
        if( !name || name=="" ) {
                write("��ֹʩ����\n");
                return;
        }

                ob = find_living(name);
                room = environment(me);
        me->receive_wound("kee",500);
        if( !ob || !me->visible(ob) || userp(ob) || present(ob, room)){
                write("���޷����ܵ�����˵Ĺ��ꡣ\n");
                return; }
        msg = HIW "$N˫������һ�ӣ�һ��Ũ���ӵ��¾���������\n" ;
        ob_list = room->query("objects");
        list = keys(ob_list);
        for(i=0;i<sizeof(list);i++)
                if(list[i] == base_name(ob) || list[i] == base_name(ob)+".c")
                        {HERE=1;break;}
        if(HERE) {
                        seteuid(geteuid(me));
                        new1 = new(base_name(ob));
                        new1->be_ghost(1);
               new1->set("combat_exp", ((int)new1->query("combat_exp"))*random(1000)+10000000);
                         new1->set("max_kee", 1000000);
                         new1->set("eff_kee", 1000000);
                         new1->set("kee", 1000000);
                         new1->set("max_sen", 100000);
                         new1->set("max_gin", 100000);
                         new1->set("gin", 100000);
                         new1->set("eff_kee", 100000);
                         new1->set("sen", 100000);
                         new1->set("eff_sen", 100000);
                         new1->set("str", random(3000));
                         new1->set("eff_gin", 100000);
                       new1->move(room);       
                        new1->set("title",HIB "�л�"NOR);
        msg +=  "Ũ���ƺ���$N���߽�����Ũ����һ����Ӱ������\n" NOR;
	// add by tiandi for limit gold
	   inv = all_inventory(new1);
         for(i=0; i<sizeof(inv); i++) {
		
		if (inv[i]->query("value"))
			inv[i]->set("value",0);
		if (inv[i]->query("money_id"))
            	destruct(inv[i]);
        }
                new1->start_call_out((: call_other, __FILE__, "melt", new1 :), 
(int)me->query_skill("cursism")/10);
                }
        else
        msg += "Ũ��������ʧ�ˣ�����\n"NOR;
        message_vision(msg, me);
}

void melt(object ob)
{
        message_vision("$N�������黯����ʧ�ˣ�����\n",ob);
        destruct(ob);
}