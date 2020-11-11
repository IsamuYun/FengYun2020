inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int time_period(int timep, object me);
string sysmsg;
int askfor();
int returngift();

void create()
{
	set_name(HIY "�������" NOR, ({ "tianji", "Tian ji", "Tian" }) );

	set("gender", "����");
	set("age", 99);
	set("long",
		"�������������ף��׷�ͯ�ա��ڱ�������������һ��
�����Ϲ٣�С��֮�ϣ�����������а�����¶��ɰ�����������������ͽ�����ޣ�������\n");
	set("attitude", "peaceful");
        set("skill_public",1);
	set("str", 26000);
	set("cor", 30);
	set("int", 24);
	set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "������������̳��˼��ڣ�������\n",
        }) );

	set("force", 40000);
	set("max_force", 80000);
	set("force_factor", 1000);

	set("combat_exp", 10000000);
	set("score", 200000);

	set_skill("unarmed", 120);
	set_skill("force", 100);
	set_skill("iron-cloth", 100);
	set_skill("yiqiforce", 30);
	set_skill("dagger",200);
	set_temp("apply/attack",300);
	set_temp("apply/damage",30000);
	map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce");
	   set("inquiry", ([
                "��æ" : (: askfor :),
	//    "������װ" : (: returngift :),

        ]) );

	create_family("��ң��", 1, "��ʦ");
        set("title", HIC"����Ұ��"NOR);
	setup();

	carry_object(__DIR__"obj/jade-ring")->wear();
	carry_object(__DIR__"obj/jade-pin")->wear();
	carry_object(__DIR__"obj/jade-boots")->wear();
	carry_object(__DIR__"obj/jade-cloth")->wear();
	carry_object(__DIR__"obj/hanyan")->wield();
}
int accept_fight(object me)
{
        command("say �����ɹ󣡲�Ҫ��Ѱ��·��");
        return 0;
}
void init()
{
        add_action("give_quest", "quest");
}
int accept_object(object who, object ob)
{
        object silk;
        int  exp, pot, score, val, extra, reb;
	string test;
	mapping quest;
	val = ob->value();
        if(ob->query("id") == "goodpin")
        {
command("say ��λ" + RANK_D->query_respect(who)+ "����û�뵽���ܰ��ҵķ����޵�������,���Ǹ���Ľ�����\n��");
silk = new("/questobj/big");
silk->move(who);
        tell_object(who,"������˸���һ��"+silk->query("name")+"��\n");
//silk->move(this_object());
//command("give jin-nang to " + who->query("id"));
who->add("bigtasks",1);
        return 1;
        }
        if (val && val >10000 && val < 20000)
	{
		       who->set("quest", 0 );
       	 	tell_object(who,"�������˵�����ðɣ������������˰ɣ���\n");
		who->delete_temp("quest_number");
		who->set("canceltask_time", (int) time()+60);
		return 1;
	}
        if(!(quest =  who->query("quest")))
	{
        tell_object(who,"�������˵�����ⲻ������Ҫ�ġ�\n");
	return 0;
	}
        if( (string)ob->query("name") != quest["quest"])
        {
        tell_object(who,"�������˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
	if( ob->is_character())
        {
        tell_object(who,"�������˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"�������˵�������ϧ����û����ָ����ʱ������ɣ�\n");
                        return 1;
        }
        else
        {
        tell_object(who,"�������˵������ϲ�㣡���������һ������\n");
reb = who->query("reborned");
        exp = quest["exp_bonus"] + random(quest["exp_bonus"])+1;
// put a cap
        if(exp > 1000) exp = 1000;
   //     extra = 2+(((int)who->query("TASK"))/3000)+(((int)who->query("bigtasks"))/1500);
        exp = exp * (int) who->query_temp("quest_number");
        exp = exp + exp/5*reb;
	if( exp > 1200) exp = 1200;
	pot = exp / 7;
//	due to weekly quest, each quet worth 20
//	score = quest["score"]/2 + random(quest["score"]/2);
	who->add("combat_exp",exp);
	who->add("potential",pot);
    tell_object(who,HIW"�㱻�����ˣ�\n" +
	chinese_number(exp) + "��ʵս����\n"+
	chinese_number(pot) + "��Ǳ��\n" NOR);
	who->set("quest", 0 );
    who->add("bbquest", 1 );

                        return 1;
        }
                return 1;
}
void attempt_apprentice(object me)
{
	switch(random(4)) {
		case 0:
message_vision("$N��$nЦ�ʵ���ʲô���Ľ���\n", this_object(),me);
			break;
		case 1:
message_vision("$N��$nЦ�ʵ���ʲô�ǣ��в������Ҳ�������һ�������ȶ�����\n", this_object(),me);	
			break;
		case 2:
message_vision("$N��$nЦ�ʵ��������Σ����Σ���ʲô��\n", this_object(),me);		
			break;
		case 3:
message_vision("$N��$nЦ�ʵ�����ѧ����߾�����ʲô��\n", this_object(),me);
			break;
	}
                        return;

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xianren");
}

int give_quest(string arg)
{
	mapping quest ;
	object me;
	int j, combatexp, timep, lvl=0,k,lv,i;
        mixed *local;
        int  t;
	string tag = "40000000";
 string *levels = ({
                        "0",
                        "4000",
                        "8000",
                        "16000",
                        "32000",
                        "64000",
                        "128000",
                        "256000",
                        "512000",
                        "1024000",
                        "1536000",
                        "2304000",
                        "3456000",
                        "5184000",
                        "7776000",
                        "11664000",
                        "17496000",
                        "26244000",
			"40000000"
        });
	if( ! arg || !sscanf(arg, "%d", lvl))
	lvl = 0;
	if(lvl<0) lvl=0;
	me = this_player();

	if(me->query("canceltask_time"))
	{
        if ((int) me->query("canceltask_time") > time() )
        {
        tell_object(me,"�������˵�������ȡ�����������һ�������룡\n");
                        return 1;
        }
	}

// Let's see if this player is a ghost
        if((int)me->query("level") >= 100)
	{
		write("��������Ѿ���������κ������ˣ�\n");
		return 1;
	}
	if((int) me->is_ghost())
	{
		write("��겻��Ҫ����\n");
		return 1;
	}

// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
	{
	if( ((int) me->query("task_time")) >  time() )
		return 0;
	else
		me->set("kee", me->query("kee")/2+1);
		me->delete_temp("quest_number");
	}
	k=2000;
	lv = me->query("level");
	for(i=0;i<lv;i++)
		k=k+k/9;
	combatexp = k;

        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
                                tag = levels[j];
				if(j < (sizeof(levels)- lvl)) tag = levels[j+lvl];
                                break;
                        }
        }
        if(!random(40) ) tag = "_new";
	if(!random(10) ) tag = "_common";
	quest = QUEST_D(tag)->query_quest();
//	to use less mem...
//	timep = quest["time"];	
	timep = 600;   // each quest give 10 mins.
// A factor here to make time random
	timep = random(timep/2)+timep/2;
	time_period(timep, me);
	if (quest["quest_type"] == "Ѱ")
	{
        tell_object(me,"�һء�"+quest["quest"]+"����������ˡ�\n" NOR);
	sysmsg +="�һء�"+quest["quest"]+"����";
	}
	        if (quest["quest_type"] == "ɱ")
        {
        tell_object(me,"���������ɱ�ˡ�"+quest["quest"]+"����\n" NOR);
	sysmsg +="ɱ�ˡ�"+quest["quest"]+"����";
        }
 	me->set("quest", quest);
	me->set("task_time", (int) time()+(int) timep);
	if((int)me->query_temp("quest_number") < 5)
	me->add_temp("quest_number",1);
	CHANNEL_D->do_channel(this_object(), "qst", sprintf("%s(%s)��%s", 
	me->query("name"),me->query("id"),sysmsg));

return 1;
}

int time_period(int timep, object me)
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

        tell_object(me,HIW + sprintf("%s",this_object()->name()) +"˵����\n����" + time + "��");
	sysmsg = "��" + time + "��";
        return 1;
}
int askfor()
{
	object ob,me,obj;
	me = this_player();
	ob = this_object();

	if (me->query("level")<6)
		{
		message_vision("$n����$N˵������ĵȼ��������ﲻ���ң���ȥĥ��һ�°ɣ����������������ҡ�\n",me,ob);
		return 1;
		}
	if (me->query("longstory")>= 5)
		{
		message_vision("$n����$N˵�����ϴζ�л��λ���Ѱ�æ��\n",me,ob);
		return 1;
		}
	if (me->query("longstory")!= 4)
		{
		message_vision("$n����$N˵���������ʲô��\n",me,ob);
		return 1;
		}
	if (!me->query_temp("askfornewbie"))
	{
	me->set_temp("askfornewbie",1);
	message_vision("������˶���"+me->query("name")+"˵���������������Ѿ���Ϥ�˷����е�����֮��������Ϸ�Ҳ����\n�����æ�ˣ��Ǽ�С���飬ֻ��Ϊ�Ϸ��ܸ��ȣ���������Ϲ�ʮ����Ƿ�Ϸ�\nһ������������δ����\n��ȥ������һ������������ʲôʱ��Ǯ��\n",me);
	me->set_temp("nofly",1);	
	return 1;
	}else
	if (me->query_temp("askfornewbie")<4 && me->query_temp("askfornewbie")>2)
	{
	me->set_temp("askfornewbie",4);
	message_vision(me->query("name")+"������������˿��������Լ����������¡�\n������˶���"+me->query("name")+"˵����������������ԣ���Ȼȫ����������ˣ��������������ˣ��鷳����ȥ�Ϲ�ʮ�����ǰ��ҵ���Ǹ�ɡ�\n",me);
	return 1;
	}else
	if (me->query_temp("askfornewbie")>6)
	{
	me->delete_temp("askfornewbie");
	me->set("longstory",5);
	message_vision(me->query("name")+"ת�����Ϲ�ʮ���ɵ���˼��\n�������΢Ц�Ŷ���"+me->query("name")+"˵������ʵ��ֻ�ǲ���һ�����Ʒ�У��Ƿ��Ǽ�թ̰��֮�ˣ�������ϸ��ˣ�������Щ��������ɣ�\n֮���·��Ҫ�����Լ����ˣ��ﲻ����ʲô�ˡ�\n",me);
	obj = new("/d/wiz/tiandi/obj/shenbing");
	obj->move(me);
	obj = new("/d/wiz/tiandi/obj/shenjia");
	obj->move(me);
	obj = new("/obj/food/dan1");
	obj->move(me);
	obj = new("/obj/food/cj");
	obj->move(me);
	me->delete_temp("nofly");
          message("system",HIY "\n�����ַ��ơ��ɳ�����"+me->query("name")+"��ʽ��ʼ̤�뽭���ˣ����Կ�ʼ��ʦѧ���ˡ�\n" NOR,users());
	return 1;
	}
	message_vision("$n�ɻ��Ŷ���$N˵�����㻹��������ʲô��\n",me,ob);
	return 1;

}
int returngift()
{
	object ob,me,obj,obj1;
	me = this_player();
	ob = this_object();

	if (me->query("longstory")<5)
		{
		message_vision("$n�ɻ��Ŷ���$N˵��������Ҫ������������������ĥ��ĥ����\n",me,ob);
		return 1;
		}
	obj = present("shenbing", me);
	obj1 = present("shenjia", me);
	if (!objectp(obj) || !objectp(obj1))
 	{	
		if (!objectp(obj))
			{
			obj = new("/d/wiz/tiandi/obj/shenbing");
			obj->move(me);
			}

		if (!objectp(obj1))
		{
			obj1 = new("/d/wiz/tiandi/obj/shenjia");
			obj1->move(me);
		}
	message_vision(me->query("name")+"��ɥ���������������˵������������װ���Ҳ�С�ĸ㶪�ˣ������ô��źð���\n
������˶���"+me->query("name")+"˵����������װ������֮��Ժ���������ʧ���뵽�Ϸ��ⲹ������ˡ�\n",me);
	return 1;
	}
}


