// by tiandi �ݷ�

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string dest, msg;
        object ob,*inv,gift,gold;
	mapping quest;
	int exp,pot,reb,score,ti,doubletime,doubletype;	
	

        seteuid(getuid());

        if( !arg || sscanf(arg, "%s",dest)!=1 )
                return notify_fail("��Ҫ�ݷ�˭��\n");

        if( !objectp(ob = present(dest, environment(me))) )
                return notify_fail("�㿴�����:����û�������Ү��\n");

        if( !ob->is_character() ) {
                message_vision("$N����$n�����Ǹ���������á�����\n", me, ob);
                return 1;
        }

        if( !ob->query("can_speak") ) {
                message_vision("$N��$n�����Ǹ���������á������þò�������������$p��Ȼ�������˻���\n", me, ob);
                return 1;
        }

        if( userp(ob) ) return 1;
        if( !living(ob) ) {
                message_vision("���Ǻ���Ȼ�ģ�$n���ڵ�״�����ʺϽӴ�$N��\n",
                        me, ob);
                return 1;
        }
	if (quest =  me->query("tiequest"))
	{
		if (ob->query("name") == quest["quest"] && quest["quest_type"] == "�ݷ�")
		{
	 	 message_vision("$N˫����Ҿ����$n���������ص���"+ RANK_D->query_respect(ob)+"���ܰ���֮�У�ǰ���ݷã��������ɺã�\n",me,ob);
		 message_vision("$n�����Ļش�$N����λ"+ RANK_D->query_respect(me)+"��лл�������ң��鷳ת�氢��һ�ж��á�\n",me,ob);
		        if ((int) me->query("tiequest_time") < time() )
   			     {
   			     tell_object(me,"���ź�����Ȼ������˰ݷ����񣬵���ȴ�����˹涨��ʱ�䡣\n");
				return 1;
			}
			        else
   			     {
     			   tell_object(me,"��ϲ�㣡���������һ����������\n");
	reb = me->query("reborned");
    exp = me->query("level");
	doubletime = me->query("doubletime");
	doubletype = (int)me->query("doubletype");
	ti = me->query_temp("tiejobtemp");
	exp = 100*exp;
	exp = exp + exp/10*ti;
	exp = exp + exp/5*reb;
	//write(exp+"/20000*"+ti);
	if (doubletime - time() > 0)
		exp = exp*(doubletype+1);
	exp = exp / 2;
	pot = exp / 7 * 4;
	score = reb+1;  

	me->add("combat_exp",exp);
	me->add("potential",pot);
    me->add("score",score);
  	tell_object(me,HIW"�㱻�����ˣ�\n" +
	chinese_number(exp) + "��ʵս����\n"+
	chinese_number(pot) + "��Ǳ��\n"+
	chinese_number(score)+"������\n" NOR);
	if (ti==10)
		{
		if ( me->query("level")>89)
				gift=new("/d/wiz/fyup/obj/hongbao5");
		else if ( me->query("level")>79)
				gift=new("/d/wiz/fyup/obj/hongbao4");
		else if ( me->query("level")>69)
				gift=new("/d/wiz/fyup/obj/hongbao3");
		else if ( me->query("level")>59)
				gift=new("/d/wiz/fyup/obj/hongbao2");
		else if ( me->query("level")>49)
				gift=new("/d/wiz/fyup/obj/hongbao1");	
		else gift=new("/d/wiz/fyup/obj/hongbao");
		gift->move(me);
		score = 60 + random(40);
		score = score + score/5*reb;
		gold=new("/obj/money/gold");
	    gold->set_amount(exp/100);
	    gold->move(me);
		me->add("score",score);
		me->add("combat_exp",exp);
		me->add("potential",pot);
  		tell_object(me,HIY"�㱻���⽱���ˣ�\n" +
		chinese_number(exp) + "��ʵս����\n"+
		chinese_number(pot) + "��Ǳ��\n"+
		chinese_number(exp/100) + "���ƽ�\n"+
		chinese_number(score)+"������\n" NOR);
		tell_object(me,HIY"��İ�����������һ�㡣\n"NOR);
		}
	ti ++;
	if (!ti) ti = 1;
	if (ti >10) ti = 1;
	me->set_temp("tiejobtemp", ti );
          me->add("tiejob", 1 );
	me->set("tiequest",0);
	return 1;
     				   }
			}
	}
 	message_vision("$N˫����Ҿ����$n���������ص���"+ RANK_D->query_respect(ob)+"���������ɺã�\n",me,ob);
	message_vision("$n�ɻ�ÿ���$N�૵��ʵ�����λ"+ RANK_D->query_respect(me)+"�����Ǻ�����\n",me,ob);
	return 1;			
}

int help(object me)
{
   write( @HELP
ָ���ʽ: visit <id>

���ָ�����������ɰݷ�NPC�Ĺ��ܡ�
���ڴ��������

HELP
   );
   return 1;
}
