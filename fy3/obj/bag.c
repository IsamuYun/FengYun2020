
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIY "����" NOR, ({ "bag"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	    set("no_drop",1);
	    set("no_get",1);
	   set("long","һ��������");
        }
        setup();
}
void init()
{
        add_action("do_finish", "finish");
}

int do_finish(string arg)
{
        object ob,money,me,target;
        int gold, combatexp,pot;
        string file,location,*roomlines,objid,output;

		  me = this_player();
		  if (!arg) return notify_fail("��ʹ��finish <id>��\n");

        ob = present(arg, environment(this_player()));
        if( !ob ) return notify_fail("����û������ˡ�\n");

        if (userp(ob)) return notify_fail("����������ߣ�ֻ�ܽ���NPC��\n");
	    if (ob->query("name") != me->query("hubiao"))
		return notify_fail("�㿴������������Ǹ�˭�İ�����\n");
	    combatexp = me->query("level");
                gold = combatexp ;
                gold = gold*2;
				pot = combatexp*50;
	    money = new("/obj/money/gold");
	    money->set_amount(gold);
	    money->move(me);
		me->add("potential",pot);
                message_vision("$N���˵�˵����лл$n�����İ��������Ǹ�$n�ĳ��ͣ������£�\n",ob,me);
                write (HIY"������"+pot+"��Ǳ�ܺ�"+gold+"���ƽ�\n�����Ѫ�ָ������ֵ��\n"NOR);	
	    me->delete("hubiao");
	    me->add("hubiaojob",1);
		me->set("eff_kee",me->query("max_kee")+me->query_temp("apply/addeffkee"));
		me->set("kee",me->query("eff_kee"));
                me->apply_condition("biaojob", 0);
	    me->delete("no_fly");
	   if (!random(5))
		{
      		  file = read_file("/quest/dynamic_location");
       		  roomlines = explode(file,"\n"); 
    	              location = roomlines[random(sizeof(roomlines))];

            	    if( catch(load_object(location)) || !load_object(location) )
              		  {
                    		    write("ˢ�µص�������⣬��㱨WIZ���ص���"+location+"��\n");
                  		      return 1;               
          			      }
		target = new ("/d/wiz/fyup/npc/jiefei");
		target->move(location);
		message("rumor", HIM"��ҥ�Ի��ڡ�ĳ�ˣ���˵��·�ٷ���"+ environment(target)->query("short")+"����ר�Ŵ�ٻ��ڵ��ˣ����λӢ������ǰȥΧ�ˣ��������Ͽ���Я�����벻���Ĳ��\n" NOR,users());
	}
	 destruct(this_object());
        return 1;
}

