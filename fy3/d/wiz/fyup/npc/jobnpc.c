inherit NPC;
#include <ansi.h>
int time_period(int timep, object me,int i);
string sysmsg;
void create()
{
	set_name(HIY "����" NOR, ({ "tie", "a tie" }) );

	set("gender", "����");
	set("age", 35);
	set("long",
		"������˭�˲�֪��˭�˲��������������и���񱣬ϲ���ռ�����ֵֹĶ�����\n");
	set("attitude", "peaceful");
	set("str", 100);
	set("per", 130);
	set("int", 100);
	set("cps", 30);

	set("combat_exp", 130000000);
	set("inquiry", ([ "����" : "�ж�־���ķ���ȴ����ТΪ�ȡ����Ƿ�Ҫ�������������أ���quest��" 
	  ]));

          set("title", HIC"����ʼ��"NOR);
	setup();
}
void init()
{
        add_action("give_quest", "quest");
}
int accept_object(object who, object ob)
{
        object gift,gold;
        int  exp, pot, score, val, extra, reb,ti,doubletime,doubletype;
	string test,file,*name;
	mapping quest;

        if(!(quest =  who->query("tiequest")))
	{
        tell_object(who,"����˵��������Ȼ�����ռ�����С���⣬����ʱȴ������Ȥ��\n");
	return 0;
	}
        if( (string)ob->query("name") != quest["quest"])
        {
        tell_object(who,"����˵��������񡣡�����������Ҫ�Ķ����ɡ�\n");
        return 0;
        }
	if( ob->is_character())
        {
        tell_object(who,"����˵�������ѣ�������ʲô��˼��\n");
        return 0;
        }
        if ((int) who->query("tiequest_time") < time() )
        {
        tell_object(who,"����̾�����������ˣ����Ѿ��ռ�����Ҫ�Ķ����ˣ�\n");
                        return 1;
        }
        else
        {
        tell_object(who,"����˵������ϲ�㣡���������һ����������\n");
    //by tiandi 08.1.30������ɾ���Ѿ�������������Ʒ
	if (ob->query("selfmaking"))
	{
	seteuid(ROOT_UID);
	rm(base_name(ob) + ".o");
	rm(base_name(ob) + ".c");
	ob->move(environment(who));
	destruct(ob);
	seteuid(getuid());
	}
		
	reb = who->query("reborned");
    exp = who->query("level");
	doubletime = who->query("doubletime");
	doubletype = (int)who->query("doubletype");
	ti = who->query_temp("tiejobtemp");
	exp = 100*exp;
	exp = exp + exp/10*ti;
	exp = exp + exp/5*reb;
	//write(exp+"/20000*"+ti);
	if (doubletime - time() > 0)
		exp = exp*(doubletype+1);
	exp = exp /2;
	pot = exp /7 *4;
	score = reb+1;  

	who->add("combat_exp",exp);
	who->add("potential",pot);
    who->add("score",score);
  	tell_object(who,HIW"�㱻�����ˣ�\n" +
	chinese_number(exp) + "��ʵս����\n"+
	chinese_number(pot) + "��Ǳ��\n"+
	chinese_number(score)+"������\n" NOR);
	if (ti==10)
		{
		if ( who->query("level")>89)
				gift=new("/d/wiz/fyup/obj/hongbao5");
		else if ( who->query("level")>79)
				gift=new("/d/wiz/fyup/obj/hongbao4");
		else if ( who->query("level")>69)
				gift=new("/d/wiz/fyup/obj/hongbao3");
		else if ( who->query("level")>59)
				gift=new("/d/wiz/fyup/obj/hongbao2");
		else if ( who->query("level")>49)
				gift=new("/d/wiz/fyup/obj/hongbao1");	
		else gift=new("/d/wiz/fyup/obj/hongbao");
		gift->move(who);
		score = 60 + random(40);
		score = score + score/5*reb;
		gold=new("/obj/money/gold");
	    gold->set_amount(exp/100);
	    gold->move(who);
		who->add("score",score);
		who->add("combat_exp",exp);
		who->add("potential",pot);
  		tell_object(who,HIY"�㱻���⽱���ˣ�\n" +
		chinese_number(exp) + "��ʵս����\n"+
		chinese_number(pot) + "��Ǳ��\n"+
		chinese_number(exp/100) + "���ƽ�\n"+
		chinese_number(score)+"������\n" NOR);
		tell_object(who,HIY"��İ�����������һ�㡣\n"NOR);
		}
	ti ++;
	if (!ti) ti = 1;
	if (ti >10) ti = 1;
	who->set_temp("tiejobtemp", ti );
          who->add("tiejob", 1 );
	who->set("tiequest",0);
            return 1;
        }
                return 1;
}

int give_quest(string arg)
{
	mapping quest ;
	object me,room,qiangdao;
	int j, combatexp, timep,lv ;
	string file,location,*roomlines;
 	room = load_object("/d/fy/fysquare");
	me = this_player();

	if((int) me->is_ghost())
	{
		write("���겻��Ҫ����\n");
		return 1;
	}
	if ((me->query("tiejob") - 650) > me->query("TASK"))
	{
		write("Ŀǰ�������������ɴ����Ѿ��ﵽ���ޡ�\n");
		return 1;
	}

        if((quest =  me->query("tiequest")))
	{
	if( ((int) me->query("tiequest_time")) >  time() )
		return 0;
	else
		me->delete_temp("tiejobtemp");
	}
    	quest = QUEST_D("tie3")->query_quest();
	timep = 900;   // each quest give 10 mins.
// A factor here to make time random
	timep = random(timep/2)+timep/2;
	if (!me->query_temp("tiejobtemp"))    
		me->set_temp("tiejobtemp",1);
	tell_object(me,"��ǰ��"+me->query_temp("tiejobtemp")+"����������\n");
	if (quest["quest_type"] == "Ѱ")
	{
	
        tell_object(me,"����˵�������ڷ��Ƴ����ȱ"+quest["quest"]+"������" NOR);
	time_period(timep, me,1);
	sysmsg +="�һء�"+quest["quest"]+"����";
	}
	if (quest["quest_type"] == "����")
        {
	
        tell_object(me,"����˵�������ڽ������ܲ���������ɱɱ����˵��"+quest["quest"]+"���羰�������ʺ����Σ�����" NOR);
	time_period(timep, me,2);
	sysmsg +="���͡�"+quest["quest"]+"����";
        }
	if (quest["quest_type"] == "�ݷ�")
        {
	
        tell_object(me,"����˵�����þ�û�аݷá�"+quest["quest"]+"���ˣ�����" NOR);
	time_period(timep, me,3);
	sysmsg +="�ݷá�"+quest["quest"]+"����";
        }
	if (quest["quest_type"] == "ɱ")
        {
	  timep= 900 +random(60);
	  file = read_file("/quest/dynamic_location");
        roomlines = explode(file,"\n"); 
        location = roomlines[random(sizeof(roomlines))];

                if( catch(load_object(location)) || !load_object(location) )
                {
                        write("�ص�ˢ�³������⣬��������ر�����Ϣ����WIZ����������λ��Ϊ"+location+"��\n");
                        return 1;               
                }
	qiangdao = new(__DIR__"qd");
//	write ("�ص���"+location);
	qiangdao ->move(location);
	room = environment(qiangdao);
	qiangdao ->set("owner",me->query("name"));
	qiangdao->set("level",me->query("level")+10); 
	lv = qiangdao->query("level");
		 qiangdao->set("str",6*lv);
		 qiangdao->set("cor",6*lv);
		 qiangdao->set("int",6*lv);
		 qiangdao->set("spi",6*lv);
		 qiangdao->set("cps",6*lv);
		 qiangdao->set("per",6*lv);
		 qiangdao->set("con",6*lv);
		 qiangdao->set("kar",6*lv);
		 qiangdao->set("agi",6*lv);
		 qiangdao->set("dur",6*lv);
		 qiangdao->set("fle",6*lv);
		 qiangdao->set("tol",6*lv);
		 qiangdao->set("max_kee",me->query("max_kee")*2);
		 qiangdao->set("eff_kee",qiangdao->query("max_kee"));
		 qiangdao->set("kee",qiangdao->query("max_kee"));
		 qiangdao->set("max_gin",me->query("max_gin")*2);
		 qiangdao->set("eff_gin",qiangdao->query("max_gin"));
		 qiangdao->set("gin",qiangdao->query("max_gin"));
		 qiangdao->set("max_sen",me->query("max_sen")*2);
		 qiangdao->set("eff_sen",qiangdao->query("max_sen"));
		 qiangdao->set("sen",qiangdao->query("max_sen"));

	qiangdao ->set("long",qiangdao->query("long")+"��˵"+me->query("name")+"��׼����ˡ�");
        tell_object(me,"����˵������˵��"+room->query("short")+"��һ��������·ǿ����Ϊ�������ˣ�����" NOR);
	time_period(timep, me,4);
	sysmsg +="ɱ�ˡ�"+room->query("short")+"������·ǿ����";
        }
	me->set("tiequest", quest);
	me->set("tieplace",room->query("short"));
	me->set("tiequest_time", (int) time()+(int) timep);
//	CHANNEL_D->do_channel(this_object(), "qst", sprintf("%s(%s)��%s", 
//	me->query("name"),me->query("id"),sysmsg));

return 1;
}

int time_period(int timep, object me,int i)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
	if (i==1) 
	{
	       tell_object(me, sprintf("��" + time + "���������ҡ�\n"));
	}
	if(i==2)
	{
	        tell_object(me,sprintf("��" + time + "��ǰȥ����һ�¡�\n"));
	}
	if(i==3)
	{
	        tell_object(me,sprintf("��" + time + "��ǰȥ�ݷ�һ�¡�\n"));
	}
	if(i==4)
	{
	        tell_object(me,("��" + time + "��ǰȥ���������\n"));
	}

	sysmsg = "��" + time + "��";
        return 1;
}