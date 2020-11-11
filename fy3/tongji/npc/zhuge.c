inherit NPC;
#include <ansi.h>
int random_action();
void create()
{
        set_name(HIB "�������" NOR, ({ "zhu ge" }) );

        set("gender", "����");
  set("reward_npc", 1);
        set("difficulty", 80); 

        set("age", 62);
        set("long",
                "    ���������������������ͳ˧���Ǵ�˵�����Ŀ��ǣ����ǵ�������
�����ң��书��ɲ⡣����������������Ѿã���γ�ɽ��Ϊ��......\n");
        set("attitude", "peaceful");
     //   set("skill_public",1);
        set("str", 26000);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("per", 50);



        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_action :)
        }) );

        set("mana", 4000000);
        set("max_mana", 800000);
        set("atman", 4000000);
        set("max_atman", 800000);
        set("force", 4000000);
        set("max_force", 800000);
        set("force_factor", 2000);

        set("combat_exp", 200000000);
        set("score", 0);
        set_skill("magic",200);
        set_skill("spells",200);
        set_skill("literate",200);
        set_skill("move",200);
        set_skill("dodge",200);
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("iron-cloth", 200);
        set_skill("yiqiforce", 100);
        set_skill("dagger",200);

        set_temp("apply/attack",300);
        set_temp("apply/damage",30000);

        map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce");

        create_family("������", 1, "ͳ˧");
        set("title", HIR "��ʦ" NOR);
        set("class", "official");
        setup();
}

int accept_fight(object me)
{       object who=this_player();
        command("say �����ò����֣������������裬����" + RANK_D->query_respect(who)+ "�Ķ��֣�");
        return 0;
}


void init()
{
        add_action("give_tongji", "tongji");
}


int accept_object(object who, object ob)
{
       object silk,silk2,goldobj;
        string sure,weap;
       int  exp, pot, score,c1,val,goldnum,reb,doubletime,doubletype;
        mapping tongji;
       tongji = who->query("tongji");
        reb = who->query("reborned");  // update by Tiandi 200712030945

        val=ob->value();
        weap=HIY"�Ͷ�����"NOR;
        if((string)ob->query("id")=="sword" || (string)ob->query("id")=="blade") c1=1;
       if(who->query("m_success/ͨ��") && c1 && weap == (string)ob->query("name"))
        {command("say лл" + RANK_D->query_respect(who)+ "��!ֻ�������书̫��,ֻ���б������޼�����,������Ĺ���,
����һ�ж�û�ܽ���,��....." + RANK_D->query_respect(who)+ "�񹦸���,��������������ѩ��һ�а��ڵ���֮��,
Ҳ�����Ц�Ҵ������.....��.....�����书֮��,������ƽ������," + RANK_D->query_respect(who)+ "ǧ��С����,
�����������Ա����ҹ�����ɲ������֮��,�����ª,����һ����,��ֱ��״," + RANK_D->query_respect(who)+ "
���С�Ĵ���,���﷢��֮������â,����������.....����Ͱ��ڴ˹�֮��,��....������
������," + RANK_D->query_respect(who)+ "�ʹ�ȥ��,Ҳ����ͨ��˹֮�Ծʹ��ƽ�Ҳδ��֪!!
����,������������,������" + RANK_D->query_respect(who)+ "����Ҫ��,���൱��������!\n");
        who->set("m_success/UFO",1);

         return 1;
        }

		if (val && val >2000 && who->query("tongji"))
        {
                who->set("tongji", 0 );
                tell_object(who,"�������˵������Ҳ̫��Ϊ���ˣ����ͨ����������˰ɣ���\n");

           if (reb) {
                 who->add("score",-1);
               }
         else {
               who->add("score",-2);
             }
                        
                return 1;
        }


     if(!(tongji =  who->query("tongji")))
        {
        	tell_object(who,"�������˵������û������ͨ��ʮ����ˡ�\n");
         	return 0;
        }
        sure ="m_success/"+tongji["tongji"];
        if(!(ob->query("id") == "tou"))
        {
         tell_object(who,"�������˵�����ⲻ������Ҫ�ġ�\n");
          return 0;
        }
        if ((string)ob->query("name") != (tongji["tongji"]+"����ͷ") ||
        	ob->query_temp("owner/id") != who->query("id"))
        {
         tell_object(who,"�������˵�����ⲻ������Ҫ�ġ���û���ˣ�\n");
          return 1;
        }
        
        goldnum = 50+random(100);
		doubletime = who->query("doubletime");
		doubletype = (int)who->query("doubletype");
		reb = who->query("reborned");
        exp = who->query("level");
		exp = 5000+exp*20;
		exp = exp + exp/5*reb;
		if (doubletime - time() > 0)
			exp = exp*(doubletype+1);
		pot = exp / 5;
		score = 1;


        message_vision(HIW "$N�������ˣ�\n"
                + chinese_number(exp) + "��ʵս���飬\n"
                + chinese_number(pot) + "��Ǳ�ܣ�\n"
               + chinese_number(score) + "�����ۣ�\n" NOR, who);
        who->add("combat_exp", exp);
        who->add("potential", pot);
        who->add("score", score);
	    goldobj=new("/obj/money/silver");
	    goldobj->set_amount(goldnum);
	    goldobj->move(who);

		who->add("ftongji",1);
		who->set("tongji_time", (int) time());
		who->set("tongji",0);
		
		if(who->query("m_success/ͨ��") || who->query(sure))
		{
			return 1;	
		}
				
		command("say ��λ" + RANK_D->query_respect(who)+ "����ɱ��ʮ�����֮һ��"+tongji["tongji"]+"��\n
			���ǰ���֮������\n");
	//	silk = new("/tongji/obj/jp");
 //silk->move(who);
// tell_object(who,"������һ��"+silk->query("name")+"��\n");
 // silk->move(this_object());
//    command("give xzhang to " + who->query("id"));
		who->add("TTQUEST",1);
		who->set(sure,1);

	    if ( who->query("m_success/�����") && who->query("m_success/��ɱ") 
	        		&& who->query("m_success/������") && who->query("m_success/������")
	        		&& who->query("m_success/ŷ������") && who->query("m_success/������")
	        		&& who->query("m_success/��ս") && who->query("m_success/�׿���")
	        		&& who->query("m_success/������") && who->query("m_success/��ԯ����"))
	    {
	        command("say ��λ" + RANK_D->query_respect(who)+ "���㾹Ȼ��Σ�����ֵ�ʮ�����ȫ������\n
	        	����Ӣ�۸������ⷬΪ��Ϊ����ؽ�����������壡���Ҳ����ɣ�\n");
		    silk2 = new("/tongji/obj/jp1");
		    silk2->move(this_object());
		    command("give jianb to " + who->query("id"));
		    who->set("title",HIR"��"+HIC"��"+HIM"Ӣ"+HIW"��"NOR);
		    who->set("m_success/ͨ��",1);
	message("system",HIC "\n�����ַ��ơ���������"+who->query("name")+"�⿪��������⣬�����"HIY"������Ӣ����"HIC"�ĳƺš�\n" NOR,users());

	    }
		
		return 1;
}



int give_tongji(string arg)
{
        mapping tongji;
        object obj0,obj1,obj2,room1;
        string file,location,*roomlines,objid,output;
        object me;
        int j, combatexp,lv,i;
        string tag ="1";
        me = this_player();
       
//		if(query_temp("gtongji") >= 10)
//		{
//               write("�Ѿ���ʮ��������ң���⣬�Ȼ����������ɣ�\n");
//                return 1;			
//		}

		if( ((int) me->query("tongji_time")) >  time() )
        {
        tell_object(me,"\n��ող������ͨ�����񣬵Ȼ����������ɣ�\n");
                return 1;
        }

         if((int)me->query("ftongji") > 5000)
        {
        tell_object(me,"\n���ͨ�������Ѿ��ǳ������ˣ�ȥ��������������ս�Ե�����ɣ�\n");
                return 1;
        }

         if((int)me->query("level") < 35)
        {
        tell_object(me,"\n��������Ȼ����1�����������ԶԸ�ʮ����ˣ�лл���ĺ��⣡\n");
               return 1;
        }

          if((int)me->query("level") > 80)
        {
        tell_object(me,"\n���Ѿ��ﵽ��������֮����ʮ����˲���Ҫ�ͷ��������ˣ�\n");
                return 1;
        }

        if((int) me->is_ghost())
        {
                write("�������չ˺����Լ��ɣ�\n");
                return 1;
        }
//        if(me->query("m_success/ͨ��"))
//        {       write("лл���ĺ��⣡ʮ������Ѿ�ȫ�������������ֿ���ƽ��һ�������ˡ�\n");
//                return 1;
//        }

		j=2000;
		lv = me->query("level");
		for(i=0;i<lv;i++)
		j=j+j/9;
		 if((int) me->query("combat_exp") > j)
        {
                write("��ľ��鳬��������������飬����������\n");
                return 1;
        }

      if((tongji =  me->query("tongji")))
        {
        tell_object(me,"\n���Ѿ�������ͨ����"+tongji["tongji"]+"��������,���Ͱ�!\n");
        return 1;
        }
        
        file = read_file("/tongji/dynamic_location");
        roomlines = explode(file,"\n"); 
        location = roomlines[random(sizeof(roomlines))];

                if( catch(load_object(location)) || !load_object(location) )
                {
                        write("ͨ�����˳����쳣�����Ժ�Ƭ�����������롣\n");
                        return 1;               
                }

tongji = TONGJI_D(tag)->query_tongji();

        tell_object(me,"�ü���,��͢����ȫ��Χ�ˡ�"+tongji["tongji"]+"�������ȥ��,�᡺"+tongji["tongji"]+"����ͷ����,��͢�������͡�\n" NOR);
        me->set("tongji", tongji);


                switch(tongji["tongji"]){
                        case "�����":
                                obj1=new("/tongji/npc/lidazui");
                                objid=obj1->query("id");
                                obj1->set_name(HIR "�����" NOR, ({ "lidazui" }) );
                                break;
                        case "��ɱ":
                                obj1=new("/tongji/npc/dusha");
                                objid=obj1->query("id");
                                obj1->set_name(HIR"��ɱ" NOR, ({ "dusha" }) );
                                break;
                        case "������":
                                obj1=new("/tongji/npc/tujiao");
                                objid=obj1->query("id");
                                obj1->set_name(HIY "������" NOR, ({ "tujiaojiao" }) );
                                break;
                        case "������":
                                obj1=new("/tongji/npc/yinjiuyou");
                                objid=obj1->query("id");
                                obj1->set_name(HIW"������" NOR, ({ "yinjiuyou" }) );
                                break;
                        case "�׿���":
                                obj1=new("/tongji/npc/baikaixin");
                                objid=obj1->query("id");
                                obj1->set_name(HIW "�׿���" NOR, ({ "baikaixin" }) );
                                break;
                        case "��ս":
                                obj1=new("/tongji/npc/tiezhan");
                                objid=obj1->query("id");
                                obj1->set_name(HIG "��ս" NOR, ({ "tiezhan" }) );
                                break;
                        case "������":
                                obj1=new("/tongji/npc/xiaomimi");
                                objid=obj1->query("id");
                                obj1->set_name(HIC"������" NOR, ({ "xiaomimi" }) );
                                break;
                        case "������":
                                obj1=new("/tongji/npc/hahaer");
                                objid=obj1->query("id");
                                obj1->set_name(HIG"������" NOR, ({ "hahaer" }) );
                                break;
                        case "ŷ������":
                                obj1=new("/tongji/npc/ouyangding");
                                objid=obj1->query("id");
                                obj1->set_name(HIB"ŷ����" NOR, ({ "ouyangding" }) );
                                obj2=new("/tongji/npc/ouyangdang");
								obj2->set_name(HIB"ŷ����" NOR, ({ "ouyangdang" }) );
                                break;
                        case "��ԯ����":
                                obj1=new("/tongji/npc/sanguang");
                                objid=obj1->query("id");
                                obj1->set_name(HIM"��ԯ����" NOR, ({ "sanguang" }) );
                                break;
                        }

//        obj1->set_temp("owner", this_object());
         obj1->set_temp("owner/id",me->query("id"));
         obj1->set("level",me->query("level")+10); 
		 lv = obj1->query("level");
		 obj1->set("str",6*lv);
		 obj1->set("cor",6*lv);
		 obj1->set("int",6*lv);
		 obj1->set("spi",6*lv);
		 obj1->set("cps",6*lv);
		 obj1->set("per",6*lv);
		 obj1->set("con",6*lv);
		 obj1->set("kar",6*lv);
		 obj1->set("agi",6*lv);
		 obj1->set("dur",6*lv);
		 obj1->set("fle",6*lv);
		 obj1->set("tol",6*lv);
		 obj1->set("max_kee",me->query("max_kee")*2);
		 obj1->set("eff_kee",obj1->query("max_kee"));
		 obj1->set("kee",obj1->query("max_kee"));
		 obj1->set("max_gin",me->query("max_gin")*2);
		 obj1->set("eff_gin",obj1->query("max_gin"));
		 obj1->set("gin",obj1->query("max_gin"));
		 obj1->set("max_sen",me->query("max_sen")*2);
		 obj1->set("eff_sen",obj1->query("max_sen"));
		 obj1->set("sen",obj1->query("max_sen"));

		obj1->move(location);
        if(obj2)
        {
         obj2->set_temp("owner/id",me->query("id"));
         obj2->set("level",me->query("level")+10); 
		 lv = obj2->query("level");
		 obj2->set("str",6*lv);
		 obj2->set("cor",6*lv);
		 obj2->set("int",6*lv);
		 obj2->set("spi",6*lv);
		 obj2->set("cps",6*lv);
		 obj2->set("per",6*lv);
		 obj2->set("con",6*lv);
		 obj2->set("kar",6*lv);
		 obj2->set("agi",6*lv);
		 obj2->set("dur",6*lv);
		 obj2->set("fle",6*lv);
		 obj2->set("tol",6*lv);
		 obj2->set("max_kee",me->query("max_kee")*2);
		 obj2->set("eff_kee",obj2->query("max_kee"));
		 obj2->set("kee",obj2->query("max_kee"));
		 obj2->set("max_gin",me->query("max_gin")*2);
		 obj2->set("eff_gin",obj2->query("max_gin"));
		 obj2->set("gin",obj2->query("max_gin"));
		 obj2->set("max_sen",me->query("max_sen")*2);
		 obj2->set("eff_sen",obj2->query("max_sen"));
		 obj2->set("sen",obj2->query("max_sen"));
        	obj2->add_team_member(obj1);
        }

//        room1 = load_object(location);
//        if(room1)
//        {
//	        room1->set("no_beg",1);
//	        room1->set("no_sheet",1);
//	        room1->set("no_magic",1);
//        }
		me->set("tongji_time", (int) time()+360);
		me->save();

	output = TASK_D->locate_obj(this_object(),objid);
	if(output=="")
		output = "��ʱȷ������ʮ����˵Ĵ��λ�á�\n";
	write(output);
//	add_temp("gtongji",1);
		if (me->query("tongjiauto")-time()>0)
				{
					write("��ʹ�õ�ͨ�����񵤷��ӹ�Ч��.\n");
					me->move(location);
				}
		return 1;
}
int random_action(){
switch(random(4)){
        case 0:
          
      command("say ��͢����ʮ�����,����λ����ͬ������Ԯ��.");
                break;
        case 1:
                command("say Э����͢����ʮ����ˣ�������");
                break;
        case 2:
      command("say ��վ�����̳��ַΪhttp://club.xilu.com/happyfy3����ӭǰ���������ı�ī��");
                break;

        case 3:
                command("say �Ҿ�Ȼ��һ�ж�������������������,�������Ĺ��򣮣�����");
                break;}
     return 1;
}
